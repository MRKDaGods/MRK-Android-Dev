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

#define MRKUI_KAPPA90 0.f// Length proportional myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c cubic bezier handle for 90deg arcs.

#define mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(arr) (sizeof(arr) / sizeof(0[arr]))


enum MRKUIcommands {
MRKUI_MOVETO = 0,
MRKUI_LINETO = 1,
MRKUI_BEZIERTO = 2,
MRKUI_CLOSE = 3,
MRKUI_WINDING = 4,
};

enum MRKUIpointFlags
{
MRKUI_PT_CORNER = 0x01,
MRKUI_PT_LEFT = 0x02,
MRKUI_PT_BEVEL = 0x04,
MRKUI_PR_INNERBEVEL = 0x08,
};

struct mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG {
mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG;
int mftQzTDkY1Dx2hMZ2PWrh9yegLKRDHSfRom5AUIiH;
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB;
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6;
float mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa;
float m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2;
int m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY;
int mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp;
float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
float xform[6];
mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq;
float munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0;
float mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp;
float mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi;
float mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0;
int mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN;
int mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK;
};
typedef struct mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG;

struct mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq {
float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y;
float dx, dy;
float mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0;
float dmx, dmy;
unsigned char m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;
};
typedef struct mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq;

struct mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx {
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* points;
int m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8;
int mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK;
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths;
int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz;
int mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3;
float bounds[4];
};
typedef struct mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx;

struct my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx {
mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;
float* commands;
int mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5;
int mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD;
float commandx, commandy;
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG states[MRKUI_MAX_STATES];
int mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun;
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* cache;
float mziHAAeKGzrAkkc2tK3CdiMpI0gvhiCLmdzioKQzR;
float mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb;
float mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6;
float miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
struct mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* fs;
int fontImages[MRKUI_MAX_FONTIMAGES];
int mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ;
int mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF;
int mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb;
int m7xL4X4USglv3XzU0HThAgGypV5Y39BZO5e4vkjy7;
int mjczuH2bMPOeWHzSDkqETboPW95rIxcwijfCkyaoM;
};

static float meEmYUafCng3fiRPZYRVshGFIPT7X5BU65NrMsLnu(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return sqrtf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float me2KfjGbZKIvK1mjFdNBr62KQWneEJRXtnXNcx4ob(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float b) { return fmodf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, b); }
static float mMSQtaqCwNJ9lLbDjdVHjGfn2E9x0vwN628QCXVA9(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return sinf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float mfeJdBfFJpRCwIL7NByGaaQQ69zcbyzH41fKAyv62(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return cosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float mQ39wHsdMvzdiXn4Itgs0uH570ySzuTHVuHH5Yuka(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return tanf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float mjXw8I9wlCCuzROlquTAJL3mUXr5YMFbYGQJKNLT7(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c,float b) { return atan2f(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, b); }
static float mmXtYEuimylMdcA5e0fpvRq3qXiTju6plErrrO4Kz(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return acosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }

static int mwn5BwslpF4AZUQMAIJOptupfaIKvJS8rQTZyr0Me(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int b) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c < b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b; }
static int mgCoMyFRbHuDdYAjINJzNO2R079lIEhBeV9rFRghN(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int b) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b; }
static int mVfnT846VCmTTQDz8FiMNea5JkFD6R80gxER7uNMP(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int mn, int mx) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c < mn ? mn : (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > mx ? mx : mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float b) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c < b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b; }
static float mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float b) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b; }
static float muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c >= 0.0f ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : -mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c; }
static float m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c >= 0.0f ? 1.0f : -1.0f; }
static float mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float mn, float mx) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c < mn ? mn : (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > mx ? mx : mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); }
static float m9fuCA1PHxZkqWkwO7uoWOGEGshXZK35kpDugFr3k(float dx0, float dy0, float dx1, float dy1) { return dx1*dy0 - dx0*dy1; }

static float m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(float *m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float* y)
{
float d = meEmYUafCng3fiRPZYRVshGFIPT7X5BU65NrMsLnu((*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)*(*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) + (*y)*(*y));
if (d > 1e-6f) {
float ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl = 1.0f / d;
*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp *= ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl;
*y *= ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl;
}
return d;
}


static void mZ4KXqGsxsWxw40A4NFxiQSgQpsPAVfRwMMvNLnWP(mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* c)
{
if (c == NULL) return;
if (c->points != NULL) free(c->points);
if (c->paths != NULL) free(c->paths);
if (c->verts != NULL) free(c->verts);
free(c);
}

static mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* mAHVTJlmCNPMkaptrslfMYMR4i48HdtadhwZ2ZKWo(void)
{
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* c = (mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx*)malloc(sizeof(mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx));
if (c == NULL) goto error;
memset(c, 0, sizeof(mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx));

c->points = (mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq*)malloc(sizeof(mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq)*MRKUI_INIT_POINTS_SIZE);
if (!c->points) goto error;
c->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8 = 0;
c->mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK = MRKUI_INIT_POINTS_SIZE;

c->paths = (mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz*)malloc(sizeof(mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz)*MRKUI_INIT_PATHS_SIZE);
if (!c->paths) goto error;
c->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = 0;
c->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU = MRKUI_INIT_PATHS_SIZE;

c->verts = (mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv*)malloc(sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv)*MRKUI_INIT_VERTS_SIZE);
if (!c->verts) goto error;
c->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;
c->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = MRKUI_INIT_VERTS_SIZE;

return c;
error:
mZ4KXqGsxsWxw40A4NFxiQSgQpsPAVfRwMMvNLnWP(c);
return NULL;
}

static void mOg4275FwjxZ33EDs8EQZO48nePwfYoqdLFIdBY9k(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float ratio)
{
ctx->mziHAAeKGzrAkkc2tK3CdiMpI0gvhiCLmdzioKQzR = 0.25f / ratio;
ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb = 0.1f / ratio;
ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6 = 1.0f / ratio;
ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l = ratio;
}

static mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mOFbUAcOu7ggy4OoGUvBSmUriQI5lFReU1hSZXRzb(int mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9)
{
int sfactor, dfactor;

if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_SOURCE_OVER)
{
sfactor = MRKUI_ONE;
dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_SOURCE_IN)
{
sfactor = MRKUI_DST_ALPHA;
dfactor = MRKUI_ZERO;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_SOURCE_OUT)
{
sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
dfactor = MRKUI_ZERO;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_ATOP)
{
sfactor = MRKUI_DST_ALPHA;
dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_DESTINATION_OVER)
{
sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
dfactor = MRKUI_ONE;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_DESTINATION_IN)
{
sfactor = MRKUI_ZERO;
dfactor = MRKUI_SRC_ALPHA;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_DESTINATION_OUT)
{
sfactor = MRKUI_ZERO;
dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_DESTINATION_ATOP)
{
sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
dfactor = MRKUI_SRC_ALPHA;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_LIGHTER)
{
sfactor = MRKUI_ONE;
dfactor = MRKUI_ONE;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_COPY)
{
sfactor = MRKUI_ONE;
dfactor = MRKUI_ZERO;
}
else if (mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 == MRKUI_XOR)
{
sfactor = MRKUI_ONE_MINUS_DST_ALPHA;
dfactor = MRKUI_ONE_MINUS_SRC_ALPHA;
}
else
{
sfactor = MRKUI_ONE;
dfactor = MRKUI_ZERO;
}

mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS = sfactor;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi = dfactor;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH = sfactor;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g = dfactor;
return msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2;
}

static mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
return &ctx->states[ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun-1];
}

my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mxdzgKV0758RY1Q0kyyt9xf633PmvdswzqoLIlrys(mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az* m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk)
{
m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8;
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx = (my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx*)malloc(sizeof(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx));
int i;
if (ctx == NULL) goto error;
memset(ctx, 0, sizeof(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx));

ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk = *m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;
for (i = 0; i < MRKUI_MAX_FONTIMAGES; i++)
ctx->fontImages[i] = 0;

ctx->commands = (float*)malloc(sizeof(float)*MRKUI_INIT_COMMANDS_SIZE);
if (!ctx->commands) goto error;
ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD = 0;
ctx->mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5 = MRKUI_INIT_COMMANDS_SIZE;

ctx->cache = mAHVTJlmCNPMkaptrslfMYMR4i48HdtadhwZ2ZKWo();
if (ctx->cache == NULL) goto error;

mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH(ctx);
m3HslY985uJxsfB7ALCTPRYnkIHe3YnVlkOXPQmWn(ctx);

mOg4275FwjxZ33EDs8EQZO48nePwfYoqdLFIdBY9k(ctx, 1.0f);

if (ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreate(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr) == 0) goto error;

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh rendering
memset(&m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8, 0, sizeof(m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8));
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = MRKUI_INIT_FONTIMAGE_SIZE;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = MRKUI_INIT_FONTIMAGE_SIZE;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = FONS_ZERO_TOPLEFT;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.renderCreate = NULL;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.renderUpdate = NULL;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.renderDraw = NULL;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.renderDelete = NULL;
m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.userPtr = NULL;
ctx->fs = fonsCreateInternal(&m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8);
if (ctx->fs == NULL) goto error;

// Create mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh texture
ctx->fontImages[0] = ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreateTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, MRKUI_TEXTURE_ALPHA, m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, m4Y0qulXg7KFWBYI2sQXEeAoyg7EDptNWMImTwdl8.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, 0, NULL);
if (ctx->fontImages[0] == 0) goto error;
ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ = 0;

return ctx;

error:
mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt(ctx);
return 0;
}

mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az* m4wxdT9dKFfcmz4hiilC50tOQEk9Fof4hR6BfAXRF(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
    return &ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;
}

void mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
int i;
if (ctx == NULL) return;
if (ctx->commands != NULL) free(ctx->commands);
if (ctx->cache != NULL) mZ4KXqGsxsWxw40A4NFxiQSgQpsPAVfRwMMvNLnWP(ctx->cache);

if (ctx->fs)
m4X2WYU3dbT2MbC06eMvvZPgza6hxYrjUFzFNDNTn(ctx->fs);

for (i = 0; i < MRKUI_MAX_FONTIMAGES; i++) {
if (ctx->fontImages[i] != 0) {
mgLGIfY89sBwjoJBwt0hJq4zsDcjF7sLvkTQCny6Z(ctx, ctx->fontImages[i]);
ctx->fontImages[i] = 0;
}
}

if (ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDelete != NULL)
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDelete(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr);

free(ctx);
}

void mwngG50VO0PjiFFGXo0Ct3P5WMQvl0FPA6cwOSuVo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float windowWidth, float windowHeight, float devicePixelRatio)
{
/*printf("Tris: draws:%d  fill:%d  stroke:%d  text:%d  TOT:%d\n",
ctx->mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF, ctx->mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb, ctx->m7xL4X4USglv3XzU0HThAgGypV5Y39BZO5e4vkjy7, ctx->mjczuH2bMPOeWHzSDkqETboPW95rIxcwijfCkyaoM,
ctx->mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb+ctx->m7xL4X4USglv3XzU0HThAgGypV5Y39BZO5e4vkjy7+ctx->mjczuH2bMPOeWHzSDkqETboPW95rIxcwijfCkyaoM);*/

ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun = 0;
mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH(ctx);
m3HslY985uJxsfB7ALCTPRYnkIHe3YnVlkOXPQmWn(ctx);

mOg4275FwjxZ33EDs8EQZO48nePwfYoqdLFIdBY9k(ctx, devicePixelRatio);

ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderViewport(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, windowWidth, windowHeight, devicePixelRatio);

ctx->mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF = 0;
ctx->mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb = 0;
ctx->m7xL4X4USglv3XzU0HThAgGypV5Y39BZO5e4vkjy7 = 0;
ctx->mjczuH2bMPOeWHzSDkqETboPW95rIxcwijfCkyaoM = 0;
}

void mRznED4JNxkkHbS48wwc1sB9x54LxHK2rxRm7rvOA(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCancel(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr);
}

void mMyqsGRCArKfd0zO6wu7PL80Q9w8FwwUDBWawurm1(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderFlush(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr);
if (ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ != 0) {
int fontImage = ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ];
int i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G, iw, ih;
// delete images that smaller than current one
if (fontImage == 0)
return;
mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(ctx, fontImage, &iw, &ih);
for (i = mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; i < ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ; i++) {
if (ctx->fontImages[i] != 0) {
int nw, nh;
mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(ctx, ctx->fontImages[i], &nw, &nh);
if (nw < iw || nh < ih)
mgLGIfY89sBwjoJBwt0hJq4zsDcjF7sLvkTQCny6Z(ctx, ctx->fontImages[i]);
else
ctx->fontImages[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++] = ctx->fontImages[i];
}
}
// make current mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT first
ctx->fontImages[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++] = ctx->fontImages[0];
ctx->fontImages[0] = fontImage;
ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ = 0;
// clear all images after mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G
for (i = mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G; i < MRKUI_MAX_FONTIMAGES; i++)
ctx->fontImages[i] = 0;
}
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mGnNiCWoJS09NaYTPtsNYrCSfaxueNHs5Ygqh9ECt(unsigned char mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, unsigned char g, unsigned char b)
{
return m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN(mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC,g,b,255);
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mJzNBdNsdcKFTbTcw9vazCXUcFjoR92fOl9ItvWPK(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b)
{
return m6XVjzn2z662ekeWHLgBlodqX0CexVV7jevThD551(mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC,g,b,1.0f);
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN(unsigned char mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, unsigned char g, unsigned char b, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
// Use longer initialization myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT suppress warning.
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC / 255.0f;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.g = g / 255.0f;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.b = b / 255.0f;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c / 255.0f;
return mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk m6XVjzn2z662ekeWHLgBlodqX0CexVV7jevThD551(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
// Use longer initialization myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT suppress warning.
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.g = g;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.b = b;
mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
return mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mNt7MfAXzSHnvc3RTlFykMVtwocOiRA3fMhekceVx(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
c.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c / 255.0f;
return c;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mUaN9OqPUgj92RGDJyLcXddPSKtyvqzm9t3i4mteZ(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
c.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
return c;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mZ2OdSFr8TenOBmNj9XBZ8znDhAaz1quVh4M42Xj7(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c0, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c1, float u)
{
int i;
float mrWfM8gISUf2640Ox7sID8xTl0zWc3qf8sbmSZ6lI;
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk cint = {{{0}}};

u = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(u, 0.0f, 1.0f);
mrWfM8gISUf2640Ox7sID8xTl0zWc3qf8sbmSZ6lI = 1.0f - u;
for( i = 0; i <4; i++ )
{
cint.rgba[i] = c0.rgba[i] * mrWfM8gISUf2640Ox7sID8xTl0zWc3qf8sbmSZ6lI + c1.rgba[i] * u;
}

return cint;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mL93rnwrJxYHluUaBQwtzPB9h7auIYfdPiQdtlrP5(float h, float s, float l)
{
return miGYj7kxkRTFoSxgmCtLnfSGhK7cwiqB2p0UzxhhT(h,s,l,255);
}

static float mdFYV9o5ffqhKWoU0B5GJrrZ30NkikQmEZGtxxrjj(float h, float m1, float m2)
{
if (h < 0) h += 1;
if (h > 1) h -= 1;
if (h < 1.0f/6.0f)
return m1 + (m2 - m1) * h * 6.0f;
else if (h < 3.0f/6.0f)
return m2;
else if (h < 4.0f/6.0f)
return m1 + (m2 - m1) * (2.0f/3.0f - h) * 6.0f;
return m1;
}

mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk miGYj7kxkRTFoSxgmCtLnfSGhK7cwiqB2p0UzxhhT(float h, float s, float l, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
float m1, m2;
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH;
h = me2KfjGbZKIvK1mjFdNBr62KQWneEJRXtnXNcx4ob(h, 1.0f);
if (h < 0.0f) h += 1.0f;
s = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(s, 0.0f, 1.0f);
l = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(l, 0.0f, 1.0f);
m2 = l <= 0.5f ? (l * (1 + s)) : (l + s - l * s);
m1 = 2 * l - m2;
mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH.mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(mdFYV9o5ffqhKWoU0B5GJrrZ30NkikQmEZGtxxrjj(h + 1.0f/3.0f, m1, m2), 0.0f, 1.0f);
mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH.g = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(mdFYV9o5ffqhKWoU0B5GJrrZ30NkikQmEZGtxxrjj(h, m1, m2), 0.0f, 1.0f);
mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH.b = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(mdFYV9o5ffqhKWoU0B5GJrrZ30NkikQmEZGtxxrjj(h - 1.0f/3.0f, m1, m2), 0.0f, 1.0f);
mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c/255.0f;
return mJDLY0FmrsoLn4EdYZV1369bneBotYx9CNM3mxnKH;
}

void m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
{
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = 1.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = 0.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = 1.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = 0.0f;
}

void m5Iobq0jvOmr7hbArbk1JRu1DW8sDF6tTE97isYAJ(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float tx, float ty)
{
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = 1.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = 0.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = 1.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = tx; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = ty;
}

void mfCoEfOtuOAQaWLRUJvPvXh3SDigf79DxeIQDFdHg(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float sx, float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso)
{
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = sx; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = 0.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = 0.0f;
}

void mLpXVZiXVxS5MbVcP3jCMPL5Jv4eQkE3qEz5tczYN(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
float cs = mfeJdBfFJpRCwIL7NByGaaQQ69zcbyzH41fKAyv62(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c), sn = mMSQtaqCwNJ9lLbDjdVHjGfn2E9x0vwN628QCXVA9(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = cs; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = sn;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = -sn; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = cs;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = 0.0f;
}

void mtzKezl3wA0Q54G3S1Uj6Z2pVMhKjLJA2OQmFmyMB(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = 1.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = 0.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = mQ39wHsdMvzdiXn4Itgs0uH570ySzuTHVuHH5Yuka(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c); mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = 1.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = 0.0f;
}

void mEeopHSnOUtdDNpMtE8lqO3FLzi0UHCEjmOz37nRA(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = 1.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = mQ39wHsdMvzdiXn4Itgs0uH570ySzuTHVuHH5Yuka(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = 1.0f;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = 0.0f; mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = 0.0f;
}

void m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, const float* s)
{
float t0 = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] * s[0] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] * s[2];
float t2 = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] * s[0] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] * s[2];
float t4 = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] * s[0] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] * s[2] + s[4];
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] * s[1] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] * s[3];
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] * s[1] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] * s[3];
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] * s[1] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] * s[3] + s[5];
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] = t0;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] = t2;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] = t4;
}

void mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, const float* s)
{
float s2[6];
memcpy(s2, s, sizeof(float)*6);
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(s2, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
memcpy(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, s2, sizeof(float)*6);
}

int mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(float* inv, const float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
{
double invdet, det = (double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] - (double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1];
if (det > -1e-6 && det < 1e-6) {
m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(inv);
return 0;
}
invdet = 1.0 / det;
inv[0] = (float)(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] * invdet);
inv[2] = (float)(-mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] * invdet);
inv[4] = (float)(((double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5] - (double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4]) * invdet);
inv[1] = (float)(-mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] * invdet);
inv[3] = (float)(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] * invdet);
inv[5] = (float)(((double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4] - (double)mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5]) * invdet);
return 1;
}

void mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(float* dx, float* dy, const float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, float sx, float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso)
{
*dx = sx*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] + mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4];
*dy = sx*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] + mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5];
}

float msovUz6tSFPDjNau73Hv8zCuKnIiy9FCvmv8j10GH(float deg)
{
return deg / 180.0f * MRKUI_PI;
}

float mhIdjpwbJP38fC6MXWYQQY2wbEfbBWEwf4t4deMxC(float rad)
{
return rad / MRKUI_PI * 180.0f;
}

static void mnBoNSY07ouDAE2HwlQhKGs89SIr8WY9nYs1eB9xo(m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP)
{
memset(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, 0, sizeof(*mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc));
m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->xform);
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA = 0.0f;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl = 1.0f;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0 = mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH = mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
}


// State handling
void mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
if (ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun >= MRKUI_MAX_STATES)
return;
if (ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun > 0)
memcpy(&ctx->states[ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun], &ctx->states[ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun-1], sizeof(mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG));
ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun++;
}

void mEnzEy2XEJSfhYRPOiZFCfb9yNUhxaCG88bCZDY81(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
if (ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun <= 1)
return;
ctx->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun--;
}

void m3HslY985uJxsfB7ALCTPRYnkIHe3YnVlkOXPQmWn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
memset(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2, 0, sizeof(*msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2));

mnBoNSY07ouDAE2HwlQhKGs89SIr8WY9nYs1eB9xo(&msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB, m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN(255,255,255,255));
mnBoNSY07ouDAE2HwlQhKGs89SIr8WY9nYs1eB9xo(&msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6, m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN(0,0,0,255));
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG = mOFbUAcOu7ggy4OoGUvBSmUriQI5lFReU1hSZXRzb(MRKUI_SOURCE_OVER);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mftQzTDkY1Dx2hMZ2PWrh9yegLKRDHSfRom5AUIiH = 1;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa = 1.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2 = 10.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp = mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY = mjfUTlQL3XpQ7EwiEeHSDb9DH1Op1wf5z3UIoyM58;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E = 1.0f;
m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[0] = -1.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[1] = -1.0f;

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0 = 16.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp = 0.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi = 1.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0 = 0.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = MRKUI_ALIGN_LEFT | MRKUI_ALIGN_BASELINE;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK = 0;
}

// State setting
void mo10ziaid6LG7PVFZYTNaHSuYCxxHbDCyhS8KaOOc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int enabled)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mftQzTDkY1Dx2hMZ2PWrh9yegLKRDHSfRom5AUIiH = enabled;
}

void m7Ar59VA6z5YPjFT04EQfG1aviRFXE3XQN1gyxhqJ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
}

void mmBxsVYmv5FUWlkF61j7PfuxLVAbpddK1TOhJ2R6N(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float limit)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2 = limit;
}

void mLmChCIzJqhUkJWprqwEgRJ4QLQBr5kMHICDbbdaY(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int cap)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp = cap;
}

void mLPlM5kv2v5G6sUk0H6xd1JrghtYF8bB09NzIEABg(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int join)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY = join;
}

void maqb8lSFbFNpBG6aTwP3huA1RPnChliAE5IXENtOp(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E = mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
}

void mjCqcV3DaKw33h5bZnbN4Wbqo4WBZ184z1AyD3Tzt(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float b, float c, float d, float e, float f)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6] = { mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, b, c, d, e, f };
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void mUeV2XTTGtaOEG60xg1zsHqdIPa0xH6jtb47MUsCj(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);
}

void mxJ8JN3mQUb8SYBOCwER49aLArugU2iMzc9zWWahS(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6];
m5Iobq0jvOmr7hbArbk1JRu1DW8sDF6tTE97isYAJ(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y);
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void m2FkAsviO5JFkZoVtMnmv68YUh3iWILEXg18r9ak0(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6];
mLpXVZiXVxS5MbVcP3jCMPL5Jv4eQkE3qEz5tczYN(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, angle);
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void m95o6iAOB11LcSKQtMvhWHfOE3GMQyJxH7BGtFJ7F(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6];
mtzKezl3wA0Q54G3S1Uj6Z2pVMhKjLJA2OQmFmyMB(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, angle);
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void m4vD8A06hXrQDUcfNq2lGBsfNzK2exZZEbYYVWqxx(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6];
mEeopHSnOUtdDNpMtE8lqO3FLzi0UHCEjmOz37nRA(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, angle);
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void mJc8eNjTvILdQejexiLH4VDMhKL4N2lwKfu4WPWna(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[6];
mfCoEfOtuOAQaWLRUJvPvXh3SDigf79DxeIQDFdHg(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y);
mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU);
}

void mq5aMgQrQLkjIa6l6mM7SqgxFQWs5lzkpJqepviSm(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float* xform)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
if (xform == NULL) return;
memcpy(xform, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, sizeof(float)*6);
}

void m04M6uiH0JLlLn2jInACI76VOPXadkfCAWk3Y2RjR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mnBoNSY07ouDAE2HwlQhKGs89SIr8WY9nYs1eB9xo(&msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6, mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
}

void mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ paint)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 = paint;
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6.xform, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);
}

void mAHZCgiUiBLU8QKhJI72eKDqcmhASKdOOw9NUPTcS(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mnBoNSY07ouDAE2HwlQhKGs89SIr8WY9nYs1eB9xo(&msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB, mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
}

void mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ paint)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB = paint;
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB.xform, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);
}

int mH1mXETCQjcvT0fCPw3rQdO3F5MjIdt6YXdCyFfE6(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* filename, int imageFlags)
{
int w, h, n, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
unsigned char* img;
stbi_set_unpremultiply_on_load(1);
stbi_convert_iphone_png_to_rgb(1);
img = stbi_load(filename, &w, &h, &n, 4);
if (img == NULL) {
//printf("Failed to load %s - %s\n", filename, stbi_failure_reason());
return 0;
}
mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = m9DDyetlwzFY4GtL4vo798SeRDjHh1vw7w67ABcpj(ctx, w, h, imageFlags, img);
stbi_image_free(img);
return mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
}

int mX5bz4Hu68LYvxJQYx8ZTPm5PkePDnX48Ox3HRx9R(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int imageFlags, unsigned char* data, int ndata)
{
int w, h, n, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
unsigned char* img = stbi_load_from_memory(data, ndata, &w, &h, &n, 4);
if (img == NULL) {
//printf("Failed to load %s - %s\n", filename, stbi_failure_reason());
return 0;
}
mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = m9DDyetlwzFY4GtL4vo798SeRDjHh1vw7w67ABcpj(ctx, w, h, imageFlags, img);
stbi_image_free(img);
return mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
}

int m9DDyetlwzFY4GtL4vo798SeRDjHh1vw7w67ABcpj(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int w, int h, int imageFlags, const unsigned char* data)
{
return ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreateTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, MRKUI_TEXTURE_RGBA, w, h, imageFlags, data);
}

void mr9NuxqW5TtGama1YyvxXmDsvSWld8V6wK6xWUJ2o(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, const unsigned char* data)
{
int w, h;
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderGetTextureSize(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, &w, &h);
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderUpdateTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, 0,0, w,h, data);
}

void mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int* w, int* h)
{
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderGetTextureSize(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, w, h);
}

void mgLGIfY89sBwjoJBwt0hJq4zsDcjF7sLvkTQCny6Z(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
{
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDeleteTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
}

m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mBOlgW8laJBK8LsBl4rKj12wJoIXDAWuhVsRnv1qn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx,
  float sx, float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso, float ex, float mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg,
  mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol)
{
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
float dx, dy, d;
const float large = 1e5;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(ctx);
memset(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, 0, sizeof(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc));

// Calculate transform aligned myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the line
dx = ex - sx;
dy = mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg - mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso;
d = sqrtf(dx*dx + dy*dy);
if (d > 0.1f) {
dx /= d;
dy /= d;
} else {
dx = 0;
dy = 1;
}

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[0] = dy; mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[1] = -dx;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[2] = dx; mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[3] = dy;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[4] = sx - dx*large; mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[5] = mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso - dy*large;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[0] = large;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[1] = large + d*0.5f;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA = 0.0f;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(1.0f, d);

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0 = icol;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH = ocol;

return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
}

m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ m0LFjxsxkBL5djdSrTBFTbHUtDq0oaTge4L5cfTTJ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx,
  float cx, float cy, float inr, float outr,
  mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol)
{
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = (inr+outr)*0.5f;
float f = (outr-inr);
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(ctx);
memset(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, 0, sizeof(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc));

m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform);
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[4] = cx;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[5] = cy;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[0] = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[1] = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(1.0f, f);

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0 = icol;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH = ocol;

return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
}

m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mdyvG2rNfeGQixvCtRbnCNlhHLX7ozeMWHpAmvGwv(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx,
   float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float f,
   mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol)
{
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(ctx);
memset(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, 0, sizeof(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc));

m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform);
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[4] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w*0.5f;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[5] = y+h*0.5f;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[0] = w*0.5f;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[1] = h*0.5f;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(1.0f, f);

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0 = icol;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH = ocol;

return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
}


m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mSwnb5D9th8QoPkkDkyiUUi0DZauFnSLsB88o1Whq(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx,
float cx, float cy, float w, float h, float angle,
int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E)
{
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(ctx);
memset(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, 0, sizeof(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc));

mLpXVZiXVxS5MbVcP3jCMPL5Jv4eQkE3qEz5tczYN(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform, angle);
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[4] = cx;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.xform[5] = cy;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[0] = w;
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.extent[1] = h;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;

mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0 = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH = m6XVjzn2z662ekeWHLgBlodqX0CexVV7jevThD551(1,1,1,mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);

return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
}

// Scissoring
void mh0nqh0yXHlHpsSLPnDkPmPJBimq6DEi4dtTV2I1v(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);

w = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(0.0f, w);
h = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(0.0f, h);

m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform[4] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w*0.5f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform[5] = y+h*0.5f;
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[0] = w*0.5f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[1] = h*0.5f;
}

static void mZDn3kcboZ3IqArFI6ABhXy5NBIecaYZlqMYnWezk(float* dst,
float ax, float ay, float aw, float ah,
float bx, float by, float bw, float bh)
{
float minx = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(ax, bx);
float miny = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(ay, by);
float maxx = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(ax+aw, bx+bw);
float maxy = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(ay+ah, by+bh);
dst[0] = minx;
dst[1] = miny;
dst[2] = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(0.0f, maxx - minx);
dst[3] = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(0.0f, maxy - miny);
}

void mPKwO5dlf39LoRMOBK7rTW94momIFpL4fJuN8geuN(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float pxform[6], invxorm[6];
float rect[4];
float ex, mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg, tex, tey;

// If no mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58 mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq has been set, set the mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq as current mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[0] < 0) {
mh0nqh0yXHlHpsSLPnDkPmPJBimq6DEi4dtTV2I1v(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, w, h);
return;
}

// Transform the current mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rect into current transform space.
// If there is difference in rotation, this will be approximation.
memcpy(pxform, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform, sizeof(float)*6);
ex = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[0];
mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[1];
mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(invxorm, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(pxform, invxorm);
tex = ex*muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(pxform[0]) + mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg*muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(pxform[2]);
tey = ex*muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(pxform[1]) + mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg*muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(pxform[3]);

// Intersect rects.
mZDn3kcboZ3IqArFI6ABhXy5NBIecaYZlqMYnWezk(rect, pxform[4]-tex,pxform[5]-tey,tex*2,tey*2, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,w,h);

mh0nqh0yXHlHpsSLPnDkPmPJBimq6DEi4dtTV2I1v(ctx, rect[0], rect[1], rect[2], rect[3]);
}

void mq46HZ4sgiUDLCotOLMENnQnv55HgOpu5j8dwovp3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
memset(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform, 0, sizeof(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.xform));
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[0] = -1.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq.extent[1] = -1.0f;
}

// Global composite operation.
void mG3eZDuI6U7eehzjXL5VcdCCoY9APvByj0KARvMcO(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG = mOFbUAcOu7ggy4OoGUvBSmUriQI5lFReU1hSZXRzb(mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9);
}

void mishAqJI5H8WM6t4OeWCGy0peJIns6FA8YzBSg84V(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int sfactor, int dfactor)
{
mEkXnGwu13Moidhqh2PvJedn7SfUL4vc8427TPkgG(ctx, sfactor, dfactor, sfactor, dfactor);
}

void mEkXnGwu13Moidhqh2PvJedn7SfUL4vc8427TPkgG(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS, int mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi, int moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH, int mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g)
{
mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9;
mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS = mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS;
mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi = mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi;
mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH = moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH;
mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g = mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g;

mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG = mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9;
}

static int mqHqyXB2TLTbAM6HA9eDlAL4XuYdMjFLQD7FkhN9k(float x1, float y1, float x2, float y2, float tol)
{
float dx = x2 - x1;
float dy = y2 - y1;
return dx*dx + dy*dy < tol*tol;
}

static float mYAvY1AcF8A0KwXayQhwvoqra9Mk27fO2i1joAG0c(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float px, float py, float qx, float qy)
{
float pqx, pqy, dx, dy, d, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
pqx = qx-px;
pqy = qy-py;
dx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp-px;
dy = y-py;
d = pqx*pqx + pqy*pqy;
mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = pqx*dx + pqy*dy;
if (d > 0) mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU /= d;
if (mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU < 0) mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = 0;
else if (mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU > 1) mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = 1;
dx = px + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU*pqx - m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
dy = py + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU*pqy - y;
return dx*dx + dy*dy;
}

static void mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float* vals, int nvals)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
int i;

if (ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD+nvals > ctx->mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5) {
float* commands;
int mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5 = ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD+nvals + ctx->mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5/2;
commands = (float*)realloc(ctx->commands, sizeof(float)*mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5);
if (commands == NULL) return;
ctx->commands = commands;
ctx->mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5 = mWbz80q41zhxJwQeO3ncKU8aTxKlS2sRnXM5ewDf5;
}

if ((int)vals[0] != MRKUI_CLOSE && (int)vals[0] != MRKUI_WINDING) {
ctx->commandx = vals[nvals-2];
ctx->commandy = vals[nvals-1];
}

// transform commands
i = 0;
while (i < nvals) {
int cmd = (int)vals[i];
switch (cmd) {
case MRKUI_MOVETO:
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&vals[i+1],&vals[i+2], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, vals[i+1],vals[i+2]);
i += 3;
break;
case MRKUI_LINETO:
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&vals[i+1],&vals[i+2], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, vals[i+1],vals[i+2]);
i += 3;
break;
case MRKUI_BEZIERTO:
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&vals[i+1],&vals[i+2], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, vals[i+1],vals[i+2]);
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&vals[i+3],&vals[i+4], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, vals[i+3],vals[i+4]);
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&vals[i+5],&vals[i+6], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, vals[i+5],vals[i+6]);
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

memcpy(&ctx->commands[ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD], vals, nvals*sizeof(float));

ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD += nvals;
}


static void m3yOUApBzGy9SDxwv8gEb7IjoklzKzBAPzIT5XCpX(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8 = 0;
ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = 0;
}

static mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* mGHnouN1Atd5zJKpAE44hEdMeQck4WH3zLciC3a5w(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
if (ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz > 0)
return &ctx->cache->paths[ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz-1];
return NULL;
}

static void mdBQv0CMmq1RDryTlHBwUyeRtRNhZ1aBCxts2TswQ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path;
if (ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz+1 > ctx->cache->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths;
int mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU = ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz+1 + ctx->cache->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU/2;
paths = (mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz*)realloc(ctx->cache->paths, sizeof(mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz)*mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU);
if (paths == NULL) return;
ctx->cache->paths = paths;
ctx->cache->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU = mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU;
}
path = &ctx->cache->paths[ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz];
memset(path, 0, sizeof(*path));
path->first = ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8;
path->mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 = MRKUI_CCW;

ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz++;
}

static mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mJ0PvP1XUGTCHJYO1a0yvuw0WSJNaR7S3Qi2aaAYl(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
if (ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8 > 0)
return &ctx->cache->points[ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8-1];
return NULL;
}

static void mAqcXVfTK2g0ICBiShd24XYaDHHVSjtDmOuyiZ5cz(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
{
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = mGHnouN1Atd5zJKpAE44hEdMeQck4WH3zLciC3a5w(ctx);
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pt;
if (path == NULL) return;

if (path->count > 0 && ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8 > 0) {
pt = mJ0PvP1XUGTCHJYO1a0yvuw0WSJNaR7S3Qi2aaAYl(ctx);
if (mqHqyXB2TLTbAM6HA9eDlAL4XuYdMjFLQD7FkhN9k(pt->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,pt->y, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb)) {
pt->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf |= m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;
return;
}
}

if (ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8+1 > ctx->cache->mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK) {
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* points;
int mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK = ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8+1 + ctx->cache->mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK/2;
points = (mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq*)realloc(ctx->cache->points, sizeof(mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq)*mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK);
if (points == NULL) return;
ctx->cache->points = points;
ctx->cache->mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK = mtCqOsEcXDV1AW8UNLSso8Hypt9HnHT0B0S7SLvdK;
}

pt = &ctx->cache->points[ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8];
memset(pt, 0, sizeof(*pt));
pt->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
pt->y = y;
pt->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = (unsigned char)m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;

ctx->cache->m9iD4S4aR14etihm5Vcm0a6sVNryLN8wN1YkiXvq8++;
path->count++;
}

static void mx5qBWlJtABEJ4FJDZsPVvX7Y4dnjKDT3qS6JUUFE(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = mGHnouN1Atd5zJKpAE44hEdMeQck4WH3zLciC3a5w(ctx);
if (path == NULL) return;
path->mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj = 1;
}

static void mO22PUT6h6zQ7Y1cXaDb9udJzcS0E34YuaqkZOvIA(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94)
{
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = mGHnouN1Atd5zJKpAE44hEdMeQck4WH3zLciC3a5w(ctx);
if (path == NULL) return;
path->mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 = mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94;
}

static float m4XTfrbNMHdOmsI2jxFrqbF3s3H2OXwfPboJFZdNg(float *mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
{
float sx = sqrtf(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0]*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2]*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2]);
float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = sqrtf(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1]*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1] + mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3]*mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3]);
return (sx + mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso) * 0.5f;
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mqfnGNKHGOJHaKOQc59rZ1Ao6s2sdIuhWkWUeFvdl(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA)
{
if (mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA > ctx->cache->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3) {
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = (mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA + 0xff) & ~0xff; // Round up myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prevent allocations when things change just slightly.
verts = (mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv*)realloc(ctx->cache->verts, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv)*m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3);
if (verts == NULL) return NULL;
ctx->cache->verts = verts;
ctx->cache->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3;
}

return ctx->cache->verts;
}

static float mBXRrwFYC6mfF5Zp95swKHZj0yVdbFREgczOVL5ys(float ax, float ay, float bx, float by, float cx, float cy)
{
float abx = bx - ax;
float aby = by - ay;
float acx = cx - ax;
float acy = cy - ay;
return acx*aby - abx*acy;
}

static float mCVpwd9DznEC0mS6WwaVJON90ALcHIZk0ShfiXAwe(mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts, int npts)
{
int i;
float mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 = 0;
for (i = 2; i < npts; i++) {
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = &pts[0];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* b = &pts[i-1];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* c = &pts[i];
mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 += mBXRrwFYC6mfF5Zp95swKHZj0yVdbFREgczOVL5ys(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c->y, b->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,b->y, c->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,c->y);
}
return mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 * 0.5f;
}

static void mZrokIVmchzwBCWnYu42rv1xXOgpbhByedzGE7Au2(mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts, int npts)
{
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4;
int i = 0, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = npts-1;
while (i < mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4 = pts[i];
pts[i] = pts[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
pts[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4;
i++;
mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G--;
}
}


static void mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* vtx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float u, float v)
{
vtx->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
vtx->y = y;
vtx->u = u;
vtx->v = v;
}

static void m1742HyZCSmidjHt1aLG3XCs8HpJrLG3NznSHbvcg(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx,
 float x1, float y1, float x2, float y2,
 float x3, float y3, float x4, float y4,
 int level, int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P)
{
float x12,y12,x23,y23,x34,y34,x123,y123,x234,y234,x1234,y1234;
float dx,dy,d2,d3;

if (level > 10) return;

x12 = (x1+x2)*0.5f;
y12 = (y1+y2)*0.5f;
x23 = (x2+x3)*0.5f;
y23 = (y2+y3)*0.5f;
x34 = (x3+x4)*0.5f;
y34 = (y3+y4)*0.5f;
x123 = (x12+x23)*0.5f;
y123 = (y12+y23)*0.5f;

dx = x4 - x1;
dy = y4 - y1;
d2 = muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(((x2 - x4) * dy - (y2 - y4) * dx));
d3 = muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(((x3 - x4) * dy - (y3 - y4) * dx));

if ((d2 + d3)*(d2 + d3) < ctx->mziHAAeKGzrAkkc2tK3CdiMpI0gvhiCLmdzioKQzR * (dx*dx + dy*dy)) {
mAqcXVfTK2g0ICBiShd24XYaDHHVSjtDmOuyiZ5cz(ctx, x4, y4, mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P);
return;
}

/*if (muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(x1+x3-x2-x2) + muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(y1+y3-y2-y2) + muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(x2+x4-x3-x3) + muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(y2+y4-y3-y3) < ctx->mziHAAeKGzrAkkc2tK3CdiMpI0gvhiCLmdzioKQzR) {
mAqcXVfTK2g0ICBiShd24XYaDHHVSjtDmOuyiZ5cz(ctx, x4, y4, mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P);
return;
}*/

x234 = (x23+x34)*0.5f;
y234 = (y23+y34)*0.5f;
x1234 = (x123+x234)*0.5f;
y1234 = (y123+y234)*0.5f;

m1742HyZCSmidjHt1aLG3XCs8HpJrLG3NznSHbvcg(ctx, x1,y1, x12,y12, x123,y123, x1234,y1234, level+1, 0);
m1742HyZCSmidjHt1aLG3XCs8HpJrLG3NznSHbvcg(ctx, x1234,y1234, x234,y234, x34,y34, x4,y4, level+1, mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P);
}

static void mV5rTfWhQZKlvt5SX150tIo5XVSS9KVl5o8eIEVwC(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* cache = ctx->cache;
//mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* last;
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0;
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1;
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts;
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path;
int i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
float* cp1;
float* cp2;
float* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
float mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5;

if (cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz > 0)
return;

// Flatten
i = 0;
while (i < ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD) {
int cmd = (int)ctx->commands[i];
switch (cmd) {
case MRKUI_MOVETO:
mdBQv0CMmq1RDryTlHBwUyeRtRNhZ1aBCxts2TswQ(ctx);
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = &ctx->commands[i+1];
mAqcXVfTK2g0ICBiShd24XYaDHHVSjtDmOuyiZ5cz(ctx, mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0], mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1], MRKUI_PT_CORNER);
i += 3;
break;
case MRKUI_LINETO:
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = &ctx->commands[i+1];
mAqcXVfTK2g0ICBiShd24XYaDHHVSjtDmOuyiZ5cz(ctx, mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0], mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1], MRKUI_PT_CORNER);
i += 3;
break;
case MRKUI_BEZIERTO:
last = mJ0PvP1XUGTCHJYO1a0yvuw0WSJNaR7S3Qi2aaAYl(ctx);
if (last != NULL) {
cp1 = &ctx->commands[i+1];
cp2 = &ctx->commands[i+3];
mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = &ctx->commands[i+5];
m1742HyZCSmidjHt1aLG3XCs8HpJrLG3NznSHbvcg(ctx, last->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,last->y, cp1[0],cp1[1], cp2[0],cp2[1], mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0],mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1], 0, MRKUI_PT_CORNER);
}
i += 7;
break;
case MRKUI_CLOSE:
mx5qBWlJtABEJ4FJDZsPVvX7Y4dnjKDT3qS6JUUFE(ctx);
i++;
break;
case MRKUI_WINDING:
mO22PUT6h6zQ7Y1cXaDb9udJzcS0E34YuaqkZOvIA(ctx, (int)ctx->commands[i+1]);
i += 2;
break;
default:
i++;
}
}

cache->bounds[0] = cache->bounds[1] = 1e6f;
cache->bounds[2] = cache->bounds[3] = -1e6f;

// Calculate the mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 length of line segments.
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++) {
path = &cache->paths[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
pts = &cache->points[path->first];

// If the first mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 last points are the same, remove the last, mark as mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj path.
p0 = &pts[path->count-1];
p1 = &pts[0];
if (mqHqyXB2TLTbAM6HA9eDlAL4XuYdMjFLQD7FkhN9k(p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,p0->y, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,p1->y, ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb)) {
path->count--;
p0 = &pts[path->count-1];
path->mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj = 1;
}

// Enforce mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94.
if (path->count > 2) {
mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 = mCVpwd9DznEC0mS6WwaVJON90ALcHIZk0ShfiXAwe(pts, path->count);
if (path->mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 == MRKUI_CCW && mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 < 0.0f)
mZrokIVmchzwBCWnYu42rv1xXOgpbhByedzGE7Au2(pts, path->count);
if (path->mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 == MRKUI_CW && mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 > 0.0f)
mZrokIVmchzwBCWnYu42rv1xXOgpbhByedzGE7Au2(pts, path->count);
}

for(i = 0; i < path->count; i++) {
// Calculate segment mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 length
p0->dx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
p0->dy = p1->y - p0->y;
p0->mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(&p0->dx, &p0->dy);
// mbBQQ8ZjGGb7I3F8fGa9qidkv5yrSsg9OPwC13uDV bounds
cache->bounds[0] = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(cache->bounds[0], p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
cache->bounds[1] = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(cache->bounds[1], p0->y);
cache->bounds[2] = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(cache->bounds[2], p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
cache->bounds[3] = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(cache->bounds[3], p0->y);
// Advance
p0 = p1++;
}
}
}

static int m0rXpFfhu6GIB877UM3H1k7EDJOpsPA8fU34hIgR9(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float arc, float tol)
{
float da = acosf(mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC / (mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC + tol)) * 2.0f;
return mgCoMyFRbHuDdYAjINJzNO2R079lIEhBeV9rFRghN(2, (int)ceilf(arc / da));
}

static void mHXU0FORKyNhAQvkf6h8XoX3tO7wAfqsBmvWUx9yj(int bevel, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1, float w,
float* x0, float* y0, float* x1, float* y1)
{
if (bevel) {
*x0 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p0->dy * w;
*y0 = p1->y - p0->dx * w;
*x1 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p1->dy * w;
*y1 = p1->y - p1->dx * w;
} else {
*x0 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p1->dmx * w;
*y0 = p1->y + p1->dmy * w;
*x1 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p1->dmx * w;
*y1 = p1->y + p1->dmy * w;
}
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mmpT8Bfg2P9gw4Llf695ni8qSLQtIlP5bx3cnVwmO(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1,
 float lw, float rw, float lu, float ru, int ncap,
 float fringe)
{
int i, n;
float dlx0 = p0->dy;
float dly0 = -p0->dx;
float dlx1 = p1->dy;
float dly1 = -p1->dx;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(fringe);

if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_LEFT) {
float lx0,ly0,lx1,ly1,a0,a1;
mHXU0FORKyNhAQvkf6h8XoX3tO7wAfqsBmvWUx9yj(p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PR_INNERBEVEL, p0, p1, lw, &lx0,&ly0, &lx1,&ly1);
a0 = atan2f(-dly0, -dlx0);
a1 = atan2f(-dly1, -dlx1);
if (a1 > a0) a1 -= MRKUI_PI*2;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx0*rw, p1->y - dly0*rw, ru,1); dst++;

n = mVfnT846VCmTTQDz8FiMNea5JkFD6R80gxER7uNMP((int)ceilf(((a0 - a1) / MRKUI_PI) * ncap), 2, ncap);
for (i = 0; i < n; i++) {
float u = i/(float)(n-1);
float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = a0 + u*(a1-a0);
float rx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + cosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * rw;
float ry = p1->y + sinf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * rw;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx, ry, ru,1); dst++;
}

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx1, ly1, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx1*rw, p1->y - dly1*rw, ru,1); dst++;

} else {
float rx0,ry0,rx1,ry1,a0,a1;
mHXU0FORKyNhAQvkf6h8XoX3tO7wAfqsBmvWUx9yj(p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PR_INNERBEVEL, p0, p1, -rw, &rx0,&ry0, &rx1,&ry1);
a0 = atan2f(dly0, dlx0);
a1 = atan2f(dly1, dlx1);
if (a1 < a0) a1 += MRKUI_PI*2;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx0*rw, p1->y + dly0*rw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx0, ry0, ru,1); dst++;

n = mVfnT846VCmTTQDz8FiMNea5JkFD6R80gxER7uNMP((int)ceilf(((a1 - a0) / MRKUI_PI) * ncap), 2, ncap);
for (i = 0; i < n; i++) {
float u = i/(float)(n-1);
float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = a0 + u*(a1-a0);
float lx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + cosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * lw;
float ly = p1->y + sinf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * lw;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx, ly, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;
}

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx1*rw, p1->y + dly1*rw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx1, ry1, ru,1); dst++;

}
return dst;
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mZhCwSiEh8ZcapVJFRSoqGNOe4KCa4eCJQCKhWxE8(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1,
float lw, float rw, float lu, float ru, float fringe)
{
float rx0,ry0,rx1,ry1;
float lx0,ly0,lx1,ly1;
float dlx0 = p0->dy;
float dly0 = -p0->dx;
float dlx1 = p1->dy;
float dly1 = -p1->dx;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(fringe);

if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_LEFT) {
mHXU0FORKyNhAQvkf6h8XoX3tO7wAfqsBmvWUx9yj(p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PR_INNERBEVEL, p0, p1, lw, &lx0,&ly0, &lx1,&ly1);

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx0*rw, p1->y - dly0*rw, ru,1); dst++;

if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_BEVEL) {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx0*rw, p1->y - dly0*rw, ru,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx1, ly1, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx1*rw, p1->y - dly1*rw, ru,1); dst++;
} else {
rx0 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - p1->dmx * rw;
ry0 = p1->y - p1->dmy * rw;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx0*rw, p1->y - dly0*rw, ru,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx0, ry0, ru,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx0, ry0, ru,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx1*rw, p1->y - dly1*rw, ru,1); dst++;
}

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx1, ly1, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dlx1*rw, p1->y - dly1*rw, ru,1); dst++;

} else {
mHXU0FORKyNhAQvkf6h8XoX3tO7wAfqsBmvWUx9yj(p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PR_INNERBEVEL, p0, p1, -rw, &rx0,&ry0, &rx1,&ry1);

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx0*lw, p1->y + dly0*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx0, ry0, ru,1); dst++;

if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_BEVEL) {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx0*lw, p1->y + dly0*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx0, ry0, ru,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx1*lw, p1->y + dly1*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx1, ry1, ru,1); dst++;
} else {
lx0 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p1->dmx * lw;
ly0 = p1->y + p1->dmy * lw;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx0*lw, p1->y + dly0*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, lu,1); dst++;

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx1*lw, p1->y + dly1*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, p1->y, 0.5f,1); dst++;
}

mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx1*lw, p1->y + dly1*lw, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, rx1, ry1, ru,1); dst++;
}

return dst;
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* myUO1z1r1cTsqxzL8dwVicoDFRQBFHDFYH4yYHK0b(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,
float dx, float dy, float w, float d,
float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, float u0, float u1)
{
float px = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - dx*d;
float py = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->y - dy*d;
float dlx = dy;
float dly = -dx;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w - dx*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, py + dly*w - dy*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0,0); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w - dx*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, py - dly*w - dy*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u1,0); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w, py + dly*w, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w, py - dly*w, u1,1); dst++;
return dst;
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* m9zK4Wm1Imadz1D3LcAqB0M4r8Xt8G55FbvHKMsdc(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,
  float dx, float dy, float w, float d,
  float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, float u0, float u1)
{
float px = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dx*d;
float py = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->y + dy*d;
float dlx = dy;
float dly = -dx;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w, py + dly*w, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w, py - dly*w, u1,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w + dx*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, py + dly*w + dy*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0,0); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w + dx*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, py - dly*w + dy*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u1,0); dst++;
return dst;
}


static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mGpWQANCseSLZdqJM2yT5Q9rlyB1TXn7uuoPtvhDW(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,
 float dx, float dy, float w, int ncap,
 float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, float u0, float u1)
{
int i;
float px = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
float py = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->y;
float dlx = dy;
float dly = -dx;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro);
for (i = 0; i < ncap; i++) {
float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = i/(float)(ncap-1)*MRKUI_PI;
float ax = cosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * w, ay = sinf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * w;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*ax - dx*ay, py - dly*ax - dy*ay, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px, py, 0.5f,1); dst++;
}
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w, py + dly*w, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w, py - dly*w, u1,1); dst++;
return dst;
}

static mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mw8weIzexlEuq1EacbgKrkatMk8tjhFZ9QBXhupa6(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst, mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,
   float dx, float dy, float w, int ncap,
   float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, float u0, float u1)
{
int i;
float px = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
float py = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->y;
float dlx = dy;
float dly = -dx;
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro);
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px + dlx*w, py + dly*w, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*w, py - dly*w, u1,1); dst++;
for (i = 0; i < ncap; i++) {
float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = i/(float)(ncap-1)*MRKUI_PI;
float ax = cosf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * w, ay = sinf(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c) * w;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px, py, 0.5f,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, px - dlx*ax + dx*ay, py - dly*ax + dy*ay, u0,1); dst++;
}
return dst;
}


static void meXfOR4DDaJliFAd5r1MKSHagG37zNLbu163nDnRc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float w, int m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, float m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2)
{
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* cache = ctx->cache;
int i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
float iw = 0.0f;

if (w > 0.0f) iw = 1.0f / w;

// Calculate which joins needs extra vertices myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT append, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 gather vertex count.
for (i = 0; i < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &cache->paths[i];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts = &cache->points[path->first];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0 = &pts[path->count-1];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1 = &pts[0];
int nleft = 0;

path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4 = 0;

for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->count; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++) {
float dlx0, dly0, dlx1, dly1, dmr2, cross, limit;
dlx0 = p0->dy;
dly0 = -p0->dx;
dlx1 = p1->dy;
dly1 = -p1->dx;
// Calculate extrusions
p1->dmx = (dlx0 + dlx1) * 0.5f;
p1->dmy = (dly0 + dly1) * 0.5f;
dmr2 = p1->dmx*p1->dmx + p1->dmy*p1->dmy;
if (dmr2 > 0.1f) {
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = 1.0f / dmr2;
if (ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy > 600.0f) {
ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = 600.0f;
}
p1->dmx *= ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
p1->dmy *= ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
}

// Clear m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf, but keep the corner.
p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_CORNER) ? MRKUI_PT_CORNER : 0;

// Keep track of left turns.
cross = p1->dx * p0->dy - p0->dx * p1->dy;
if (cross > 0.0f) {
nleft++;
p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf |= MRKUI_PT_LEFT;
}

// Calculate if we should mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA bevel or miter for inner join.
limit = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(1.1f, mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(p0->mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, p1->mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0) * iw);
if ((dmr2 * limit*limit) < 1.0f)
p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf |= MRKUI_PR_INNERBEVEL;

// Check myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT see if the corner needs myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be beveled.
if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_CORNER) {
if ((dmr2 * m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2*m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2) < 1.0f || m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY == MRKUI_BEVEL || m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY == MRKUI_ROUND) {
p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf |= MRKUI_PT_BEVEL;
}
}

if ((p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0)
path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4++;

p0 = p1++;
}

path->m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1 = (nleft == path->count) ? 1 : 0;
}
}


static int mS7Ztf4j3gPwIddcQJuRzS358g1XMYOXLjXKUJyNc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float w, float fringe, int mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp, int m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, float m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2)
{
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* cache = ctx->cache;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3, i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro = fringe;//ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6;
float u0 = 0.0f, u1 = 1.0f;
int ncap = m0rXpFfhu6GIB877UM3H1k7EDJOpsPA8fU34hIgR9(w, MRKUI_PI, ctx->mziHAAeKGzrAkkc2tK3CdiMpI0gvhiCLmdzioKQzR);// Calculate divisions per half circle.

w += mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro * 0.5f;

// Disable the gradient used for antialiasing when antialiasing is not used.
if (mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro == 0.0f) {
u0 = 0.5f;
u1 = 0.5f;
}

meXfOR4DDaJliFAd5r1MKSHagG37zNLbu163nDnRc(ctx, w, m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2);

// Calculate max vertex usage.
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = 0;
for (i = 0; i < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &cache->paths[i];
int loop = (path->mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj == 0) ? 0 : 1;
if (m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY == MRKUI_ROUND)
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += (path->count + path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4*(ncap+2) + 1) * 2; // plus one for loop
else
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += (path->count + path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4*5 + 1) * 2; // plus one for loop
if (loop == 0) {
// space for caps
if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == MRKUI_ROUND) {
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += (ncap*2 + 2)*2;
} else {
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += (3+3)*2;
}
}
}

verts = mqfnGNKHGOJHaKOQc59rZ1Ao6s2sdIuhWkWUeFvdl(ctx, m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3);
if (verts == NULL) return 0;

for (i = 0; i < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &cache->paths[i];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts = &cache->points[path->first];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0;
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1;
int s, e, loop;
float dx, dy;

path->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB = 0;
path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ = 0;

// Calculate fringe or mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6
loop = (path->mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj == 0) ? 0 : 1;
dst = verts;
path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 = dst;

if (loop) {
// Looping
p0 = &pts[path->count-1];
p1 = &pts[0];
s = 0;
e = path->count;
} else {
// Add cap
p0 = &pts[0];
p1 = &pts[1];
s = 1;
e = path->count-1;
}

if (loop == 0) {
// Add cap
dx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
dy = p1->y - p0->y;
m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(&dx, &dy);
if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l)
dst = myUO1z1r1cTsqxzL8dwVicoDFRQBFHDFYH4yYHK0b(dst, p0, dx, dy, w, -mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro*0.5f, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
else if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l || mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == MRKUI_SQUARE)
dst = myUO1z1r1cTsqxzL8dwVicoDFRQBFHDFYH4yYHK0b(dst, p0, dx, dy, w, w-mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
else if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == MRKUI_ROUND)
dst = mGpWQANCseSLZdqJM2yT5Q9rlyB1TXn7uuoPtvhDW(dst, p0, dx, dy, w, ncap, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
}

for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = s; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < e; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
if ((p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0) {
if (m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY == MRKUI_ROUND) {
dst = mmpT8Bfg2P9gw4Llf695ni8qSLQtIlP5bx3cnVwmO(dst, p0, p1, w, w, u0, u1, ncap, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro);
} else {
dst = mZhCwSiEh8ZcapVJFRSoqGNOe4KCa4eCJQCKhWxE8(dst, p0, p1, w, w, u0, u1, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro);
}
} else {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (p1->dmx * w), p1->y + (p1->dmy * w), u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - (p1->dmx * w), p1->y - (p1->dmy * w), u1,1); dst++;
}
p0 = p1++;
}

if (loop) {
// Loop it
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, verts[0].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, verts[0].y, u0,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, verts[1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, verts[1].y, u1,1); dst++;
} else {
// Add cap
dx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - p0->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
dy = p1->y - p0->y;
m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(&dx, &dy);
if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l)
dst = m9zK4Wm1Imadz1D3LcAqB0M4r8Xt8G55FbvHKMsdc(dst, p1, dx, dy, w, -mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro*0.5f, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
else if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l || mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == MRKUI_SQUARE)
dst = m9zK4Wm1Imadz1D3LcAqB0M4r8Xt8G55FbvHKMsdc(dst, p1, dx, dy, w, w-mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
else if (mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp == MRKUI_ROUND)
dst = mw8weIzexlEuq1EacbgKrkatMk8tjhFZ9QBXhupa6(dst, p1, dx, dy, w, ncap, mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro, u0, u1);
}

path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza = (int)(dst - verts);

verts = dst;
}

return 1;
}

static int mrie5bdf4mpWgVU0Ab7xHZEAZKbZ7NNNjPrQNBPtY(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float w, int m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, float m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2)
{
mXt7YsIfeNqSgl8wnWTYDndBYOj4ER0xmTpURwtjx* cache = ctx->cache;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* dst;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3, m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1, i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
float mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro = ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6;
int fringe = w > 0.0f;

meXfOR4DDaJliFAd5r1MKSHagG37zNLbu163nDnRc(ctx, w, m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2);

// Calculate max vertex usage.
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = 0;
for (i = 0; i < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &cache->paths[i];
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += path->count + path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4 + 1;
if (fringe)
m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 += (path->count + path->mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4*5 + 1) * 2; // plus one for loop
}

verts = mqfnGNKHGOJHaKOQc59rZ1Ao6s2sdIuhWkWUeFvdl(ctx, m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3);
if (verts == NULL) return 0;

m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1 = cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz == 1 && cache->paths[0].m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1;

for (i = 0; i < cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &cache->paths[i];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* pts = &cache->points[path->first];
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p0;
mNKYc2zIjDW4PeskfGKJiK7s0KDQ9uX54FvhZNAAq* p1;
float rw, lw, woff;
float ru, lu;

// Calculate shape vertices.
woff = 0.5f*mEfQknglnijwa0f1kkewnm54u4wJdDKPH03RQHHro;
dst = verts;
path->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB = dst;

if (fringe) {
// Looping
p0 = &pts[path->count-1];
p1 = &pts[0];
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->count; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_BEVEL) {
float dlx0 = p0->dy;
float dly0 = -p0->dx;
float dlx1 = p1->dy;
float dly1 = -p1->dx;
if (p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_PT_LEFT) {
float lx = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + p1->dmx * woff;
float ly = p1->y + p1->dmy * woff;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx, ly, 0.5f,1); dst++;
} else {
float lx0 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx0 * woff;
float ly0 = p1->y + dly0 * woff;
float lx1 = p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + dlx1 * woff;
float ly1 = p1->y + dly1 * woff;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx0, ly0, 0.5f,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, lx1, ly1, 0.5f,1); dst++;
}
} else {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (p1->dmx * woff), p1->y + (p1->dmy * woff), 0.5f,1); dst++;
}
p0 = p1++;
}
} else {
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->count; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, pts[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, pts[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y, 0.5f,1);
dst++;
}
}

path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ = (int)(dst - verts);
verts = dst;

// Calculate fringe
if (fringe) {
lw = w + woff;
rw = w - woff;
lu = 0;
ru = 1;
dst = verts;
path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 = dst;

// Create only half mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c fringe for m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1 shapes so that
// the shape can be rendered without stenciling.
if (m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1) {
lw = woff;// This should generate the same vertex as m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB inset above.
lu = 0.5f;// Set outline fade at middle.
}

// Looping
p0 = &pts[path->count-1];
p1 = &pts[0];

for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->count; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
if ((p1->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (MRKUI_PT_BEVEL | MRKUI_PR_INNERBEVEL)) != 0) {
dst = mZhCwSiEh8ZcapVJFRSoqGNOe4KCa4eCJQCKhWxE8(dst, p0, p1, lw, rw, lu, ru, ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6);
} else {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (p1->dmx * lw), p1->y + (p1->dmy * lw), lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, p1->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - (p1->dmx * rw), p1->y - (p1->dmy * rw), ru,1); dst++;
}
p0 = p1++;
}

// Loop it
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, verts[0].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, verts[0].y, lu,1); dst++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(dst, verts[1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, verts[1].y, ru,1); dst++;

path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza = (int)(dst - verts);
verts = dst;
} else {
path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 = NULL;
path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza = 0;
}
}

return 1;
}


// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD
void m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD = 0;
m3yOUApBzGy9SDxwv8gEb7IjoklzKzBAPzIT5XCpX(ctx);
}

void mnXY5sFv1yWENQJH4Cfds6nQTfYQ1YEOdmrKRBoIh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
float vals[] = { MRKUI_MOVETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y };
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mnvQT0XESunqaW0WDt1e3i5Afxvr2I0HeVciDi9qR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
float vals[] = { MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y };
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void maIlF1yQjLFyjdQrK54pywyvSsM3PdRFPp6wifS7V(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float c1x, float c1y, float c2x, float c2y, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
float vals[] = { MRKUI_BEZIERTO, c1x, c1y, c2x, c2y, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y };
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mDPFPb3pHtj5N2Ncf0Ep7QJcGDdCEboxRFbmYjWRh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
    float x0 = ctx->commandx;
    float y0 = ctx->commandy;
    float vals[] = { MRKUI_BEZIERTO,
        x0 + 2.0f/3.0f*(cx - x0), y0 + 2.0f/3.0f*(cy - y0),
        m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + 2.0f/3.0f*(cx - m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp), y + 2.0f/3.0f*(cy - y),
        m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y };
    mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mM3OSf7JThNjD61wm18Eijghjq8TZ4XgFyclkcHzc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float x1, float y1, float x2, float y2, float mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA)
{
float x0 = ctx->commandx;
float y0 = ctx->commandy;
float dx0,dy0, dx1,dy1, mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, d, cx,cy, a0,a1;
int mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG;

if (ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD == 0) {
return;
}

// Handle degenerate cases.
if (mqHqyXB2TLTbAM6HA9eDlAL4XuYdMjFLQD7FkhN9k(x0,y0, x1,y1, ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb) ||
mqHqyXB2TLTbAM6HA9eDlAL4XuYdMjFLQD7FkhN9k(x1,y1, x2,y2, ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb) ||
mYAvY1AcF8A0KwXayQhwvoqra9Mk27fO2i1joAG0c(x1,y1, x0,y0, x2,y2) < ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb*ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb ||
mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA < ctx->mkU5709fCEuZspMVUqObCVROhXwjIx40IRqa1fLhb) {
mnvQT0XESunqaW0WDt1e3i5Afxvr2I0HeVciDi9qR(ctx, x1,y1);
return;
}

// Calculate tangential circle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT m5RtqEm8VqdvN2MxHFxp8N6bkwFEegsbelmVWAFCI (x0,y0)-(x1,y1) mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 (x1,y1)-(x2,y2).
dx0 = x0-x1;
dy0 = y0-y1;
dx1 = x2-x1;
dy1 = y2-y1;
m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(&dx0,&dy0);
m2WeFX18JuXTLFyOxmcr0Ei96vVGzxuPI68PpVPBj(&dx1,&dy1);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = mmXtYEuimylMdcA5e0fpvRq3qXiTju6plErrrO4Kz(dx0*dx1 + dy0*dy1);
d = mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA / mQ39wHsdMvzdiXn4Itgs0uH570ySzuTHVuHH5Yuka(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c/2.0f);

//printf("a=%f° d=%f\n", mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c/MRKUI_PI*180.0f, d);

if (d > 10000.0f) {
mnvQT0XESunqaW0WDt1e3i5Afxvr2I0HeVciDi9qR(ctx, x1,y1);
return;
}

if (m9fuCA1PHxZkqWkwO7uoWOGEGshXZK35kpDugFr3k(dx0,dy0, dx1,dy1) > 0.0f) {
cx = x1 + dx0*d + dy0*mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
cy = y1 + dy0*d + -dx0*mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
a0 = mjXw8I9wlCCuzROlquTAJL3mUXr5YMFbYGQJKNLT7(dx0, -dy0);
a1 = mjXw8I9wlCCuzROlquTAJL3mUXr5YMFbYGQJKNLT7(-dx1, dy1);
mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG = MRKUI_CW;
//printf("CW c=(%f, %f) a0=%f° a1=%f°\n", cx, cy, a0/MRKUI_PI*180.0f, a1/MRKUI_PI*180.0f);
} else {
cx = x1 + dx0*d + -dy0*mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
cy = y1 + dy0*d + dx0*mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
a0 = mjXw8I9wlCCuzROlquTAJL3mUXr5YMFbYGQJKNLT7(-dx0, dy0);
a1 = mjXw8I9wlCCuzROlquTAJL3mUXr5YMFbYGQJKNLT7(dx1, -dy1);
mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG = MRKUI_CCW;
//printf("CCW c=(%f, %f) a0=%f° a1=%f°\n", cx, cy, a0/MRKUI_PI*180.0f, a1/MRKUI_PI*180.0f);
}

m2lRILpDMm6QDNwKu9HDaQpGldexernFQzFbEnHq3(ctx, cx, cy, mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA, a0, a1, mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG);
}

void ms07Giq2JzZ7IGMZgUiMKM4Ji21IsaTrCq6IbdeSz(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
float vals[] = { MRKUI_CLOSE };
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mMpOiLjNtM3NKwGDIVibdVvuR4j5kOSi2F4HtykIa(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG)
{
float vals[] = { MRKUI_WINDING, (float)mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG };
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void m2lRILpDMm6QDNwKu9HDaQpGldexernFQzFbEnHq3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float a0, float a1, int mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG)
{
float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = 0, da = 0, hda = 0, kappa = 0;
float dx = 0, dy = 0, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0, y = 0, tanx = 0, tany = 0;
float px = 0, py = 0, ptanx = 0, ptany = 0;
float vals[3 + 5*7 + 100];
int i, ndivs, nvals;
int move = ctx->mTymron5VWB462Jn9cztSNjVFeaAcRHRBerbVcJJD > 0 ? MRKUI_LINETO : MRKUI_MOVETO;

// mSJi5DgfL6Oz62AYnDMSAboOd6C8hZ64nKWNw0fpq angles
da = a1 - a0;
if (mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG == MRKUI_CW) {
if (muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(da) >= MRKUI_PI*2) {
da = MRKUI_PI*2;
} else {
while (da < 0.0f) da += MRKUI_PI*2;
}
} else {
if (muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(da) >= MRKUI_PI*2) {
da = -MRKUI_PI*2;
} else {
while (da > 0.0f) da -= MRKUI_PI*2;
}
}

// Split arc into max 90 degree segments.
ndivs = mgCoMyFRbHuDdYAjINJzNO2R079lIEhBeV9rFRghN(1, mwn5BwslpF4AZUQMAIJOptupfaIKvJS8rQTZyr0Me((int)(muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(da) / (MRKUI_PI*0.5f) + 0.5f), 5));
hda = (da / (float)ndivs) / 2.0f;
kappa = muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(4.0f / 3.0f * (1.0f - mfeJdBfFJpRCwIL7NByGaaQQ69zcbyzH41fKAyv62(hda)) / mMSQtaqCwNJ9lLbDjdVHjGfn2E9x0vwN628QCXVA9(hda));

if (mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG == MRKUI_CCW)
kappa = -kappa;

nvals = 0;
for (i = 0; i <= ndivs; i++) {
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = a0 + da * (i/(float)ndivs);
dx = mfeJdBfFJpRCwIL7NByGaaQQ69zcbyzH41fKAyv62(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);
dy = mMSQtaqCwNJ9lLbDjdVHjGfn2E9x0vwN628QCXVA9(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = cx + dx*mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;
y = cy + dy*mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;
tanx = -dy*mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC*kappa;
tany = dx*mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC*kappa;

if (i == 0) {
vals[nvals++] = (float)move;
vals[nvals++] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
vals[nvals++] = y;
} else {
vals[nvals++] = MRKUI_BEZIERTO;
vals[nvals++] = px+ptanx;
vals[nvals++] = py+ptany;
vals[nvals++] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp-tanx;
vals[nvals++] = y-tany;
vals[nvals++] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
vals[nvals++] = y;
}
px = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
py = y;
ptanx = tanx;
ptany = tany;
}

mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, nvals);
}

void mbdzVdcmDPpti0WQVy5cqYRzWcIAY8juY3gINMaKR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h)
{
float vals[] = {
MRKUI_MOVETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y+h,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w,y+h,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w,y,
MRKUI_CLOSE
};
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mfEKIaL94HRGW1PVm6mFSruo4HDpunzmJoIspWRcu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC)
{
mGrvPRwH9AWqJLHf8VhulgE3a7PTI8nocuAuYJ6i1(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, w, h, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC);
}

void mGrvPRwH9AWqJLHf8VhulgE3a7PTI8nocuAuYJ6i1(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft)
{
if(radTopLeft < 0.1f && radTopRight < 0.1f && radBottomRight < 0.1f && radBottomLeft < 0.1f) {
mbdzVdcmDPpti0WQVy5cqYRzWcIAY8juY3gINMaKR(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, w, h);
return;
} else {
float halfw = muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(w)*0.5f;
float halfh = muSd7puHO2VduHCeBHG6vwPtFKGrPtdXKkrgqJjYB(h)*0.5f;
float rxBL = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radBottomLeft, halfw) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(w), ryBL = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radBottomLeft, halfh) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(h);
float rxBR = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radBottomRight, halfw) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(w), ryBR = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radBottomRight, halfh) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(h);
float rxTR = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radTopRight, halfw) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(w), ryTR = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radTopRight, halfh) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(h);
float rxTL = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radTopLeft, halfw) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(w), ryTL = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(radTopLeft, halfh) * m1ENrYcjxSF8glHEi9RAVZuodpJuhgyTNOS8AcqOS(h);
float vals[] = {
MRKUI_MOVETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y + ryTL,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y + h - ryBL,
MRKUI_BEZIERTO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y + h - ryBL*(1 - MRKUI_KAPPA90), m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + rxBL*(1 - MRKUI_KAPPA90), y + h, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + rxBL, y + h,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w - rxBR, y + h,
MRKUI_BEZIERTO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w - rxBR*(1 - MRKUI_KAPPA90), y + h, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w, y + h - ryBR*(1 - MRKUI_KAPPA90), m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w, y + h - ryBR,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w, y + ryTR,
MRKUI_BEZIERTO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w, y + ryTR*(1 - MRKUI_KAPPA90), m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w - rxTR*(1 - MRKUI_KAPPA90), y, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w - rxTR, y,
MRKUI_LINETO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + rxTL, y,
MRKUI_BEZIERTO, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + rxTL*(1 - MRKUI_KAPPA90), y, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y + ryTL*(1 - MRKUI_KAPPA90), m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y + ryTL,
MRKUI_CLOSE
};
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}
}

void mdswyh7B2rHkksI3POM6yOQ4jmTJozgo0AaNKD4z8(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float rx, float ry)
{
float vals[] = {
MRKUI_MOVETO, cx-rx, cy,
MRKUI_BEZIERTO, cx-rx, cy+ry*MRKUI_KAPPA90, cx-rx*MRKUI_KAPPA90, cy+ry, cx, cy+ry,
MRKUI_BEZIERTO, cx+rx*MRKUI_KAPPA90, cy+ry, cx+rx, cy+ry*MRKUI_KAPPA90, cx+rx, cy,
MRKUI_BEZIERTO, cx+rx, cy-ry*MRKUI_KAPPA90, cx+rx*MRKUI_KAPPA90, cy-ry, cx, cy-ry,
MRKUI_BEZIERTO, cx-rx*MRKUI_KAPPA90, cy-ry, cx-rx, cy-ry*MRKUI_KAPPA90, cx-rx, cy,
MRKUI_CLOSE
};
mmP8FwL5MC1B5g7lE2ox5gXIf0BmiLuoNCjZMbZYe(ctx, vals, mm3LCpxyphdk4x1fbHvDHs8xScZzDiWnEETXmdTZF(vals));
}

void mHFyOk07XkLTtFw0zawwr10sM43Bn57rxgfN7QgDK(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC)
{
mdswyh7B2rHkksI3POM6yOQ4jmTJozgo0AaNKD4z8(ctx, cx,cy, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC,mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC);
}

void mXBTgV2Be9oifB3yCBGvWvMZlummY106SmVme4Aby(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path;
int i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;

printf("Dumping %d cached paths\n", ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
for (i = 0; i < ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
path = &ctx->cache->paths[i];
printf(" - Path %d\n", i);
if (path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ) {
printf("   - fill: %d\n", path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ);
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++)
printf("%f\t%f\n", path->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, path->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y);
}
if (path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza) {
printf("   - stroke: %d\n", path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza);
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++)
printf("%f\t%f\n", path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y);
}
}
}

void mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path;
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ fillPaint = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB;
int i;

mV5rTfWhQZKlvt5SX150tIo5XVSS9KVl5o8eIEVwC(ctx);
if (ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mdFwDLRZbeFsqCZz9pURAan4Yu9PfxsoA1NcxRnS8 && msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mftQzTDkY1Dx2hMZ2PWrh9yegLKRDHSfRom5AUIiH)
mrie5bdf4mpWgVU0Ab7xHZEAZKbZ7NNNjPrQNBPtY(ctx, ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6, mjfUTlQL3XpQ7EwiEeHSDb9DH1Op1wf5z3UIoyM58, 2.4f);
else
mrie5bdf4mpWgVU0Ab7xHZEAZKbZ7NNNjPrQNBPtY(ctx, 0.0f, mjfUTlQL3XpQ7EwiEeHSDb9DH1Op1wf5z3UIoyM58, 2.4f);

// Apply global mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E
fillPaint.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
fillPaint.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;

ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderFill(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, &fillPaint, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, &msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6,
   ctx->cache->bounds, ctx->cache->paths, ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);

// Count triangles
for (i = 0; i < ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
path = &ctx->cache->paths[i];
ctx->mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb += path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ-2;
ctx->mt405vd7M8fi8wQdxg630cGvoLMf2RcLj0PecrLFb += path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza-2;
ctx->mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF += 2;
}
}

void m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = m4XTfrbNMHdOmsI2jxFrqbF3s3H2OXwfPboJFZdNg(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform);
float mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa * ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, 0.0f, 200.0f);
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ strokePaint = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6;
const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path;
int i;


if (mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa < ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6) {
// If the mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn is less than pixel size, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT emulate coverage.
// Since coverage is mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy by mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E*mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E.
float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E = mxdANv9NS279L8Fg079gBg43jN4rEKYIFEqkhuNxH(mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa / ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6, 0.0f, 1.0f);
strokePaint.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E*mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
strokePaint.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E*mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa = ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6;
}

// Apply global mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E
strokePaint.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
strokePaint.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;

mV5rTfWhQZKlvt5SX150tIo5XVSS9KVl5o8eIEVwC(ctx);

if (ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mdFwDLRZbeFsqCZz9pURAan4Yu9PfxsoA1NcxRnS8 && msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mftQzTDkY1Dx2hMZ2PWrh9yegLKRDHSfRom5AUIiH)
mS7Ztf4j3gPwIddcQJuRzS358g1XMYOXLjXKUJyNc(ctx, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa*0.5f, ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2);
else
mS7Ztf4j3gPwIddcQJuRzS358g1XMYOXLjXKUJyNc(ctx, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa*0.5f, 0.0f, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mJv7lniCliD9o2jCIgwwq0J7NggbR5inpdV37faZp, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m4pYGdjaO6B11orBYLN1xNvlAMlu3PQWBlwkWHlpY, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m8usiOpNymp73hdsTL9RanNM7SsXxwTfM9dThmui2);

ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderStroke(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, &strokePaint, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, &msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, ctx->mQwPCea3SAKl5kW7oYA5J1SsBLRY25onZpwCVMAZ6,
 mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, ctx->cache->paths, ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);

// Count triangles
for (i = 0; i < ctx->cache->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
path = &ctx->cache->paths[i];
ctx->m7xL4X4USglv3XzU0HThAgGypV5Y39BZO5e4vkjy7 += path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza-2;
ctx->mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF++;
}
}

// Add fonts
int mbskZGF4cD9os92z8lNen3B8rdAeQFBnJMClX0tQk(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name, const char* path)
{
return mJRBeC21nobd9NV6L8lzOus5k5PXtlIK5jZxqknQJ(ctx->fs, name, path);
}

int mbJ3kB9gPNC1YiAZVvHGaan3n6En5fXdPGDP2dGXq(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name, unsigned char* data, int ndata, int m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs)
{
return mlHxLh07uUuA4qDyLtpqLXteafiyEOTVNgcqcKpaQ(ctx->fs, name, data, ndata, m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs);
}

int mJNOhvufOnyeEOedMkPmdvoNWVrjPBUKDID1O6PGw(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name)
{
if (name == NULL) return -1;
return mrddbNZB0tEIa2rZcntIh3ekWxwXkQOpwSaH8Aext(ctx->fs, name);
}


int ms8YvT518GOoXhraGol4MvxdXcuArkka49UW8fKJo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int baseFont, int fallbackFont)
{
if(baseFont == -1 || fallbackFont == -1) return 0;
return mIJMalRGBWWh8eBLqZNhPtwapG9nukapS14BWeZQy(ctx->fs, baseFont, fallbackFont);
}

int mszOMbQOEAEG6nyfRYCqz9p2ydGYflvGR5zYNQR6R(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* baseFont, const char* fallbackFont)
{
return ms8YvT518GOoXhraGol4MvxdXcuArkka49UW8fKJo(ctx, mJNOhvufOnyeEOedMkPmdvoNWVrjPBUKDID1O6PGw(ctx, baseFont), mJNOhvufOnyeEOedMkPmdvoNWVrjPBUKDID1O6PGw(ctx, fallbackFont));
}

// State setting
void mjNjN168G2bSWj18cM4zcrPY7ni4eaiYrbzWELo06(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float size)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0 = size;
}

void mxjmFUvEoFJbhg2lPQS55TvXUj7bSzWU8jCCCCQUo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0 = m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
}

void m9Dcq9MVgxDLCmEaTH50A5jd486udOmW5pQR50Loh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp = mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s;
}

void m64byjh6deGqridOdonlIETpOqijhLAqPyPxMg8mV(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi = mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi;
}

void mycndqGrNMF9dZ5US9CfM249LUbM2GP2pD1APR4Nr(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz;
}

void merC4jTWVp3RwPCCSrTZkKxjzwJzOSa0cOHjdUbgW(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
}

void mGsQx3ATSmaIicqFfQwJiZrqi6Wlf57qZbKidHsNn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK = mrddbNZB0tEIa2rZcntIh3ekWxwXkQOpwSaH8Aext(ctx->fs, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);
}

static float mm5ESMSeQmWFxkwsYNXP9Rz0ZfEseM7tmGlG1T63Z(float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float d)
{
return ((int)(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c / d + 0.5f)) * d;
}

static float mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2)
{
return mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(mm5ESMSeQmWFxkwsYNXP9Rz0ZfEseM7tmGlG1T63Z(m4XTfrbNMHdOmsI2jxFrqbF3s3H2OXwfPboJFZdNg(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform), 0.1f), 4.0f);
}

static void m56ODN90dVzwEYQ32zaWaZUaykLpF1o6oaPhRmMZQ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
int dirty[4];

if (m3oKu2RdKV0jprJqKpsGRO44el4JfkKu6WPqxt88L(ctx->fs, dirty)) {
int fontImage = ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ];
// mbBQQ8ZjGGb7I3F8fGa9qidkv5yrSsg9OPwC13uDV texture
if (fontImage != 0) {
int iw, ih;
const unsigned char* data = fonsGetTextureData(ctx->fs, &iw, &ih);
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = dirty[0];
int y = dirty[1];
int w = dirty[2] - dirty[0];
int h = dirty[3] - dirty[1];
ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderUpdateTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, fontImage, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, w,h, data);
}
}
}

static int mgrse1kccYWIKuEqrz9WbvVh5T6UtsbfqIQT3IhJf(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
{
int iw, ih;
m56ODN90dVzwEYQ32zaWaZUaykLpF1o6oaPhRmMZQ(ctx);
if (ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ >= MRKUI_MAX_FONTIMAGES-1)
return 0;
// if mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 fontImage already have mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c texture
if (ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ+1] != 0)
mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(ctx, ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ+1], &iw, &ih);
else { // calculate the new mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R size mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 create it.
mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(ctx, ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ], &iw, &ih);
if (iw > ih)
ih *= 2;
else
iw *= 2;
if (iw > MRKUI_MAX_FONTIMAGE_SIZE || ih > MRKUI_MAX_FONTIMAGE_SIZE)
iw = ih = MRKUI_MAX_FONTIMAGE_SIZE;
ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ+1] = ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreateTexture(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, MRKUI_TEXTURE_ALPHA, iw, ih, 0, NULL);
}
++ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ;
mnvwva4NVW9YH0eW70Ga58c2O04LAwNj4qN7eeiXF(ctx->fs, iw, ih);
return 1;
}

static void mpVngL4cZvILAC0Ux2uq42dyIysTr5jewOXYZYNFS(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts, int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ paint = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB;

// Render triangles.
paint.mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = ctx->fontImages[ctx->mQIDihpMK5O0UqW00rUyhjf8u0bRk2ReXEBIOnWyZ];

// Apply global mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E
paint.mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
paint.mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c *= msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;

ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderTriangles(ctx->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, &paint, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, &msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, verts, mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);

ctx->mEuPaDEguBwNSxZ9ZItIXHJJLdL21Lh2j2nhcSpLF++;
ctx->mjczuH2bMPOeWHzSDkqETboPW95rIxcwijfCkyaoM += mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA/3;
}

float mD7BGE6tD15Q5JVrQe9kvq1unJq8YyOeJI9TYQO33(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW iter, prevIter;
mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = 0;
int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;

if (end == NULL)
end = string + strlen(string);

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);

m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = mgCoMyFRbHuDdYAjINJzNO2R079lIEhBeV9rFRghN(2, (int)(end - string)) * 6; // conservative estimate.
verts = mqfnGNKHGOJHaKOQc59rZ1Ao6s2sdIuhWkWUeFvdl(ctx, m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3);
if (verts == NULL) return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;

m7PieUDQehumYiYh4252A99B8amS5Zd6uspppOu0X(ctx->fs, &iter, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, y*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, string, end, FONS_GLYPH_BITMAP_REQUIRED);
prevIter = iter;
while (mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i)) {
float c[4*2];
if (iter.mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm == -1) { // can not retrieve glyph?
if (mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA != 0) {
mpVngL4cZvILAC0Ux2uq42dyIysTr5jewOXYZYNFS(ctx, verts, mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);
mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;
}
if (!mgrse1kccYWIKuEqrz9WbvVh5T6UtsbfqIQT3IhJf(ctx))
break; // no memory :(
iter = prevIter;
mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i); // try again
if (iter.mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm == -1) // still can not find glyph?
break;
}
prevIter = iter;
// Transform corners.
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&c[0],&c[1], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0*invscale, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0*invscale);
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&c[2],&c[3], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1*invscale, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0*invscale);
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&c[4],&c[5], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1*invscale, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1*invscale);
mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(&c[6],&c[7], msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->xform, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0*invscale, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1*invscale);
// Create triangles
if (mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA+6 <= m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3) {
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[0], c[1], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[4], c[5], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[2], c[3], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[0], c[1], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[6], c[7], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
mCohv3AGXKTBPPp7mw5jT8YkrxFL6qplM2PSctEV0(&verts[mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA], c[4], c[5], mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1); mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
}
}

// TODO: mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB back-end bit myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT do this just once per frame.
m56ODN90dVzwEYQ32zaWaZUaykLpF1o6oaPhRmMZQ(ctx);

mpVngL4cZvILAC0Ux2uq42dyIysTr5jewOXYZYNFS(ctx, verts, mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);

return iter.nextx / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
}

void mlDDINOiSAzPEsR6fOSUm1OPckjtObbytWmEuqkol(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float breakRowWidth, const char* string, const char* end)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb rows[2];
int nrows = 0, i;
int oldAlign = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN;
int haling = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN & (MRKUI_ALIGN_LEFT | MRKUI_ALIGN_CENTER | MRKUI_ALIGN_RIGHT);
int valign = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN & (MRKUI_ALIGN_TOP | MRKUI_ALIGN_MIDDLE | MRKUI_ALIGN_BOTTOM | MRKUI_ALIGN_BASELINE);
float m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 = 0;

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return;

mQgXnBH9OJw8GqGMIMxCz10HumRGPpIdwcouPGuxu(ctx, NULL, NULL, &m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9);

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = MRKUI_ALIGN_LEFT | valign;

while ((nrows = mch8m96TeGdu8qfsSSpZGy0pKPFqF2aK7SoOQse2M(ctx, string, end, breakRowWidth, rows, 2))) {
for (i = 0; i < nrows; i++) {
mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb* row = &rows[i];
if (haling & MRKUI_ALIGN_LEFT)
mD7BGE6tD15Q5JVrQe9kvq1unJq8YyOeJI9TYQO33(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, row->start, row->end);
else if (haling & MRKUI_ALIGN_CENTER)
mD7BGE6tD15Q5JVrQe9kvq1unJq8YyOeJI9TYQO33(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + breakRowWidth*0.5f - row->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn*0.5f, y, row->start, row->end);
else if (haling & MRKUI_ALIGN_RIGHT)
mD7BGE6tD15Q5JVrQe9kvq1unJq8YyOeJI9TYQO33(ctx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + breakRowWidth - row->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, y, row->start, row->end);
y += m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 * msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi;
}
string = rows[nrows-1].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
}

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = oldAlign;
}

int mjH2QqdlRvG7u6XA83F5uLKLhzXUzE10wAjVGVVlo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end, mEc0XjUKIeWy3xadDd0enfrDKINh4p3Bap6Gmn0ag* positions, int maxPositions)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW iter, prevIter;
mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
int npos = 0;

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return 0;

if (end == NULL)
end = string + strlen(string);

if (string == end)
return 0;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);

m7PieUDQehumYiYh4252A99B8amS5Zd6uspppOu0X(ctx->fs, &iter, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, y*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, string, end, FONS_GLYPH_BITMAP_OPTIONAL);
prevIter = iter;
while (mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i)) {
if (iter.mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm < 0 && mgrse1kccYWIKuEqrz9WbvVh5T6UtsbfqIQT3IhJf(ctx)) { // can not retrieve glyph?
iter = prevIter;
mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i); // try again
}
prevIter = iter;
positions[npos].str = iter.str;
positions[npos].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp * invscale;
positions[npos].minx = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0) * invscale;
positions[npos].maxx = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(iter.nextx, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1) * invscale;
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

int mch8m96TeGdu8qfsSSpZGy0pKPFqF2aK7SoOQse2M(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* string, const char* end, float breakRowWidth, mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb* rows, int maxRows)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW iter, prevIter;
mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
int nrows = 0;
float rowStartX = 0;
float rowWidth = 0;
float rowMinX = 0;
float rowMaxX = 0;
const char* rowStart = NULL;
const char* rowEnd = NULL;
const char* wordStart = NULL;
float wordStartX = 0;
float wordMinX = 0;
const char* breakEnd = NULL;
float breakWidth = 0;
float breakMaxX = 0;
int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_SPACE, ptype = MRKUI_SPACE;
unsigned int pcodepoint = 0;

if (maxRows == 0) return 0;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return 0;

if (end == NULL)
end = string + strlen(string);

if (string == end) return 0;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);

breakRowWidth *= ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;

m7PieUDQehumYiYh4252A99B8amS5Zd6uspppOu0X(ctx->fs, &iter, 0, 0, string, end, FONS_GLYPH_BITMAP_OPTIONAL);
prevIter = iter;
while (mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i)) {
if (iter.mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm < 0 && mgrse1kccYWIKuEqrz9WbvVh5T6UtsbfqIQT3IhJf(ctx)) { // can not retrieve glyph?
iter = prevIter;
mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(ctx->fs, &iter, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i); // try again
}
prevIter = iter;
switch (iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw) {
case 9:// \mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU
case 11:// \v
case 12:// \f
case 32:// space
case 0x00a0:// NBSP
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_SPACE;
break;
case 10:// \n
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = pcodepoint == 13 ? MRKUI_SPACE : MRKUI_NEWLINE;
break;
case 13:// \mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = pcodepoint == 10 ? MRKUI_SPACE : MRKUI_NEWLINE;
break;
case 0x0085:// NEL
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_NEWLINE;
break;
default:
if ((iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0x4E00 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0x9FFF) ||
(iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0x3000 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0x30FF) ||
(iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0xFF00 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0xFFEF) ||
(iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0x1100 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0x11FF) ||
(iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0x3130 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0x318F) ||
(iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw >= 0xAC00 && iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw <= 0xD7AF))
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_CJK_CHAR;
else
mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_CHAR;
break;
}

if (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_NEWLINE) {
// Always handle new m5RtqEm8VqdvN2MxHFxp8N6bkwFEegsbelmVWAFCI.
rows[nrows].start = rowStart != NULL ? rowStart : iter.str;
rows[nrows].end = rowEnd != NULL ? rowEnd : iter.str;
rows[nrows].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = rowWidth * invscale;
rows[nrows].minx = rowMinX * invscale;
rows[nrows].maxx = rowMaxX * invscale;
rows[nrows].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = iter.mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
nrows++;
if (nrows >= maxRows)
return nrows;
// Set null break point
breakEnd = rowStart;
breakWidth = 0.0;
breakMaxX = 0.0;
// Indicate myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT skip the white space at the beginning of the row.
rowStart = NULL;
rowEnd = NULL;
rowWidth = 0;
rowMinX = rowMaxX = 0;
} else {
if (rowStart == NULL) {
// Skip white space until the beginning of the line
if (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CHAR || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR) {
// The current char is the row so far
rowStartX = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
rowStart = iter.str;
rowEnd = iter.mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
rowWidth = iter.nextx - rowStartX; // mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 - rowStartX;
rowMinX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 - rowStartX;
rowMaxX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 - rowStartX;
wordStart = iter.str;
wordStartX = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
wordMinX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 - rowStartX;
// Set null break point
breakEnd = rowStart;
breakWidth = 0.0;
breakMaxX = 0.0;
}
} else {
float nextWidth = iter.nextx - rowStartX;

// track last non-white space character
if (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CHAR || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR) {
rowEnd = iter.mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
rowWidth = iter.nextx - rowStartX;
rowMaxX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 - rowStartX;
}
// track last end of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c word
if (((ptype == MRKUI_CHAR || ptype == MRKUI_CJK_CHAR) && mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_SPACE) || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR) {
breakEnd = iter.str;
breakWidth = rowWidth;
breakMaxX = rowMaxX;
}
// track last beginning of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c word
if ((ptype == MRKUI_SPACE && (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CHAR || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR)) || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR) {
wordStart = iter.str;
wordStartX = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
wordMinX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 - rowStartX;
}

// Break myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT new line when mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c character is beyond break myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn.
if ((mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CHAR || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_CJK_CHAR) && nextWidth > breakRowWidth) {
// The run length is too long, need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT break myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT new line.
if (breakEnd == rowStart) {
// The current word is longer than the row length, just break it from here.
rows[nrows].start = rowStart;
rows[nrows].end = iter.str;
rows[nrows].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = rowWidth * invscale;
rows[nrows].minx = rowMinX * invscale;
rows[nrows].maxx = rowMaxX * invscale;
rows[nrows].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = iter.str;
nrows++;
if (nrows >= maxRows)
return nrows;
rowStartX = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
rowStart = iter.str;
rowEnd = iter.mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
rowWidth = iter.nextx - rowStartX;
rowMinX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 - rowStartX;
rowMaxX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 - rowStartX;
wordStart = iter.str;
wordStartX = iter.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
wordMinX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 - rowStartX;
} else {
// Break the line from the end of the last word, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 start new line from the beginning of the new.
rows[nrows].start = rowStart;
rows[nrows].end = breakEnd;
rows[nrows].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = breakWidth * invscale;
rows[nrows].minx = rowMinX * invscale;
rows[nrows].maxx = breakMaxX * invscale;
rows[nrows].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = wordStart;
nrows++;
if (nrows >= maxRows)
return nrows;
rowStartX = wordStartX;
rowStart = wordStart;
rowEnd = iter.mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
rowWidth = iter.nextx - rowStartX;
rowMinX = wordMinX;
rowMaxX = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 - rowStartX;
// No change myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the word start
}
// Set null break point
breakEnd = rowStart;
breakWidth = 0.0;
breakMaxX = 0.0;
}
}
}

pcodepoint = iter.m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
ptype = mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
}

// Break the line from the end of the last word, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 start new line from the beginning of the new.
if (rowStart != NULL) {
rows[nrows].start = rowStart;
rows[nrows].end = rowEnd;
rows[nrows].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = rowWidth * invscale;
rows[nrows].minx = rowMinX * invscale;
rows[nrows].maxx = rowMaxX * invscale;
rows[nrows].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = end;
nrows++;
}

return nrows;
}

float mn7QRzZxAXSev1fD8gaV5NKb8sR9fPlOP9kwXpXb8(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end, float* bounds)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return 0;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);

myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(ctx->fs, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, y*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, string, end, bounds);
if (bounds != NULL) {
// Use line bounds for mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc.
muDcsBo45qKRlHe2BxEcMMlTJjUo1FnJrCboKt4ed(ctx->fs, y*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, &bounds[1], &bounds[3]);
bounds[0] *= invscale;
bounds[1] *= invscale;
bounds[2] *= invscale;
bounds[3] *= invscale;
}
return myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * invscale;
}

void mSiUIizxsnUBv6UFRjysvmtlYFdivNlDKpcDli8AV(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float breakRowWidth, const char* string, const char* end, float* bounds)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb rows[2];
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
int nrows = 0, i;
int oldAlign = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN;
int haling = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN & (MRKUI_ALIGN_LEFT | MRKUI_ALIGN_CENTER | MRKUI_ALIGN_RIGHT);
int valign = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN & (MRKUI_ALIGN_TOP | MRKUI_ALIGN_MIDDLE | MRKUI_ALIGN_BOTTOM | MRKUI_ALIGN_BASELINE);
float m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 = 0, rminy = 0, rmaxy = 0;
float minx, miny, maxx, maxy;

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) {
if (bounds != NULL)
bounds[0] = bounds[1] = bounds[2] = bounds[3] = 0.0f;
return;
}

mQgXnBH9OJw8GqGMIMxCz10HumRGPpIdwcouPGuxu(ctx, NULL, NULL, &m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9);

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = MRKUI_ALIGN_LEFT | valign;

minx = maxx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
miny = maxy = y;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);
muDcsBo45qKRlHe2BxEcMMlTJjUo1FnJrCboKt4ed(ctx->fs, 0, &rminy, &rmaxy);
rminy *= invscale;
rmaxy *= invscale;

while ((nrows = mch8m96TeGdu8qfsSSpZGy0pKPFqF2aK7SoOQse2M(ctx, string, end, breakRowWidth, rows, 2))) {
for (i = 0; i < nrows; i++) {
mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb* row = &rows[i];
float rminx, rmaxx, dx = 0;
// Horizontal bounds
if (haling & MRKUI_ALIGN_LEFT)
dx = 0;
else if (haling & MRKUI_ALIGN_CENTER)
dx = breakRowWidth*0.5f - row->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn*0.5f;
else if (haling & MRKUI_ALIGN_RIGHT)
dx = breakRowWidth - row->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
rminx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + row->minx + dx;
rmaxx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + row->maxx + dx;
minx = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(minx, rminx);
maxx = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(maxx, rmaxx);
// Vertical bounds.
miny = mWmBUz7nywTiUfJ1OoFHm6oEEVDd3DLy8JUOvJRuq(miny, y + rminy);
maxy = mqRGOKZmNFuhoYn5iEEnq57Bibxxj21KYMyzdGIFj(maxy, y + rmaxy);

y += m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 * msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi;
}
string = rows[nrows-1].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
}

msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN = oldAlign;

if (bounds != NULL) {
bounds[0] = minx;
bounds[1] = miny;
bounds[2] = maxx;
bounds[3] = maxy;
}
}

void mQgXnBH9OJw8GqGMIMxCz10HumRGPpIdwcouPGuxu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float* m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi, float* mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr, float* m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9)
{
mlMTxOWJK5yBadEjZRdSrKbAp4hoOwZjMNLRId3zG* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = meXgjn3DkTKILMCKxqoDNb0n4BiqmvNIQJcCD9d5I(ctx);
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mo4XbK7PeTzaej6bvyWlr7eg2Y0eF3RSrSmi8Br1i(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2) * ctx->miBZPEVpVeAbGC3Y0PXo21VmcCgaywNyMWiX1270l;
float invscale = 1.0f / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;

if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK == FONS_INVALID) return;

muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mlUXL1kjZAi7ES9F3lXgY0tjwCzqOYShFNmZzcKZp*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mGBxDENjXoVXXyacUXGvIvnljXOtAgAYnOJRpl5Z0*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mFpxNiEKacB5Zv0Ch762F21ixavpOwLz7NfBeOkMN);
midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(ctx->fs, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mBTYAKb0xMcSpzCq9bIljkGhONoRcQvywtMzvPPWK);

muBl5zwa2xJ8yDTKkn6ofR8MjHElponvWK5Q9lrpL(ctx->fs, m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi, mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr, m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9);
if (m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi != NULL)
*m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi *= invscale;
if (mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr != NULL)
*mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr *= invscale;
if (m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 != NULL)
*m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 *= invscale;
}
// vim: ft=c nu noet ts=4
