#ifndef MRKUIGLUTILS_H
#define MRKUIGLUTILS_H

struct mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk {
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx;
GLuint fbo;
GLuint rbo;
GLuint texture;
int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
};
typedef struct mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk;

// Helper function myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT create GL frame buffer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT.
void mY0cVdhacc7Ob1Yaf2IxcRs61erpac5OzPrEe8SWt(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* fb);
mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* mEV8RTKL3zqz0fZWgVLLqvr2ZRQpG1eDfLNiGl6Qu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int w, int h, int imageFlags);
void mTws7QHlNNMofwzRxyriod5fJtJtZ7VaTm1ebqmvt(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* fb);

#endif // MRKUI_GL_UTILS_H

#ifdef MRKUI_GL_IMPLEMENTATION

#if defined(MRKUI_GL3) || defined(MRKUI_GLES2) || defined(MRKUI_GLES3)
// FBO is core in OpenGL 3>.
#define MRKUI_FBO_VALID 1
#elif defined(MRKUI_GL2)
// On OS mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14 including glext defines FBO on GL2 too.
#ifdef __APPLE__
#include <OpenGL/glext.h>
#define MRKUI_FBO_VALID 1
#endif
#endif

static GLint defaultFBO = -1;

mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* mEV8RTKL3zqz0fZWgVLLqvr2ZRQpG1eDfLNiGl6Qu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int w, int h, int imageFlags)
{
#ifdef MRKUI_FBO_VALID
GLint defaultFBO;
GLint defaultRBO;
mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* fb = NULL;

glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFBO);
glGetIntegerv(GL_RENDERBUFFER_BINDING, &defaultRBO);

fb = (mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk*)malloc(sizeof(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk));
if (fb == NULL) goto error;
memset(fb, 0, sizeof(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk));

fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = m9DDyetlwzFY4GtL4vo798SeRDjHh1vw7w67ABcpj(ctx, w, h, imageFlags | MRKUI_IMAGE_FLIPY | MRKUI_IMAGE_PREMULTIPLIED, NULL);

#if defined MRKUI_GL2
fb->texture = m1JPqNUXEtiXwxpjaJfOkZlzdmFzJ4RuJ0AqSOZ54(ctx, fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
#elif defined MRKUI_GL3
fb->texture = mC8seyhmmHvNULUrG7xf7X7fb17eYtpedBt7jHCaT(ctx, fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
#elif defined MRKUI_GLES2
fb->texture = moKnx5evqI2ZQl78o4zXmb7QpVYQjoze4kEbqiw0O(ctx, fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
#elif defined MRKUI_GLES3
fb->texture = mMFrUATJuwe61hht7K2U4y62i9QxhYJiuz8zeZACr(ctx, fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
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
// If GL_STENCIL_INDEX8 is not supported, try GL_DEPTH24_STENCIL8 as mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c fallback.
// Some graphics cards require mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c depth buffer along with mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c stencil.
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
mTws7QHlNNMofwzRxyriod5fJtJtZ7VaTm1ebqmvt(fb);
return NULL;
#else
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(ctx);
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(w);
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(h);
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(imageFlags);
return NULL;
#endif
}

void mY0cVdhacc7Ob1Yaf2IxcRs61erpac5OzPrEe8SWt(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* fb)
{
#ifdef MRKUI_FBO_VALID
if (defaultFBO == -1) glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFBO);
glBindFramebuffer(GL_FRAMEBUFFER, fb != NULL ? fb->fbo : defaultFBO);
#else
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(fb);
#endif
}

void mTws7QHlNNMofwzRxyriod5fJtJtZ7VaTm1ebqmvt(mkzXE4bPWbTYWI1vwVP1QbabChrzTwiYDzB2aOgpk* fb)
{
#ifdef MRKUI_FBO_VALID
if (fb == NULL) return;
if (fb->fbo != 0)
glDeleteFramebuffers(1, &fb->fbo);
if (fb->rbo != 0)
glDeleteRenderbuffers(1, &fb->rbo);
if (fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R >= 0)
mgLGIfY89sBwjoJBwt0hJq4zsDcjF7sLvkTQCny6Z(fb->ctx, fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
fb->ctx = NULL;
fb->fbo = 0;
fb->rbo = 0;
fb->texture = 0;
fb->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = -1;
free(fb);
#else
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(fb);
#endif
}

#endif // MRKUIGL_IMPLEMENTATION
