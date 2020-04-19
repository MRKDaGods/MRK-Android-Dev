#ifndef MRKUI_GL_H
#define MRKUI_GL_H

#include <GLES2/gl2.h>
#include "MRKUI.h"

#ifdef __cplusplus
extern "C" {
#endif

// Create m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf

enum MRKUIcreateFlags {
// Flag indicating if geometry based anti-aliasing is used (may not be needed when using MSAA).
MRKUI_ANTIALIAS = 1<<0,
// Flag indicating if strokes should be drawn using stencil buffer. The rendering will be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c little
// slower, but path overlaps (i.e. self-intersecting or sharp turns) will be drawn just once.
MRKUI_STENCIL_STROKES= 1<<1,
// Flag indicating that additional debug checks are done.
MRKUI_DEBUG = 1<<2,
};

#if defined MRKUI_GL2_IMPLEMENTATION
#  define MRKUI_GL2 1
#  define MRKUI_GL_IMPLEMENTATION 1
#elif defined MRKUI_GL3_IMPLEMENTATION
#  define MRKUI_GL3 1
#  define MRKUI_GL_IMPLEMENTATION 1
#  define MRKUI_GL_USE_UNIFORMBUFFER 1
#elif defined MRKUI_GLES2_IMPLEMENTATION
#  define MRKUI_GLES2 1
#  define MRKUI_GL_IMPLEMENTATION 1
#elif defined MRKUI_GLES3_IMPLEMENTATION
#  define MRKUI_GLES3 1
#  define MRKUI_GL_IMPLEMENTATION 1
#endif

#define mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ (1)

// Creates MRKUI contexts for different OpenGL (ES) versions.
// Flags should be combination of the create m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf above.

#if defined MRKUI_GL2

my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* m9Ngz2briPGjprzrHsFQRLyH3germdNJ8NWLH9cO2(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
void md3Kodz6DM0nLPRQiazCrQpCga8HC8pHxvlcdoIi2(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

int mOJYEWRGivYnIA7w8OhgSXwxeUenm8G7ptht94nY3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
GLuint m1JPqNUXEtiXwxpjaJfOkZlzdmFzJ4RuJ0AqSOZ54(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

#endif

#if defined MRKUI_GL3

my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* m9qaGLB9d6kSay0Ssh4fxjnDR80ukS0BlUPxpWebX(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
void mJJLnNKg6JzTH6aRFLq5zfQjMbyzmm6bj8Hv5bS80(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

int mXG8i05GcFkDp79AR3Z69KDtpriWgCZL0PMsvfBfb(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
GLuint mC8seyhmmHvNULUrG7xf7X7fb17eYtpedBt7jHCaT(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

#endif

#if defined MRKUI_GLES2

my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mjehP2hwYEpapVML419Sm6AokFHrqEoXqjg4GmDZL(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
void mTXoYjcfLhg7OhZfSOOsi4IGWpq05BdMBT2HU0WAK(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

int mbNDj6EBhFgsE2p8dMkzQtgp6MtwzzbAI8XWyhIZE(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
GLuint moKnx5evqI2ZQl78o4zXmb7QpVYQjoze4kEbqiw0O(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

#endif

#if defined MRKUI_GLES3

my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mv6fD4ZOs20s5sF0RaLlNqn4p91QUqpO5BS1sBEsU(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
void mtTs7jOn0BBdeOVgvcMHc4FpJ88e3UTa8qsHU66qH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

int mKBBSsBJj0LqXgEnxpUd9Re6cwmdp5eh7OnrsLtUD(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
GLuint mMFrUATJuwe61hht7K2U4y62i9QxhYJiuz8zeZACr(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

#endif

// These are additional m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf on top of MRKUIimageFlags.
enum MRKUIimageFlagsGL {
MRKUI_IMAGE_NODELETE= 1<<16,// Do not delete GL texture handle.
};

#ifdef __cplusplus
}
#endif

#endif /* MRKUI_GL_H */

#ifdef MRKUI_GL_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "MRKUI.h"

enum GLMRKUIuniformLoc {
GLMRKUI_LOC_VIEWSIZE,
GLMRKUI_LOC_TEX,
GLMRKUI_LOC_FRAG,
GLMRKUI_MAX_LOCS
};

enum GLMRKUIshaderType {
NSVG_SHADER_FILLGRAD,
NSVG_SHADER_FILLIMG,
NSVG_SHADER_SIMPLE,
NSVG_SHADER_IMG
};

#if MRKUI_GL_USE_UNIFORMBUFFER
enum GLMRKUIuniformBindings {
GLMRKUI_FRAG_BINDING = 0,
};
#endif

struct m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0 {
GLuint prog;
GLuint frag;
GLuint vert;
GLint loc[GLMRKUI_MAX_LOCS];
};
typedef struct m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0 m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0;

struct mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a {
int ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl;
GLuint tex;
int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;
};
typedef struct mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a;

struct mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC
{
GLenum mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS;
GLenum mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi;
GLenum moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH;
GLenum mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g;
};
typedef struct mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC;

enum GLMRKUIcallType {
GLMRKUI_NONE = 0,
GLMRKUI_FILL,
GLMRKUI_CONVEXFILL,
GLMRKUI_STROKE,
GLMRKUI_TRIANGLES,
};

struct mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv {
int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
int mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p;
int mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs;
int mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK;
int mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc;
int mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU;
mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv;
};
typedef struct mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv;

struct mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6 {
int mV6Ymwo4OAavNckWMsuOBvHvudaSkP99DpZ0RC2C7;
int mqiEl06lgwkdBBvgvz8JJ6cMN9B6CfzjnkBtBprgL;
int m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0;
int mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA;
};
typedef struct mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6 mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6;

struct mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL {
#if MRKUI_GL_USE_UNIFORMBUFFER
float scissorMat[12]; // matrices are actually 3 vec4s
float paintMat[12];
struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mVFGcP0i08BlDERV3DCNVPeLLZFTQqHyhN01lQs5e;
struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mWAgLYA6sXdgAseIoTHVzXQhgikCJwoo5GWTHZo2n;
float scissorExt[2];
float scissorScale[2];
float extent[2];
float mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
float mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl;
float mGgaEz43UEiole5u7RU0JXROcfUgARXbqRB1fXoOJ;
float m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk;
int mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W;
int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
#else
// note: after modifying layout or size of uniform array,
// don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU forget myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT also update the fragment mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37 source!
#define MRKUI_GL_UNIFORMARRAY_SIZE 11
union {
struct {
float scissorMat[12]; // matrices are actually 3 vec4s
float paintMat[12];
struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mVFGcP0i08BlDERV3DCNVPeLLZFTQqHyhN01lQs5e;
struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mWAgLYA6sXdgAseIoTHVzXQhgikCJwoo5GWTHZo2n;
float scissorExt[2];
float scissorScale[2];
float extent[2];
float mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
float mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl;
float mGgaEz43UEiole5u7RU0JXROcfUgARXbqRB1fXoOJ;
float m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk;
float mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W;
float mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
};
float uniformArray[MRKUI_GL_UNIFORMARRAY_SIZE][4];
};
#endif
};
typedef struct mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL;

struct mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P {
m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0 mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* textures;
float view[2];
int m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E;
int mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l;
int mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx;
GLuint vertBuf;
#if defined MRKUI_GL3
GLuint vertArr;
#endif
#if MRKUI_GL_USE_UNIFORMBUFFER
GLuint fragBuf;
#endif
int mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5;
int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;

// Per frame buffers
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* calls;
int my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa;
int mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4;
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* paths;
int mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU;
int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz;
struct mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3;
int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA;
unsigned char* uniforms;
int mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j;
int miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ;

// cached msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
GLuint boundTexture;
GLuint stencilMask;
GLenum stencilFunc;
GLint stencilFuncRef;
GLuint stencilFuncMask;
mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv;
#endif
};
typedef struct mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P;

static int mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int b) { return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b; }

#ifdef MRKUI_GLES2
static unsigned int mzd2dfym3I8JebtNOey4ujFhKapzCs9V0vwmJL4Ze(unsigned int num)
{
unsigned n = num > 0 ? num - 1 : 0;
n |= n >> 1;
n |= n >> 2;
n |= n >> 4;
n |= n >> 8;
n |= n >> 16;
n++;
return n;
}
#endif

static void mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, GLuint tex)
{
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
if (gl->boundTexture != tex) {
gl->boundTexture = tex;
glBindTexture(GL_TEXTURE_2D, tex);
}
#else
glBindTexture(GL_TEXTURE_2D, tex);
#endif
}

static void mhHTe9yfypzJhgE5V1qDaWa47u9BixmGoG0FKEWBy(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, GLuint mask)
{
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
if (gl->stencilMask != mask) {
gl->stencilMask = mask;
glStencilMask(mask);
}
#else
glStencilMask(mask);
#endif
}

static void m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, GLenum func, GLint ref, GLuint mask)
{
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
if ((gl->stencilFunc != func) ||
(gl->stencilFuncRef != ref) ||
(gl->stencilFuncMask != mask)) {

gl->stencilFunc = func;
gl->stencilFuncRef = ref;
gl->stencilFuncMask = mask;
glStencilFunc(func, ref, mask);
}
#else
glStencilFunc(func, ref, mask);
#endif
}
static void mkUR1gwwAwJSlDuiiQ6k6T6UA6RL0VTr6biSFh5je(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, const mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC* mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P)
{
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
if ((gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS != mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS) ||
(gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi != mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi) ||
(gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH != mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH) ||
(gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g != mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g)) {

gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv = *mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P;
glBlendFuncSeparate(mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS, mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi, mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH,mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g);
}
#else
glBlendFuncSeparate(mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS, mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi, mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH,mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P->mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g);
#endif
}

static mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* glMRKUI__allocTexture(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl)
{
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = NULL;
int i;

for (i = 0; i < gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E; i++) {
if (gl->textures[i].ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl == 0) {
tex = &gl->textures[i];
break;
}
}
if (tex == NULL) {
if (gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E+1 > gl->mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l) {
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* textures;
int mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l = mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E+1, 4) +  gl->mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l/2; // 1.5m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp Overallocate
textures = (mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a*)realloc(gl->textures, sizeof(mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a)*mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l);
if (textures == NULL) return NULL;
gl->textures = textures;
gl->mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l = mmb4wzZ5XH8fioNvLmwpcHOoByMbVg9GiYX6TrE8l;
}
tex = &gl->textures[gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E++];
}

memset(tex, 0, sizeof(*tex));
tex->ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl = ++gl->mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx;

return tex;
}

static mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* glMRKUI__findTexture(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl)
{
int i;
for (i = 0; i < gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E; i++)
if (gl->textures[i].ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl == ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl)
return &gl->textures[i];
return NULL;
}

static int mCL3CNZVhaCeAnPLdnayWMo6jpJQitj9lH6Og4uyE(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl)
{
int i;
for (i = 0; i < gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E; i++) {
if (gl->textures[i].ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl == ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl) {
if (gl->textures[i].tex != 0 && (gl->textures[i].m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_IMAGE_NODELETE) == 0)
glDeleteTextures(1, &gl->textures[i].tex);
memset(&gl->textures[i], 0, sizeof(gl->textures[i]));
return 1;
}
}
return 0;
}

static void mSfLBHTEVz4uwR9S4r2UuF2nXEyGIf723YsZZUOqD(GLuint mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, const char* name, const char* mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P)
{
GLchar str[512+1];
GLsizei mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = 0;
glGetShaderInfoLog(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, 512, &mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, str);
if (mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 > 512) mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = 512;
str[mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0] = '\0';
printf("Shader %s/%s error:\n%s\n", name, mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, str);
}

static void mphMiuiq6US9Sz6Wq8VBpF60sfHQ0Vm84p3ufnFnv(GLuint prog, const char* name)
{
GLchar str[512+1];
GLsizei mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = 0;
glGetProgramInfoLog(prog, 512, &mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, str);
if (mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 > 512) mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = 512;
str[mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0] = '\0';
printf("Program %s error:\n%s\n", name, str);
}

static void mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, const char* str)
{
GLenum err;
if ((gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_DEBUG) == 0) return;
err = glGetError();
if (err != GL_NO_ERROR) {
printf("Error %08x after %s\n", err, str);
return;
}
}

static int mBhfTbQtYHddnCkUONUZ1WBFiVfnLUvB7TdpFBjPP(m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0* mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, const char* name, const char* header, const char* opts, const char* vshader, const char* fshader)
{
GLint status;
GLuint prog, vert, frag;
const char* str[3];
str[0] = header;
str[1] = opts != NULL ? opts : "";

memset(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, 0, sizeof(*mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37));

prog = glCreateProgram();
vert = glCreateShader(GL_VERTEX_SHADER);
frag = glCreateShader(GL_FRAGMENT_SHADER);
str[2] = vshader;
glShaderSource(vert, 3, str, 0);
str[2] = fshader;
glShaderSource(frag, 3, str, 0);

glCompileShader(vert);
glGetShaderiv(vert, GL_COMPILE_STATUS, &status);
if (status != GL_TRUE) {
mSfLBHTEVz4uwR9S4r2UuF2nXEyGIf723YsZZUOqD(vert, name, "vert");
return 0;
}

glCompileShader(frag);
glGetShaderiv(frag, GL_COMPILE_STATUS, &status);
if (status != GL_TRUE) {
mSfLBHTEVz4uwR9S4r2UuF2nXEyGIf723YsZZUOqD(frag, name, "frag");
return 0;
}

glAttachShader(prog, vert);
glAttachShader(prog, frag);

glBindAttribLocation(prog, 0, "vertex");
glBindAttribLocation(prog, 1, "tcoord");

glLinkProgram(prog);
glGetProgramiv(prog, GL_LINK_STATUS, &status);
if (status != GL_TRUE) {
mphMiuiq6US9Sz6Wq8VBpF60sfHQ0Vm84p3ufnFnv(prog, name);
return 0;
}

mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog = prog;
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->vert = vert;
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->frag = frag;

return 1;
}

static void mphaN1VQT0Q4jUZeFDKCxILk4eqrBs3dcfRcbATQI(m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0* mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37)
{
if (mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog != 0)
glDeleteProgram(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog);
if (mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->vert != 0)
glDeleteShader(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->vert);
if (mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->frag != 0)
glDeleteShader(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->frag);
}

static void m8XyJhLcXvJUnL1KuLBUKjtoStPj1a0dP0VFQ6XFD(m9YeYZ8yuieP4KhYSu5AVzRukDneqw3uxFrhGPSb0* mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37)
{
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->loc[GLMRKUI_LOC_VIEWSIZE] = glGetUniformLocation(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog, "viewSize");
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->loc[GLMRKUI_LOC_TEX] = glGetUniformLocation(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog, "tex");

#if MRKUI_GL_USE_UNIFORMBUFFER
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->loc[GLMRKUI_LOC_FRAG] = glGetUniformBlockIndex(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog, "frag");
#else
mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->loc[GLMRKUI_LOC_FRAG] = glGetUniformLocation(mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37->prog, "frag");
#endif
}

static int mVeG11qckkQEDaGfpAqrJUNtxthV8kJfPsahbmqHg(void* uptr)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz = 4;

// TODO: mediump float may not be enough for GLES2 in iOS.
static const char* shaderHeader =
#if defined MRKUI_GL2
"#define MRKUI_GL2 1\n"
#elif defined MRKUI_GL3
"#version 150 core\n"
"#define MRKUI_GL3 1\n"
#elif defined MRKUI_GLES2
"#version 100\n"
"#define MRKUI_GL2 1\n"
#elif defined MRKUI_GLES3
"#version 300 es\n"
"#define MRKUI_GL3 1\n"
#endif

#if MRKUI_GL_USE_UNIFORMBUFFER
"#define USE_UNIFORMBUFFER 1\n"
#else
"#define UNIFORMARRAY_SIZE 11\n"
#endif
"\n";

static const char* fillVertShader =
"#ifdef MRKUI_GL3\n"
"	uniform vec2 viewSize;\n"
"	in vec2 vertex;\n"
"	in vec2 tcoord;\n"
"	out vec2 ftcoord;\n"
"	out vec2 fpos;\n"
"#else\n"
"	uniform vec2 viewSize;\n"
"	attribute vec2 vertex;\n"
"	attribute vec2 tcoord;\n"
"	varying vec2 ftcoord;\n"
"	varying vec2 fpos;\n"
"#endif\n"
"void main(void) {\n"
"	ftcoord = tcoord;\n"
"	fpos = vertex;\n"
"	gl_Position = vec4(2.0*vertex.x/viewSize.x - 1.0, 1.0 - 2.0*vertex.y/viewSize.y, 0, 1);\n"
"}\n";

static const char* fillFragShader =
"#ifdef GL_ES\n"
"#if defined(GL_FRAGMENT_PRECISION_HIGH) || defined(MRKUI_GL3)\n"
" precision highp float;\n"
"#else\n"
" precision mediump float;\n"
"#endif\n"
"#endif\n"
"#ifdef MRKUI_GL3\n"
"#ifdef USE_UNIFORMBUFFER\n"
"	layout(std140) uniform frag {\n"
"		mat3 scissorMat;\n"
"		mat3 paintMat;\n"
"		vec4 innerCol;\n"
"		vec4 outerCol;\n"
"		vec2 scissorExt;\n"
"		vec2 scissorScale;\n"
"		vec2 extent;\n"
"		float radius;\n"
"		float feather;\n"
"		float strokeMult;\n"
"		float strokeThr;\n"
"		int texType;\n"
"		int type;\n"
"	};\n"
"#else\n" // MRKUI_GL3 && !USE_UNIFORMBUFFER
"	uniform vec4 frag[UNIFORMARRAY_SIZE];\n"
"#endif\n"
"	uniform sampler2D tex;\n"
"	in vec2 ftcoord;\n"
"	in vec2 fpos;\n"
"	out vec4 outColor;\n"
"#else\n" // !MRKUI_GL3
"	uniform vec4 frag[UNIFORMARRAY_SIZE];\n"
"	uniform sampler2D tex;\n"
"	varying vec2 ftcoord;\n"
"	varying vec2 fpos;\n"
"#endif\n"
"#ifndef USE_UNIFORMBUFFER\n"
"	#define scissorMat mat3(frag[0].xyz, frag[1].xyz, frag[2].xyz)\n"
"	#define paintMat mat3(frag[3].xyz, frag[4].xyz, frag[5].xyz)\n"
"	#define innerCol frag[6]\n"
"	#define outerCol frag[7]\n"
"	#define scissorExt frag[8].xy\n"
"	#define scissorScale frag[8].zw\n"
"	#define extent frag[9].xy\n"
"	#define radius frag[9].z\n"
"	#define feather frag[9].w\n"
"	#define strokeMult frag[10].x\n"
"	#define strokeThr frag[10].y\n"
"	#define texType int(frag[10].z)\n"
"	#define type int(frag[10].w)\n"
"#endif\n"
"\n"
"float sdroundrect(vec2 pt, vec2 ext, float rad) {\n"
"	vec2 ext2 = ext - vec2(rad,rad);\n"
"	vec2 d = abs(pt) - ext2;\n"
"	return min(max(d.x,d.y),0.0) + length(max(d,0.0)) - rad;\n"
"}\n"
"\n"
"// Scissoring\n"
"float scissorMask(vec2 p) {\n"
"	vec2 sc = (abs((scissorMat * vec3(p,1.0)).xy) - scissorExt);\n"
"	sc = vec2(0.5,0.5) - sc * scissorScale;\n"
"	return clamp(sc.x,0.0,1.0) * clamp(sc.y,0.0,1.0);\n"
"}\n"
"#ifdef EDGE_AA\n"
"// Stroke - from [0..1] to clipped pyramid, where the slope is 1px.\n"
"float strokeMask() {\n"
"	return min(1.0, (1.0-abs(ftcoord.x*2.0-1.0))*strokeMult) * min(1.0, ftcoord.y);\n"
"}\n"
"#endif\n"
"\n"
"void main(void) {\n"
"   vec4 result;\n"
"	float scissor = scissorMask(fpos);\n"
"#ifdef EDGE_AA\n"
"	float strokeAlpha = strokeMask();\n"
"	if (strokeAlpha < strokeThr) discard;\n"
"#else\n"
"	float strokeAlpha = 1.0;\n"
"#endif\n"
"	if (type == 0) {			// Gradient\n"
"		// Calculate gradient color using box gradient\n"
"		vec2 pt = (paintMat * vec3(fpos,1.0)).xy;\n"
"		float d = clamp((sdroundrect(pt, extent, radius) + feather*0.5) / feather, 0.0, 1.0);\n"
"		vec4 color = mix(innerCol,outerCol,d);\n"
"		// Combine alpha\n"
"		color *= strokeAlpha * scissor;\n"
"		result = color;\n"
"	} else if (type == 1) {		// Image\n"
"		// Calculate color fron texture\n"
"		vec2 pt = (paintMat * vec3(fpos,1.0)).xy / extent;\n"
"#ifdef MRKUI_GL3\n"
"		vec4 color = texture(tex, pt);\n"
"#else\n"
"		vec4 color = texture2D(tex, pt);\n"
"#endif\n"
"		if (texType == 1) color = vec4(color.xyz*color.w,color.w);"
"		if (texType == 2) color = vec4(color.x);"
"		// Apply color tint and alpha.\n"
"		color *= innerCol;\n"
"		// Combine alpha\n"
"		color *= strokeAlpha * scissor;\n"
"		result = color;\n"
"	} else if (type == 2) {		// Stencil fill\n"
"		result = vec4(1,1,1,1);\n"
"	} else if (type == 3) {		// Textured tris\n"
"#ifdef MRKUI_GL3\n"
"		vec4 color = texture(tex, ftcoord);\n"
"#else\n"
"		vec4 color = texture2D(tex, ftcoord);\n"
"#endif\n"
"		if (texType == 1) color = vec4(color.xyz*color.w,color.w);"
"		if (texType == 2) color = vec4(color.x);"
"		color *= scissor;\n"
"		result = color * innerCol;\n"
"	}\n"
"#ifdef MRKUI_GL3\n"
"	outColor = result;\n"
"#else\n"
"	gl_FragColor = result;\n"
"#endif\n"
"}\n";

mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "init");

if (gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_ANTIALIAS) {
if (mBhfTbQtYHddnCkUONUZ1WBFiVfnLUvB7TdpFBjPP(&gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, "shader", shaderHeader, "#define EDGE_AA 1\n", fillVertShader, fillFragShader) == 0)
return 0;
} else {
if (mBhfTbQtYHddnCkUONUZ1WBFiVfnLUvB7TdpFBjPP(&gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37, "shader", shaderHeader, NULL, fillVertShader, fillFragShader) == 0)
return 0;
}

mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "uniform locations");
m8XyJhLcXvJUnL1KuLBUKjtoStPj1a0dP0VFQ6XFD(&gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37);

// Create dynamic vertex array
#if defined MRKUI_GL3
glGenVertexArrays(1, &gl->vertArr);
#endif
glGenBuffers(1, &gl->vertBuf);

#if MRKUI_GL_USE_UNIFORMBUFFER
// Create UBOs
glUniformBlockBinding(gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.prog, gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.loc[GLMRKUI_LOC_FRAG], GLMRKUI_FRAG_BINDING);
glGenBuffers(1, &gl->fragBuf);
glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz);
#endif
gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5 = sizeof(mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL) + miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz - sizeof(mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL) % miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz;

mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "create done");

glFinish();

return 1;
}

static int mtCnOwWdCGiKmq15q1VcaXnbxRqh8IxghtjAme6h7(void* uptr, int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, int w, int h, int imageFlags, const unsigned char* data)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__allocTexture(gl);

if (tex == NULL) return 0;

#ifdef MRKUI_GLES2
// Check for non-power of 2.
if (mzd2dfym3I8JebtNOey4ujFhKapzCs9V0vwmJL4Ze(w) != (unsigned int)w || mzd2dfym3I8JebtNOey4ujFhKapzCs9V0vwmJL4Ze(h) != (unsigned int)h) {
// No repeat
if ((imageFlags & MRKUI_IMAGE_REPEATX) != 0 || (imageFlags & MRKUI_IMAGE_REPEATY) != 0) {
printf("Repeat X/Y is not supported for non power-of-two textures (%d x %d)\n", w, h);
imageFlags &= ~(MRKUI_IMAGE_REPEATX | MRKUI_IMAGE_REPEATY);
}
// No mips.
if (imageFlags & MRKUI_IMAGE_GENERATE_MIPMAPS) {
printf("Mip-maps is not support for non power-of-two textures (%d x %d)\n", w, h);
imageFlags &= ~MRKUI_IMAGE_GENERATE_MIPMAPS;
}
}
#endif

glGenTextures(1, &tex->tex);
tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = w;
tex->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = h;
tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
tex->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = imageFlags;
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, tex->tex);

glPixelStorei(GL_UNPACK_ALIGNMENT,1);
#ifndef MRKUI_GLES2
glPixelStorei(GL_UNPACK_ROW_LENGTH, tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
#endif

#if defined (MRKUI_GL2)
// GL 1.4 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 later has support for generating mipmaps using mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c tex parameter.
if (imageFlags & MRKUI_IMAGE_GENERATE_MIPMAPS) {
glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
}
#endif

if (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_TEXTURE_RGBA)
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
else
#if defined(MRKUI_GLES2) || defined (MRKUI_GL2)
glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
#elif defined(MRKUI_GLES3)
glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, w, h, 0, GL_RED, GL_UNSIGNED_BYTE, data);
#else
glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, w, h, 0, GL_RED, GL_UNSIGNED_BYTE, data);
#endif

if (imageFlags & MRKUI_IMAGE_GENERATE_MIPMAPS) {
if (imageFlags & MRKUI_IMAGE_NEAREST) {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
} else {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}
} else {
if (imageFlags & MRKUI_IMAGE_NEAREST) {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
} else {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}
}

if (imageFlags & MRKUI_IMAGE_NEAREST) {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
} else {
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

if (imageFlags & MRKUI_IMAGE_REPEATX)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
else
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

if (imageFlags & MRKUI_IMAGE_REPEATY)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
else
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
#ifndef MRKUI_GLES2
glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
#endif

// The new way myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT build mipmaps on GLES mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 GL3
#if !defined(MRKUI_GL2)
if (imageFlags & MRKUI_IMAGE_GENERATE_MIPMAPS) {
glGenerateMipmap(GL_TEXTURE_2D);
}
#endif

mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "create tex");
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, 0);

return tex->ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl;
}


static int mcXNUm98PjHa4llLsAcG8kTzzLF9PeCyG0PsoKFOR(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
return mCL3CNZVhaCeAnPLdnayWMo6jpJQitj9lH6Og4uyE(gl, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
}

static int mciPoRem7O7er3QO0wQHnNddvlepl3dTReh2gheYG(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, int y, int w, int h, const unsigned char* data)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__findTexture(gl, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

if (tex == NULL) return 0;
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, tex->tex);

glPixelStorei(GL_UNPACK_ALIGNMENT,1);

#ifndef MRKUI_GLES2
glPixelStorei(GL_UNPACK_ROW_LENGTH, tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
glPixelStorei(GL_UNPACK_SKIP_PIXELS, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
glPixelStorei(GL_UNPACK_SKIP_ROWS, y);
#else
// No support for all of skip, need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT update mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c whole row at mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c time.
if (tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_TEXTURE_RGBA)
data += y*tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn*4;
else
data += y*tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0;
w = tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
#endif

if (tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_TEXTURE_RGBA)
glTexSubImage2D(GL_TEXTURE_2D, 0, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, w,h, GL_RGBA, GL_UNSIGNED_BYTE, data);
else
#if defined(MRKUI_GLES2) || defined(MRKUI_GL2)
glTexSubImage2D(GL_TEXTURE_2D, 0, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, w,h, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
#else
glTexSubImage2D(GL_TEXTURE_2D, 0, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, w,h, GL_RED, GL_UNSIGNED_BYTE, data);
#endif

glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
#ifndef MRKUI_GLES2
glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
#endif

mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, 0);

return 1;
}

static int mq0yUxNhJyTNzJbZtJmamKyF14GVhnc6fueAjwljm(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int* w, int* h)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__findTexture(gl, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
if (tex == NULL) return 0;
*w = tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
*h = tex->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
return 1;
}

static void m1Ie5hUHbvOBtMB5b9Sw7nbQyhD5ZCIqQ6EGZAwL4(float* m3, float* mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
{
m3[0] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[0];
m3[1] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[1];
m3[2] = 0.0f;
m3[3] = 0.0f;
m3[4] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[2];
m3[5] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[3];
m3[6] = 0.0f;
m3[7] = 0.0f;
m3[8] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[4];
m3[9] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU[5];
m3[10] = 1.0f;
m3[11] = 0.0f;
}

static mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk m3yTNqSAzyBEpnNraixDjpN5INq72ObFPptxo55KA(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c)
{
c.mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC *= c.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
c.g *= c.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
c.b *= c.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
return c;
}

static int mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* frag, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint,
   mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, float fringe, float m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk)
{
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = NULL;
float invxform[6];

memset(frag, 0, sizeof(*frag));

frag->mVFGcP0i08BlDERV3DCNVPeLLZFTQqHyhN01lQs5e = m3yTNqSAzyBEpnNraixDjpN5INq72ObFPptxo55KA(paint->mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0);
frag->mWAgLYA6sXdgAseIoTHVzXQhgikCJwoo5GWTHZo2n = m3yTNqSAzyBEpnNraixDjpN5INq72ObFPptxo55KA(paint->mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH);

if (mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->extent[0] < -0.5f || mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->extent[1] < -0.5f) {
memset(frag->scissorMat, 0, sizeof(frag->scissorMat));
frag->scissorExt[0] = 1.0f;
frag->scissorExt[1] = 1.0f;
frag->scissorScale[0] = 1.0f;
frag->scissorScale[1] = 1.0f;
} else {
mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(invxform, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform);
m1Ie5hUHbvOBtMB5b9Sw7nbQyhD5ZCIqQ6EGZAwL4(frag->scissorMat, invxform);
frag->scissorExt[0] = mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->extent[0];
frag->scissorExt[1] = mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->extent[1];
frag->scissorScale[0] = sqrtf(mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[0]*mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[0] + mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[2]*mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[2]) / fringe;
frag->scissorScale[1] = sqrtf(mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[1]*mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[1] + mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[3]*mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq->xform[3]) / fringe;
}

memcpy(frag->extent, paint->extent, sizeof(frag->extent));
frag->mGgaEz43UEiole5u7RU0JXROcfUgARXbqRB1fXoOJ = (myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn*0.5f + fringe*0.5f) / fringe;
frag->m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk = m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk;

if (paint->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R != 0) {
tex = glMRKUI__findTexture(gl, paint->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
if (tex == NULL) return 0;
if ((tex->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_IMAGE_FLIPY) != 0) {
float m1[6], m2[6];
m5Iobq0jvOmr7hbArbk1JRu1DW8sDF6tTE97isYAJ(m1, 0.0f, frag->extent[1] * 0.5f);
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(m1, paint->xform);
mfCoEfOtuOAQaWLRUJvPvXh3SDigf79DxeIQDFdHg(m2, 1.0f, -1.0f);
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(m2, m1);
m5Iobq0jvOmr7hbArbk1JRu1DW8sDF6tTE97isYAJ(m1, 0.0f, -frag->extent[1] * 0.5f);
m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(m1, m2);
mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(invxform, m1);
} else {
mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(invxform, paint->xform);
}
frag->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = NSVG_SHADER_FILLIMG;

#if MRKUI_GL_USE_UNIFORMBUFFER
if (tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_TEXTURE_RGBA)
frag->mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W = (tex->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_IMAGE_PREMULTIPLIED) ? 0 : 1;
else
frag->mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W = 2;
#else
if (tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == MRKUI_TEXTURE_RGBA)
frag->mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W = (tex->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_IMAGE_PREMULTIPLIED) ? 0.0f : 1.0f;
else
frag->mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W = 2.0f;
#endif
//printf("frag->texType = %d\n", frag->mcnpvd2WqqmbuYY3yYFHz61PPLVXQfiEDrAs4ZE5W);
} else {
frag->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = NSVG_SHADER_FILLGRAD;
frag->mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA = paint->mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
frag->mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl = paint->mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl;
mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(invxform, paint->xform);
}

m1Ie5hUHbvOBtMB5b9Sw7nbQyhD5ZCIqQ6EGZAwL4(frag->paintMat, invxform);

return 1;
}

static mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int i);

static void mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
{
#if MRKUI_GL_USE_UNIFORMBUFFER
glBindBufferRange(GL_UNIFORM_BUFFER, GLMRKUI_FRAG_BINDING, gl->fragBuf, mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, sizeof(mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL));
#else
mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* frag = mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU);
glUniform4fv(gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.loc[GLMRKUI_LOC_FRAG], MRKUI_GL_UNIFORMARRAY_SIZE, &(frag->uniformArray[0][0]));
#endif

if (mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R != 0) {
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__findTexture(gl, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, tex != NULL ? tex->tex : 0);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "tex paint tex");
} else {
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, 0);
}
}

static void mE3iwZmC1WzUfULz1F9xr4IBcKog4FstrDAjLxsjv(void* uptr, float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, float mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, float devicePixelRatio)
{
mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(devicePixelRatio);
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
gl->view[0] = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
gl->view[1] = mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
}

static void mo3lpVAyNu0N9I23QpWh1EqQvIKCgtxcPdSezhZq0(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call)
{
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* paths = &gl->paths[call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p];
int i, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = call->mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs;

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD shapes
glEnable(GL_STENCIL_TEST);
mhHTe9yfypzJhgE5V1qDaWa47u9BixmGoG0FKEWBy(gl, 0xff);
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_ALWAYS, 0, 0xff);
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

// set bindpoint for solid loc
mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, 0);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "fill simple");

glStencilOpSeparate(GL_FRONT, GL_KEEP, GL_KEEP, GL_INCR_WRAP);
glStencilOpSeparate(GL_BACK, GL_KEEP, GL_KEEP, GL_DECR_WRAP);
glDisable(GL_CULL_FACE);
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_FAN, paths[i].mV6Ymwo4OAavNckWMsuOBvHvudaSkP99DpZ0RC2C7, paths[i].mqiEl06lgwkdBBvgvz8JJ6cMN9B6CfzjnkBtBprgL);
glEnable(GL_CULL_FACE);

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD anti-aliased m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU + gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "fill fill");

if (gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_ANTIALIAS) {
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_EQUAL, 0x00, 0xff);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD fringes
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);
}

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_NOTEQUAL, 0x0, 0xff);
glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO);
glDrawArrays(GL_TRIANGLE_STRIP, call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK, call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc);

glDisable(GL_STENCIL_TEST);
}

static void mzQWPnwnEFfT9FqCaVD1fKiTLaszYgKXL31HtIHOP(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call)
{
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* paths = &gl->paths[call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p];
int i, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = call->mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs;

mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "convex fill");

for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
glDrawArrays(GL_TRIANGLE_FAN, paths[i].mV6Ymwo4OAavNckWMsuOBvHvudaSkP99DpZ0RC2C7, paths[i].mqiEl06lgwkdBBvgvz8JJ6cMN9B6CfzjnkBtBprgL);
// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD fringes
if (paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA > 0) {
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);
}
}
}

static void mEDIKwgSGtfDpix4SbyAr7LByImEzVJwi7QcCUqP9(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call)
{
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* paths = &gl->paths[call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p];
int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = call->mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs, i;

if (gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_STENCIL_STROKES) {

glEnable(GL_STENCIL_TEST);
mhHTe9yfypzJhgE5V1qDaWa47u9BixmGoG0FKEWBy(gl, 0xff);

// Fill the mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 base without overlap
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_EQUAL, 0x0, 0xff);
glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);
mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU + gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "stroke fill 0");
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD anti-aliased m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam.
mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_EQUAL, 0x00, 0xff);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);

// Clear stencil buffer.
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
m8CKIP75478Wc73uxE4wxHyVd4vMgbdgQ9GbdU6VK(gl, GL_ALWAYS, 0x0, 0xff);
glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "stroke fill 1");
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

glDisable(GL_STENCIL_TEST);

//mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU + gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, fringe, 1.0f - 0.5f/255.0f);

} else {
mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "stroke fill");
// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD Strokes
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++)
glDrawArrays(GL_TRIANGLE_STRIP, paths[i].m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0, paths[i].mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA);
}
}

static void mKWq13JZuVlqh3AMe7s87CkkM4YA6ZycRT3dPhsvG(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call)
{
mQEcC0mlx1SBQMf6hQrkNVodneTjf8L3lNEy1sMsR(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU, call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
mboMCq4QjVlhPAQX67c5sImedKqYOOf1dg4xRP6au(gl, "triangles fill");

glDrawArrays(GL_TRIANGLES, call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK, call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc);
}

static void mfqZNFq3KUiOBlsEKI4utUTSsHb5CRszPbI4mC6zm(void* uptr) {
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;
gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = 0;
gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 = 0;
gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ = 0;
}

static GLenum glMRKUI_convertBlendFuncFactor(int factor)
{
if (factor == MRKUI_ZERO)
return GL_ZERO;
if (factor == MRKUI_ONE)
return GL_ONE;
if (factor == MRKUI_SRC_COLOR)
return GL_SRC_COLOR;
if (factor == MRKUI_ONE_MINUS_SRC_COLOR)
return GL_ONE_MINUS_SRC_COLOR;
if (factor == MRKUI_DST_COLOR)
return GL_DST_COLOR;
if (factor == MRKUI_ONE_MINUS_DST_COLOR)
return GL_ONE_MINUS_DST_COLOR;
if (factor == MRKUI_SRC_ALPHA)
return GL_SRC_ALPHA;
if (factor == MRKUI_ONE_MINUS_SRC_ALPHA)
return GL_ONE_MINUS_SRC_ALPHA;
if (factor == MRKUI_DST_ALPHA)
return GL_DST_ALPHA;
if (factor == MRKUI_ONE_MINUS_DST_ALPHA)
return GL_ONE_MINUS_DST_ALPHA;
if (factor == MRKUI_SRC_ALPHA_SATURATE)
return GL_SRC_ALPHA_SATURATE;
return GL_INVALID_ENUM;
}

static mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC m6eNCaDUVutkDelgOIrYGv60w3yHjp32AIwpax6al(mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9)
{
mCDqBd35ar8M21mAw3FEHeTphJIxBFNYFfIePIzUC mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P;
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS = glMRKUI_convertBlendFuncFactor(mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS);
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi = glMRKUI_convertBlendFuncFactor(mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi);
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH = glMRKUI_convertBlendFuncFactor(mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH);
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g = glMRKUI_convertBlendFuncFactor(mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g);
if (mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS == GL_INVALID_ENUM || mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi == GL_INVALID_ENUM || mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH == GL_INVALID_ENUM || mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g == GL_INVALID_ENUM)
{
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS = GL_ONE;
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi = GL_ONE_MINUS_SRC_ALPHA;
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH = GL_ONE;
mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g = GL_ONE_MINUS_SRC_ALPHA;
}
return mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P;
}

static void mt3Rrurl40gbkqTPGJIR25WID0jPPS82fvUag9ocy(void* uptr)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
int i;

if (gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 > 0) {

// Setup require GL msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.
glUseProgram(gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.prog);

glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);
glFrontFace(GL_CCW);
glEnable(GL_BLEND);
glDisable(GL_DEPTH_TEST);
glDisable(GL_SCISSOR_TEST);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
glStencilMask(0xffffffff);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
glStencilFunc(GL_ALWAYS, 0, 0xffffffff);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, 0);
#if mCLZm4Y8XR5QGigHTT22LSDTqaePoMO0UcY5eMpRZ
gl->boundTexture = 0;
gl->stencilMask = 0xffffffff;
gl->stencilFunc = GL_ALWAYS;
gl->stencilFuncRef = 0;
gl->stencilFuncMask = 0xffffffff;
gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS = GL_INVALID_ENUM;
gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH = GL_INVALID_ENUM;
gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi = GL_INVALID_ENUM;
gl->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv.mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g = GL_INVALID_ENUM;
#endif

#if MRKUI_GL_USE_UNIFORMBUFFER
// Upload ubo for frag shaders
glBindBuffer(GL_UNIFORM_BUFFER, gl->fragBuf);
glBufferData(GL_UNIFORM_BUFFER, gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ * gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5, gl->uniforms, GL_STREAM_DRAW);
#endif

// Upload vertex data
#if defined MRKUI_GL3
glBindVertexArray(gl->vertArr);
#endif
glBindBuffer(GL_ARRAY_BUFFER, gl->vertBuf);
glBufferData(GL_ARRAY_BUFFER, gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA * sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv), gl->verts, GL_STREAM_DRAW);
glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv), (const GLvoid*)(size_t)0);
glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv), (const GLvoid*)(0 + 2*sizeof(float)));

// Set view mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 texture just once per frame.
glUniform1i(gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.loc[GLMRKUI_LOC_TEX], 0);
glUniform2fv(gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37.loc[GLMRKUI_LOC_VIEWSIZE], 1, gl->view);

#if MRKUI_GL_USE_UNIFORMBUFFER
glBindBuffer(GL_UNIFORM_BUFFER, gl->fragBuf);
#endif

for (i = 0; i < gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4; i++) {
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call = &gl->calls[i];
mkUR1gwwAwJSlDuiiQ6k6T6UA6RL0VTr6biSFh5je(gl,&call->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv);
if (call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == GLMRKUI_FILL)
mo3lpVAyNu0N9I23QpWh1EqQvIKCgtxcPdSezhZq0(gl, call);
else if (call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == GLMRKUI_CONVEXFILL)
mzQWPnwnEFfT9FqCaVD1fKiTLaszYgKXL31HtIHOP(gl, call);
else if (call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == GLMRKUI_STROKE)
mEDIKwgSGtfDpix4SbyAr7LByImEzVJwi7QcCUqP9(gl, call);
else if (call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == GLMRKUI_TRIANGLES)
mKWq13JZuVlqh3AMe7s87CkkM4YA6ZycRT3dPhsvG(gl, call);
}

glDisableVertexAttribArray(0);
glDisableVertexAttribArray(1);
#if defined MRKUI_GL3
glBindVertexArray(0);
#endif
glDisable(GL_CULL_FACE);
glBindBuffer(GL_ARRAY_BUFFER, 0);
glUseProgram(0);
mhLyv62OH9GapWAD11Mb3DFzDFDeSjz4veOxKFbYq(gl, 0);
}

// Reset calls
gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;
gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz = 0;
gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 = 0;
gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ = 0;
}

static int mqvNogvgWWNLp4Z17UD5G6IccAG0291tZcmJbEJHJ(const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths, int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz)
{
int i, count = 0;
for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
count += paths[i].mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ;
count += paths[i].maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
}
return count;
}

static mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* glMRKUI__allocCall(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl)
{
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* ret = NULL;
if (gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4+1 > gl->my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa) {
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* calls;
int my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa = mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4+1, 128) + gl->my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa/2; // 1.5m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp Overallocate
calls = (mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv*)realloc(gl->calls, sizeof(mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv) * my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa);
if (calls == NULL) return NULL;
gl->calls = calls;
gl->my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa = my2UYRqZLJFW1HvTXxzz4pM9ovCaPXZX78gdTNiPa;
}
ret = &gl->calls[gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4++];
memset(ret, 0, sizeof(mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv));
return ret;
}

static int myPuRK8OIep1lZwrtWiyCSfqOMuh4DusJBHWM4QbC(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int n)
{
int ret = 0;
if (gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz+n > gl->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU) {
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* paths;
int mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU = mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz + n, 128) + gl->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU/2; // 1.5m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp Overallocate
paths = (mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6*)realloc(gl->paths, sizeof(mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6) * mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU);
if (paths == NULL) return -1;
gl->paths = paths;
gl->mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU = mZch9y9unram8zGTnjnQwXPqgzqsLIhBTCBoppuyU;
}
ret = gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz;
gl->m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz += n;
return ret;
}

static int mzZLnpK9DvCXsEeRGIUZpdopnUJk8LQdAv3St3kbx(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int n)
{
int ret = 0;
if (gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA+n > gl->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3) {
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts;
int m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA + n, 4096) + gl->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3/2; // 1.5m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp Overallocate
verts = (mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv*)realloc(gl->verts, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv) * m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3);
if (verts == NULL) return -1;
gl->verts = verts;
gl->m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3 = m6onPj4Knp1rhwtTXlBvcg8IBKkNTCcVU6MyYphh3;
}
ret = gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA;
gl->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA += n;
return ret;
}

static int mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int n)
{
int ret = 0, structSize = gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5;
if (gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ+n > gl->mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j) {
unsigned char* uniforms;
int mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j = mbvLVWkCs0KZQeFOtkQtBnfwcK8YarwdURwyc7Lsf(gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ+n, 128) + gl->mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j/2; // 1.5m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp Overallocate
uniforms = (unsigned char*)realloc(gl->uniforms, structSize * mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j);
if (uniforms == NULL) return -1;
gl->uniforms = uniforms;
gl->mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j = mFVYBN73W81olpkHSbllrHfQg2tb8e2vQnJtUGM1j;
}
ret = gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ * structSize;
gl->miLVi5izRMBFdoZkqiNlVkb2RZ63JCbzijfViRlWZ += n;
return ret;
}

static mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl, int i)
{
return (mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL*)&gl->uniforms[i];
}

static void mO3Vy65mNlpyns62opWMkdOuIaaCzaIHczKYF0I3h(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* vtx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float u, float v)
{
vtx->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
vtx->y = y;
vtx->u = u;
vtx->v = v;
}

static void m3AtLOnodCCGUwIuYP904IZF8lcjnrIMRBw4sU4B6(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, float fringe,
  const float* bounds, const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths, int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call = glMRKUI__allocCall(gl);
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* quad;
mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* frag;
int i, maxverts, offset;

if (call == NULL) return;

call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = GLMRKUI_FILL;
call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc = 4;
call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p = myPuRK8OIep1lZwrtWiyCSfqOMuh4DusJBHWM4QbC(gl, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
if (call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p == -1) goto error;
call->mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs = m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz;
call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = paint->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
call->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv = m6eNCaDUVutkDelgOIrYGv60w3yHjp32AIwpax6al(mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG);

if (m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz == 1 && paths[0].m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1)
{
call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = GLMRKUI_CONVEXFILL;
call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc = 0;// Bounding box m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB quad not needed for m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1 m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB
}

// Allocate vertices for all the paths.
maxverts = mqvNogvgWWNLp4Z17UD5G6IccAG0291tZcmJbEJHJ(paths, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz) + call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc;
offset = mzZLnpK9DvCXsEeRGIUZpdopnUJk8LQdAv3St3kbx(gl, maxverts);
if (offset == -1) goto error;

for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* copy = &gl->paths[call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p + i];
const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &paths[i];
memset(copy, 0, sizeof(mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6));
if (path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ > 0) {
copy->mV6Ymwo4OAavNckWMsuOBvHvudaSkP99DpZ0RC2C7 = offset;
copy->mqiEl06lgwkdBBvgvz8JJ6cMN9B6CfzjnkBtBprgL = path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ;
memcpy(&gl->verts[offset], path->m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv) * path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ);
offset += path->mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ;
}
if (path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza > 0) {
copy->m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0 = offset;
copy->mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA = path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
memcpy(&gl->verts[offset], path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv) * path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza);
offset += path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
}
}

// Setup uniforms for draw calls
if (call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == GLMRKUI_FILL) {
// Quad
call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK = offset;
quad = &gl->verts[call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK];
mO3Vy65mNlpyns62opWMkdOuIaaCzaIHczKYF0I3h(&quad[0], bounds[2], bounds[3], 0.5f, 1.0f);
mO3Vy65mNlpyns62opWMkdOuIaaCzaIHczKYF0I3h(&quad[1], bounds[2], bounds[1], 0.5f, 1.0f);
mO3Vy65mNlpyns62opWMkdOuIaaCzaIHczKYF0I3h(&quad[2], bounds[0], bounds[3], 0.5f, 1.0f);
mO3Vy65mNlpyns62opWMkdOuIaaCzaIHczKYF0I3h(&quad[3], bounds[0], bounds[1], 0.5f, 1.0f);

call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU = mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(gl, 2);
if (call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU == -1) goto error;
// Simple mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37 for stencil
frag = mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU);
memset(frag, 0, sizeof(*frag));
frag->m672lkFtBcrYccmWtn3D8bF0Aj3DwS40ycFhNP5yk = -1.0f;
frag->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = NSVG_SHADER_SIMPLE;
// Fill mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37
mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU + gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, fringe, fringe, -1.0f);
} else {
call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU = mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(gl, 1);
if (call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU == -1) goto error;
// Fill mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37
mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, fringe, fringe, -1.0f);
}

return;

error:
// We get here if call alloc was ok, but something else is not.
// Roll back the last call myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prevent drawing it.
if (gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 > 0) gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4--;
}

static void m5xId5sSWlrsFjCP5dlcDIPQmlX0YLZBaolwoQ0WO(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, float fringe,
float mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths, int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call = glMRKUI__allocCall(gl);
int i, maxverts, offset;

if (call == NULL) return;

call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = GLMRKUI_STROKE;
call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p = myPuRK8OIep1lZwrtWiyCSfqOMuh4DusJBHWM4QbC(gl, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
if (call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p == -1) goto error;
call->mBpHrCk6RV5wmT7S45DwPDnBXVkb5wcxitoIvoucs = m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz;
call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = paint->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
call->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv = m6eNCaDUVutkDelgOIrYGv60w3yHjp32AIwpax6al(mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG);

// Allocate vertices for all the paths.
maxverts = mqvNogvgWWNLp4Z17UD5G6IccAG0291tZcmJbEJHJ(paths, m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
offset = mzZLnpK9DvCXsEeRGIUZpdopnUJk8LQdAv3St3kbx(gl, maxverts);
if (offset == -1) goto error;

for (i = 0; i < m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz; i++) {
mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6* copy = &gl->paths[call->mWuOegCppQZ3EQR4H5t719GqbafHJDMPQ37oE559p + i];
const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* path = &paths[i];
memset(copy, 0, sizeof(mrqxP03eRSFgOIlApKtibO9DXdSCkwf2eBdwlpTi6));
if (path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza) {
copy->m96ULVOLGIGJ7O3If56gTeeKQglSFnoMIhHP6vAa0 = offset;
copy->mY6UuPfQUn8qZQg0wUFZ9S6BFNuCCjtJOjUzwWvBA = path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
memcpy(&gl->verts[offset], path->mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv) * path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza);
offset += path->maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
}
}

if (gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_STENCIL_STROKES) {
// Fill mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37
call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU = mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(gl, 2);
if (call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU == -1) goto error;

mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, fringe, -1.0f);
mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU + gl->mWHKx7tOielraoAe7V4T1rxocevZ9E82vV8Hd5EI5), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, fringe, 1.0f - 0.5f/255.0f);

} else {
// Fill mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37
call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU = mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(gl, 1);
if (call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU == -1) goto error;
mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU), paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, fringe, -1.0f);
}

return;

error:
// We get here if call alloc was ok, but something else is not.
// Roll back the last call myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prevent drawing it.
if (gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 > 0) gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4--;
}

static void mShvWx6WQV4DVIZ7MJ3tmXd3SXB3Hl26XLHHVTsTv(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq,
   const mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts, int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
mOqT8YHTkq84siWbj6WmJsjIJEcdVsMbrbt9rKYIv* call = glMRKUI__allocCall(gl);
mB21F8vky9jjO8HDfLLL6rIow9oG1bXiZsud9izOL* frag;

if (call == NULL) return;

call->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = GLMRKUI_TRIANGLES;
call->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R = paint->mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
call->mCMeyxa9uUvWTBax3BQzoENwi2zIdZxnOwx1M8ouv = m6eNCaDUVutkDelgOIrYGv60w3yHjp32AIwpax6al(mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG);

// Allocate vertices for all the paths.
call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK = mzZLnpK9DvCXsEeRGIUZpdopnUJk8LQdAv3St3kbx(gl, mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);
if (call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK == -1) goto error;
call->mFjD0AsTLXNIwZ56r6dMkdkIHKyr253l3E4kRSDzc = mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA;

memcpy(&gl->verts[call->mqeIyBKHM4jOsyWrB1urTxmD4G1vjQi8R8WRdtMXK], verts, sizeof(mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv) * mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);

// Fill mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37
call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU = mTSeZOaDCfYiBo9wUq7KP0W5IWcEJAiCMqI6I6ZJL(gl, 1);
if (call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU == -1) goto error;
frag = mowVLcb4Cre49PNMtyN53ieJBe4jO6ZjLYT1FDWP7(gl, call->mDgnUGsAuOT4z5kTlilKbWsB6Uk9B4gHszpHurinU);
mF1XP4k9SHwE7W5ohhCRQ3htSqQSrXxerYbozXdMj(gl, frag, paint, mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, 1.0f, 1.0f, -1.0f);
frag->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = NSVG_SHADER_IMG;

return;

error:
// We get here if call alloc was ok, but something else is not.
// Roll back the last call myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prevent drawing it.
if (gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4 > 0) gl->mVvfFXupnznVVodXeFLvmSfj3qcagnOvCzUCM3Aj4--;
}

static void mW5wG8fZsuNxEsnYUNf7SVrPCzJbamX8mVwBqAQxq(void* uptr)
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)uptr;
int i;
if (gl == NULL) return;

mphaN1VQT0Q4jUZeFDKCxILk4eqrBs3dcfRcbATQI(&gl->mWKloKyzP7AI4cnAkbecfz8M8fiBfRFFDLuZ5sa37);

#if MRKUI_GL3
#if MRKUI_GL_USE_UNIFORMBUFFER
if (gl->fragBuf != 0)
glDeleteBuffers(1, &gl->fragBuf);
#endif
if (gl->vertArr != 0)
glDeleteVertexArrays(1, &gl->vertArr);
#endif
if (gl->vertBuf != 0)
glDeleteBuffers(1, &gl->vertBuf);

for (i = 0; i < gl->m3dXFUUQ1BMseJm3G7DZ2fE9mkJcfZelWrS93Kt2E; i++) {
if (gl->textures[i].tex != 0 && (gl->textures[i].m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_IMAGE_NODELETE) == 0)
glDeleteTextures(1, &gl->textures[i].tex);
}
free(gl->textures);

free(gl->paths);
free(gl->verts);
free(gl->uniforms);
free(gl->calls);

free(gl);
}


#if defined MRKUI_GL2
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* m9Ngz2briPGjprzrHsFQRLyH3germdNJ8NWLH9cO2(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
#elif defined MRKUI_GL3
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* m9qaGLB9d6kSay0Ssh4fxjnDR80ukS0BlUPxpWebX(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
#elif defined MRKUI_GLES2
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mjehP2hwYEpapVML419Sm6AokFHrqEoXqjg4GmDZL(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
#elif defined MRKUI_GLES3
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mv6fD4ZOs20s5sF0RaLlNqn4p91QUqpO5BS1sBEsU(int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
#endif
{
mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx = NULL;
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)malloc(sizeof(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P));
if (gl == NULL) goto error;
memset(gl, 0, sizeof(mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P));

memset(&m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk, 0, sizeof(m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk));
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreate = mVeG11qckkQEDaGfpAqrJUNtxthV8kJfPsahbmqHg;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreateTexture = mtCnOwWdCGiKmq15q1VcaXnbxRqh8IxghtjAme6h7;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDeleteTexture = mcXNUm98PjHa4llLsAcG8kTzzLF9PeCyG0PsoKFOR;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderUpdateTexture = mciPoRem7O7er3QO0wQHnNddvlepl3dTReh2gheYG;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderGetTextureSize = mq0yUxNhJyTNzJbZtJmamKyF14GVhnc6fueAjwljm;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderViewport = mE3iwZmC1WzUfULz1F9xr4IBcKog4FstrDAjLxsjv;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCancel = mfqZNFq3KUiOBlsEKI4utUTSsHb5CRszPbI4mC6zm;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderFlush = mt3Rrurl40gbkqTPGJIR25WID0jPPS82fvUag9ocy;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderFill = m3AtLOnodCCGUwIuYP904IZF8lcjnrIMRBw4sU4B6;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderStroke = m5xId5sSWlrsFjCP5dlcDIPQmlX0YLZBaolwoQ0WO;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderTriangles = mShvWx6WQV4DVIZ7MJ3tmXd3SXB3Hl26XLHHVTsTv;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDelete = mW5wG8fZsuNxEsnYUNf7SVrPCzJbamX8mVwBqAQxq;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr = gl;
m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mdFwDLRZbeFsqCZz9pURAan4Yu9PfxsoA1NcxRnS8 = m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & MRKUI_ANTIALIAS ? 1 : 0;

gl->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;

ctx = mxdzgKV0758RY1Q0kyyt9xf633PmvdswzqoLIlrys(&m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk);
if (ctx == NULL) goto error;

return ctx;

error:
// 'gl' is freed by mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt.
if (ctx != NULL) mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt(ctx);
return NULL;
}

#if defined MRKUI_GL2
void md3Kodz6DM0nLPRQiazCrQpCga8HC8pHxvlcdoIi2(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
#elif defined MRKUI_GL3
void mJJLnNKg6JzTH6aRFLq5zfQjMbyzmm6bj8Hv5bS80(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
#elif defined MRKUI_GLES2
void mTXoYjcfLhg7OhZfSOOsi4IGWpq05BdMBT2HU0WAK(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
#elif defined MRKUI_GLES3
void mtTs7jOn0BBdeOVgvcMHc4FpJ88e3UTa8qsHU66qH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx)
#endif
{
mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt(ctx);
}

#if defined MRKUI_GL2
int mOJYEWRGivYnIA7w8OhgSXwxeUenm8G7ptht94nY3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int imageFlags)
#elif defined MRKUI_GL3
int mXG8i05GcFkDp79AR3Z69KDtpriWgCZL0PMsvfBfb(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int imageFlags)
#elif defined MRKUI_GLES2
int mbNDj6EBhFgsE2p8dMkzQtgp6MtwzzbAI8XWyhIZE(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int imageFlags)
#elif defined MRKUI_GLES3
int mKBBSsBJj0LqXgEnxpUd9Re6cwmdp5eh7OnrsLtUD(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, GLuint mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx, int w, int h, int imageFlags)
#endif
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)m4wxdT9dKFfcmz4hiilC50tOQEk9Fof4hR6BfAXRF(ctx)->userPtr;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__allocTexture(gl);

if (tex == NULL) return 0;

tex->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = MRKUI_TEXTURE_RGBA;
tex->tex = mvbUXP2bzSE2pD9mCNqJFhJWUykEkbqP4vv8MMJEx;
tex->m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = imageFlags;
tex->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = w;
tex->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = h;

return tex->ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl;
}

#if defined MRKUI_GL2
GLuint m1JPqNUXEtiXwxpjaJfOkZlzdmFzJ4RuJ0AqSOZ54(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
#elif defined MRKUI_GL3
GLuint mC8seyhmmHvNULUrG7xf7X7fb17eYtpedBt7jHCaT(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
#elif defined MRKUI_GLES2
GLuint moKnx5evqI2ZQl78o4zXmb7QpVYQjoze4kEbqiw0O(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
#elif defined MRKUI_GLES3
GLuint mMFrUATJuwe61hht7K2U4y62i9QxhYJiuz8zeZACr(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R)
#endif
{
mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P* gl = (mDUkBFJBan3Rz6IVBsnxQsKGiR1O5OsppMikRfA2P*)m4wxdT9dKFfcmz4hiilC50tOQEk9Fof4hR6BfAXRF(ctx)->userPtr;
mQfIy64FU2X03ZQXu9f4oDzSEZRN8OcCM2LR08P0a* tex = glMRKUI__findTexture(gl, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
return tex->tex;
}

#endif /* MRKUI_GL_IMPLEMENTATION */
