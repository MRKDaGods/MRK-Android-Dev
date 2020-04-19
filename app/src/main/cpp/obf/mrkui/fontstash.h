#ifndef FONS_H
#define FONS_H

#define FONS_INVALID -1

enum FONSflags {
FONS_ZERO_TOPLEFT = 1,
FONS_ZERO_BOTTOMLEFT = 2,
};

enum FONSalign {
// Horizontal miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz
FONS_ALIGN_LEFT = 1<<0,// Default
FONS_ALIGN_CENTER = 1<<1,
FONS_ALIGN_RIGHT = 1<<2,
// Vertical miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz
FONS_ALIGN_TOP = 1<<3,
FONS_ALIGN_MIDDLE= 1<<4,
FONS_ALIGN_BOTTOM= 1<<5,
FONS_ALIGN_BASELINE= 1<<6, // Default
};

enum FONSglyphBitmap {
FONS_GLYPH_BITMAP_OPTIONAL = 1,
FONS_GLYPH_BITMAP_REQUIRED = 2,
};

enum FONSerrorCode {
// Font atlas is full.
FONS_ATLAS_FULL = 1,
// Scratch memory used myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render glyphs is full, requested size reported in 'val', you may need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT bump up FONS_SCRATCH_BUF_SIZE.
FONS_SCRATCH_FULL = 2,
// Calls myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mtJnqTShpQhBSqGlYw1GUVKppZmj6to2y8k8qLNEj has created too large stack, if you need deep msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 stack bump up FONS_MAX_STATES.
FONS_STATES_OVERFLOW = 3,
// Trying myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT pop too many states mMOSoAfw0yMSC1XdM1ejVsS7hvTNy7E0W7SQ4tusp().
FONS_STATES_UNDERFLOW = 4,
};

struct m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx {
int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
unsigned char m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;
void* userPtr;
int (*renderCreate)(void* uptr, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
int (*renderResize)(void* uptr, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
void (*renderUpdate)(void* uptr, int* rect, const unsigned char* data);
void (*renderDraw)(void* uptr, const float* verts, const float* tcoords, const unsigned int* colors, int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);
void (*renderDelete)(void* uptr);
};
typedef struct m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx;

struct mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8
{
float x0,y0,s0,t0;
float x1,y1,s1,t1;
};
typedef struct mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8;

struct mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW {
float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, nextx, nexty, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s;
unsigned int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
short isize, iblur;
struct mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
int mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm;
const char* str;
const char* mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
const char* end;
unsigned int mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl;
int mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u;
};
typedef struct mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW;

typedef struct mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm;

// Constructor mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 destructor.
mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* fonsCreateInternal(m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx* m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk);
void m4X2WYU3dbT2MbC06eMvvZPgza6hxYrjUFzFNDNTn(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s);

void mfSqr199KBchusmZdvrjEUGn5mxHafvlF4FMFdE3h(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, void (*callback)(void* uptr, int error, int val), void* uptr);
// Returns current atlas size.
void mCLnHuss0SRna4vUxe0Ru21AfH6Jf7uw2tXrRwnQY(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, int* myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int* mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
// Expands the atlas size.
int mKzMmbkPg48FMCVM8ZSHum9ev8arIsAV1HNAyXbCr(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
// Resets the whole stash.
int mnvwva4NVW9YH0eW70Ga58c2O04LAwNj4qN7eeiXF(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

// Add fonts
int mJRBeC21nobd9NV6L8lzOus5k5PXtlIK5jZxqknQJ(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, const char* name, const char* path);
int mlHxLh07uUuA4qDyLtpqLXteafiyEOTVNgcqcKpaQ(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, const char* name, unsigned char* data, int ndata, int m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs);
int mrddbNZB0tEIa2rZcntIh3ekWxwXkQOpwSaH8Aext(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, const char* name);

// State handling
void mtJnqTShpQhBSqGlYw1GUVKppZmj6to2y8k8qLNEj(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s);
void mMOSoAfw0yMSC1XdM1ejVsS7hvTNy7E0W7SQ4tusp(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s);
void my6kiqBLdd5UIWcfSPUArHcBp9SEfFMi5YaBIYxi1(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s);

// State setting
void muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float size);
void mtep8SKAnuvijex54Nncrct8sc1n5oQBSCACVGIfC(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, unsigned int mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
void mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s);
void mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8);
void mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz);
void midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, int mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD text
float mrtJIKwlxubSHJvekx3Ccb5njw4ZcF08AswBWra2b(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end);

// Measure text
float mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end, float* bounds);
void muDcsBo45qKRlHe2BxEcMMlTJjUo1FnJrCboKt4ed(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float y, float* miny, float* maxy);
void muBl5zwa2xJ8yDTKkn6ofR8MjHElponvWK5Q9lrpL(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float* m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi, float* mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr, float* m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9);

// Text iterator
int m7PieUDQehumYiYh4252A99B8amS5Zd6uspppOu0X(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW* iter, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* str, const char* end, int mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u);
int mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW* iter, struct mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8* quad);

// Pull texture changes
const unsigned char* fonsGetTextureData(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int* myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int* mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
int m3oKu2RdKV0jprJqKpsGRO44el4JfkKu6WPqxt88L(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, int* dirty);

// Draws the stash texture for debugging
void mK2nupGEmsQlXcd7FqfiGbNHFAhDcTSCX0pmm7tU0(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

#endif // FONTSTASH_H


#ifdef FONTSTASH_IMPLEMENTATION

#define FONS_NOTUSED(v)  (void)sizeof(v)

#ifdef FONS_USE_FREETYPE

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_ADVANCES_H
#include <math.h>

struct mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS {
FT_Face mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
};
typedef struct mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS;

static FT_Library ftLibrary;

int mF6mJLOOCf6PPIiZTSf2HQGSZFvU7JAT8hB6Q3VCX(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm *context)
{
FT_Error ftError;
        FONS_NOTUSED(context);
ftError = FT_Init_FreeType(&ftLibrary);
return ftError == 0;
}

int mrSSAq28BTByJMC6SXNxUq8rVIe7x1KxhhpmQEUon(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm *context, mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, unsigned char *data, int m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x)
{
FT_Error ftError;
FONS_NOTUSED(context);

//mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh.userdata = stash;
ftError = FT_New_Memory_Face(ftLibrary, (const FT_Byte*)data, m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x, 0, &mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);
return ftError == 0;
}

void mn02uH1yPph3WSko9DcUy4CDYggv2M2f9TyAMYdFT(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int *ascent, int *descent, int *lineGap)
{
*ascent = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi;
*descent = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr;
*lineGap = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc - (*ascent - *descent);
}

float maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, float size)
{
return size / (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi - mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr);
}

int mqYmvt97NEXoZTqJqiW4l1z9DWSYfzDeq6Fz1Xb2w(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw)
{
return FT_Get_Char_Index(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
}

int mz3dbl46xcKSdPf9a0GLDdTdTMtcpL5KfbRVFCAsi(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float size, float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,
  int *mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, int *lsb, int *x0, int *y0, int *x1, int *y1)
{
FT_Error ftError;
FT_GlyphSlot ftGlyph;
FT_Fixed advFixed;
FONS_NOTUSED(ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);

ftError = FT_Set_Pixel_Sizes(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, 0, (FT_UInt)(size * (float)mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->units_per_EM / (float)(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi - mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr)));
if (ftError) return 0;
ftError = FT_Load_Glyph(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT);
if (ftError) return 0;
ftError = FT_Get_Advance(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, FT_LOAD_NO_SCALE, &advFixed);
if (ftError) return 0;
ftGlyph = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyph;
*mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa = (int)advFixed;
*lsb = (int)ftGlyph->metrics.horiBearingX;
*x0 = ftGlyph->bitmap_left;
*x1 = *x0 + ftGlyph->bitmap.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
*y0 = -ftGlyph->bitmap_top;
*y1 = *y0 + ftGlyph->bitmap.rows;
return 1;
}

void m6t5G0m3v6FsPvE0Ga6mv8oJcXyUWRQaoqdoBE1CV(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, unsigned char *output, int outWidth, int outHeight, int outStride,
float scaleX, float scaleY, int glyph)
{
FT_GlyphSlot ftGlyph = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyph;
int ftGlyphOffset = 0;
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y;
FONS_NOTUSED(outWidth);
FONS_NOTUSED(outHeight);
FONS_NOTUSED(scaleX);
FONS_NOTUSED(scaleY);
FONS_NOTUSED(glyph);// glyph has already been loaded by mz3dbl46xcKSdPf9a0GLDdTdTMtcpL5KfbRVFCAsi

for ( y = 0; y < ftGlyph->bitmap.rows; y++ ) {
for ( m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < ftGlyph->bitmap.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++ ) {
output[(y * outStride) + m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] = ftGlyph->bitmap.buffer[ftGlyphOffset++];
}
}
}

int mlDl3iyVr74tFENym8zQ27F5lVusMrsG6gK35mjVX(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph1, int glyph2)
{
FT_Vector ftKerning;
FT_Get_Kerning(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph1, glyph2, FT_KERNING_DEFAULT, &ftKerning);
return (int)((ftKerning.m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + 32) >> 6);  // Round up mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 convert myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT integer
}

#else

#define STB_TRUETYPE_IMPLEMENTATION
static void* fons__tmpalloc(size_t size, void* up);
static void m9lNGW7lXCMLspFEk1caA87cll5ufYjbp2iVr5QLY(void* ptr, void* up);
#define STBTT_malloc(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)    fons__tmpalloc(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)
#define STBTT_free(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)      m9lNGW7lXCMLspFEk1caA87cll5ufYjbp2iVr5QLY(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)
#include "stb_truetype.h"

struct mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS {
mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
};
typedef struct mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS;

int mF6mJLOOCf6PPIiZTSf2HQGSZFvU7JAT8hB6Q3VCX(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm *context)
{
FONS_NOTUSED(context);
return 1;
}

int mrSSAq28BTByJMC6SXNxUq8rVIe7x1KxhhpmQEUon(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm *context, mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, unsigned char *data, int m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x)
{
int m6fN6YXn4wZZuipcsfvOr21X4S2NcbWCeaLLBZ0uE;
FONS_NOTUSED(m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x);

mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh.userdata = context;
m6fN6YXn4wZZuipcsfvOr21X4S2NcbWCeaLLBZ0uE = m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, data, 0);
return m6fN6YXn4wZZuipcsfvOr21X4S2NcbWCeaLLBZ0uE;
}

void mn02uH1yPph3WSko9DcUy4CDYggv2M2f9TyAMYdFT(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int *ascent, int *descent, int *lineGap)
{
m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, ascent, descent, lineGap);
}

float maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, float size)
{
return mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, size);
}

int mqYmvt97NEXoZTqJqiW4l1z9DWSYfzDeq6Fz1Xb2w(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw)
{
return muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
}

int mz3dbl46xcKSdPf9a0GLDdTdTMtcpL5KfbRVFCAsi(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float size, float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,
  int *mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, int *lsb, int *x0, int *y0, int *x1, int *y1)
{
FONS_NOTUSED(size);
mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, lsb);
mP80dwmBGZLrpqWepQSMhzjJ9qZEqEd7Y8CiXHxrK(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, x0, y0, x1, y1);
return 1;
}

void m6t5G0m3v6FsPvE0Ga6mv8oJcXyUWRQaoqdoBE1CV(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, unsigned char *output, int outWidth, int outHeight, int outStride,
float scaleX, float scaleY, int glyph)
{
myiiRccknlTrdvBQ3bNuxFMoCkdb0jmZFCa0gaoci(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, output, outWidth, outHeight, outStride, scaleX, scaleY, glyph);
}

int mlDl3iyVr74tFENym8zQ27F5lVusMrsG6gK35mjVX(mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph1, int glyph2)
{
return mGLXO0TZk0U9bnggRmK3RW0XXKif5Bi9WEJd522FF(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph1, glyph2);
}

#endif

#ifndef FONS_SCRATCH_BUF_SIZE
#define FONS_SCRATCH_BUF_SIZE 96000
#endif
#ifndef FONS_HASH_LUT_SIZE
#define FONS_HASH_LUT_SIZE 256
#endif
#ifndef FONS_INIT_FONTS
#define FONS_INIT_FONTS 4
#endif
#ifndef FONS_INIT_GLYPHS
#define FONS_INIT_GLYPHS 256
#endif
#ifndef FONS_INIT_ATLAS_NODES
#define FONS_INIT_ATLAS_NODES 256
#endif
#ifndef FONS_VERTEX_COUNT
#define FONS_VERTEX_COUNT 1024
#endif
#ifndef FONS_MAX_STATES
#define FONS_MAX_STATES 20
#endif
#ifndef FONS_MAX_FALLBACKS
#define FONS_MAX_FALLBACKS 20
#endif

static unsigned int mXxi6NiyiRUR4am7Va7EddQYogrV4c2YYXGSsn70o(unsigned int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
{
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c += ~(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c<<15);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ^=  (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c>>10);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c +=  (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c<<3);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ^=  (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c>>6);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c += ~(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c<<11);
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ^=  (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c>>16);
return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
}

static int mcL3h14N6njeGIBFUaUBM0zwWeOe2xzxkUjLCpusj(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int b)
{
return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c < b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b;
}

static int mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, int b)
{
return mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > b ? mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c : b;
}

struct mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0
{
unsigned int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
int mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS;
int mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
short size, m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
short x0,y0,x1,y1;
short xadv,xoff,yoff;
};
typedef struct mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0 mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0;

struct mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2
{
mRaHHNOKc6APx7auUSL8ORDd6fqcyRJQuJWmFCAjS mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
char name[64];
unsigned char* data;
int m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x;
unsigned char m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs;
float m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi;
float mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr;
float m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9;
mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyphs;
int mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk;
int mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI;
int lut[FONS_HASH_LUT_SIZE];
int fallbacks[FONS_MAX_FALLBACKS];
int muk7zJ4AL3QPetdH4HSZB5EKcWGJZXxIm0Uh6DJCR;
};
typedef struct mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2 mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2;

struct mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0
{
int mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz;
float size;
unsigned int mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
float m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s;
};
typedef struct mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0 mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0;

struct mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA {
    short m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
};
typedef struct mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA;

struct m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH
{
int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA* nodes;
int mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm;
int mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY;
};
typedef struct m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH;

struct mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm
{
m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;
float itw,ith;
unsigned char* texData;
int dirtyRect[4];
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2** fonts;
m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas;
int mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss;
int mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO;
float verts[FONS_VERTEX_COUNT*2];
float tcoords[FONS_VERTEX_COUNT*2];
unsigned int colors[FONS_VERTEX_COUNT];
int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA;
unsigned char* scratch;
int mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c;
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0 states[FONS_MAX_STATES];
int mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun;
void (*handleError)(void* uptr, int error, int val);
void* errorUptr;
};

#ifdef STB_TRUETYPE_IMPLEMENTATION

static void* fons__tmpalloc(size_t size, void* up)
{
unsigned char* ptr;
mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash = (mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm*)up;

// 16-byte miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz the returned pointer
size = (size + 0xf) & ~0xf;

if (stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c+(int)size > FONS_SCRATCH_BUF_SIZE) {
if (stash->handleError)
stash->handleError(stash->errorUptr, FONS_SCRATCH_FULL, stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c+(int)size);
return NULL;
}
ptr = stash->scratch + stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c;
stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c += (int)size;
return ptr;
}

static void m9lNGW7lXCMLspFEk1caA87cll5ufYjbp2iVr5QLY(void* ptr, void* up)
{
(void)ptr;
(void)up;
// empty
}

#endif // STB_TRUETYPE_IMPLEMENTATION

// Copyright (c) 2008-2010 Bjoern Hoehrmann <bjoern@hoehrmann.de>
// See http://bjoern.hoehrmann.de/utf-8/decoder/dfa/ for details.

#define FONS_UTF8_ACCEPT 0
#define FONS_UTF8_REJECT 12

static unsigned int miKAK9BQWkKsN4IrkEOJm4boZIEjbGMT7T0BbT8NF(unsigned int* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2, unsigned int* codep, unsigned int byte)
{
static const unsigned char utf8d[] = {
// The first part of the table maps bytes myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT character classes that
// myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT reduce the size of the transition table mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 create bitmasks.
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
8,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
10,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3, 11,6,6,6,5,8,8,8,8,8,8,8,8,8,8,8,

// The second part is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c transition table that maps mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c combination
// of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 of the automaton mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c character class myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.
0,12,24,36,60,96,84,12,12,12,48,72, 12,12,12,12,12,12,12,12,12,12,12,12,
12, 0,12,12,12,12,12, 0,12, 0,12,12, 12,24,12,12,12,12,12,24,12,24,12,12,
12,12,12,12,12,12,12,24,12,12,12,12, 12,24,12,12,12,12,12,12,12,24,12,12,
12,12,12,12,12,12,12,36,12,36,12,12, 12,36,12,12,12,12,12,36,12,36,12,12,
12,36,12,12,12,12,12,12,12,12,12,12,
    };

unsigned int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = utf8d[byte];

    *codep = (*msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 != FONS_UTF8_ACCEPT) ?
(byte & 0x3fu) | (*codep << 6) :
(0xff >> mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P) & (byte);

*msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = utf8d[256 + *msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 + mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P];
return *msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2;
}

static void mMoA4Zmk7Mb1r2ApUEJu70hpS0RYbqenXMHV9HBG0(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas)
{
if (atlas == NULL) return;
if (atlas->nodes != NULL) free(atlas->nodes);
free(atlas);
}

static m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* fons__allocAtlas(int w, int h, int mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm)
{
m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas = NULL;

// Allocate memory for the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh stash.
atlas = (m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH*)malloc(sizeof(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH));
if (atlas == NULL) goto error;
memset(atlas, 0, sizeof(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH));

atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = w;
atlas->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = h;

// Allocate space for skyline nodes
atlas->nodes = (mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA*)malloc(sizeof(mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA) * mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm);
if (atlas->nodes == NULL) goto error;
memset(atlas->nodes, 0, sizeof(mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA) * mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm);
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm = 0;
atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY = mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm;

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn root node.
atlas->nodes[0].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0;
atlas->nodes[0].y = 0;
atlas->nodes[0].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = (short)w;
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm++;

return atlas;

error:
if (atlas) mMoA4Zmk7Mb1r2ApUEJu70hpS0RYbqenXMHV9HBG0(atlas);
return NULL;
}

static int mx4mZp4TjGjGZJTahflRoYg7mS3UOR2pYWm8Ev2Jl(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int idx, int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, int y, int w)
{
int i;
// Insert node
if (atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm+1 > atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY) {
atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY = atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY == 0 ? 8 : atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY * 2;
atlas->nodes = (mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA*)realloc(atlas->nodes, sizeof(mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA) * atlas->mAJlgp7jUDzoKMlJM7plLbuY88Q1d7BrTT8RAUxlY);
if (atlas->nodes == NULL)
return 0;
}
for (i = atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm; i > idx; i--)
atlas->nodes[i] = atlas->nodes[i-1];
atlas->nodes[idx].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (short)m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
atlas->nodes[idx].y = (short)y;
atlas->nodes[idx].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = (short)w;
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm++;

return 1;
}

static void m1ZITQ33cD2gtfLBBnfisBmpShrs3u3hq2JkrkfwO(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int idx)
{
int i;
if (atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm == 0) return;
for (i = idx; i < atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm-1; i++)
atlas->nodes[i] = atlas->nodes[i+1];
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm--;
}

static void mU915ql5hgtbU1tdUxYnPsm4JMUsJwea4TQekAOLG(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int w, int h)
{
// Insert node for empty space
if (w > atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn)
mx4mZp4TjGjGZJTahflRoYg7mS3UOR2pYWm8Ev2Jl(atlas, atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm, atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, 0, w - atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = w;
atlas->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = h;
}

static void mbMvvDmXnl5EcyiAdzjZmGN977HsYjy2n59ZEtbNm(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int w, int h)
{
atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = w;
atlas->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = h;
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm = 0;

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn root node.
atlas->nodes[0].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0;
atlas->nodes[0].y = 0;
atlas->nodes[0].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = (short)w;
atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm++;
}

static int m9KsQgR3zpy4s1U9rNDqFEHheunefWeuIWnfu0H8M(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int idx, int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, int y, int w, int h)
{
int i;

// Insert new node
if (mx4mZp4TjGjGZJTahflRoYg7mS3UOR2pYWm8Ev2Jl(atlas, idx, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y+h, w) == 0)
return 0;

// Delete skyline segments that fall under the shadow of the new segment.
for (i = idx+1; i < atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm; i++) {
if (atlas->nodes[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < atlas->nodes[i-1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + atlas->nodes[i-1].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn) {
int shrink = atlas->nodes[i-1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + atlas->nodes[i-1].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn - atlas->nodes[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
atlas->nodes[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += (short)shrink;
atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn -= (short)shrink;
if (atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn <= 0) {
m1ZITQ33cD2gtfLBBnfisBmpShrs3u3hq2JkrkfwO(atlas, i);
i--;
} else {
break;
}
} else {
break;
}
}

// Merge same mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc skyline segments that are mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT each other.
for (i = 0; i < atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm-1; i++) {
if (atlas->nodes[i].y == atlas->nodes[i+1].y) {
atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn += atlas->nodes[i+1].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
m1ZITQ33cD2gtfLBBnfisBmpShrs3u3hq2JkrkfwO(atlas, i+1);
i--;
}
}

return 1;
}

static int mtdadGHXkTuQE3UAQKLDFXVoz4IkQ7z7B0d9Klouc(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int i, int w, int h)
{
// Checks if there is enough space at the location of skyline span 'i',
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 return the max mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of all skyline spans under that at that location,
// (think tetris block being dropped at that position). Or -1 if no space found.
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = atlas->nodes[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
int y = atlas->nodes[i].y;
int mLNRaSCZRipyh0IcT728Dchbl4iKjed7eUzFrh00I;
if (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + w > atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn)
return -1;
mLNRaSCZRipyh0IcT728Dchbl4iKjed7eUzFrh00I = w;
while (mLNRaSCZRipyh0IcT728Dchbl4iKjed7eUzFrh00I > 0) {
if (i == atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm) return -1;
y = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(y, atlas->nodes[i].y);
if (y + h > atlas->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) return -1;
mLNRaSCZRipyh0IcT728Dchbl4iKjed7eUzFrh00I -= atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
++i;
}
return y;
}

static int mvsCETxY6RUqQmkTMutl0zVnxyR7i4pbSwHyU956C(m8SDWmHeFFCQYuoF77QHoqSAExVYINmeb7cEpI7YH* atlas, int rw, int rh, int* rx, int* ry)
{
int besth = atlas->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, bestw = atlas->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, besti = -1;
int bestx = -1, besty = -1, i;

// Bottom left fit heuristic.
for (i = 0; i < atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm; i++) {
int y = mtdadGHXkTuQE3UAQKLDFXVoz4IkQ7z7B0d9Klouc(atlas, i, rw, rh);
if (y != -1) {
if (y + rh < besth || (y + rh == besth && atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn < bestw)) {
besti = i;
bestw = atlas->nodes[i].myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
besth = y + rh;
bestx = atlas->nodes[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
besty = y;
}
}
}

if (besti == -1)
return 0;

// Perform the actual packing.
if (m9KsQgR3zpy4s1U9rNDqFEHheunefWeuIWnfu0H8M(atlas, besti, bestx, besty, rw, rh) == 0)
return 0;

*rx = bestx;
*ry = besty;

return 1;
}

static void muR0KZ01ZUFeanhUmZp4vRK5mqGiI40Jkz1Ki5gME(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int w, int h)
{
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, gx, gy;
unsigned char* dst;
if (mvsCETxY6RUqQmkTMutl0zVnxyR7i4pbSwHyU956C(stash->atlas, w, h, &gx, &gy) == 0)
return;

// Rasterize
dst = &stash->texData[gx + gy * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
for (y = 0; y < h; y++) {
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < w; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++)
dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] = 0xff;
dst += stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
}

stash->dirtyRect[0] = mcL3h14N6njeGIBFUaUBM0zwWeOe2xzxkUjLCpusj(stash->dirtyRect[0], gx);
stash->dirtyRect[1] = mcL3h14N6njeGIBFUaUBM0zwWeOe2xzxkUjLCpusj(stash->dirtyRect[1], gy);
stash->dirtyRect[2] = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(stash->dirtyRect[2], gx+w);
stash->dirtyRect[3] = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(stash->dirtyRect[3], gy+h);
}

mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* fonsCreateInternal(m3IWzgj9NA3umTCobp4FY31o3YJXM7lJG7TFdJYnx* m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk)
{
mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash = NULL;

// Allocate memory for the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh stash.
stash = (mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm*)malloc(sizeof(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm));
if (stash == NULL) goto error;
memset(stash, 0, sizeof(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm));

stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk = *m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk;

// Allocate scratch buffer.
stash->scratch = (unsigned char*)malloc(FONS_SCRATCH_BUF_SIZE);
if (stash->scratch == NULL) goto error;

// Initialize implementation library
if (!mF6mJLOOCf6PPIiZTSf2HQGSZFvU7JAT8hB6Q3VCX(stash)) goto error;

if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreate != NULL) {
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderCreate(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) == 0)
goto error;
}

stash->atlas = fons__allocAtlas(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, FONS_INIT_ATLAS_NODES);
if (stash->atlas == NULL) goto error;

// Allocate space for fonts.
stash->fonts = (mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2**)malloc(sizeof(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2*) * FONS_INIT_FONTS);
if (stash->fonts == NULL) goto error;
memset(stash->fonts, 0, sizeof(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2*) * FONS_INIT_FONTS);
stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss = FONS_INIT_FONTS;
stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO = 0;

// Create texture for the cache.
stash->itw = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->ith = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->texData = (unsigned char*)malloc(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
if (stash->texData == NULL) goto error;
memset(stash->texData, 0, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

stash->dirtyRect[0] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->dirtyRect[1] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->dirtyRect[2] = 0;
stash->dirtyRect[3] = 0;

// Add white rect at 0,0 for debug drawing.
muR0KZ01ZUFeanhUmZp4vRK5mqGiI40Jkz1Ki5gME(stash, 2,2);

mtJnqTShpQhBSqGlYw1GUVKppZmj6to2y8k8qLNEj(stash);
my6kiqBLdd5UIWcfSPUArHcBp9SEfFMi5YaBIYxi1(stash);

return stash;

error:
m4X2WYU3dbT2MbC06eMvvZPgza6hxYrjUFzFNDNTn(stash);
return NULL;
}

static mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* fons__getState(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
return &stash->states[stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun-1];
}

int mIJMalRGBWWh8eBLqZNhPtwapG9nukapS14BWeZQy(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int base, int fallback)
{
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* baseFont = stash->fonts[base];
if (baseFont->muk7zJ4AL3QPetdH4HSZB5EKcWGJZXxIm0Uh6DJCR < FONS_MAX_FALLBACKS) {
baseFont->fallbacks[baseFont->muk7zJ4AL3QPetdH4HSZB5EKcWGJZXxIm0Uh6DJCR++] = fallback;
return 1;
}
return 0;
}

void muyUmqNS1tYxpSY3dKdW1s0staGe4ZxrEBigaO7w2(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float size)
{
fons__getState(stash)->size = size;
}

void mtep8SKAnuvijex54Nncrct8sc1n5oQBSCACVGIfC(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, unsigned int mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP)
{
fons__getState(stash)->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP = mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP;
}

void mmUiDifjSajOuipSz7Sq2VX4kPkqKdezp23iVlIsN(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s)
{
fons__getState(stash)->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s = mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s;
}

void mPuLpWZKPmnxuCWrQe9nvlOGZSRxa4APr3O2Qdzsl(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8)
{
fons__getState(stash)->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 = m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
}

void mGqxYCtnHICm8S7gTwdzR4yQdK3oYH6c21RD1vQzp(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz)
{
fons__getState(stash)->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz = miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz;
}

void midCxDQ7SHnd3s3uMCi3vS0ky2nS4lvMLKhHfP2z1(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
fons__getState(stash)->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
}

void mtJnqTShpQhBSqGlYw1GUVKppZmj6to2y8k8qLNEj(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
if (stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun >= FONS_MAX_STATES) {
if (stash->handleError)
stash->handleError(stash->errorUptr, FONS_STATES_OVERFLOW, 0);
return;
}
if (stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun > 0)
memcpy(&stash->states[stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun], &stash->states[stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun-1], sizeof(mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0));
stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun++;
}

void mMOSoAfw0yMSC1XdM1ejVsS7hvTNy7E0W7SQ4tusp(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
if (stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun <= 1) {
if (stash->handleError)
stash->handleError(stash->errorUptr, FONS_STATES_UNDERFLOW, 0);
return;
}
stash->mE2PHXbQGvtHur167XbOTMDG0RRX72J3wR7FHtaun--;
}

void my6kiqBLdd5UIWcfSPUArHcBp9SEfFMi5YaBIYxi1(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size = 12.0f;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP = 0xffffffff;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = 0;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 = 0;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s = 0;
msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz = FONS_ALIGN_LEFT | FONS_ALIGN_BASELINE;
}

static void mEsWlDhrFFPMyB8jLau9ipXza6kDMg05lZRsXUIUT(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh == NULL) return;
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs) free(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs);
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs && mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data) free(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data);
free(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);
}

static int m7toG0u98wAlKrU7cVG0vzZCf9pEcr2Wb9L45KjdX(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = NULL;
if (stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO+1 > stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss) {
stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss = stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss == 0 ? 8 : stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss * 2;
stash->fonts = (mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2**)realloc(stash->fonts, sizeof(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2*) * stash->mj7rCpd3sVuYrz7VcgwDqUdtmk8TYhz15zU3qOkss);
if (stash->fonts == NULL)
return -1;
}
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = (mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2*)malloc(sizeof(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2));
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh == NULL) goto error;
memset(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, 0, sizeof(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2));

mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs = (mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0*)malloc(sizeof(mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0) * FONS_INIT_GLYPHS);
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs == NULL) goto error;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk = FONS_INIT_GLYPHS;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI = 0;

stash->fonts[stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO++] = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
return stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO-1;

error:
mEsWlDhrFFPMyB8jLau9ipXza6kDMg05lZRsXUIUT(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);

return FONS_INVALID;
}

int mJRBeC21nobd9NV6L8lzOus5k5PXtlIK5jZxqknQJ(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, const char* name, const char* path)
{
FILE* fp = 0;
int m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x = 0;
size_t readed;
unsigned char* data = NULL;

// Read in the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh data.
fp = fopen(path, "rb");
if (fp == NULL) goto error;
fseek(fp,0,SEEK_END);
m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x = (int)ftell(fp);
fseek(fp,0,SEEK_SET);
data = (unsigned char*)malloc(m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x);
if (data == NULL) goto error;
readed = fread(data, 1, m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x, fp);
fclose(fp);
fp = 0;
if (readed != m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x) goto error;

return mlHxLh07uUuA4qDyLtpqLXteafiyEOTVNgcqcKpaQ(stash, name, data, m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x, 1);

error:
if (data) free(data);
if (fp) fclose(fp);
return FONS_INVALID;
}

int mlHxLh07uUuA4qDyLtpqLXteafiyEOTVNgcqcKpaQ(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, const char* name, unsigned char* data, int m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x, int m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs)
{
int i, ascent, descent, fh, lineGap;
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;

int idx = m7toG0u98wAlKrU7cVG0vzZCf9pEcr2Wb9L45KjdX(stash);
if (idx == FONS_INVALID)
return FONS_INVALID;

mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[idx];

strncpy(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->name, name, sizeof(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->name));
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->name[sizeof(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->name)-1] = '\0';

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn hash lookup.
for (i = 0; i < FONS_HASH_LUT_SIZE; ++i)
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->lut[i] = -1;

// Read in the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh data.
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x = m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data = data;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs = (unsigned char)m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs;

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh
stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c = 0;
if (!mrSSAq28BTByJMC6SXNxUq8rVIe7x1KxhhpmQEUon(stash, &mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, data, m54FHEiRiDsMHwNQqWB4f70k0P3u7yznRhQIDgs4x)) goto error;

// Store normalized line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc. The real line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc is got
// by multiplying the m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 by mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size.
mn02uH1yPph3WSko9DcUy4CDYggv2M2f9TyAMYdFT( &mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, &ascent, &descent, &lineGap);
fh = ascent - descent;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi = (float)ascent / (float)fh;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr = (float)descent / (float)fh;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 = (float)(fh + lineGap) / (float)fh;

return idx;

error:
mEsWlDhrFFPMyB8jLau9ipXza6kDMg05lZRsXUIUT(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);
stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO--;
return FONS_INVALID;
}

int mrddbNZB0tEIa2rZcntIh3ekWxwXkQOpwSaH8Aext(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* s, const char* name)
{
int i;
for (i = 0; i < s->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO; i++) {
if (strcmp(s->fonts[i]->name, name) == 0)
return i;
}
return FONS_INVALID;
}


static mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* fons__allocGlyph(mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI+1 > mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk) {
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk == 0 ? 8 : mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk * 2;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs = (mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0*)realloc(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs, sizeof(mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0) * mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mgCdd96rOiaAse5FHvOulLKECLZqcfv4oRoH7F2bk);
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs == NULL) return NULL;
}
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI++;
return &mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI-1];
}

#define APREC 16
#define ZPREC 7

static void mssfj2uSWh8KXkJkpkgBlwXwqRFx21qEupWR4CcP0(unsigned char* dst, int w, int h, int dstStride, int mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E)
{
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y;
for (y = 0; y < h; y++) {
int m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = 0; // force zero border
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 1; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < w; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++) {
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D += (mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E * (((int)(dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp]) << ZPREC) - m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D)) >> APREC;
dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] = (unsigned char)(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D >> ZPREC);
}
dst[w-1] = 0; // force zero border
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = 0;
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = w-2; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp >= 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp--) {
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D += (mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E * (((int)(dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp]) << ZPREC) - m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D)) >> APREC;
dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] = (unsigned char)(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D >> ZPREC);
}
dst[0] = 0; // force zero border
dst += dstStride;
}
}

static void m14Q15O9F0wNFRl9HZyVWYO9Jui42KJ4PghdtlKv0(unsigned char* dst, int w, int h, int dstStride, int mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E)
{
int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y;
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < w; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++) {
int m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = 0; // force zero border
for (y = dstStride; y < h*dstStride; y += dstStride) {
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D += (mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E * (((int)(dst[y]) << ZPREC) - m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D)) >> APREC;
dst[y] = (unsigned char)(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D >> ZPREC);
}
dst[(h-1)*dstStride] = 0; // force zero border
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = 0;
for (y = (h-2)*dstStride; y >= 0; y -= dstStride) {
m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D += (mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E * (((int)(dst[y]) << ZPREC) - m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D)) >> APREC;
dst[y] = (unsigned char)(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D >> ZPREC);
}
dst[0] = 0; // force zero border
dst++;
}
}


static void miBu2IIPV1BCEDzvr2bZNQX0JkrVhCJwiHniGfKiJ(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, unsigned char* dst, int w, int h, int dstStride, int m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8)
{
int mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E;
float m3kuJHFS0WFCPA7hinGoZL5yKue47SAqStYsGCXd3;
(void)stash;

if (m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 < 1)
return;
// Calculate the mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E such that 90% of the kernel is within the mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA. (Kernel extends myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT infinity)
m3kuJHFS0WFCPA7hinGoZL5yKue47SAqStYsGCXd3 = (float)m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 * 0.57735f; // 1 / sqrt(3)
mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E = (int)((1<<APREC) * (1.0f - expf(-2.3f / (m3kuJHFS0WFCPA7hinGoZL5yKue47SAqStYsGCXd3+1.0f))));
m14Q15O9F0wNFRl9HZyVWYO9Jui42KJ4PghdtlKv0(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
mssfj2uSWh8KXkJkpkgBlwXwqRFx21qEupWR4CcP0(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
m14Q15O9F0wNFRl9HZyVWYO9Jui42KJ4PghdtlKv0(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
mssfj2uSWh8KXkJkpkgBlwXwqRFx21qEupWR4CcP0(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
//fons__blurrows(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
//fons__blurcols(dst, w, h, dstStride, mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);
}

static mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* fons__getGlyph(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, unsigned int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw,
 short isize, short iblur, int mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u)
{
int i, g, mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, lsb, x0, y0, x1, y1, gw, gh, gx, gy, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y;
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyph = NULL;
unsigned int h;
float size = isize/10.0f;
int pad, added;
unsigned char* bdst;
unsigned char* dst;
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* renderFont = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;

if (isize < 2) return NULL;
if (iblur > 20) iblur = 20;
pad = iblur+2;

// Reset allocator.
stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c = 0;

// Find code point mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 size.
h = mXxi6NiyiRUR4am7Va7EddQYogrV4c2YYXGSsn70o(m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw) & (FONS_HASH_LUT_SIZE-1);
i = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->lut[h];
while (i != -1) {
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[i].m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw == m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw && mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[i].size == isize && mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[i].m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 == iblur) {
glyph = &mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[i];
if (mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u == FONS_GLYPH_BITMAP_OPTIONAL || (glyph->x0 >= 0 && glyph->y0 >= 0)) {
  return glyph;
}
// At this point, glyph exists but the bitmap data is not yet created.
break;
}
i = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->glyphs[i].mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
}

// Create mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c new glyph or rasterize bitmap data for mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c cached glyph.
g = mqYmvt97NEXoZTqJqiW4l1z9DWSYfzDeq6Fz1Xb2w(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
// Try myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT find the glyph in fallback fonts.
if (g == 0) {
for (i = 0; i < mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->muk7zJ4AL3QPetdH4HSZB5EKcWGJZXxIm0Uh6DJCR; ++i) {
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* fallbackFont = stash->fonts[mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->fallbacks[i]];
int fallbackIndex = mqYmvt97NEXoZTqJqiW4l1z9DWSYfzDeq6Fz1Xb2w(&fallbackFont->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
if (fallbackIndex != 0) {
g = fallbackIndex;
renderFont = fallbackFont;
break;
}
}
// It is possible that we did not find mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c fallback glyph.
// In that case the glyph mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS 'g' is 0, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 we'll proceed below mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 cache empty glyph.
}
ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(&renderFont->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, size);
mz3dbl46xcKSdPf9a0GLDdTdTMtcpL5KfbRVFCAsi(&renderFont->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, g, size, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, &mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, &lsb, &x0, &y0, &x1, &y1);
gw = x1-x0 + pad*2;
gh = y1-y0 + pad*2;

// Determines the spot myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw glyph in the atlas.
if (mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u == FONS_GLYPH_BITMAP_REQUIRED) {
// Find free spot for the rect in the atlas
added = mvsCETxY6RUqQmkTMutl0zVnxyR7i4pbSwHyU956C(stash->atlas, gw, gh, &gx, &gy);
if (added == 0 && stash->handleError != NULL) {
// Atlas is full, let the user myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT resize the atlas (or not), mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 try again.
stash->handleError(stash->errorUptr, FONS_ATLAS_FULL, 0);
added = mvsCETxY6RUqQmkTMutl0zVnxyR7i4pbSwHyU956C(stash->atlas, gw, gh, &gx, &gy);
}
if (added == 0) return NULL;
} else {
// Negative coordinate indicates there is no bitmap data created.
gx = -1;
gy = -1;
}

// m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn glyph.
if (glyph == NULL) {
glyph = fons__allocGlyph(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);
glyph->m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw = m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
glyph->size = isize;
glyph->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 = iblur;
glyph->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = 0;

// Insert char myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT hash lookup.
glyph->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->lut[h];
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->lut[h] = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI-1;
}
glyph->mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS = g;
glyph->x0 = (short)gx;
glyph->y0 = (short)gy;
glyph->x1 = (short)(glyph->x0+gw);
glyph->y1 = (short)(glyph->y0+gh);
glyph->xadv = (short)(ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa * 10.0f);
glyph->xoff = (short)(x0 - pad);
glyph->yoff = (short)(y0 - pad);

if (mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u == FONS_GLYPH_BITMAP_OPTIONAL) {
return glyph;
}

// Rasterize
dst = &stash->texData[(glyph->x0+pad) + (glyph->y0+pad) * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
m6t5G0m3v6FsPvE0Ga6mv8oJcXyUWRQaoqdoBE1CV(&renderFont->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, dst, gw-pad*2,gh-pad*2, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, g);

// Make sure there is one pixel empty border.
dst = &stash->texData[glyph->x0 + glyph->y0 * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
for (y = 0; y < gh; y++) {
dst[y*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn] = 0;
dst[gw-1 + y*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn] = 0;
}
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < gw; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++) {
dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] = 0;
dst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (gh-1)*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn] = 0;
}

// Debug code myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP the glyph background
/*unsigned char* fdst = &stash->texData[glyph->x0 + glyph->y0 * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
for (y = 0; y < gh; y++) {
for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < gw; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp++) {
int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = (int)fdst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+y*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn] + 20;
if (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c > 255) mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = 255;
fdst[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+y*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn] = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
}
}*/

// Blur
if (iblur > 0) {
stash->mdISIOYknuo9s7SFxcmJeQ8rgHRCd8aIlhlYvsa0c = 0;
bdst = &stash->texData[glyph->x0 + glyph->y0 * stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
miBu2IIPV1BCEDzvr2bZNQX0JkrVhCJwiHniGfKiJ(stash, bdst, gw, gh, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, iblur);
}

stash->dirtyRect[0] = mcL3h14N6njeGIBFUaUBM0zwWeOe2xzxkUjLCpusj(stash->dirtyRect[0], glyph->x0);
stash->dirtyRect[1] = mcL3h14N6njeGIBFUaUBM0zwWeOe2xzxkUjLCpusj(stash->dirtyRect[1], glyph->y0);
stash->dirtyRect[2] = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(stash->dirtyRect[2], glyph->x1);
stash->dirtyRect[3] = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(stash->dirtyRect[3], glyph->y1);

return glyph;
}

static void m7uTAtX6Dy8cqKlipI9ShQ6RKv472ueiyBIOETmkE(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh,
   int mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm, mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyph,
   float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s, float* m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float* y, mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8* mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i)
{
float rx,ry,xoff,yoff,x0,y0,x1,y1;

if (mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm != -1) {
float adv = mlDl3iyVr74tFENym8zQ27F5lVusMrsG6gK35mjVX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm, glyph->mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS) * ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += (int)(adv + mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s + 0.5f);
}

// Each glyph has 2px border myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT allow good interpolation,
// one pixel myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prevent leaking, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 one myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT allow good interpolation for rendering.
// Inset the texture region by one pixel for correct interpolation.
xoff = (short)(glyph->xoff+1);
yoff = (short)(glyph->yoff+1);
x0 = (float)(glyph->x0+1);
y0 = (float)(glyph->y0+1);
x1 = (float)(glyph->x1-1);
y1 = (float)(glyph->y1-1);

if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & FONS_ZERO_TOPLEFT) {
rx = (float)(int)(*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + xoff);
ry = (float)(int)(*y + yoff);

mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x0 = rx;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y0 = ry;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x1 = rx + x1 - x0;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y1 = ry + y1 - y0;

mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s0 = x0 * stash->itw;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t0 = y0 * stash->ith;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s1 = x1 * stash->itw;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t1 = y1 * stash->ith;
} else {
rx = (float)(int)(*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + xoff);
ry = (float)(int)(*y - yoff);

mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x0 = rx;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y0 = ry;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x1 = rx + x1 - x0;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y1 = ry - y1 + y0;

mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s0 = x0 * stash->itw;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t0 = y0 * stash->ith;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s1 = x1 * stash->itw;
mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t1 = y1 * stash->ith;
}

*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += (int)(glyph->xadv / 10.0f + 0.5f);
}

static void mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
// Flush texture
if (stash->dirtyRect[0] < stash->dirtyRect[2] && stash->dirtyRect[1] < stash->dirtyRect[3]) {
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderUpdate != NULL)
stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderUpdate(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, stash->dirtyRect, stash->texData);
// Reset dirty rect
stash->dirtyRect[0] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->dirtyRect[1] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->dirtyRect[2] = 0;
stash->dirtyRect[3] = 0;
}

// Flush triangles
if (stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA > 0) {
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDraw != NULL)
stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDraw(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, stash->verts, stash->tcoords, stash->colors, stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);
stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA = 0;
}
}

static __inline void mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float s, float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, unsigned int c)
{
stash->verts[stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA*2+0] = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
stash->verts[stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA*2+1] = y;
stash->tcoords[stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA*2+0] = s;
stash->tcoords[stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA*2+1] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
stash->colors[stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA] = c;
stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA++;
}

static float mCHVDLRejUYvK1h0qgM4OPiDkdSk5FC8ERDHRInCG(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz, short isize)
{
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & FONS_ZERO_TOPLEFT) {
if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_TOP) {
return mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi * (float)isize/10.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_MIDDLE) {
return (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi + mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr) / 2.0f * (float)isize/10.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_BASELINE) {
return 0.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_BOTTOM) {
return mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr * (float)isize/10.0f;
}
} else {
if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_TOP) {
return -mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi * (float)isize/10.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_MIDDLE) {
return -(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi + mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr) / 2.0f * (float)isize/10.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_BASELINE) {
return 0.0f;
} else if (miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_BOTTOM) {
return -mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr * (float)isize/10.0f;
}
}
return 0.0;
}

float mrtJIKwlxubSHJvekx3Ccb5njw4ZcF08AswBWra2b(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash,
   float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y,
   const char* str, const char* end)
{
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
unsigned int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
unsigned int mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl = 0;
mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyph = NULL;
mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
int mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = -1;
short isize = (short)(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size*10.0f);
short iblur = (short)msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;

if (stash == NULL) return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh < 0 || msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh >= stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO) return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh];
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data == NULL) return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;

ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, (float)isize/10.0f);

if (end == NULL)
end = str + strlen(str);

// Align horizontally
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_LEFT) {
// empty
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_RIGHT) {
myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, str, end, NULL);
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp -= myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_CENTER) {
myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, str, end, NULL);
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp -= myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * 0.5f;
}
// Align vertically.
y += mCHVDLRejUYvK1h0qgM4OPiDkdSk5FC8ERDHRInCG(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz, isize);

for (; str != end; ++str) {
if (miKAK9BQWkKsN4IrkEOJm4boZIEjbGMT7T0BbT8NF(&mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl, &m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, *(const unsigned char*)str))
continue;
glyph = fons__getGlyph(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, isize, iblur, FONS_GLYPH_BITMAP_REQUIRED);
if (glyph != NULL) {
m7uTAtX6Dy8cqKlipI9ShQ6RKv472ueiyBIOETmkE(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm, glyph, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s, &m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, &y, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i);

if (stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA+6 > FONS_VERTEX_COUNT)
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1, mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);
}
mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = glyph != NULL ? glyph->mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS : -1;
}
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
}

int m7PieUDQehumYiYh4252A99B8amS5Zd6uspppOu0X(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW* iter,
 float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* str, const char* end, int mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u)
{
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;

memset(iter, 0, sizeof(*iter));

if (stash == NULL) return 0;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh < 0 || msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh >= stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO) return 0;
iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh];
if (iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data == NULL) return 0;

iter->isize = (short)(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size*10.0f);
iter->iblur = (short)msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
iter->ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(&iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, (float)iter->isize/10.0f);

// Align horizontally
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_LEFT) {
// empty
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_RIGHT) {
myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, str, end, NULL);
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp -= myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_CENTER) {
myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, str, end, NULL);
m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp -= myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * 0.5f;
}
// Align vertically.
y += mCHVDLRejUYvK1h0qgM4OPiDkdSk5FC8ERDHRInCG(stash, iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz, iter->isize);

if (end == NULL)
end = str + strlen(str);

iter->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = iter->nextx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
iter->y = iter->nexty = y;
iter->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s = msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s;
iter->str = str;
iter->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = str;
iter->end = end;
iter->m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw = 0;
iter->mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = -1;
iter->mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u = mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u;

return 1;
}

int mB3MvHxzdIngosMnVq4jtoO77xRqe5okM9ZmDbZEw(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, mWVNDrYNDjMJjdWqZZpdVjLQ4EKIRCtMQFCoOeNdW* iter, mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8* quad)
{
mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyph = NULL;
const char* str = iter->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
iter->str = iter->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;

if (str == iter->end)
return 0;

for (; str != iter->end; str++) {
if (miKAK9BQWkKsN4IrkEOJm4boZIEjbGMT7T0BbT8NF(&iter->mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl, &iter->m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, *(const unsigned char*)str))
continue;
str++;
// Get glyph mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 quad
iter->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = iter->nextx;
iter->y = iter->nexty;
glyph = fons__getGlyph(stash, iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, iter->m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, iter->isize, iter->iblur, iter->mmpwSXvMxoC5Qa7n1os3gajvm1Dg3xDHnYQMTVq2u);
// If the iterator was initialized with FONS_GLYPH_BITMAP_OPTIONAL, then the UV coordinates of the quad will be invalid.
if (glyph != NULL)
m7uTAtX6Dy8cqKlipI9ShQ6RKv472ueiyBIOETmkE(stash, iter->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, iter->mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm, glyph, iter->ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, iter->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s, &iter->nextx, &iter->nexty, quad);
iter->mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = glyph != NULL ? glyph->mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS : -1;
break;
}
iter->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = str;

return 1;
}

void mK2nupGEmsQlXcd7FqfiGbNHFAhDcTSCX0pmm7tU0(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
int i;
int w = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
int h = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
float u = w == 0 ? 0 : (1.0f / w);
float v = h == 0 ? 0 : (1.0f / h);

if (stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA+6+6 > FONS_VERTEX_COUNT)
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD background
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+0, u, v, 0x0fffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+h, u, v, 0x0fffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+0, u, v, 0x0fffffff);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+0, u, v, 0x0fffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+h, u, v, 0x0fffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+h, u, v, 0x0fffffff);

// mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD texture
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+0, 0, 0, 0xffffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+h, 1, 1, 0xffffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+0, 1, 0, 0xffffffff);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+0, 0, 0, 0xffffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+h, 0, 1, 0xffffffff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+w, y+h, 1, 1, 0xffffffff);

// Drawbug draw atlas
for (i = 0; i < stash->atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm; i++) {
mXWtsQG9DhIsQraf9P2mw6PYrbFnuwIMPbRususoA* n = &stash->atlas->nodes[i];

if (stash->mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA+6 > FONS_VERTEX_COUNT)
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+n->y+0, u, v, 0xc00000ff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, y+n->y+1, u, v, 0xc00000ff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, y+n->y+0, u, v, 0xc00000ff);

mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+n->y+0, u, v, 0xc00000ff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+0, y+n->y+1, u, v, 0xc00000ff);
mEoNa7oYxPva9vn4gndYMm3uzVs36FKIpH2InMdr3(stash, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+n->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, y+n->y+1, u, v, 0xc00000ff);
}

mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);
}

float mr9ff0yn47k3YsJiTNHcSfVeaCZcLuihGeXLWwMkb(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash,
 float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y,
 const char* str, const char* end,
 float* bounds)
{
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
unsigned int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw;
unsigned int mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl = 0;
mt1iFtAEoyvtiTomnjcl8MRfxaaJozNSiXPBjyNg8 mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
mjxIhL8He8PUz2m4MsjaqZiITBXULAEtCmv7830d0* glyph = NULL;
int mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = -1;
short isize = (short)(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size*10.0f);
short iblur = (short)msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8;
float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
float startx, mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
float minx, miny, maxx, maxy;

if (stash == NULL) return 0;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh < 0 || msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh >= stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO) return 0;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh];
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data == NULL) return 0;

ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = maKzS78JXlBN9Cx5b5YTA85awykFiYlQOvUCoGuYX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, (float)isize/10.0f);

// Align vertically.
y += mCHVDLRejUYvK1h0qgM4OPiDkdSk5FC8ERDHRInCG(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz, isize);

minx = maxx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
miny = maxy = y;
startx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;

if (end == NULL)
end = str + strlen(str);

for (; str != end; ++str) {
if (miKAK9BQWkKsN4IrkEOJm4boZIEjbGMT7T0BbT8NF(&mBa9tXEwqdY91Jo8qDTYMf2yloHnxgZH3KC2PwBVl, &m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, *(const unsigned char*)str))
continue;
glyph = fons__getGlyph(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, isize, iblur, FONS_GLYPH_BITMAP_OPTIONAL);
if (glyph != NULL) {
m7uTAtX6Dy8cqKlipI9ShQ6RKv472ueiyBIOETmkE(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm, glyph, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s, &m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, &y, &mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i);
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0 < minx) minx = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0;
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1 > maxx) maxx = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1;
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & FONS_ZERO_TOPLEFT) {
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0 < miny) miny = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0;
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1 > maxy) maxy = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1;
} else {
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1 < miny) miny = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1;
if (mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0 > maxy) maxy = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0;
}
}
mt7uF6zIh8mGcYjggSTwsxx2rD1ZkJBWklPaBNJkm = glyph != NULL ? glyph->mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS : -1;
}

mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - startx;

// Align horizontally
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_LEFT) {
// empty
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_RIGHT) {
minx -= mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
maxx -= mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
} else if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz & FONS_ALIGN_CENTER) {
minx -= mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa * 0.5f;
maxx -= mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa * 0.5f;
}

if (bounds) {
bounds[0] = minx;
bounds[1] = miny;
bounds[2] = maxx;
bounds[3] = maxy;
}

return mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
}

void muBl5zwa2xJ8yDTKkn6ofR8MjHElponvWK5Q9lrpL(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash,
 float* m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi, float* mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr, float* m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9)
{
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
short isize;

if (stash == NULL) return;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh < 0 || msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh >= stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO) return;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh];
isize = (short)(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size*10.0f);
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data == NULL) return;

if (m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi)
*m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi*isize/10.0f;
if (mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr)
*mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr*isize/10.0f;
if (m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9)
*m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9 = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9*isize/10.0f;
}

void muDcsBo45qKRlHe2BxEcMMlTJjUo1FnJrCboKt4ed(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, float y, float* miny, float* maxy)
{
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
mCdWzGgIVcwjvRsEdp1D9n6JNzElHmlJdhmpTs9j0* msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 = fons__getState(stash);
short isize;

if (stash == NULL) return;
if (msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh < 0 || msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh >= stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO) return;
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh];
isize = (short)(msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->size*10.0f);
if (mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data == NULL) return;

y += mCHVDLRejUYvK1h0qgM4OPiDkdSk5FC8ERDHRInCG(stash, mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2->miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz, isize);

if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & FONS_ZERO_TOPLEFT) {
*miny = y - mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi * (float)isize/10.0f;
*maxy = *miny + mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9*isize/10.0f;
} else {
*maxy = y + mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr * (float)isize/10.0f;
*miny = *maxy - mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9*isize/10.0f;
}
}

const unsigned char* fonsGetTextureData(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int* myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int* mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
{
if (myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn != NULL)
*myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
if (mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc != NULL)
*mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
return stash->texData;
}

int m3oKu2RdKV0jprJqKpsGRO44el4JfkKu6WPqxt88L(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int* dirty)
{
if (stash->dirtyRect[0] < stash->dirtyRect[2] && stash->dirtyRect[1] < stash->dirtyRect[3]) {
dirty[0] = stash->dirtyRect[0];
dirty[1] = stash->dirtyRect[1];
dirty[2] = stash->dirtyRect[2];
dirty[3] = stash->dirtyRect[3];
// Reset dirty rect
stash->dirtyRect[0] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->dirtyRect[1] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->dirtyRect[2] = 0;
stash->dirtyRect[3] = 0;
return 1;
}
return 0;
}

void m4X2WYU3dbT2MbC06eMvvZPgza6hxYrjUFzFNDNTn(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash)
{
int i;
if (stash == NULL) return;

if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDelete)
stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderDelete(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr);

for (i = 0; i < stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO; ++i)
mEsWlDhrFFPMyB8jLau9ipXza6kDMg05lZRsXUIUT(stash->fonts[i]);

if (stash->atlas) mMoA4Zmk7Mb1r2ApUEJu70hpS0RYbqenXMHV9HBG0(stash->atlas);
if (stash->fonts) free(stash->fonts);
if (stash->texData) free(stash->texData);
if (stash->scratch) free(stash->scratch);
free(stash);
}

void mfSqr199KBchusmZdvrjEUGn5mxHafvlF4FMFdE3h(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, void (*callback)(void* uptr, int error, int val), void* uptr)
{
if (stash == NULL) return;
stash->handleError = callback;
stash->errorUptr = uptr;
}

void mCLnHuss0SRna4vUxe0Ru21AfH6Jf7uw2tXrRwnQY(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int* myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int* mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
{
if (stash == NULL) return;
*myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
*mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
}

int mKzMmbkPg48FMCVM8ZSHum9ev8arIsAV1HNAyXbCr(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
{
int i, maxy = 0;
unsigned char* data = NULL;
if (stash == NULL) return 0;

myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

if (myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn == stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn && mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc == stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
return 1;

// Flush pending glyphs.
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

// Create new texture
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderResize != NULL) {
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderResize(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) == 0)
return 0;
}
// Copy old texture data over.
data = (unsigned char*)malloc(myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
if (data == NULL)
return 0;
for (i = 0; i < stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc; i++) {
unsigned char* dst = &data[i*myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
unsigned char* src = &stash->texData[i*stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn];
memcpy(dst, src, stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
if (myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn > stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn)
memset(dst+stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, 0, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn - stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
}
if (mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc > stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
memset(&data[stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc * myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn], 0, (mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc - stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) * myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);

free(stash->texData);
stash->texData = data;

// Increase atlas size
mU915ql5hgtbU1tdUxYnPsm4JMUsJwea4TQekAOLG(stash->atlas, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

// Add existing data as dirty.
for (i = 0; i < stash->atlas->mwS7G5tPyrLVbpaO864ZeBKY8XdCYeDTN6Udk8Fvm; i++)
maxy = mZ4dvJfIBP6AjQX31xgWxFdKzeU4CO2DEVm70naei(maxy, stash->atlas->nodes[i].y);
stash->dirtyRect[0] = 0;
stash->dirtyRect[1] = 0;
stash->dirtyRect[2] = stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->dirtyRect[3] = maxy;

stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->itw = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->ith = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;

return 1;
}

int mnvwva4NVW9YH0eW70Ga58c2O04LAwNj4qN7eeiXF(mZ4X03DqVJr6YTGxJCVASp1nwOLeRQ8KGH838Sdkm* stash, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
{
int i, mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
if (stash == NULL) return 0;

// Flush pending glyphs.
mivwxRYLFHljsTMKqxfIS6A67BHfJKkgvdJ0HUEW4(stash);

// Create new texture
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderResize != NULL) {
if (stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.renderResize(stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.userPtr, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) == 0)
return 0;
}

// Reset atlas
mbMvvDmXnl5EcyiAdzjZmGN977HsYjy2n59ZEtbNm(stash->atlas, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

// Clear texture data.
stash->texData = (unsigned char*)realloc(stash->texData, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);
if (stash->texData == NULL) return 0;
memset(stash->texData, 0, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn * mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc);

// Reset dirty rect
stash->dirtyRect[0] = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->dirtyRect[1] = mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->dirtyRect[2] = 0;
stash->dirtyRect[3] = 0;

// Reset cached glyphs
for (i = 0; i < stash->mvUn3WZW9i7EyR7rhAnN0h31az0NfnRbrAtKCjffO; i++) {
mLrod79SqyP4duW56pXST7XNS4glLf2Gb33p787J2* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = stash->fonts[i];
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mNoK9OXD5xgFtmxScWLkpTJs9h6JktFbo8vWYRYzI = 0;
for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < FONS_HASH_LUT_SIZE; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++)
mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->lut[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = -1;
}

stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
stash->itw = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
stash->ith = 1.0f/stash->m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk.mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;

// Add white rect at 0,0 for debug drawing.
muR0KZ01ZUFeanhUmZp4vRK5mqGiI40Jkz1Ki5gME(stash, 2,2);

return 1;
}


#endif
