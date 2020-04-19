#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>

#include "MRKUI.h"

#define FONTSTASH_IMPLEMENTATION

#include "fontstash.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#ifdef _MSC_VER
                                                                                                                        #pragma warning(disable: 4100)  // unreferenced formal parameter
#pragma warning(disable: 4127)  // conditional expression is constant
#pragma warning(disable: 4204)  // nonstandard extension used : non-constant aggregate initializer
#pragma warning(disable: 4706)  // assignment within conditional expression
#endif

#define MRKUI_INIT_FONTIMAGE_SIZE  512
#define MRKUI_MAX_FONTIMAGE_SIZE   2048
#define MRKUI_MAX_FONTIMAGES       4

#define MRKUI_INIT_COMMANDS_SIZE 256
#define MRKUI_INIT_POINTS_SIZE 128
#define MRKUI_INIT_PATHS_SIZE 16
#define MRKUI_INIT_VERTS_SIZE 256
#define MRKUI_MAX_STATES 32

#define MRKUI_KAPPA90 0.5522847493f    // Length proportional to radius of a cubic bezier handle for 90deg arcs.

#define MRKUI_COUNTOF(arr) (sizeof(arr) / sizeof(0[arr]))


enum MRKUIcommands {
    MRKUI_MOVETO = 0,
    MRKUI_LINETO = 1,
    MRKUI_BEZIERTO = 2,
    MRKUI_CLOSE = 3,
    MRKUI_WINDING = 4,
};

enum MRKUIpointFlags {
    MRKUI_PT_CORNER = 0x01,
    MRKUI_PT_LEFT = 0x02,
    MRKUI_PT_BEVEL = 0x04,
    MRKUI_PR_INNERBEVEL = 0x08,
};

struct MRKUIstate {
    MRKUIcompositeOperationState compositeOperation;
    int shapeAntiAlias;
    MRKUIpaint fill;
    MRKUIpaint stroke;
    float strokeWidth;
    float miterLimit;
    int lineJoin;
    int lineCap;
    float alpha;
    float xform[6];
    MRKUIscissor scissor;
    float fontSize;
    float letterSpacing;
    float lineHeight;
    float fontBlur;
    int textAlign;
    int fontId;
};
typedef struct MRKUIstate MRKUIstate;

struct MRKUIpoint {
    float x, y;
    float dx, dy;
    float len;
    float dmx, dmy;
    unsigned char flags;
};
typedef struct MRKUIpoint MRKUIpoint;

struct MRKUIpathCache {
    MRKUIpoint *points;
    int npoints;
    int cpoints;
    MRKUIpath *paths;
    int npaths;
    int cpaths;
    MRKUIvertex *verts;
    int nverts;
    int cverts;
    float bounds[4];
};
typedef struct MRKUIpathCache MRKUIpathCache;

struct MRKUIcontext {
    MRKUIparams params;
    float *commands;
    int ccommands;
    int ncommands;
    float commandx, commandy;
    MRKUIstate states[MRKUI_MAX_STATES];
    int nstates;
    MRKUIpathCache *cache;
    float tessTol;
    float distTol;
    float fringeWidth;
    float devicePxRatio;
    struct FONScontext *fs;
    int fontImages[MRKUI_MAX_FONTIMAGES];
    int fontImageIdx;
    int drawCallCount;
    int fillTriCount;
    int strokeTriCount;
    int textTriCount;
};

static float MRKUI__sqrtf(float a) { return sqrtf(a); }

static float MRKUI__modf(float a, float b) { return fmodf(a, b); }

static float MRKUI__sinf(float a) { return sinf(a); }

static float MRKUI__cosf(float a) { return cosf(a); }

static float MRKUI__tanf(float a) { return tanf(a); }

static float MRKUI__atan2f(float a, float b) { return atan2f(a, b); }

static float MRKUI__acosf(float a) { return acosf(a); }

static int MRKUI__mini(int a, int b) { return a < b ? a : b; }

static int MRKUI__maxi(int a, int b) { return a > b ? a : b; }

static int MRKUI__clampi(int a, int mn, int mx) { return a < mn ? mn : (a > mx ? mx : a); }

static float MRKUI__minf(float a, float b) { return a < b ? a : b; }

static float MRKUI__maxf(float a, float b) { return a > b ? a : b; }

static float MRKUI__absf(float a) { return a >= 0.0f ? a : -a; }

static float MRKUI__signf(float a) { return a >= 0.0f ? 1.0f : -1.0f; }

static float MRKUI__clampf(float a, float mn, float mx) { return a < mn ? mn : (a > mx ? mx : a); }

static float MRKUI__cross(float dx0, float dy0, float dx1, float dy1) {
    return dx1 * dy0 - dx0 * dy1;
}

static float MRKUI__normalize(float *x, float *y) {
    float d = MRKUI__sqrtf((*x) * (*x) + (*y) * (*y));
    if (d > 1e-6f) {
        float id = 1.0f / d;
        *x *= id;
        *y *= id;
    }
    return d;
}


static void MRKUI__deletePathCache(MRKUIpathCache *c) {
    if (c == NULL) return;
    if (c->points != NULL) free(c->points);
    if (c->paths != NULL) free(c->paths);
    if (c->verts != NULL) free(c->verts);
    free(c);
}

static MRKUIpathCache *MRKUI__allocPathCache(void) {
    MRKUIpathCache *c = (MRKUIpathCache *) malloc(sizeof(MRKUIpathCache));
    if (c == NULL) goto error;
    memset(c, 0, sizeof(MRKUIpathCache));

    c->points = (MRKUIpoint *) malloc(sizeof(MRKUIpoint) * MRKUI_INIT_POINTS_SIZE);
    if (!c->points) goto error;
    c->npoints = 0;
    c->cpoints = MRKUI_INIT_POINTS_SIZE;

    c->paths = (MRKUIpath *) malloc(sizeof(MRKUIpath) * MRKUI_INIT_PATHS_SIZE);
    if (!c->paths) goto error;
    c->npaths = 0;
    c->cpaths = MRKUI_INIT_PATHS_SIZE;

    c->verts = (MRKUIvertex *) malloc(sizeof(MRKUIvertex) * MRKUI_INIT_VERTS_SIZE);
    if (!c->verts) goto error;
    c->nverts = 0;
    c->cverts = MRKUI_INIT_VERTS_SIZE;

    return c;
    error:
    MRKUI__deletePathCache(c);
    return NULL;
}

static void MRKUI__setDevicePixelRatio(MRKUIcontext *ctx, float ratio) {
    ctx->tessTol = 0.25f / ratio;
    ctx->distTol = 0.01f / ratio;
    ctx->fringeWidth = 1.0f / ratio;
    ctx->devicePxRatio = ratio;
}

static MRKUIcompositeOperationState MRKUI__compositeOperationState(int op) {
    int sfactor, dfactor;

    if (op == MRKUI_SOURCE_OVER) {
        sfactor = MRKUI_ONE;
        dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
    } else if (op == MRKUI_SOURCE_IN) {
        sfactor = MRKUI_DST_ALPHA;
        dfactor = MRKUI_ZERO;
    } else if (op == MRKUI_SOURCE_OUT) {
        sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
        dfactor = MRKUI_ZERO;
    } else if (op == MRKUI_ATOP) {
        sfactor = MRKUI_DST_ALPHA;
        dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
    } else if (op == MRKUI_DESTINATION_OVER) {
        sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
        dfactor = MRKUI_ONE;
    } else if (op == MRKUI_DESTINATION_IN) {
        sfactor = MRKUI_ZERO;
        dfactor = MRKUI_SRC_ALPHA;
    } else if (op == MRKUI_DESTINATION_OUT) {
        sfactor = MRKUI_ZERO;
        dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
    } else if (op == MRKUI_DESTINATION_ATOP) {
        sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
        dfactor = MRKUI_SRC_ALPHA;
    } else if (op == MRKUI_LIGHTER) {
        sfactor = MRKUI_ONE;
        dfactor = MRKUI_ONE;
    } else if (op == MRKUI_COPY) {
        sfactor = MRKUI_ONE;
        dfactor = MRKUI_ZERO;
    } else if (op == MRKUI_XOR) {
        sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
        dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
    } else {
        sfactor = MRKUI_ONE;
        dfactor = MRKUI_ZERO;
    }

    MRKUIcompositeOperationState state;
    state.srcRGB = sfactor;
    state.dstRGB = dfactor;
    state.srcAlpha = sfactor;
    state.dstAlpha = dfactor;
    return state;
}

static MRKUIstate *MRKUI__getState(MRKUIcontext *ctx) {
    return &ctx->states[ctx->nstates - 1];
}

MRKUIcontext *MRKUICreateInternal(MRKUIparams *params) {
    FONSparams fontParams;
    MRKUIcontext *ctx = (MRKUIcontext *) malloc(sizeof(MRKUIcontext));
    int i;
    if (ctx == NULL) goto error;
    memset(ctx, 0, sizeof(MRKUIcontext));

    ctx->params = *params;
    for (i = 0; i < MRKUI_MAX_FONTIMAGES; i++)
        ctx->fontImages[i] = 0;

    ctx->commands = (float *) malloc(sizeof(float) * MRKUI_INIT_COMMANDS_SIZE);
    if (!ctx->commands) goto error;
    ctx->ncommands = 0;
    ctx->ccommands = MRKUI_INIT_COMMANDS_SIZE;

    ctx->cache = MRKUI__allocPathCache();
    if (ctx->cache == NULL) goto error;

    MRKUISave(ctx);
    MRKUIReset(ctx);

    MRKUI__setDevicePixelRatio(ctx, 1.0f);

    if (ctx->params.renderCreate(ctx->params.userPtr) == 0) goto error;

    // Init font rendering
    memset(&fontParams, 0, sizeof(fontParams));
    fontParams.width = MRKUI_INIT_FONTIMAGE_SIZE;
    fontParams.height = MRKUI_INIT_FONTIMAGE_SIZE;
    fontParams.flags = FONS_ZERO_TOPLEFT;
    fontParams.renderCreate = NULL;
    fontParams.renderUpdate = NULL;
    fontParams.renderDraw = NULL;
    fontParams.renderDelete = NULL;
    fontParams.userPtr = NULL;
    ctx->fs = fonsCreateInternal(&fontParams);
    if (ctx->fs == NULL) goto error;

    // Create font texture
    ctx->fontImages[0] = ctx->params.renderCreateTexture(ctx->params.userPtr, MRKUI_TEXTURE_ALPHA,
                                                         fontParams.width, fontParams.height, 0,
                                                         NULL);
    if (ctx->fontImages[0] == 0) goto error;
    ctx->fontImageIdx = 0;

    return ctx;

    error:
    MRKUIDeleteInternal(ctx);
    return 0;
}

MRKUIparams *MRKUIInternalParams(MRKUIcontext *ctx) {
    return &ctx->params;
}

void MRKUIDeleteInternal(MRKUIcontext *ctx) {
    int i;
    if (ctx == NULL) return;
    if (ctx->commands != NULL) free(ctx->commands);
    if (ctx->cache != NULL) MRKUI__deletePathCache(ctx->cache);

    if (ctx->fs)
        fonsDeleteInternal(ctx->fs);

    for (i = 0; i < MRKUI_MAX_FONTIMAGES; i++) {
        if (ctx->fontImages[i] != 0) {
            MRKUIDeleteImage(ctx, ctx->fontImages[i]);
            ctx->fontImages[i] = 0;
        }
    }

    if (ctx->params.renderDelete != NULL)
        ctx->params.renderDelete(ctx->params.userPtr);

    free(ctx);
}

void
MRKUIBeginFrame(MRKUIcontext *ctx, float windowWidth, float windowHeight, float devicePixelRatio) {
/*	printf("Tris: draws:%d  fill:%d  stroke:%d  text:%d  TOT:%d\n",
		ctx->drawCallCount, ctx->fillTriCount, ctx->strokeTriCount, ctx->textTriCount,
		ctx->fillTriCount+ctx->strokeTriCount+ctx->textTriCount);*/

    ctx->nstates = 0;
    MRKUISave(ctx);
    MRKUIReset(ctx);

    MRKUI__setDevicePixelRatio(ctx, devicePixelRatio);

    ctx->params.renderViewport(ctx->params.userPtr, windowWidth, windowHeight, devicePixelRatio);

    ctx->drawCallCount = 0;
    ctx->fillTriCount = 0;
    ctx->strokeTriCount = 0;
    ctx->textTriCount = 0;
}

void MRKUICancelFrame(MRKUIcontext *ctx) {
    ctx->params.renderCancel(ctx->params.userPtr);
}

void MRKUIEndFrame(MRKUIcontext *ctx) {
    ctx->params.renderFlush(ctx->params.userPtr);
    if (ctx->fontImageIdx != 0) {
        int fontImage = ctx->fontImages[ctx->fontImageIdx];
        int i, j, iw, ih;
        // delete images that smaller than current one
        if (fontImage == 0)
            return;
        MRKUIImageSize(ctx, fontImage, &iw, &ih);
        for (i = j = 0; i < ctx->fontImageIdx; i++) {
            if (ctx->fontImages[i] != 0) {
                int nw, nh;
                MRKUIImageSize(ctx, ctx->fontImages[i], &nw, &nh);
                if (nw < iw || nh < ih)
                    MRKUIDeleteImage(ctx, ctx->fontImages[i]);
                else
                    ctx->fontImages[j++] = ctx->fontImages[i];
            }
        }
        // make current font image to first
        ctx->fontImages[j++] = ctx->fontImages[0];
        ctx->fontImages[0] = fontImage;
        ctx->fontImageIdx = 0;
        // clear all images after j
        for (i = j; i < MRKUI_MAX_FONTIMAGES; i++)
            ctx->fontImages[i] = 0;
    }
}

MRKUIcolor MRKUIRGB(unsigned char r, unsigned char g, unsigned char b) {
    return MRKUIRGBA(r, g, b, 255);
}

MRKUIcolor MRKUIRGBf(float r, float g, float b) {
    return MRKUIRGBAf(r, g, b, 1.0f);
}

MRKUIcolor MRKUIRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    MRKUIcolor color;
    // Use longer initialization to suppress warning.
    color.r = r / 255.0f;
    color.g = g / 255.0f;
    color.b = b / 255.0f;
    color.a = a / 255.0f;
    return color;
}

MRKUIcolor MRKUIRGBAf(float r, float g, float b, float a) {
    MRKUIcolor color;
    // Use longer initialization to suppress warning.
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

MRKUIcolor MRKUITransRGBA(MRKUIcolor c, unsigned char a) {
    c.a = a / 255.0f;
    return c;
}

MRKUIcolor MRKUITransRGBAf(MRKUIcolor c, float a) {
    c.a = a;
    return c;
}

MRKUIcolor MRKUILerpRGBA(MRKUIcolor c0, MRKUIcolor c1, float u) {
    int i;
    float oneminu;
    MRKUIcolor cint = {{{0}}};

    u = MRKUI__clampf(u, 0.0f, 1.0f);
    oneminu = 1.0f - u;
    for (i = 0; i < 4; i++) {
        cint.rgba[i] = c0.rgba[i] * oneminu + c1.rgba[i] * u;
    }

    return cint;
}

MRKUIcolor MRKUIHSL(float h, float s, float l) {
    return MRKUIHSLA(h, s, l, 255);
}

static float MRKUI__hue(float h, float m1, float m2) {
    if (h < 0) h += 1;
    if (h > 1) h -= 1;
    if (h < 1.0f / 6.0f)
        return m1 + (m2 - m1) * h * 6.0f;
    else if (h < 3.0f / 6.0f)
        return m2;
    else if (h < 4.0f / 6.0f)
        return m1 + (m2 - m1) * (2.0f / 3.0f - h) * 6.0f;
    return m1;
}

MRKUIcolor MRKUIHSLA(float h, float s, float l, unsigned char a) {
    float m1, m2;
    MRKUIcolor col;
    h = MRKUI__modf(h, 1.0f);
    if (h < 0.0f) h += 1.0f;
    s = MRKUI__clampf(s, 0.0f, 1.0f);
    l = MRKUI__clampf(l, 0.0f, 1.0f);
    m2 = l <= 0.5f ? (l * (1 + s)) : (l + s - l * s);
    m1 = 2 * l - m2;
    col.r = MRKUI__clampf(MRKUI__hue(h + 1.0f / 3.0f, m1, m2), 0.0f, 1.0f);
    col.g = MRKUI__clampf(MRKUI__hue(h, m1, m2), 0.0f, 1.0f);
    col.b = MRKUI__clampf(MRKUI__hue(h - 1.0f / 3.0f, m1, m2), 0.0f, 1.0f);
    col.a = a / 255.0f;
    return col;
}

void MRKUITransformIdentity(float *t) {
    t[0] = 1.0f;
    t[1] = 0.0f;
    t[2] = 0.0f;
    t[3] = 1.0f;
    t[4] = 0.0f;
    t[5] = 0.0f;
}

void MRKUITransformTranslate(float *t, float tx, float ty) {
    t[0] = 1.0f;
    t[1] = 0.0f;
    t[2] = 0.0f;
    t[3] = 1.0f;
    t[4] = tx;
    t[5] = ty;
}

void MRKUITransformScale(float *t, float sx, float sy) {
    t[0] = sx;
    t[1] = 0.0f;
    t[2] = 0.0f;
    t[3] = sy;
    t[4] = 0.0f;
    t[5] = 0.0f;
}

void MRKUITransformRotate(float *t, float a) {
    float cs = MRKUI__cosf(a), sn = MRKUI__sinf(a);
    t[0] = cs;
    t[1] = sn;
    t[2] = -sn;
    t[3] = cs;
    t[4] = 0.0f;
    t[5] = 0.0f;
}

void MRKUITransformSkewX(float *t, float a) {
    t[0] = 1.0f;
    t[1] = 0.0f;
    t[2] = MRKUI__tanf(a);
    t[3] = 1.0f;
    t[4] = 0.0f;
    t[5] = 0.0f;
}

void MRKUITransformSkewY(float *t, float a) {
    t[0] = 1.0f;
    t[1] = MRKUI__tanf(a);
    t[2] = 0.0f;
    t[3] = 1.0f;
    t[4] = 0.0f;
    t[5] = 0.0f;
}

void MRKUITransformMultiply(float *t, const float *s) {
    float t0 = t[0] * s[0] + t[1] * s[2];
    float t2 = t[2] * s[0] + t[3] * s[2];
    float t4 = t[4] * s[0] + t[5] * s[2] + s[4];
    t[1] = t[0] * s[1] + t[1] * s[3];
    t[3] = t[2] * s[1] + t[3] * s[3];
    t[5] = t[4] * s[1] + t[5] * s[3] + s[5];
    t[0] = t0;
    t[2] = t2;
    t[4] = t4;
}

void MRKUITransformPremultiply(float *t, const float *s) {
    float s2[6];
    memcpy(s2, s, sizeof(float) * 6);
    MRKUITransformMultiply(s2, t);
    memcpy(t, s2, sizeof(float) * 6);
}

int MRKUITransformInverse(float *inv, const float *t) {
    double invdet, det = (double) t[0] * t[3] - (double) t[2] * t[1];
    if (det > -1e-6 && det < 1e-6) {
        MRKUITransformIdentity(inv);
        return 0;
    }
    invdet = 1.0 / det;
    inv[0] = (float) (t[3] * invdet);
    inv[2] = (float) (-t[2] * invdet);
    inv[4] = (float) (((double) t[2] * t[5] - (double) t[3] * t[4]) * invdet);
    inv[1] = (float) (-t[1] * invdet);
    inv[3] = (float) (t[0] * invdet);
    inv[5] = (float) (((double) t[1] * t[4] - (double) t[0] * t[5]) * invdet);
    return 1;
}

void MRKUITransformPoint(float *dx, float *dy, const float *t, float sx, float sy) {
    *dx = sx * t[0] + sy * t[2] + t[4];
    *dy = sx * t[1] + sy * t[3] + t[5];
}

float MRKUIDegToRad(float deg) {
    return deg / 180.0f * MRKUI_PI;
}

float MRKUIRadToDeg(float rad) {
    return rad / MRKUI_PI * 180.0f;
}

static void MRKUI__setPaintColor(MRKUIpaint *p, MRKUIcolor color) {
    memset(p, 0, sizeof(*p));
    MRKUITransformIdentity(p->xform);
    p->radius = 0.0f;
    p->feather = 1.0f;
    p->innerColor = color;
    p->outerColor = color;
}


// State handling
void MRKUISave(MRKUIcontext *ctx) {
    if (ctx->nstates >= MRKUI_MAX_STATES)
        return;
    if (ctx->nstates > 0)
        memcpy(&ctx->states[ctx->nstates], &ctx->states[ctx->nstates - 1], sizeof(MRKUIstate));
    ctx->nstates++;
}

void MRKUIRestore(MRKUIcontext *ctx) {
    if (ctx->nstates <= 1)
        return;
    ctx->nstates--;
}

void MRKUIReset(MRKUIcontext *ctx) {
    MRKUIstate *state = MRKUI__getState(ctx);
    memset(state, 0, sizeof(*state));

    MRKUI__setPaintColor(&state->fill, MRKUIRGBA(255, 255, 255, 255));
    MRKUI__setPaintColor(&state->stroke, MRKUIRGBA(0, 0, 0, 255));
    state->compositeOperation = MRKUI__compositeOperationState(MRKUI_SOURCE_OVER);
    state->shapeAntiAlias = 1;
    state->strokeWidth = 1.0f;
    state->miterLimit = 10.0f;
    state->lineCap = MRKUI_BUTT;
    state->lineJoin = MRKUI_MITER;
    state->alpha = 1.0f;
    MRKUITransformIdentity(state->xform);

    state->scissor.extent[0] = -1.0f;
    state->scissor.extent[1] = -1.0f;

    state->fontSize = 16.0f;
    state->letterSpacing = 0.0f;
    state->lineHeight = 1.0f;
    state->fontBlur = 0.0f;
    state->textAlign = MRKUI_ALIGN_LEFT | MRKUI_ALIGN_BASELINE;
    state->fontId = 0;
}

// State setting
void MRKUIShapeAntiAlias(MRKUIcontext *ctx, int enabled) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->shapeAntiAlias = enabled;
}

void MRKUIStrokeWidth(MRKUIcontext *ctx, float width) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->strokeWidth = width;
}

void MRKUIMiterLimit(MRKUIcontext *ctx, float limit) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->miterLimit = limit;
}

void MRKUILineCap(MRKUIcontext *ctx, int cap) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->lineCap = cap;
}

void MRKUILineJoin(MRKUIcontext *ctx, int join) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->lineJoin = join;
}

void MRKUIGlobalAlpha(MRKUIcontext *ctx, float alpha) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->alpha = alpha;
}

void MRKUITransform(MRKUIcontext *ctx, float a, float b, float c, float d, float e, float f) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6] = {a, b, c, d, e, f};
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUIResetTransform(MRKUIcontext *ctx) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUITransformIdentity(state->xform);
}

void MRKUITranslate(MRKUIcontext *ctx, float x, float y) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6];
    MRKUITransformTranslate(t, x, y);
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUIRotate(MRKUIcontext *ctx, float angle) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6];
    MRKUITransformRotate(t, angle);
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUISkewX(MRKUIcontext *ctx, float angle) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6];
    MRKUITransformSkewX(t, angle);
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUISkewY(MRKUIcontext *ctx, float angle) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6];
    MRKUITransformSkewY(t, angle);
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUIScale(MRKUIcontext *ctx, float x, float y) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float t[6];
    MRKUITransformScale(t, x, y);
    MRKUITransformPremultiply(state->xform, t);
}

void MRKUICurrentTransform(MRKUIcontext *ctx, float *xform) {
    MRKUIstate *state = MRKUI__getState(ctx);
    if (xform == NULL) return;
    memcpy(xform, state->xform, sizeof(float) * 6);
}

void MRKUIStrokeColor(MRKUIcontext *ctx, MRKUIcolor color) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUI__setPaintColor(&state->stroke, color);
}

void MRKUIStrokePaint(MRKUIcontext *ctx, MRKUIpaint paint) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->stroke = paint;
    MRKUITransformMultiply(state->stroke.xform, state->xform);
}

void MRKUIFillColor(MRKUIcontext *ctx, MRKUIcolor color) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUI__setPaintColor(&state->fill, color);
}

void MRKUIFillPaint(MRKUIcontext *ctx, MRKUIpaint paint) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->fill = paint;
    MRKUITransformMultiply(state->fill.xform, state->xform);
}

int MRKUICreateImage(MRKUIcontext *ctx, const char *filename, int imageFlags) {
    int w, h, n, image;
    unsigned char *img;
    stbi_set_unpremultiply_on_load(1);
    stbi_convert_iphone_png_to_rgb(1);
    img = stbi_load(filename, &w, &h, &n, 4);
    if (img == NULL) {
//		printf("Failed to load %s - %s\n", filename, stbi_failure_reason());
        return 0;
    }
    image = MRKUICreateImageRGBA(ctx, w, h, imageFlags, img);
    stbi_image_free(img);
    return image;
}

int MRKUICreateImageMem(MRKUIcontext *ctx, int imageFlags, unsigned char *data, int ndata) {
    int w, h, n, image;
    unsigned char *img = stbi_load_from_memory(data, ndata, &w, &h, &n, 4);
    if (img == NULL) {
//		printf("Failed to load %s - %s\n", filename, stbi_failure_reason());
        return 0;
    }
    image = MRKUICreateImageRGBA(ctx, w, h, imageFlags, img);
    stbi_image_free(img);
    return image;
}

int
MRKUICreateImageRGBA(MRKUIcontext *ctx, int w, int h, int imageFlags, const unsigned char *data) {
    return ctx->params.renderCreateTexture(ctx->params.userPtr, MRKUI_TEXTURE_RGBA, w, h,
                                           imageFlags, data);
}

void MRKUIUpdateImage(MRKUIcontext *ctx, int image, const unsigned char *data) {
    int w, h;
    ctx->params.renderGetTextureSize(ctx->params.userPtr, image, &w, &h);
    ctx->params.renderUpdateTexture(ctx->params.userPtr, image, 0, 0, w, h, data);
}

void MRKUIImageSize(MRKUIcontext *ctx, int image, int *w, int *h) {
    ctx->params.renderGetTextureSize(ctx->params.userPtr, image, w, h);
}

void MRKUIDeleteImage(MRKUIcontext *ctx, int image) {
    ctx->params.renderDeleteTexture(ctx->params.userPtr, image);
}

MRKUIpaint MRKUILinearGradient(MRKUIcontext *ctx,
                               float sx, float sy, float ex, float ey,
                               MRKUIcolor icol, MRKUIcolor ocol) {
    MRKUIpaint p;
    float dx, dy, d;
    const float large = 1e5;
    MRKUI_NOTUSED(ctx);
    memset(&p, 0, sizeof(p));

    // Calculate transform aligned to the line
    dx = ex - sx;
    dy = ey - sy;
    d = sqrtf(dx * dx + dy * dy);
    if (d > 0.0001f) {
        dx /= d;
        dy /= d;
    } else {
        dx = 0;
        dy = 1;
    }

    p.xform[0] = dy;
    p.xform[1] = -dx;
    p.xform[2] = dx;
    p.xform[3] = dy;
    p.xform[4] = sx - dx * large;
    p.xform[5] = sy - dy * large;

    p.extent[0] = large;
    p.extent[1] = large + d * 0.5f;

    p.radius = 0.0f;

    p.feather = MRKUI__maxf(1.0f, d);

    p.innerColor = icol;
    p.outerColor = ocol;

    return p;
}

MRKUIpaint MRKUIRadialGradient(MRKUIcontext *ctx,
                               float cx, float cy, float inr, float outr,
                               MRKUIcolor icol, MRKUIcolor ocol) {
    MRKUIpaint p;
    float r = (inr + outr) * 0.5f;
    float f = (outr - inr);
    MRKUI_NOTUSED(ctx);
    memset(&p, 0, sizeof(p));

    MRKUITransformIdentity(p.xform);
    p.xform[4] = cx;
    p.xform[5] = cy;

    p.extent[0] = r;
    p.extent[1] = r;

    p.radius = r;

    p.feather = MRKUI__maxf(1.0f, f);

    p.innerColor = icol;
    p.outerColor = ocol;

    return p;
}

MRKUIpaint MRKUIBoxGradient(MRKUIcontext *ctx,
                            float x, float y, float w, float h, float r, float f,
                            MRKUIcolor icol, MRKUIcolor ocol) {
    MRKUIpaint p;
    MRKUI_NOTUSED(ctx);
    memset(&p, 0, sizeof(p));

    MRKUITransformIdentity(p.xform);
    p.xform[4] = x + w * 0.5f;
    p.xform[5] = y + h * 0.5f;

    p.extent[0] = w * 0.5f;
    p.extent[1] = h * 0.5f;

    p.radius = r;

    p.feather = MRKUI__maxf(1.0f, f);

    p.innerColor = icol;
    p.outerColor = ocol;

    return p;
}


MRKUIpaint MRKUIImagePattern(MRKUIcontext *ctx,
                             float cx, float cy, float w, float h, float angle,
                             int image, float alpha) {
    MRKUIpaint p;
    MRKUI_NOTUSED(ctx);
    memset(&p, 0, sizeof(p));

    MRKUITransformRotate(p.xform, angle);
    p.xform[4] = cx;
    p.xform[5] = cy;

    p.extent[0] = w;
    p.extent[1] = h;

    p.image = image;

    p.innerColor = p.outerColor = MRKUIRGBAf(1, 1, 1, alpha);

    return p;
}

// Scissoring
void MRKUIScissor(MRKUIcontext *ctx, float x, float y, float w, float h) {
    MRKUIstate *state = MRKUI__getState(ctx);

    w = MRKUI__maxf(0.0f, w);
    h = MRKUI__maxf(0.0f, h);

    MRKUITransformIdentity(state->scissor.xform);
    state->scissor.xform[4] = x + w * 0.5f;
    state->scissor.xform[5] = y + h * 0.5f;
    MRKUITransformMultiply(state->scissor.xform, state->xform);

    state->scissor.extent[0] = w * 0.5f;
    state->scissor.extent[1] = h * 0.5f;
}

static void MRKUI__isectRects(float *dst,
                              float ax, float ay, float aw, float ah,
                              float bx, float by, float bw, float bh) {
    float minx = MRKUI__maxf(ax, bx);
    float miny = MRKUI__maxf(ay, by);
    float maxx = MRKUI__minf(ax + aw, bx + bw);
    float maxy = MRKUI__minf(ay + ah, by + bh);
    dst[0] = minx;
    dst[1] = miny;
    dst[2] = MRKUI__maxf(0.0f, maxx - minx);
    dst[3] = MRKUI__maxf(0.0f, maxy - miny);
}

void MRKUIIntersectScissor(MRKUIcontext *ctx, float x, float y, float w, float h) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float pxform[6], invxorm[6];
    float rect[4];
    float ex, ey, tex, tey;

    // If no previous scissor has been set, set the scissor as current scissor.
    if (state->scissor.extent[0] < 0) {
        MRKUIScissor(ctx, x, y, w, h);
        return;
    }

    // Transform the current scissor rect into current transform space.
    // If there is difference in rotation, this will be approximation.
    memcpy(pxform, state->scissor.xform, sizeof(float) * 6);
    ex = state->scissor.extent[0];
    ey = state->scissor.extent[1];
    MRKUITransformInverse(invxorm, state->xform);
    MRKUITransformMultiply(pxform, invxorm);
    tex = ex * MRKUI__absf(pxform[0]) + ey * MRKUI__absf(pxform[2]);
    tey = ex * MRKUI__absf(pxform[1]) + ey * MRKUI__absf(pxform[3]);

    // Intersect rects.
    MRKUI__isectRects(rect, pxform[4] - tex, pxform[5] - tey, tex * 2, tey * 2, x, y, w, h);

    MRKUIScissor(ctx, rect[0], rect[1], rect[2], rect[3]);
}

void MRKUIResetScissor(MRKUIcontext *ctx) {
    MRKUIstate *state = MRKUI__getState(ctx);
    memset(state->scissor.xform, 0, sizeof(state->scissor.xform));
    state->scissor.extent[0] = -1.0f;
    state->scissor.extent[1] = -1.0f;
}

// Global composite operation.
void MRKUIGlobalCompositeOperation(MRKUIcontext *ctx, int op) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->compositeOperation = MRKUI__compositeOperationState(op);
}

void MRKUIGlobalCompositeBlendFunc(MRKUIcontext *ctx, int sfactor, int dfactor) {
    MRKUIGlobalCompositeBlendFuncSeparate(ctx, sfactor, dfactor, sfactor, dfactor);
}

void MRKUIGlobalCompositeBlendFuncSeparate(MRKUIcontext *ctx, int srcRGB, int dstRGB, int srcAlpha,
                                           int dstAlpha) {
    MRKUIcompositeOperationState op;
    op.srcRGB = srcRGB;
    op.dstRGB = dstRGB;
    op.srcAlpha = srcAlpha;
    op.dstAlpha = dstAlpha;

    MRKUIstate *state = MRKUI__getState(ctx);
    state->compositeOperation = op;
}

static int MRKUI__ptEquals(float x1, float y1, float x2, float y2, float tol) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return dx * dx + dy * dy < tol * tol;
}

static float MRKUI__distPtSeg(float x, float y, float px, float py, float qx, float qy) {
    float pqx, pqy, dx, dy, d, t;
    pqx = qx - px;
    pqy = qy - py;
    dx = x - px;
    dy = y - py;
    d = pqx * pqx + pqy * pqy;
    t = pqx * dx + pqy * dy;
    if (d > 0) t /= d;
    if (t < 0) t = 0;
    else if (t > 1) t = 1;
    dx = px + t * pqx - x;
    dy = py + t * pqy - y;
    return dx * dx + dy * dy;
}

static void MRKUI__appendCommands(MRKUIcontext *ctx, float *vals, int nvals) {
    MRKUIstate *state = MRKUI__getState(ctx);
    int i;

    if (ctx->ncommands + nvals > ctx->ccommands) {
        float *commands;
        int ccommands = ctx->ncommands + nvals + ctx->ccommands / 2;
        commands = (float *) realloc(ctx->commands, sizeof(float) * ccommands);
        if (commands == NULL) return;
        ctx->commands = commands;
        ctx->ccommands = ccommands;
    }

    if ((int) vals[0] != MRKUI_CLOSE && (int) vals[0] != MRKUI_WINDING) {
        ctx->commandx = vals[nvals - 2];
        ctx->commandy = vals[nvals - 1];
    }

    // transform commands
    i = 0;
    while (i < nvals) {
        int cmd = (int) vals[i];
        switch (cmd) {
            case MRKUI_MOVETO:
                MRKUITransformPoint(&vals[i + 1], &vals[i + 2], state->xform, vals[i + 1],
                                    vals[i + 2]);
                i += 3;
                break;
            case MRKUI_LINETO:
                MRKUITransformPoint(&vals[i + 1], &vals[i + 2], state->xform, vals[i + 1],
                                    vals[i + 2]);
                i += 3;
                break;
            case MRKUI_BEZIERTO:
                MRKUITransformPoint(&vals[i + 1], &vals[i + 2], state->xform, vals[i + 1],
                                    vals[i + 2]);
                MRKUITransformPoint(&vals[i + 3], &vals[i + 4], state->xform, vals[i + 3],
                                    vals[i + 4]);
                MRKUITransformPoint(&vals[i + 5], &vals[i + 6], state->xform, vals[i + 5],
                                    vals[i + 6]);
                i += 7;
                break;
            case MRKUI_CLOSE:
                i++;
                break;
            case MRKUI_WINDING:
                i += 2;
                break;
            default:
                i++;
        }
    }

    memcpy(&ctx->commands[ctx->ncommands], vals, nvals * sizeof(float));

    ctx->ncommands += nvals;
}


static void MRKUI__clearPathCache(MRKUIcontext *ctx) {
    ctx->cache->npoints = 0;
    ctx->cache->npaths = 0;
}

static MRKUIpath *MRKUI__lastPath(MRKUIcontext *ctx) {
    if (ctx->cache->npaths > 0)
        return &ctx->cache->paths[ctx->cache->npaths - 1];
    return NULL;
}

static void MRKUI__addPath(MRKUIcontext *ctx) {
    MRKUIpath *path;
    if (ctx->cache->npaths + 1 > ctx->cache->cpaths) {
        MRKUIpath *paths;
        int cpaths = ctx->cache->npaths + 1 + ctx->cache->cpaths / 2;
        paths = (MRKUIpath *) realloc(ctx->cache->paths, sizeof(MRKUIpath) * cpaths);
        if (paths == NULL) return;
        ctx->cache->paths = paths;
        ctx->cache->cpaths = cpaths;
    }
    path = &ctx->cache->paths[ctx->cache->npaths];
    memset(path, 0, sizeof(*path));
    path->first = ctx->cache->npoints;
    path->winding = MRKUI_CCW;

    ctx->cache->npaths++;
}

static MRKUIpoint *MRKUI__lastPoint(MRKUIcontext *ctx) {
    if (ctx->cache->npoints > 0)
        return &ctx->cache->points[ctx->cache->npoints - 1];
    return NULL;
}

static void MRKUI__addPoint(MRKUIcontext *ctx, float x, float y, int flags) {
    MRKUIpath *path = MRKUI__lastPath(ctx);
    MRKUIpoint *pt;
    if (path == NULL) return;

    if (path->count > 0 && ctx->cache->npoints > 0) {
        pt = MRKUI__lastPoint(ctx);
        if (MRKUI__ptEquals(pt->x, pt->y, x, y, ctx->distTol)) {
            pt->flags |= flags;
            return;
        }
    }

    if (ctx->cache->npoints + 1 > ctx->cache->cpoints) {
        MRKUIpoint *points;
        int cpoints = ctx->cache->npoints + 1 + ctx->cache->cpoints / 2;
        points = (MRKUIpoint *) realloc(ctx->cache->points, sizeof(MRKUIpoint) * cpoints);
        if (points == NULL) return;
        ctx->cache->points = points;
        ctx->cache->cpoints = cpoints;
    }

    pt = &ctx->cache->points[ctx->cache->npoints];
    memset(pt, 0, sizeof(*pt));
    pt->x = x;
    pt->y = y;
    pt->flags = (unsigned char) flags;

    ctx->cache->npoints++;
    path->count++;
}

static void MRKUI__closePath(MRKUIcontext *ctx) {
    MRKUIpath *path = MRKUI__lastPath(ctx);
    if (path == NULL) return;
    path->closed = 1;
}

static void MRKUI__pathWinding(MRKUIcontext *ctx, int winding) {
    MRKUIpath *path = MRKUI__lastPath(ctx);
    if (path == NULL) return;
    path->winding = winding;
}

static float MRKUI__getAverageScale(float *t) {
    float sx = sqrtf(t[0] * t[0] + t[2] * t[2]);
    float sy = sqrtf(t[1] * t[1] + t[3] * t[3]);
    return (sx + sy) * 0.5f;
}

static MRKUIvertex *MRKUI__allocTempVerts(MRKUIcontext *ctx, int nverts) {
    if (nverts > ctx->cache->cverts) {
        MRKUIvertex *verts;
        int cverts = (nverts + 0xff) &
                     ~0xff; // Round up to prevent allocations when things change just slightly.
        verts = (MRKUIvertex *) realloc(ctx->cache->verts, sizeof(MRKUIvertex) * cverts);
        if (verts == NULL) return NULL;
        ctx->cache->verts = verts;
        ctx->cache->cverts = cverts;
    }

    return ctx->cache->verts;
}

static float MRKUI__triarea2(float ax, float ay, float bx, float by, float cx, float cy) {
    float abx = bx - ax;
    float aby = by - ay;
    float acx = cx - ax;
    float acy = cy - ay;
    return acx * aby - abx * acy;
}

static float MRKUI__polyArea(MRKUIpoint *pts, int npts) {
    int i;
    float area = 0;
    for (i = 2; i < npts; i++) {
        MRKUIpoint *a = &pts[0];
        MRKUIpoint *b = &pts[i - 1];
        MRKUIpoint *c = &pts[i];
        area += MRKUI__triarea2(a->x, a->y, b->x, b->y, c->x, c->y);
    }
    return area * 0.5f;
}

static void MRKUI__polyReverse(MRKUIpoint *pts, int npts) {
    MRKUIpoint tmp;
    int i = 0, j = npts - 1;
    while (i < j) {
        tmp = pts[i];
        pts[i] = pts[j];
        pts[j] = tmp;
        i++;
        j--;
    }
}


static void MRKUI__vset(MRKUIvertex *vtx, float x, float y, float u, float v) {
    vtx->x = x;
    vtx->y = y;
    vtx->u = u;
    vtx->v = v;
}

static void MRKUI__tesselateBezier(MRKUIcontext *ctx,
                                   float x1, float y1, float x2, float y2,
                                   float x3, float y3, float x4, float y4,
                                   int level, int type) {
    float x12, y12, x23, y23, x34, y34, x123, y123, x234, y234, x1234, y1234;
    float dx, dy, d2, d3;

    if (level > 10) return;

    x12 = (x1 + x2) * 0.5f;
    y12 = (y1 + y2) * 0.5f;
    x23 = (x2 + x3) * 0.5f;
    y23 = (y2 + y3) * 0.5f;
    x34 = (x3 + x4) * 0.5f;
    y34 = (y3 + y4) * 0.5f;
    x123 = (x12 + x23) * 0.5f;
    y123 = (y12 + y23) * 0.5f;

    dx = x4 - x1;
    dy = y4 - y1;
    d2 = MRKUI__absf(((x2 - x4) * dy - (y2 - y4) * dx));
    d3 = MRKUI__absf(((x3 - x4) * dy - (y3 - y4) * dx));

    if ((d2 + d3) * (d2 + d3) < ctx->tessTol * (dx * dx + dy * dy)) {
        MRKUI__addPoint(ctx, x4, y4, type);
        return;
    }

/*	if (MRKUI__absf(x1+x3-x2-x2) + MRKUI__absf(y1+y3-y2-y2) + MRKUI__absf(x2+x4-x3-x3) + MRKUI__absf(y2+y4-y3-y3) < ctx->tessTol) {
		MRKUI__addPoint(ctx, x4, y4, type);
		return;
	}*/

    x234 = (x23 + x34) * 0.5f;
    y234 = (y23 + y34) * 0.5f;
    x1234 = (x123 + x234) * 0.5f;
    y1234 = (y123 + y234) * 0.5f;

    MRKUI__tesselateBezier(ctx, x1, y1, x12, y12, x123, y123, x1234, y1234, level + 1, 0);
    MRKUI__tesselateBezier(ctx, x1234, y1234, x234, y234, x34, y34, x4, y4, level + 1, type);
}

static void MRKUI__flattenPaths(MRKUIcontext *ctx) {
    MRKUIpathCache *cache = ctx->cache;
//	MRKUIstate* state = MRKUI__getState(ctx);
    MRKUIpoint *last;
    MRKUIpoint *p0;
    MRKUIpoint *p1;
    MRKUIpoint *pts;
    MRKUIpath *path;
    int i, j;
    float *cp1;
    float *cp2;
    float *p;
    float area;

    if (cache->npaths > 0)
        return;

    // Flatten
    i = 0;
    while (i < ctx->ncommands) {
        int cmd = (int) ctx->commands[i];
        switch (cmd) {
            case MRKUI_MOVETO:
                MRKUI__addPath(ctx);
                p = &ctx->commands[i + 1];
                MRKUI__addPoint(ctx, p[0], p[1], MRKUI_PT_CORNER);
                i += 3;
                break;
            case MRKUI_LINETO:
                p = &ctx->commands[i + 1];
                MRKUI__addPoint(ctx, p[0], p[1], MRKUI_PT_CORNER);
                i += 3;
                break;
            case MRKUI_BEZIERTO:
                last = MRKUI__lastPoint(ctx);
                if (last != NULL) {
                    cp1 = &ctx->commands[i + 1];
                    cp2 = &ctx->commands[i + 3];
                    p = &ctx->commands[i + 5];
                    MRKUI__tesselateBezier(ctx, last->x, last->y, cp1[0], cp1[1], cp2[0], cp2[1],
                                           p[0], p[1], 0, MRKUI_PT_CORNER);
                }
                i += 7;
                break;
            case MRKUI_CLOSE:
                MRKUI__closePath(ctx);
                i++;
                break;
            case MRKUI_WINDING:
                MRKUI__pathWinding(ctx, (int) ctx->commands[i + 1]);
                i += 2;
                break;
            default:
                i++;
        }
    }

    cache->bounds[0] = cache->bounds[1] = 1e6f;
    cache->bounds[2] = cache->bounds[3] = -1e6f;

    // Calculate the direction and length of line segments.
    for (j = 0; j < cache->npaths; j++) {
        path = &cache->paths[j];
        pts = &cache->points[path->first];

        // If the first and last points are the same, remove the last, mark as closed path.
        p0 = &pts[path->count - 1];
        p1 = &pts[0];
        if (MRKUI__ptEquals(p0->x, p0->y, p1->x, p1->y, ctx->distTol)) {
            path->count--;
            p0 = &pts[path->count - 1];
            path->closed = 1;
        }

        // Enforce winding.
        if (path->count > 2) {
            area = MRKUI__polyArea(pts, path->count);
            if (path->winding == MRKUI_CCW && area < 0.0f)
                MRKUI__polyReverse(pts, path->count);
            if (path->winding == MRKUI_CW && area > 0.0f)
                MRKUI__polyReverse(pts, path->count);
        }

        for (i = 0; i < path->count; i++) {
            // Calculate segment direction and length
            p0->dx = p1->x - p0->x;
            p0->dy = p1->y - p0->y;
            p0->len = MRKUI__normalize(&p0->dx, &p0->dy);
            // Update bounds
            cache->bounds[0] = MRKUI__minf(cache->bounds[0], p0->x);
            cache->bounds[1] = MRKUI__minf(cache->bounds[1], p0->y);
            cache->bounds[2] = MRKUI__maxf(cache->bounds[2], p0->x);
            cache->bounds[3] = MRKUI__maxf(cache->bounds[3], p0->y);
            // Advance
            p0 = p1++;
        }
    }
}

static int MRKUI__curveDivs(float r, float arc, float tol) {
    float da = acosf(r / (r + tol)) * 2.0f;
    return MRKUI__maxi(2, (int) ceilf(arc / da));
}

static void MRKUI__chooseBevel(int bevel, MRKUIpoint *p0, MRKUIpoint *p1, float w,
                               float *x0, float *y0, float *x1, float *y1) {
    if (bevel) {
        *x0 = p1->x + p0->dy * w;
        *y0 = p1->y - p0->dx * w;
        *x1 = p1->x + p1->dy * w;
        *y1 = p1->y - p1->dx * w;
    } else {
        *x0 = p1->x + p1->dmx * w;
        *y0 = p1->y + p1->dmy * w;
        *x1 = p1->x + p1->dmx * w;
        *y1 = p1->y + p1->dmy * w;
    }
}

static MRKUIvertex *MRKUI__roundJoin(MRKUIvertex *dst, MRKUIpoint *p0, MRKUIpoint *p1,
                                     float lw, float rw, float lu, float ru, int ncap,
                                     float fringe) {
    int i, n;
    float dlx0 = p0->dy;
    float dly0 = -p0->dx;
    float dlx1 = p1->dy;
    float dly1 = -p1->dx;
    MRKUI_NOTUSED(fringe);

    if (p1->flags & MRKUI_PT_LEFT) {
        float lx0, ly0, lx1, ly1, a0, a1;
        MRKUI__chooseBevel(p1->flags & MRKUI_PR_INNERBEVEL, p0, p1, lw, &lx0, &ly0, &lx1, &ly1);
        a0 = atan2f(-dly0, -dlx0);
        a1 = atan2f(-dly1, -dlx1);
        if (a1 > a0) a1 -= MRKUI_PI * 2;

        MRKUI__vset(dst, lx0, ly0, lu, 1);
        dst++;
        MRKUI__vset(dst, p1->x - dlx0 * rw, p1->y - dly0 * rw, ru, 1);
        dst++;

        n = MRKUI__clampi((int) ceilf(((a0 - a1) / MRKUI_PI) * ncap), 2, ncap);
        for (i = 0; i < n; i++) {
            float u = i / (float) (n - 1);
            float a = a0 + u * (a1 - a0);
            float rx = p1->x + cosf(a) * rw;
            float ry = p1->y + sinf(a) * rw;
            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;
            MRKUI__vset(dst, rx, ry, ru, 1);
            dst++;
        }

        MRKUI__vset(dst, lx1, ly1, lu, 1);
        dst++;
        MRKUI__vset(dst, p1->x - dlx1 * rw, p1->y - dly1 * rw, ru, 1);
        dst++;

    } else {
        float rx0, ry0, rx1, ry1, a0, a1;
        MRKUI__chooseBevel(p1->flags & MRKUI_PR_INNERBEVEL, p0, p1, -rw, &rx0, &ry0, &rx1, &ry1);
        a0 = atan2f(dly0, dlx0);
        a1 = atan2f(dly1, dlx1);
        if (a1 < a0) a1 += MRKUI_PI * 2;

        MRKUI__vset(dst, p1->x + dlx0 * rw, p1->y + dly0 * rw, lu, 1);
        dst++;
        MRKUI__vset(dst, rx0, ry0, ru, 1);
        dst++;

        n = MRKUI__clampi((int) ceilf(((a1 - a0) / MRKUI_PI) * ncap), 2, ncap);
        for (i = 0; i < n; i++) {
            float u = i / (float) (n - 1);
            float a = a0 + u * (a1 - a0);
            float lx = p1->x + cosf(a) * lw;
            float ly = p1->y + sinf(a) * lw;
            MRKUI__vset(dst, lx, ly, lu, 1);
            dst++;
            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;
        }

        MRKUI__vset(dst, p1->x + dlx1 * rw, p1->y + dly1 * rw, lu, 1);
        dst++;
        MRKUI__vset(dst, rx1, ry1, ru, 1);
        dst++;

    }
    return dst;
}

static MRKUIvertex *MRKUI__bevelJoin(MRKUIvertex *dst, MRKUIpoint *p0, MRKUIpoint *p1,
                                     float lw, float rw, float lu, float ru, float fringe) {
    float rx0, ry0, rx1, ry1;
    float lx0, ly0, lx1, ly1;
    float dlx0 = p0->dy;
    float dly0 = -p0->dx;
    float dlx1 = p1->dy;
    float dly1 = -p1->dx;
    MRKUI_NOTUSED(fringe);

    if (p1->flags & MRKUI_PT_LEFT) {
        MRKUI__chooseBevel(p1->flags & MRKUI_PR_INNERBEVEL, p0, p1, lw, &lx0, &ly0, &lx1, &ly1);

        MRKUI__vset(dst, lx0, ly0, lu, 1);
        dst++;
        MRKUI__vset(dst, p1->x - dlx0 * rw, p1->y - dly0 * rw, ru, 1);
        dst++;

        if (p1->flags & MRKUI_PT_BEVEL) {
            MRKUI__vset(dst, lx0, ly0, lu, 1);
            dst++;
            MRKUI__vset(dst, p1->x - dlx0 * rw, p1->y - dly0 * rw, ru, 1);
            dst++;

            MRKUI__vset(dst, lx1, ly1, lu, 1);
            dst++;
            MRKUI__vset(dst, p1->x - dlx1 * rw, p1->y - dly1 * rw, ru, 1);
            dst++;
        } else {
            rx0 = p1->x - p1->dmx * rw;
            ry0 = p1->y - p1->dmy * rw;

            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;
            MRKUI__vset(dst, p1->x - dlx0 * rw, p1->y - dly0 * rw, ru, 1);
            dst++;

            MRKUI__vset(dst, rx0, ry0, ru, 1);
            dst++;
            MRKUI__vset(dst, rx0, ry0, ru, 1);
            dst++;

            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;
            MRKUI__vset(dst, p1->x - dlx1 * rw, p1->y - dly1 * rw, ru, 1);
            dst++;
        }

        MRKUI__vset(dst, lx1, ly1, lu, 1);
        dst++;
        MRKUI__vset(dst, p1->x - dlx1 * rw, p1->y - dly1 * rw, ru, 1);
        dst++;

    } else {
        MRKUI__chooseBevel(p1->flags & MRKUI_PR_INNERBEVEL, p0, p1, -rw, &rx0, &ry0, &rx1, &ry1);

        MRKUI__vset(dst, p1->x + dlx0 * lw, p1->y + dly0 * lw, lu, 1);
        dst++;
        MRKUI__vset(dst, rx0, ry0, ru, 1);
        dst++;

        if (p1->flags & MRKUI_PT_BEVEL) {
            MRKUI__vset(dst, p1->x + dlx0 * lw, p1->y + dly0 * lw, lu, 1);
            dst++;
            MRKUI__vset(dst, rx0, ry0, ru, 1);
            dst++;

            MRKUI__vset(dst, p1->x + dlx1 * lw, p1->y + dly1 * lw, lu, 1);
            dst++;
            MRKUI__vset(dst, rx1, ry1, ru, 1);
            dst++;
        } else {
            lx0 = p1->x + p1->dmx * lw;
            ly0 = p1->y + p1->dmy * lw;

            MRKUI__vset(dst, p1->x + dlx0 * lw, p1->y + dly0 * lw, lu, 1);
            dst++;
            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;

            MRKUI__vset(dst, lx0, ly0, lu, 1);
            dst++;
            MRKUI__vset(dst, lx0, ly0, lu, 1);
            dst++;

            MRKUI__vset(dst, p1->x + dlx1 * lw, p1->y + dly1 * lw, lu, 1);
            dst++;
            MRKUI__vset(dst, p1->x, p1->y, 0.5f, 1);
            dst++;
        }

        MRKUI__vset(dst, p1->x + dlx1 * lw, p1->y + dly1 * lw, lu, 1);
        dst++;
        MRKUI__vset(dst, rx1, ry1, ru, 1);
        dst++;
    }

    return dst;
}

static MRKUIvertex *MRKUI__buttCapStart(MRKUIvertex *dst, MRKUIpoint *p,
                                        float dx, float dy, float w, float d,
                                        float aa, float u0, float u1) {
    float px = p->x - dx * d;
    float py = p->y - dy * d;
    float dlx = dy;
    float dly = -dx;
    MRKUI__vset(dst, px + dlx * w - dx * aa, py + dly * w - dy * aa, u0, 0);
    dst++;
    MRKUI__vset(dst, px - dlx * w - dx * aa, py - dly * w - dy * aa, u1, 0);
    dst++;
    MRKUI__vset(dst, px + dlx * w, py + dly * w, u0, 1);
    dst++;
    MRKUI__vset(dst, px - dlx * w, py - dly * w, u1, 1);
    dst++;
    return dst;
}

static MRKUIvertex *MRKUI__buttCapEnd(MRKUIvertex *dst, MRKUIpoint *p,
                                      float dx, float dy, float w, float d,
                                      float aa, float u0, float u1) {
    float px = p->x + dx * d;
    float py = p->y + dy * d;
    float dlx = dy;
    float dly = -dx;
    MRKUI__vset(dst, px + dlx * w, py + dly * w, u0, 1);
    dst++;
    MRKUI__vset(dst, px - dlx * w, py - dly * w, u1, 1);
    dst++;
    MRKUI__vset(dst, px + dlx * w + dx * aa, py + dly * w + dy * aa, u0, 0);
    dst++;
    MRKUI__vset(dst, px - dlx * w + dx * aa, py - dly * w + dy * aa, u1, 0);
    dst++;
    return dst;
}


static MRKUIvertex *MRKUI__roundCapStart(MRKUIvertex *dst, MRKUIpoint *p,
                                         float dx, float dy, float w, int ncap,
                                         float aa, float u0, float u1) {
    int i;
    float px = p->x;
    float py = p->y;
    float dlx = dy;
    float dly = -dx;
    MRKUI_NOTUSED(aa);
    for (i = 0; i < ncap; i++) {
        float a = i / (float) (ncap - 1) * MRKUI_PI;
        float ax = cosf(a) * w, ay = sinf(a) * w;
        MRKUI__vset(dst, px - dlx * ax - dx * ay, py - dly * ax - dy * ay, u0, 1);
        dst++;
        MRKUI__vset(dst, px, py, 0.5f, 1);
        dst++;
    }
    MRKUI__vset(dst, px + dlx * w, py + dly * w, u0, 1);
    dst++;
    MRKUI__vset(dst, px - dlx * w, py - dly * w, u1, 1);
    dst++;
    return dst;
}

static MRKUIvertex *MRKUI__roundCapEnd(MRKUIvertex *dst, MRKUIpoint *p,
                                       float dx, float dy, float w, int ncap,
                                       float aa, float u0, float u1) {
    int i;
    float px = p->x;
    float py = p->y;
    float dlx = dy;
    float dly = -dx;
    MRKUI_NOTUSED(aa);
    MRKUI__vset(dst, px + dlx * w, py + dly * w, u0, 1);
    dst++;
    MRKUI__vset(dst, px - dlx * w, py - dly * w, u1, 1);
    dst++;
    for (i = 0; i < ncap; i++) {
        float a = i / (float) (ncap - 1) * MRKUI_PI;
        float ax = cosf(a) * w, ay = sinf(a) * w;
        MRKUI__vset(dst, px, py, 0.5f, 1);
        dst++;
        MRKUI__vset(dst, px - dlx * ax + dx * ay, py - dly * ax + dy * ay, u0, 1);
        dst++;
    }
    return dst;
}


static void MRKUI__calculateJoins(MRKUIcontext *ctx, float w, int lineJoin, float miterLimit) {
    MRKUIpathCache *cache = ctx->cache;
    int i, j;
    float iw = 0.0f;

    if (w > 0.0f) iw = 1.0f / w;

    // Calculate which joins needs extra vertices to append, and gather vertex count.
    for (i = 0; i < cache->npaths; i++) {
        MRKUIpath *path = &cache->paths[i];
        MRKUIpoint *pts = &cache->points[path->first];
        MRKUIpoint *p0 = &pts[path->count - 1];
        MRKUIpoint *p1 = &pts[0];
        int nleft = 0;

        path->nbevel = 0;

        for (j = 0; j < path->count; j++) {
            float dlx0, dly0, dlx1, dly1, dmr2, cross, limit;
            dlx0 = p0->dy;
            dly0 = -p0->dx;
            dlx1 = p1->dy;
            dly1 = -p1->dx;
            // Calculate extrusions
            p1->dmx = (dlx0 + dlx1) * 0.5f;
            p1->dmy = (dly0 + dly1) * 0.5f;
            dmr2 = p1->dmx * p1->dmx + p1->dmy * p1->dmy;
            if (dmr2 > 0.000001f) {
                float scale = 1.0f / dmr2;
                if (scale > 600.0f) {
                    scale = 600.0f;
                }
                p1->dmx *= scale;
                p1->dmy *= scale;
            }

            // Clear flags, but keep the corner.
            p1->flags = (p1->flags & MRKUI_PT_CORNER) ? MRKUI_PT_CORNER : 0;

            // Keep track of left turns.
            cross = p1->dx * p0->dy - p0->dx * p1->dy;
            if (cross > 0.0f) {
                nleft++;
                p1->flags |= MRKUI_PT_LEFT;
            }

            // Calculate if we should use bevel or miter for inner join.
            limit = MRKUI__maxf(1.01f, MRKUI__minf(p0->len, p1->len) * iw);
            if ((dmr2 * limit * limit) < 1.0f)
                p1->flags |= MRKUI_PR_INNERBEVEL;

            // Check to see if the corner needs to be beveled.
            if (p1->flags & MRKUI_PT_CORNER) {
                if ((dmr2 * miterLimit * miterLimit) < 1.0f || lineJoin == MRKUI_BEVEL ||
                    lineJoin == MRKUI_ROUND) {
                    p1->flags |= MRKUI_PT_BEVEL;
                }
            }

            if ((p1->flags & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0)
                path->nbevel++;

            p0 = p1++;
        }

        path->convex = (nleft == path->count) ? 1 : 0;
    }
}


static int MRKUI__expandStroke(MRKUIcontext *ctx, float w, float fringe, int lineCap, int lineJoin,
                               float miterLimit) {
    MRKUIpathCache *cache = ctx->cache;
    MRKUIvertex *verts;
    MRKUIvertex *dst;
    int cverts, i, j;
    float aa = fringe;//ctx->fringeWidth;
    float u0 = 0.0f, u1 = 1.0f;
    int ncap = MRKUI__curveDivs(w, MRKUI_PI,
                                ctx->tessTol);    // Calculate divisions per half circle.

    w += aa * 0.5f;

    // Disable the gradient used for antialiasing when antialiasing is not used.
    if (aa == 0.0f) {
        u0 = 0.5f;
        u1 = 0.5f;
    }

    MRKUI__calculateJoins(ctx, w, lineJoin, miterLimit);

    // Calculate max vertex usage.
    cverts = 0;
    for (i = 0; i < cache->npaths; i++) {
        MRKUIpath *path = &cache->paths[i];
        int loop = (path->closed == 0) ? 0 : 1;
        if (lineJoin == MRKUI_ROUND)
            cverts += (path->count + path->nbevel * (ncap + 2) + 1) * 2; // plus one for loop
        else
            cverts += (path->count + path->nbevel * 5 + 1) * 2; // plus one for loop
        if (loop == 0) {
            // space for caps
            if (lineCap == MRKUI_ROUND) {
                cverts += (ncap * 2 + 2) * 2;
            } else {
                cverts += (3 + 3) * 2;
            }
        }
    }

    verts = MRKUI__allocTempVerts(ctx, cverts);
    if (verts == NULL) return 0;

    for (i = 0; i < cache->npaths; i++) {
        MRKUIpath *path = &cache->paths[i];
        MRKUIpoint *pts = &cache->points[path->first];
        MRKUIpoint *p0;
        MRKUIpoint *p1;
        int s, e, loop;
        float dx, dy;

        path->fill = 0;
        path->nfill = 0;

        // Calculate fringe or stroke
        loop = (path->closed == 0) ? 0 : 1;
        dst = verts;
        path->stroke = dst;

        if (loop) {
            // Looping
            p0 = &pts[path->count - 1];
            p1 = &pts[0];
            s = 0;
            e = path->count;
        } else {
            // Add cap
            p0 = &pts[0];
            p1 = &pts[1];
            s = 1;
            e = path->count - 1;
        }

        if (loop == 0) {
            // Add cap
            dx = p1->x - p0->x;
            dy = p1->y - p0->y;
            MRKUI__normalize(&dx, &dy);
            if (lineCap == MRKUI_BUTT)
                dst = MRKUI__buttCapStart(dst, p0, dx, dy, w, -aa * 0.5f, aa, u0, u1);
            else if (lineCap == MRKUI_BUTT || lineCap == MRKUI_SQUARE)
                dst = MRKUI__buttCapStart(dst, p0, dx, dy, w, w - aa, aa, u0, u1);
            else if (lineCap == MRKUI_ROUND)
                dst = MRKUI__roundCapStart(dst, p0, dx, dy, w, ncap, aa, u0, u1);
        }

        for (j = s; j < e; ++j) {
            if ((p1->flags & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0) {
                if (lineJoin == MRKUI_ROUND) {
                    dst = MRKUI__roundJoin(dst, p0, p1, w, w, u0, u1, ncap, aa);
                } else {
                    dst = MRKUI__bevelJoin(dst, p0, p1, w, w, u0, u1, aa);
                }
            } else {
                MRKUI__vset(dst, p1->x + (p1->dmx * w), p1->y + (p1->dmy * w), u0, 1);
                dst++;
                MRKUI__vset(dst, p1->x - (p1->dmx * w), p1->y - (p1->dmy * w), u1, 1);
                dst++;
            }
            p0 = p1++;
        }

        if (loop) {
            // Loop it
            MRKUI__vset(dst, verts[0].x, verts[0].y, u0, 1);
            dst++;
            MRKUI__vset(dst, verts[1].x, verts[1].y, u1, 1);
            dst++;
        } else {
            // Add cap
            dx = p1->x - p0->x;
            dy = p1->y - p0->y;
            MRKUI__normalize(&dx, &dy);
            if (lineCap == MRKUI_BUTT)
                dst = MRKUI__buttCapEnd(dst, p1, dx, dy, w, -aa * 0.5f, aa, u0, u1);
            else if (lineCap == MRKUI_BUTT || lineCap == MRKUI_SQUARE)
                dst = MRKUI__buttCapEnd(dst, p1, dx, dy, w, w - aa, aa, u0, u1);
            else if (lineCap == MRKUI_ROUND)
                dst = MRKUI__roundCapEnd(dst, p1, dx, dy, w, ncap, aa, u0, u1);
        }

        path->nstroke = (int) (dst - verts);

        verts = dst;
    }

    return 1;
}

static int MRKUI__expandFill(MRKUIcontext *ctx, float w, int lineJoin, float miterLimit) {
    MRKUIpathCache *cache = ctx->cache;
    MRKUIvertex *verts;
    MRKUIvertex *dst;
    int cverts, convex, i, j;
    float aa = ctx->fringeWidth;
    int fringe = w > 0.0f;

    MRKUI__calculateJoins(ctx, w, lineJoin, miterLimit);

    // Calculate max vertex usage.
    cverts = 0;
    for (i = 0; i < cache->npaths; i++) {
        MRKUIpath *path = &cache->paths[i];
        cverts += path->count + path->nbevel + 1;
        if (fringe)
            cverts += (path->count + path->nbevel * 5 + 1) * 2; // plus one for loop
    }

    verts = MRKUI__allocTempVerts(ctx, cverts);
    if (verts == NULL) return 0;

    convex = cache->npaths == 1 && cache->paths[0].convex;

    for (i = 0; i < cache->npaths; i++) {
        MRKUIpath *path = &cache->paths[i];
        MRKUIpoint *pts = &cache->points[path->first];
        MRKUIpoint *p0;
        MRKUIpoint *p1;
        float rw, lw, woff;
        float ru, lu;

        // Calculate shape vertices.
        woff = 0.5f * aa;
        dst = verts;
        path->fill = dst;

        if (fringe) {
            // Looping
            p0 = &pts[path->count - 1];
            p1 = &pts[0];
            for (j = 0; j < path->count; ++j) {
                if (p1->flags & MRKUI_PT_BEVEL) {
                    float dlx0 = p0->dy;
                    float dly0 = -p0->dx;
                    float dlx1 = p1->dy;
                    float dly1 = -p1->dx;
                    if (p1->flags & MRKUI_PT_LEFT) {
                        float lx = p1->x + p1->dmx * woff;
                        float ly = p1->y + p1->dmy * woff;
                        MRKUI__vset(dst, lx, ly, 0.5f, 1);
                        dst++;
                    } else {
                        float lx0 = p1->x + dlx0 * woff;
                        float ly0 = p1->y + dly0 * woff;
                        float lx1 = p1->x + dlx1 * woff;
                        float ly1 = p1->y + dly1 * woff;
                        MRKUI__vset(dst, lx0, ly0, 0.5f, 1);
                        dst++;
                        MRKUI__vset(dst, lx1, ly1, 0.5f, 1);
                        dst++;
                    }
                } else {
                    MRKUI__vset(dst, p1->x + (p1->dmx * woff), p1->y + (p1->dmy * woff), 0.5f, 1);
                    dst++;
                }
                p0 = p1++;
            }
        } else {
            for (j = 0; j < path->count; ++j) {
                MRKUI__vset(dst, pts[j].x, pts[j].y, 0.5f, 1);
                dst++;
            }
        }

        path->nfill = (int) (dst - verts);
        verts = dst;

        // Calculate fringe
        if (fringe) {
            lw = w + woff;
            rw = w - woff;
            lu = 0;
            ru = 1;
            dst = verts;
            path->stroke = dst;

            // Create only half a fringe for convex shapes so that
            // the shape can be rendered without stenciling.
            if (convex) {
                lw = woff;    // This should generate the same vertex as fill inset above.
                lu = 0.5f;    // Set outline fade at middle.
            }

            // Looping
            p0 = &pts[path->count - 1];
            p1 = &pts[0];

            for (j = 0; j < path->count; ++j) {
                if ((p1->flags & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0) {
                    dst = MRKUI__bevelJoin(dst, p0, p1, lw, rw, lu, ru, ctx->fringeWidth);
                } else {
                    MRKUI__vset(dst, p1->x + (p1->dmx * lw), p1->y + (p1->dmy * lw), lu, 1);
                    dst++;
                    MRKUI__vset(dst, p1->x - (p1->dmx * rw), p1->y - (p1->dmy * rw), ru, 1);
                    dst++;
                }
                p0 = p1++;
            }

            // Loop it
            MRKUI__vset(dst, verts[0].x, verts[0].y, lu, 1);
            dst++;
            MRKUI__vset(dst, verts[1].x, verts[1].y, ru, 1);
            dst++;

            path->nstroke = (int) (dst - verts);
            verts = dst;
        } else {
            path->stroke = NULL;
            path->nstroke = 0;
        }
    }

    return 1;
}


// Draw
void MRKUIBeginPath(MRKUIcontext *ctx) {
    ctx->ncommands = 0;
    MRKUI__clearPathCache(ctx);
}

void MRKUIMoveTo(MRKUIcontext *ctx, float x, float y) {
    float vals[] = {MRKUI_MOVETO, x, y};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUILineTo(MRKUIcontext *ctx, float x, float y) {
    float vals[] = {MRKUI_LINETO, x, y};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void
MRKUIBezierTo(MRKUIcontext *ctx, float c1x, float c1y, float c2x, float c2y, float x, float y) {
    float vals[] = {MRKUI_BEZIERTO, c1x, c1y, c2x, c2y, x, y};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUIQuadTo(MRKUIcontext *ctx, float cx, float cy, float x, float y) {
    float x0 = ctx->commandx;
    float y0 = ctx->commandy;
    float vals[] = {MRKUI_BEZIERTO,
                    x0 + 2.0f / 3.0f * (cx - x0), y0 + 2.0f / 3.0f * (cy - y0),
                    x + 2.0f / 3.0f * (cx - x), y + 2.0f / 3.0f * (cy - y),
                    x, y};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUIArcTo(MRKUIcontext *ctx, float x1, float y1, float x2, float y2, float radius) {
    float x0 = ctx->commandx;
    float y0 = ctx->commandy;
    float dx0, dy0, dx1, dy1, a, d, cx, cy, a0, a1;
    int dir;

    if (ctx->ncommands == 0) {
        return;
    }

    // Handle degenerate cases.
    if (MRKUI__ptEquals(x0, y0, x1, y1, ctx->distTol) ||
        MRKUI__ptEquals(x1, y1, x2, y2, ctx->distTol) ||
        MRKUI__distPtSeg(x1, y1, x0, y0, x2, y2) < ctx->distTol * ctx->distTol ||
        radius < ctx->distTol) {
        MRKUILineTo(ctx, x1, y1);
        return;
    }

    // Calculate tangential circle to lines (x0,y0)-(x1,y1) and (x1,y1)-(x2,y2).
    dx0 = x0 - x1;
    dy0 = y0 - y1;
    dx1 = x2 - x1;
    dy1 = y2 - y1;
    MRKUI__normalize(&dx0, &dy0);
    MRKUI__normalize(&dx1, &dy1);
    a = MRKUI__acosf(dx0 * dx1 + dy0 * dy1);
    d = radius / MRKUI__tanf(a / 2.0f);

//	printf("a=%f° d=%f\n", a/MRKUI_PI*180.0f, d);

    if (d > 10000.0f) {
        MRKUILineTo(ctx, x1, y1);
        return;
    }

    if (MRKUI__cross(dx0, dy0, dx1, dy1) > 0.0f) {
        cx = x1 + dx0 * d + dy0 * radius;
        cy = y1 + dy0 * d + -dx0 * radius;
        a0 = MRKUI__atan2f(dx0, -dy0);
        a1 = MRKUI__atan2f(-dx1, dy1);
        dir = MRKUI_CW;
//		printf("CW c=(%f, %f) a0=%f° a1=%f°\n", cx, cy, a0/MRKUI_PI*180.0f, a1/MRKUI_PI*180.0f);
    } else {
        cx = x1 + dx0 * d + -dy0 * radius;
        cy = y1 + dy0 * d + dx0 * radius;
        a0 = MRKUI__atan2f(-dx0, dy0);
        a1 = MRKUI__atan2f(dx1, -dy1);
        dir = MRKUI_CCW;
//		printf("CCW c=(%f, %f) a0=%f° a1=%f°\n", cx, cy, a0/MRKUI_PI*180.0f, a1/MRKUI_PI*180.0f);
    }

    MRKUIArc(ctx, cx, cy, radius, a0, a1, dir);
}

void MRKUIClosePath(MRKUIcontext *ctx) {
    float vals[] = {MRKUI_CLOSE};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUIPathWinding(MRKUIcontext *ctx, int dir) {
    float vals[] = {MRKUI_WINDING, (float) dir};
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUIArc(MRKUIcontext *ctx, float cx, float cy, float r, float a0, float a1, int dir) {
    float a = 0, da = 0, hda = 0, kappa = 0;
    float dx = 0, dy = 0, x = 0, y = 0, tanx = 0, tany = 0;
    float px = 0, py = 0, ptanx = 0, ptany = 0;
    float vals[3 + 5 * 7 + 100];
    int i, ndivs, nvals;
    int move = ctx->ncommands > 0 ? MRKUI_LINETO : MRKUI_MOVETO;

    // Clamp angles
    da = a1 - a0;
    if (dir == MRKUI_CW) {
        if (MRKUI__absf(da) >= MRKUI_PI * 2) {
            da = MRKUI_PI * 2;
        } else {
            while (da < 0.0f) da += MRKUI_PI * 2;
        }
    } else {
        if (MRKUI__absf(da) >= MRKUI_PI * 2) {
            da = -MRKUI_PI * 2;
        } else {
            while (da > 0.0f) da -= MRKUI_PI * 2;
        }
    }

    // Split arc into max 90 degree segments.
    ndivs = MRKUI__maxi(1, MRKUI__mini((int) (MRKUI__absf(da) / (MRKUI_PI * 0.5f) + 0.5f), 5));
    hda = (da / (float) ndivs) / 2.0f;
    kappa = MRKUI__absf(4.0f / 3.0f * (1.0f - MRKUI__cosf(hda)) / MRKUI__sinf(hda));

    if (dir == MRKUI_CCW)
        kappa = -kappa;

    nvals = 0;
    for (i = 0; i <= ndivs; i++) {
        a = a0 + da * (i / (float) ndivs);
        dx = MRKUI__cosf(a);
        dy = MRKUI__sinf(a);
        x = cx + dx * r;
        y = cy + dy * r;
        tanx = -dy * r * kappa;
        tany = dx * r * kappa;

        if (i == 0) {
            vals[nvals++] = (float) move;
            vals[nvals++] = x;
            vals[nvals++] = y;
        } else {
            vals[nvals++] = MRKUI_BEZIERTO;
            vals[nvals++] = px + ptanx;
            vals[nvals++] = py + ptany;
            vals[nvals++] = x - tanx;
            vals[nvals++] = y - tany;
            vals[nvals++] = x;
            vals[nvals++] = y;
        }
        px = x;
        py = y;
        ptanx = tanx;
        ptany = tany;
    }

    MRKUI__appendCommands(ctx, vals, nvals);
}

void MRKUIRect(MRKUIcontext *ctx, float x, float y, float w, float h) {
    float vals[] = {
            MRKUI_MOVETO, x, y,
            MRKUI_LINETO, x, y + h,
            MRKUI_LINETO, x + w, y + h,
            MRKUI_LINETO, x + w, y,
            MRKUI_CLOSE
    };
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUIRoundedRect(MRKUIcontext *ctx, float x, float y, float w, float h, float r) {
    MRKUIRoundedRectVarying(ctx, x, y, w, h, r, r, r, r);
}

void
MRKUIRoundedRectVarying(MRKUIcontext *ctx, float x, float y, float w, float h, float radTopLeft,
                        float radTopRight, float radBottomRight, float radBottomLeft) {
    if (radTopLeft < 0.1f && radTopRight < 0.1f && radBottomRight < 0.1f && radBottomLeft < 0.1f) {
        MRKUIRect(ctx, x, y, w, h);
        return;
    } else {
        float halfw = MRKUI__absf(w) * 0.5f;
        float halfh = MRKUI__absf(h) * 0.5f;
        float rxBL = MRKUI__minf(radBottomLeft, halfw) * MRKUI__signf(w), ryBL =
                MRKUI__minf(radBottomLeft, halfh) * MRKUI__signf(h);
        float rxBR = MRKUI__minf(radBottomRight, halfw) * MRKUI__signf(w), ryBR =
                MRKUI__minf(radBottomRight, halfh) * MRKUI__signf(h);
        float rxTR = MRKUI__minf(radTopRight, halfw) * MRKUI__signf(w), ryTR =
                MRKUI__minf(radTopRight, halfh) * MRKUI__signf(h);
        float rxTL = MRKUI__minf(radTopLeft, halfw) * MRKUI__signf(w), ryTL =
                MRKUI__minf(radTopLeft, halfh) * MRKUI__signf(h);
        float vals[] = {
                MRKUI_MOVETO, x, y + ryTL,
                MRKUI_LINETO, x, y + h - ryBL,
                MRKUI_BEZIERTO, x, y + h - ryBL * (1 - MRKUI_KAPPA90),
                x + rxBL * (1 - MRKUI_KAPPA90), y + h, x + rxBL, y + h,
                MRKUI_LINETO, x + w - rxBR, y + h,
                MRKUI_BEZIERTO, x + w - rxBR * (1 - MRKUI_KAPPA90), y + h, x + w,
                y + h - ryBR * (1 - MRKUI_KAPPA90), x + w, y + h - ryBR,
                MRKUI_LINETO, x + w, y + ryTR,
                MRKUI_BEZIERTO, x + w, y + ryTR * (1 - MRKUI_KAPPA90),
                x + w - rxTR * (1 - MRKUI_KAPPA90), y, x + w - rxTR, y,
                MRKUI_LINETO, x + rxTL, y,
                MRKUI_BEZIERTO, x + rxTL * (1 - MRKUI_KAPPA90), y, x,
                y + ryTL * (1 - MRKUI_KAPPA90), x, y + ryTL,
                MRKUI_CLOSE
        };
        MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
    }
}

void MRKUIEllipse(MRKUIcontext *ctx, float cx, float cy, float rx, float ry) {
    float vals[] = {
            MRKUI_MOVETO, cx - rx, cy,
            MRKUI_BEZIERTO, cx - rx, cy + ry * MRKUI_KAPPA90, cx - rx * MRKUI_KAPPA90, cy + ry, cx,
            cy + ry,
            MRKUI_BEZIERTO, cx + rx * MRKUI_KAPPA90, cy + ry, cx + rx, cy + ry * MRKUI_KAPPA90,
            cx + rx, cy,
            MRKUI_BEZIERTO, cx + rx, cy - ry * MRKUI_KAPPA90, cx + rx * MRKUI_KAPPA90, cy - ry, cx,
            cy - ry,
            MRKUI_BEZIERTO, cx - rx * MRKUI_KAPPA90, cy - ry, cx - rx, cy - ry * MRKUI_KAPPA90,
            cx - rx, cy,
            MRKUI_CLOSE
    };
    MRKUI__appendCommands(ctx, vals, MRKUI_COUNTOF(vals));
}

void MRKUICircle(MRKUIcontext *ctx, float cx, float cy, float r) {
    MRKUIEllipse(ctx, cx, cy, r, r);
}

void MRKUIDebugDumpPathCache(MRKUIcontext *ctx) {
    const MRKUIpath *path;
    int i, j;

    printf("Dumping %d cached paths\n", ctx->cache->npaths);
    for (i = 0; i < ctx->cache->npaths; i++) {
        path = &ctx->cache->paths[i];
        printf(" - Path %d\n", i);
        if (path->nfill) {
            printf("   - fill: %d\n", path->nfill);
            for (j = 0; j < path->nfill; j++)
                printf("%f\t%f\n", path->fill[j].x, path->fill[j].y);
        }
        if (path->nstroke) {
            printf("   - stroke: %d\n", path->nstroke);
            for (j = 0; j < path->nstroke; j++)
                printf("%f\t%f\n", path->stroke[j].x, path->stroke[j].y);
        }
    }
}

void MRKUIFill(MRKUIcontext *ctx) {
    MRKUIstate *state = MRKUI__getState(ctx);
    const MRKUIpath *path;
    MRKUIpaint fillPaint = state->fill;
    int i;

    MRKUI__flattenPaths(ctx);
    if (ctx->params.edgeAntiAlias && state->shapeAntiAlias)
        MRKUI__expandFill(ctx, ctx->fringeWidth, MRKUI_MITER, 2.4f);
    else
        MRKUI__expandFill(ctx, 0.0f, MRKUI_MITER, 2.4f);

    // Apply global alpha
    fillPaint.innerColor.a *= state->alpha;
    fillPaint.outerColor.a *= state->alpha;

    ctx->params.renderFill(ctx->params.userPtr, &fillPaint, state->compositeOperation,
                           &state->scissor, ctx->fringeWidth,
                           ctx->cache->bounds, ctx->cache->paths, ctx->cache->npaths);

    // Count triangles
    for (i = 0; i < ctx->cache->npaths; i++) {
        path = &ctx->cache->paths[i];
        ctx->fillTriCount += path->nfill - 2;
        ctx->fillTriCount += path->nstroke - 2;
        ctx->drawCallCount += 2;
    }
}

void MRKUIStroke(MRKUIcontext *ctx) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float scale = MRKUI__getAverageScale(state->xform);
    float strokeWidth = MRKUI__clampf(state->strokeWidth * scale, 0.0f, 200.0f);
    MRKUIpaint strokePaint = state->stroke;
    const MRKUIpath *path;
    int i;


    if (strokeWidth < ctx->fringeWidth) {
        // If the stroke width is less than pixel size, use alpha to emulate coverage.
        // Since coverage is area, scale by alpha*alpha.
        float alpha = MRKUI__clampf(strokeWidth / ctx->fringeWidth, 0.0f, 1.0f);
        strokePaint.innerColor.a *= alpha * alpha;
        strokePaint.outerColor.a *= alpha * alpha;
        strokeWidth = ctx->fringeWidth;
    }

    // Apply global alpha
    strokePaint.innerColor.a *= state->alpha;
    strokePaint.outerColor.a *= state->alpha;

    MRKUI__flattenPaths(ctx);

    if (ctx->params.edgeAntiAlias && state->shapeAntiAlias)
        MRKUI__expandStroke(ctx, strokeWidth * 0.5f, ctx->fringeWidth, state->lineCap,
                            state->lineJoin, state->miterLimit);
    else
        MRKUI__expandStroke(ctx, strokeWidth * 0.5f, 0.0f, state->lineCap, state->lineJoin,
                            state->miterLimit);

    ctx->params.renderStroke(ctx->params.userPtr, &strokePaint, state->compositeOperation,
                             &state->scissor, ctx->fringeWidth,
                             strokeWidth, ctx->cache->paths, ctx->cache->npaths);

    // Count triangles
    for (i = 0; i < ctx->cache->npaths; i++) {
        path = &ctx->cache->paths[i];
        ctx->strokeTriCount += path->nstroke - 2;
        ctx->drawCallCount++;
    }
}

// Add fonts
int MRKUICreateFont(MRKUIcontext *ctx, const char *name, const char *path) {
    return fonsAddFont(ctx->fs, name, path);
}

int MRKUICreateFontMem(MRKUIcontext *ctx, const char *name, unsigned char *data, int ndata,
                       int freeData) {
    return fonsAddFontMem(ctx->fs, name, data, ndata, freeData);
}

int MRKUIFindFont(MRKUIcontext *ctx, const char *name) {
    if (name == NULL) return -1;
    return fonsGetFontByName(ctx->fs, name);
}


int MRKUIAddFallbackFontId(MRKUIcontext *ctx, int baseFont, int fallbackFont) {
    if (baseFont == -1 || fallbackFont == -1) return 0;
    return fonsAddFallbackFont(ctx->fs, baseFont, fallbackFont);
}

int MRKUIAddFallbackFont(MRKUIcontext *ctx, const char *baseFont, const char *fallbackFont) {
    return MRKUIAddFallbackFontId(ctx, MRKUIFindFont(ctx, baseFont),
                                  MRKUIFindFont(ctx, fallbackFont));
}

// State setting
void MRKUIFontSize(MRKUIcontext *ctx, float size) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->fontSize = size;
}

void MRKUIFontBlur(MRKUIcontext *ctx, float blur) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->fontBlur = blur;
}

void MRKUITextLetterSpacing(MRKUIcontext *ctx, float spacing) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->letterSpacing = spacing;
}

void MRKUITextLineHeight(MRKUIcontext *ctx, float lineHeight) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->lineHeight = lineHeight;
}

void MRKUITextAlign(MRKUIcontext *ctx, int align) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->textAlign = align;
}

void MRKUIFontFaceId(MRKUIcontext *ctx, int font) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->fontId = font;
}

void MRKUIFontFace(MRKUIcontext *ctx, const char *font) {
    MRKUIstate *state = MRKUI__getState(ctx);
    state->fontId = fonsGetFontByName(ctx->fs, font);
}

static float MRKUI__quantize(float a, float d) {
    return ((int) (a / d + 0.5f)) * d;
}

static float MRKUI__getFontScale(MRKUIstate *state) {
    return MRKUI__minf(MRKUI__quantize(MRKUI__getAverageScale(state->xform), 0.01f), 4.0f);
}

static void MRKUI__flushTextTexture(MRKUIcontext *ctx) {
    int dirty[4];

    if (fonsValidateTexture(ctx->fs, dirty)) {
        int fontImage = ctx->fontImages[ctx->fontImageIdx];
        // Update texture
        if (fontImage != 0) {
            int iw, ih;
            const unsigned char *data = fonsGetTextureData(ctx->fs, &iw, &ih);
            int x = dirty[0];
            int y = dirty[1];
            int w = dirty[2] - dirty[0];
            int h = dirty[3] - dirty[1];
            ctx->params.renderUpdateTexture(ctx->params.userPtr, fontImage, x, y, w, h, data);
        }
    }
}

static int MRKUI__allocTextAtlas(MRKUIcontext *ctx) {
    int iw, ih;
    MRKUI__flushTextTexture(ctx);
    if (ctx->fontImageIdx >= MRKUI_MAX_FONTIMAGES - 1)
        return 0;
    // if next fontImage already have a texture
    if (ctx->fontImages[ctx->fontImageIdx + 1] != 0)
        MRKUIImageSize(ctx, ctx->fontImages[ctx->fontImageIdx + 1], &iw, &ih);
    else { // calculate the new font image size and create it.
        MRKUIImageSize(ctx, ctx->fontImages[ctx->fontImageIdx], &iw, &ih);
        if (iw > ih)
            ih *= 2;
        else
            iw *= 2;
        if (iw > MRKUI_MAX_FONTIMAGE_SIZE || ih > MRKUI_MAX_FONTIMAGE_SIZE)
            iw = ih = MRKUI_MAX_FONTIMAGE_SIZE;
        ctx->fontImages[ctx->fontImageIdx + 1] = ctx->params.renderCreateTexture(
                ctx->params.userPtr, MRKUI_TEXTURE_ALPHA, iw, ih, 0, NULL);
    }
    ++ctx->fontImageIdx;
    fonsResetAtlas(ctx->fs, iw, ih);
    return 1;
}

static void MRKUI__renderText(MRKUIcontext *ctx, MRKUIvertex *verts, int nverts) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUIpaint paint = state->fill;

    // Render triangles.
    paint.image = ctx->fontImages[ctx->fontImageIdx];

    // Apply global alpha
    paint.innerColor.a *= state->alpha;
    paint.outerColor.a *= state->alpha;

    ctx->params.renderTriangles(ctx->params.userPtr, &paint, state->compositeOperation,
                                &state->scissor, verts, nverts);

    ctx->drawCallCount++;
    ctx->textTriCount += nverts / 3;
}

float MRKUIText(MRKUIcontext *ctx, float x, float y, const char *string, const char *end) {
    MRKUIstate *state = MRKUI__getState(ctx);
    FONStextIter iter, prevIter;
    FONSquad q;
    MRKUIvertex *verts;
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;
    int cverts = 0;
    int nverts = 0;

    if (end == NULL)
        end = string + strlen(string);

    if (state->fontId == FONS_INVALID) return x;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);

    cverts = MRKUI__maxi(2, (int) (end - string)) * 6; // conservative estimate.
    verts = MRKUI__allocTempVerts(ctx, cverts);
    if (verts == NULL) return x;

    fonsTextIterInit(ctx->fs, &iter, x * scale, y * scale, string, end, FONS_GLYPH_BITMAP_REQUIRED);
    prevIter = iter;
    while (fonsTextIterNext(ctx->fs, &iter, &q)) {
        float c[4 * 2];
        if (iter.prevGlyphIndex == -1) { // can not retrieve glyph?
            if (nverts != 0) {
                MRKUI__renderText(ctx, verts, nverts);
                nverts = 0;
            }
            if (!MRKUI__allocTextAtlas(ctx))
                break; // no memory :(
            iter = prevIter;
            fonsTextIterNext(ctx->fs, &iter, &q); // try again
            if (iter.prevGlyphIndex == -1) // still can not find glyph?
                break;
        }
        prevIter = iter;
        // Transform corners.
        MRKUITransformPoint(&c[0], &c[1], state->xform, q.x0 * invscale, q.y0 * invscale);
        MRKUITransformPoint(&c[2], &c[3], state->xform, q.x1 * invscale, q.y0 * invscale);
        MRKUITransformPoint(&c[4], &c[5], state->xform, q.x1 * invscale, q.y1 * invscale);
        MRKUITransformPoint(&c[6], &c[7], state->xform, q.x0 * invscale, q.y1 * invscale);
        // Create triangles
        if (nverts + 6 <= cverts) {
            MRKUI__vset(&verts[nverts], c[0], c[1], q.s0, q.t0);
            nverts++;
            MRKUI__vset(&verts[nverts], c[4], c[5], q.s1, q.t1);
            nverts++;
            MRKUI__vset(&verts[nverts], c[2], c[3], q.s1, q.t0);
            nverts++;
            MRKUI__vset(&verts[nverts], c[0], c[1], q.s0, q.t0);
            nverts++;
            MRKUI__vset(&verts[nverts], c[6], c[7], q.s0, q.t1);
            nverts++;
            MRKUI__vset(&verts[nverts], c[4], c[5], q.s1, q.t1);
            nverts++;
        }
    }

    // TODO: add back-end bit to do this just once per frame.
    MRKUI__flushTextTexture(ctx);

    MRKUI__renderText(ctx, verts, nverts);

    return iter.nextx / scale;
}

void MRKUITextBox(MRKUIcontext *ctx, float x, float y, float breakRowWidth, const char *string,
                  const char *end) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUItextRow rows[2];
    int nrows = 0, i;
    int oldAlign = state->textAlign;
    int haling = state->textAlign & (MRKUI_ALIGN_LEFT | MRKUI_ALIGN_CENTER | MRKUI_ALIGN_RIGHT);
    int valign = state->textAlign &
                 (MRKUI_ALIGN_TOP | MRKUI_ALIGN_MIDDLE | MRKUI_ALIGN_BOTTOM | MRKUI_ALIGN_BASELINE);
    float lineh = 0;

    if (state->fontId == FONS_INVALID) return;

    MRKUITextMetrics(ctx, NULL, NULL, &lineh);

    state->textAlign = MRKUI_ALIGN_LEFT | valign;

    while ((nrows = MRKUITextBreakLines(ctx, string, end, breakRowWidth, rows, 2))) {
        for (i = 0; i < nrows; i++) {
            MRKUItextRow *row = &rows[i];
            if (haling & MRKUI_ALIGN_LEFT)
                MRKUIText(ctx, x, y, row->start, row->end);
            else if (haling & MRKUI_ALIGN_CENTER)
                MRKUIText(ctx, x + breakRowWidth * 0.5f - row->width * 0.5f, y, row->start,
                          row->end);
            else if (haling & MRKUI_ALIGN_RIGHT)
                MRKUIText(ctx, x + breakRowWidth - row->width, y, row->start, row->end);
            y += lineh * state->lineHeight;
        }
        string = rows[nrows - 1].next;
    }

    state->textAlign = oldAlign;
}

int
MRKUITextGlyphPositions(MRKUIcontext *ctx, float x, float y, const char *string, const char *end,
                        MRKUIglyphPosition *positions, int maxPositions) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;
    FONStextIter iter, prevIter;
    FONSquad q;
    int npos = 0;

    if (state->fontId == FONS_INVALID) return 0;

    if (end == NULL)
        end = string + strlen(string);

    if (string == end)
        return 0;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);

    fonsTextIterInit(ctx->fs, &iter, x * scale, y * scale, string, end, FONS_GLYPH_BITMAP_OPTIONAL);
    prevIter = iter;
    while (fonsTextIterNext(ctx->fs, &iter, &q)) {
        if (iter.prevGlyphIndex < 0 && MRKUI__allocTextAtlas(ctx)) { // can not retrieve glyph?
            iter = prevIter;
            fonsTextIterNext(ctx->fs, &iter, &q); // try again
        }
        prevIter = iter;
        positions[npos].str = iter.str;
        positions[npos].x = iter.x * invscale;
        positions[npos].minx = MRKUI__minf(iter.x, q.x0) * invscale;
        positions[npos].maxx = MRKUI__maxf(iter.nextx, q.x1) * invscale;
        npos++;
        if (npos >= maxPositions)
            break;
    }

    return npos;
}

enum MRKUIcodepointType {
    MRKUI_SPACE,
    MRKUI_NEWLINE,
    MRKUI_CHAR,
    MRKUI_CJK_CHAR,
};

int MRKUITextBreakLines(MRKUIcontext *ctx, const char *string, const char *end, float breakRowWidth,
                        MRKUItextRow *rows, int maxRows) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;
    FONStextIter iter, prevIter;
    FONSquad q;
    int nrows = 0;
    float rowStartX = 0;
    float rowWidth = 0;
    float rowMinX = 0;
    float rowMaxX = 0;
    const char *rowStart = NULL;
    const char *rowEnd = NULL;
    const char *wordStart = NULL;
    float wordStartX = 0;
    float wordMinX = 0;
    const char *breakEnd = NULL;
    float breakWidth = 0;
    float breakMaxX = 0;
    int type = MRKUI_SPACE, ptype = MRKUI_SPACE;
    unsigned int pcodepoint = 0;

    if (maxRows == 0) return 0;
    if (state->fontId == FONS_INVALID) return 0;

    if (end == NULL)
        end = string + strlen(string);

    if (string == end) return 0;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);

    breakRowWidth *= scale;

    fonsTextIterInit(ctx->fs, &iter, 0, 0, string, end, FONS_GLYPH_BITMAP_OPTIONAL);
    prevIter = iter;
    while (fonsTextIterNext(ctx->fs, &iter, &q)) {
        if (iter.prevGlyphIndex < 0 && MRKUI__allocTextAtlas(ctx)) { // can not retrieve glyph?
            iter = prevIter;
            fonsTextIterNext(ctx->fs, &iter, &q); // try again
        }
        prevIter = iter;
        switch (iter.codepoint) {
            case 9:            // \t
            case 11:        // \v
            case 12:        // \f
            case 32:        // space
            case 0x00a0:    // NBSP
                type = MRKUI_SPACE;
                break;
            case 10:        // \n
                type = pcodepoint == 13 ? MRKUI_SPACE : MRKUI_NEWLINE;
                break;
            case 13:        // \r
                type = pcodepoint == 10 ? MRKUI_SPACE : MRKUI_NEWLINE;
                break;
            case 0x0085:    // NEL
                type = MRKUI_NEWLINE;
                break;
            default:
                if ((iter.codepoint >= 0x4E00 && iter.codepoint <= 0x9FFF) ||
                    (iter.codepoint >= 0x3000 && iter.codepoint <= 0x30FF) ||
                    (iter.codepoint >= 0xFF00 && iter.codepoint <= 0xFFEF) ||
                    (iter.codepoint >= 0x1100 && iter.codepoint <= 0x11FF) ||
                    (iter.codepoint >= 0x3130 && iter.codepoint <= 0x318F) ||
                    (iter.codepoint >= 0xAC00 && iter.codepoint <= 0xD7AF))
                    type = MRKUI_CJK_CHAR;
                else
                    type = MRKUI_CHAR;
                break;
        }

        if (type == MRKUI_NEWLINE) {
            // Always handle new lines.
            rows[nrows].start = rowStart != NULL ? rowStart : iter.str;
            rows[nrows].end = rowEnd != NULL ? rowEnd : iter.str;
            rows[nrows].width = rowWidth * invscale;
            rows[nrows].minx = rowMinX * invscale;
            rows[nrows].maxx = rowMaxX * invscale;
            rows[nrows].next = iter.next;
            nrows++;
            if (nrows >= maxRows)
                return nrows;
            // Set null break point
            breakEnd = rowStart;
            breakWidth = 0.0;
            breakMaxX = 0.0;
            // Indicate to skip the white space at the beginning of the row.
            rowStart = NULL;
            rowEnd = NULL;
            rowWidth = 0;
            rowMinX = rowMaxX = 0;
        } else {
            if (rowStart == NULL) {
                // Skip white space until the beginning of the line
                if (type == MRKUI_CHAR || type == MRKUI_CJK_CHAR) {
                    // The current char is the row so far
                    rowStartX = iter.x;
                    rowStart = iter.str;
                    rowEnd = iter.next;
                    rowWidth = iter.nextx - rowStartX; // q.x1 - rowStartX;
                    rowMinX = q.x0 - rowStartX;
                    rowMaxX = q.x1 - rowStartX;
                    wordStart = iter.str;
                    wordStartX = iter.x;
                    wordMinX = q.x0 - rowStartX;
                    // Set null break point
                    breakEnd = rowStart;
                    breakWidth = 0.0;
                    breakMaxX = 0.0;
                }
            } else {
                float nextWidth = iter.nextx - rowStartX;

                // track last non-white space character
                if (type == MRKUI_CHAR || type == MRKUI_CJK_CHAR) {
                    rowEnd = iter.next;
                    rowWidth = iter.nextx - rowStartX;
                    rowMaxX = q.x1 - rowStartX;
                }
                // track last end of a word
                if (((ptype == MRKUI_CHAR || ptype == MRKUI_CJK_CHAR) && type == MRKUI_SPACE) ||
                    type == MRKUI_CJK_CHAR) {
                    breakEnd = iter.str;
                    breakWidth = rowWidth;
                    breakMaxX = rowMaxX;
                }
                // track last beginning of a word
                if ((ptype == MRKUI_SPACE && (type == MRKUI_CHAR || type == MRKUI_CJK_CHAR)) ||
                    type == MRKUI_CJK_CHAR) {
                    wordStart = iter.str;
                    wordStartX = iter.x;
                    wordMinX = q.x0 - rowStartX;
                }

                // Break to new line when a character is beyond break width.
                if ((type == MRKUI_CHAR || type == MRKUI_CJK_CHAR) && nextWidth > breakRowWidth) {
                    // The run length is too long, need to break to new line.
                    if (breakEnd == rowStart) {
                        // The current word is longer than the row length, just break it from here.
                        rows[nrows].start = rowStart;
                        rows[nrows].end = iter.str;
                        rows[nrows].width = rowWidth * invscale;
                        rows[nrows].minx = rowMinX * invscale;
                        rows[nrows].maxx = rowMaxX * invscale;
                        rows[nrows].next = iter.str;
                        nrows++;
                        if (nrows >= maxRows)
                            return nrows;
                        rowStartX = iter.x;
                        rowStart = iter.str;
                        rowEnd = iter.next;
                        rowWidth = iter.nextx - rowStartX;
                        rowMinX = q.x0 - rowStartX;
                        rowMaxX = q.x1 - rowStartX;
                        wordStart = iter.str;
                        wordStartX = iter.x;
                        wordMinX = q.x0 - rowStartX;
                    } else {
                        // Break the line from the end of the last word, and start new line from the beginning of the new.
                        rows[nrows].start = rowStart;
                        rows[nrows].end = breakEnd;
                        rows[nrows].width = breakWidth * invscale;
                        rows[nrows].minx = rowMinX * invscale;
                        rows[nrows].maxx = breakMaxX * invscale;
                        rows[nrows].next = wordStart;
                        nrows++;
                        if (nrows >= maxRows)
                            return nrows;
                        rowStartX = wordStartX;
                        rowStart = wordStart;
                        rowEnd = iter.next;
                        rowWidth = iter.nextx - rowStartX;
                        rowMinX = wordMinX;
                        rowMaxX = q.x1 - rowStartX;
                        // No change to the word start
                    }
                    // Set null break point
                    breakEnd = rowStart;
                    breakWidth = 0.0;
                    breakMaxX = 0.0;
                }
            }
        }

        pcodepoint = iter.codepoint;
        ptype = type;
    }

    // Break the line from the end of the last word, and start new line from the beginning of the new.
    if (rowStart != NULL) {
        rows[nrows].start = rowStart;
        rows[nrows].end = rowEnd;
        rows[nrows].width = rowWidth * invscale;
        rows[nrows].minx = rowMinX * invscale;
        rows[nrows].maxx = rowMaxX * invscale;
        rows[nrows].next = end;
        nrows++;
    }

    return nrows;
}

float MRKUITextBounds(MRKUIcontext *ctx, float x, float y, const char *string, const char *end,
                      float *bounds) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;
    float width;

    if (state->fontId == FONS_INVALID) return 0;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);

    width = fonsTextBounds(ctx->fs, x * scale, y * scale, string, end, bounds);
    if (bounds != NULL) {
        // Use line bounds for height.
        fonsLineBounds(ctx->fs, y * scale, &bounds[1], &bounds[3]);
        bounds[0] *= invscale;
        bounds[1] *= invscale;
        bounds[2] *= invscale;
        bounds[3] *= invscale;
    }
    return width * invscale;
}

void
MRKUITextBoxBounds(MRKUIcontext *ctx, float x, float y, float breakRowWidth, const char *string,
                   const char *end, float *bounds) {
    MRKUIstate *state = MRKUI__getState(ctx);
    MRKUItextRow rows[2];
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;
    int nrows = 0, i;
    int oldAlign = state->textAlign;
    int haling = state->textAlign & (MRKUI_ALIGN_LEFT | MRKUI_ALIGN_CENTER | MRKUI_ALIGN_RIGHT);
    int valign = state->textAlign &
                 (MRKUI_ALIGN_TOP | MRKUI_ALIGN_MIDDLE | MRKUI_ALIGN_BOTTOM | MRKUI_ALIGN_BASELINE);
    float lineh = 0, rminy = 0, rmaxy = 0;
    float minx, miny, maxx, maxy;

    if (state->fontId == FONS_INVALID) {
        if (bounds != NULL)
            bounds[0] = bounds[1] = bounds[2] = bounds[3] = 0.0f;
        return;
    }

    MRKUITextMetrics(ctx, NULL, NULL, &lineh);

    state->textAlign = MRKUI_ALIGN_LEFT | valign;

    minx = maxx = x;
    miny = maxy = y;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);
    fonsLineBounds(ctx->fs, 0, &rminy, &rmaxy);
    rminy *= invscale;
    rmaxy *= invscale;

    while ((nrows = MRKUITextBreakLines(ctx, string, end, breakRowWidth, rows, 2))) {
        for (i = 0; i < nrows; i++) {
            MRKUItextRow *row = &rows[i];
            float rminx, rmaxx, dx = 0;
            // Horizontal bounds
            if (haling & MRKUI_ALIGN_LEFT)
                dx = 0;
            else if (haling & MRKUI_ALIGN_CENTER)
                dx = breakRowWidth * 0.5f - row->width * 0.5f;
            else if (haling & MRKUI_ALIGN_RIGHT)
                dx = breakRowWidth - row->width;
            rminx = x + row->minx + dx;
            rmaxx = x + row->maxx + dx;
            minx = MRKUI__minf(minx, rminx);
            maxx = MRKUI__maxf(maxx, rmaxx);
            // Vertical bounds.
            miny = MRKUI__minf(miny, y + rminy);
            maxy = MRKUI__maxf(maxy, y + rmaxy);

            y += lineh * state->lineHeight;
        }
        string = rows[nrows - 1].next;
    }

    state->textAlign = oldAlign;

    if (bounds != NULL) {
        bounds[0] = minx;
        bounds[1] = miny;
        bounds[2] = maxx;
        bounds[3] = maxy;
    }
}

void MRKUITextMetrics(MRKUIcontext *ctx, float *ascender, float *descender, float *lineh) {
    MRKUIstate *state = MRKUI__getState(ctx);
    float scale = MRKUI__getFontScale(state) * ctx->devicePxRatio;
    float invscale = 1.0f / scale;

    if (state->fontId == FONS_INVALID) return;

    fonsSetSize(ctx->fs, state->fontSize * scale);
    fonsSetSpacing(ctx->fs, state->letterSpacing * scale);
    fonsSetBlur(ctx->fs, state->fontBlur * scale);
    fonsSetAlign(ctx->fs, state->textAlign);
    fonsSetFont(ctx->fs, state->fontId);

    fonsVertMetrics(ctx->fs, ascender, descender, lineh);
    if (ascender != NULL)
        *ascender *= invscale;
    if (descender != NULL)
        *descender *= invscale;
    if (lineh != NULL)
        *lineh *= invscale;
}
// vim: ft=c nu noet ts=4
