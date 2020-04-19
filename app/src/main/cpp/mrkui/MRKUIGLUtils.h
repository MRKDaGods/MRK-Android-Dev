#ifndef MRKUIGLUTILS_H
#define MRKUIGLUTILS_H

struct MRKUILUframebuffer {
    MRKUIcontext *ctx;
    GLuint fbo;
    GLuint rbo;
    GLuint texture;
    int image;
};
typedef struct MRKUILUframebuffer MRKUILUframebuffer;

// Helper function to create GL frame buffer to render to.
void MRKUIluBindFramebuffer(MRKUILUframebuffer *fb);

MRKUILUframebuffer *MRKUIluCreateFramebuffer(MRKUIcontext *ctx, int w, int h, int imageFlags);

void MRKUIluDeleteFramebuffer(MRKUILUframebuffer *fb);

#endif // MRKUI_GL_UTILS_H

#ifdef MRKUI_GL_IMPLEMENTATION

#if defined(MRKUI_GL3) || defined(MRKUI_GLES2) || defined(MRKUI_GLES3)
// FBO is core in OpenGL 3>.
#	define MRKUI_FBO_VALID 1
#elif defined(MRKUI_GL2)
// On OS X including glext defines FBO on GL2 too.
#	ifdef __APPLE__
#		include <OpenGL/glext.h>
#		define MRKUI_FBO_VALID 1
#	endif
#endif

static GLint defaultFBO = -1;

MRKUILUframebuffer* MRKUIluCreateFramebuffer(MRKUIcontext* ctx, int w, int h, int imageFlags)
{
#ifdef MRKUI_FBO_VALID
    GLint defaultFBO;
    GLint defaultRBO;
    MRKUILUframebuffer* fb = NULL;

    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFBO);
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &defaultRBO);

    fb = (MRKUILUframebuffer*)malloc(sizeof(MRKUILUframebuffer));
    if (fb == NULL) goto error;
    memset(fb, 0, sizeof(MRKUILUframebuffer));

    fb->image = MRKUICreateImageRGBA(ctx, w, h, imageFlags | MRKUI_IMAGE_FLIPY | MRKUI_IMAGE_PREMULTIPLIED, NULL);

#if defined MRKUI_GL2
    fb->texture = MRKUIlImageHandleGL2(ctx, fb->image);
#elif defined MRKUI_GL3
    fb->texture = MRKUIlImageHandleGL3(ctx, fb->image);
#elif defined MRKUI_GLES2
    fb->texture = MRKUIlImageHandleGLES2(ctx, fb->image);
#elif defined MRKUI_GLES3
    fb->texture = MRKUIlImageHandleGLES3(ctx, fb->image);
#endif

    fb->ctx = ctx;

    // frame buffer object
    glGenFramebuffers(1, &fb->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fb->fbo);

    // render buffer object
    glGenRenderbuffers(1, &fb->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, fb->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, w, h);

    // combine all
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb->texture, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, fb->rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
#ifdef GL_DEPTH24_STENCIL8
        // If GL_STENCIL_INDEX8 is not supported, try GL_DEPTH24_STENCIL8 as a fallback.
        // Some graphics cards require a depth buffer along with a stencil.
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, w, h);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb->texture, 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, fb->rbo);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
#endif // GL_DEPTH24_STENCIL8
            goto error;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, defaultFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, defaultRBO);
    return fb;
error:
    glBindFramebuffer(GL_FRAMEBUFFER, defaultFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, defaultRBO);
    MRKUIluDeleteFramebuffer(fb);
    return NULL;
#else
    MRKUI_NOTUSED(ctx);
    MRKUI_NOTUSED(w);
    MRKUI_NOTUSED(h);
    MRKUI_NOTUSED(imageFlags);
    return NULL;
#endif
}

void MRKUIluBindFramebuffer(MRKUILUframebuffer* fb)
{
#ifdef MRKUI_FBO_VALID
    if (defaultFBO == -1) glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, fb != NULL ? fb->fbo : defaultFBO);
#else
    MRKUI_NOTUSED(fb);
#endif
}

void MRKUIluDeleteFramebuffer(MRKUILUframebuffer* fb)
{
#ifdef MRKUI_FBO_VALID
    if (fb == NULL) return;
    if (fb->fbo != 0)
        glDeleteFramebuffers(1, &fb->fbo);
    if (fb->rbo != 0)
        glDeleteRenderbuffers(1, &fb->rbo);
    if (fb->image >= 0)
        MRKUIDeleteImage(fb->ctx, fb->image);
    fb->ctx = NULL;
    fb->fbo = 0;
    fb->rbo = 0;
    fb->texture = 0;
    fb->image = -1;
    free(fb);
#else
    MRKUI_NOTUSED(fb);
#endif
}

#endif // MRKUIGL_IMPLEMENTATION
