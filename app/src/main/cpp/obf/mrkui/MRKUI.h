#ifndef MRKUI_H
#define MRKUI_H

#ifdef __cplusplus
extern "C" {
#endif

#define MRKUI_PI 3.f

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#endif

typedef struct my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx;

struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk {
union {
float rgba[4];
struct {
float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC,g,b,mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
};
};
};
typedef struct mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk;

struct m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ {
float xform[6];
float extent[2];
float mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA;
float mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl;
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mdCtopK7pMIZqOtGb0VPtGCm4OAjHG5TaGPYKUJZ0;
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mcQDL9HSGPlLh4ivTbrEd43bXm9g7w8hF2wG5RyHH;
int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R;
};
typedef struct m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ;

enum MRKUIwinding {
MRKUI_CCW = 1,// Winding for solid shapes
MRKUI_CW = 2,// Winding for holes
};

enum MRKUIsolidity {
MRKUI_SOLID = 1,// CCW
MRKUI_HOLE = 2,// CW
};

enum MRKUIlineCap {
mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l,
MRKUI_ROUND,
MRKUI_SQUARE,
MRKUI_BEVEL,
mjfUTlQL3XpQ7EwiEeHSDb9DH1Op1wf5z3UIoyM58,
};

enum MRKUIalign {
// Horizontal miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz
MRKUI_ALIGN_LEFT = 1<<0,// Default, miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz text horizontally myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT left.
MRKUI_ALIGN_CENTER = 1<<1,// Align text horizontally myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT center.
MRKUI_ALIGN_RIGHT = 1<<2,// Align text horizontally myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT right.
// Vertical miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz
MRKUI_ALIGN_TOP = 1<<3,// Align text vertically myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT top.
MRKUI_ALIGN_MIDDLE= 1<<4,// Align text vertically myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT middle.
MRKUI_ALIGN_BOTTOM= 1<<5,// Align text vertically myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT bottom.
MRKUI_ALIGN_BASELINE= 1<<6, // Default, miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz text vertically myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT baseline.
};

enum MRKUIblendFactor {
MRKUI_ZERO = 1<<0,
MRKUI_ONE = 1<<1,
MRKUI_SRC_COLOR = 1<<2,
MRKUI_ONE_MINUS_SRC_COLOR = 1<<3,
MRKUI_DST_COLOR = 1<<4,
MRKUI_ONE_MINUS_DST_COLOR = 1<<5,
MRKUI_SRC_ALPHA = 1<<6,
MRKUI_ONE_MINUS_SRC_ALPHA = 1<<7,
MRKUI_DST_ALPHA = 1<<8,
MRKUI_ONE_MINUS_DST_ALPHA = 1<<9,
MRKUI_SRC_ALPHA_SATURATE = 1<<10,
};

enum MRKUIcompositeOperation {
MRKUI_SOURCE_OVER,
MRKUI_SOURCE_IN,
MRKUI_SOURCE_OUT,
MRKUI_ATOP,
MRKUI_DESTINATION_OVER,
MRKUI_DESTINATION_IN,
MRKUI_DESTINATION_OUT,
MRKUI_DESTINATION_ATOP,
MRKUI_LIGHTER,
MRKUI_COPY,
MRKUI_XOR,
};

struct mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS {
int mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS;
int mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi;
int moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH;
int mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g;
};
typedef struct mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS;

struct mEc0XjUKIeWy3xadDd0enfrDKINh4p3Bap6Gmn0ag {
const char* str;// mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6 of the glyph in the input string.
float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;// The m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp-coordinate of the logical glyph position.
float minx, maxx;// The bounds of the glyph shape.
};
typedef struct mEc0XjUKIeWy3xadDd0enfrDKINh4p3Bap6Gmn0ag mEc0XjUKIeWy3xadDd0enfrDKINh4p3Bap6Gmn0ag;

struct mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb {
const char* start;// Pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the input text where the row starts.
const char* end;// Pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the input text where the row ends (one past the last character).
const char* mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;// Pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the beginning of the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 row.
float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;// Logical myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn of the row.
float minx, maxx;// Actual bounds of the row. Logical with mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 bounds can differ because of kerning mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 some parts over extending.
};
typedef struct mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb;

enum MRKUIimageFlags {
    MRKUI_IMAGE_GENERATE_MIPMAPS= 1<<0,     // Generate mipmaps during creation of the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
MRKUI_IMAGE_REPEATX= 1<<1,// Repeat mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R in mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14 mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q.
MRKUI_IMAGE_REPEATY= 1<<2,// Repeat mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R in m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3 mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q.
MRKUI_IMAGE_FLIPY= 1<<3,// Flips (inverses) mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R in m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3 mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q when rendered.
MRKUI_IMAGE_PREMULTIPLIED= 1<<4,// Image data has premultiplied mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E.
MRKUI_IMAGE_NEAREST= 1<<5,// Image interpolation is Nearest instead Linear
};

// Begin drawing mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c new frame
// Calls myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT MRKUI drawing API should be wrapped in mwngG50VO0PjiFFGXo0Ct3P5WMQvl0FPA6cwOSuVo() & mMyqsGRCArKfd0zO6wu7PL80Q9w8FwwUDBWawurm1()
// mwngG50VO0PjiFFGXo0Ct3P5WMQvl0FPA6cwOSuVo() defines the size of the window myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT in relation currently
// set viewport (i.e. glViewport on GL backends). Device pixel ration allows myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
// control the rendering on Hi-DPI devices.
// For example, GLFW returns two dimension for an opened window: window size mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02
// frame buffer size. In that case you would set windowWidth/mIaNvvhpxzdoORTDpylhlYCZ41HRqxpYRBn0g6JFn myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the window size
// devicePixelRatio myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT: frameBufferWidth / windowWidth.
void mwngG50VO0PjiFFGXo0Ct3P5WMQvl0FPA6cwOSuVo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float windowWidth, float windowHeight, float devicePixelRatio);

// Cancels drawing the current frame.
void mRznED4JNxkkHbS48wwc1sB9x54LxHK2rxRm7rvOA(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Ends drawing flushing remaining render msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.
void mMyqsGRCArKfd0zO6wu7PL80Q9w8FwwUDBWawurm1(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

//
// Composite operation
//
// The composite operations in MRKUI are modeled after HTML Canvas API, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02
// the mRl1lsvkFwWGaSZfJQLzB7Mf9TYjFgno1g4rVtw3P func is based on OpenGL (see corresponding manuals for more m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C).
// The colors in the blending msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 have premultiplied mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E.

// Sets the composite operation. The mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9 parameter should be one of MRKUIcompositeOperation.
void mG3eZDuI6U7eehzjXL5VcdCCoY9APvByj0KARvMcO(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mnZkzelaXxRS8eQ3I8LBtosIjkVsnERaTfiBvTwm9);

// Sets the composite operation with custom pixel arithmetic. The parameters should be one of MRKUIblendFactor.
void mishAqJI5H8WM6t4OeWCGy0peJIns6FA8YzBSg84V(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int sfactor, int dfactor);

// Sets the composite operation with custom pixel arithmetic for RGB mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E components separately. The parameters should be one of MRKUIblendFactor.
void mEkXnGwu13Moidhqh2PvJedn7SfUL4vc8427TPkgG(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mZjyAmo3u3mpz6r9K54Cw37J5A1SNaOZGLyrBBzjS, int mBNGPmHR3xpACduR9eemxX2HQHg7Bq4sjgVZwmQzi, int moCy6DfT5F3zMaFaFh3ZrgGBrEYM4cIYt1a8MdjjH, int mFlR0ClbsgOOAZo1bA6jereTJqsb0ic7A0XodCj5g);

//
// Color utils
//
// Colors in MRKUI are stored as unsigned ints in ABGR format.

// Returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value from red, green, blue values. Alpha will be set myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT 255 (1.0f).
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mGnNiCWoJS09NaYTPtsNYrCSfaxueNHs5Ygqh9ECt(unsigned char mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, unsigned char g, unsigned char b);

// Returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value from red, green, blue values. Alpha will be set myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT 1.0f.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mJzNBdNsdcKFTbTcw9vazCXUcFjoR92fOl9ItvWPK(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b);


// Returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value from red, green, blue mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E values.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN(unsigned char mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, unsigned char g, unsigned char b, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value from red, green, blue mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E values.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk m6XVjzn2z662ekeWHLgBlodqX0CexVV7jevThD551(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);


// Linearly interpolates from mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP c0 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT c1, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns resulting mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mZ2OdSFr8TenOBmNj9XBZ8znDhAaz1quVh4M42Xj7(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c0, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c1, float u);

// Sets transparency of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mNt7MfAXzSHnvc3RTlFykMVtwocOiRA3fMhekceVx(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c0, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Sets transparency of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mUaN9OqPUgj92RGDJyLcXddPSKtyvqzm9t3i4mteZ(mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk c0, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Returns mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value specified by hue, saturation mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 lightness.
// HSL values are all in range [0..1], mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E will be set myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT 255.
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mL93rnwrJxYHluUaBQwtzPB9h7auIYfdPiQdtlrP5(float h, float s, float l);

// Returns mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value specified by hue, saturation mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 lightness mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E.
// HSL values are all in range [0..1], mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E in range [0..255]
mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk miGYj7kxkRTFoSxgmCtLnfSGhK7cwiqB2p0UzxhhT(float h, float s, float l, unsigned char mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

//
// State Handling
//
// MRKUI contains msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 which represents how paths will be rendered.
// The msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 contains transform, m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 styles, text mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh styles,
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq clipping.

// Pushes mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 saves the current render msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 into mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 stack.
// mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel matching mEnzEy2XEJSfhYRPOiZFCfb9yNUhxaCG88bCZDY81() must be used myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT restore the msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.
void mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Pops mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 restores current render msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2.
void mEnzEy2XEJSfhYRPOiZFCfb9yNUhxaCG88bCZDY81(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Resets current render msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT default values. Does not affect the render msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 stack.
void m3HslY985uJxsfB7ALCTPRYnkIHe3YnVlkOXPQmWn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

//
// Render styles
//
// Fill mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 render style can be either mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c solid mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP or mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c paint which is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c gradient or mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c pattern.
// Solid mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP is simply defined as mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP value, different kinds of paints can be created
// using mBOlgW8laJBK8LsBl4rKj12wJoIXDAWuhVsRnv1qn(), mdyvG2rNfeGQixvCtRbnCNlhHLX7ozeMWHpAmvGwv(), m0LFjxsxkBL5djdSrTBFTbHUtDq0oaTge4L5cfTTJ() mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mSwnb5D9th8QoPkkDkyiUUi0DZauFnSLsB88o1Whq().
//
// Current render style can be saved mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 restored using mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH() mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mEnzEy2XEJSfhYRPOiZFCfb9yNUhxaCG88bCZDY81().

// Sets whether myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw antialias for m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX() mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(). It's enabled by default.
void mo10ziaid6LG7PVFZYTNaHSuYCxxHbDCyhS8KaOOc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int enabled);

// Sets current mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c solid mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.
void m04M6uiH0JLlLn2jInACI76VOPXadkfCAWk3Y2RjR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);

// Sets current mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c paint, which can be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c one of the gradients or mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c pattern.
void mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ paint);

// Sets current m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB style myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c solid mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.
void mAHZCgiUiBLU8QKhJI72eKDqcmhASKdOOw9NUPTcS(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP);

// Sets current m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB style myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c paint, which can be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c one of the gradients or mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c pattern.
void mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ paint);

// Sets the miter limit of the mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style.
// Miter limit controls when mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c sharp corner is beveled.
void mmBxsVYmv5FUWlkF61j7PfuxLVAbpddK1TOhJ2R6N(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float limit);

// Sets the mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn of the mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style.
void m7Ar59VA6z5YPjFT04EQfG1aviRFXE3XQN1gyxhqJ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float size);

// Sets how the end of the line (cap) is drawn,
// Can be one of: mF9TF3xFZ7mhGVugbfTyGeMukGH3utDZkr4cuyz5l (default), MRKUI_ROUND, MRKUI_SQUARE.
void mLmChCIzJqhUkJWprqwEgRJ4QLQBr5kMHICDbbdaY(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int cap);

// Sets how sharp path corners are drawn.
// Can be one of mjfUTlQL3XpQ7EwiEeHSDb9DH1Op1wf5z3UIoyM58 (default), MRKUI_ROUND, MRKUI_BEVEL.
void mLPlM5kv2v5G6sUk0H6xd1JrghtYF8bB09NzIEABg(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int join);

// Sets the transparency applied myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT all rendered shapes.
// Already transparent paths will get proportionally more transparent as well.
void maqb8lSFbFNpBG6aTwP3huA1RPnChliAE5IXENtOp(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);

//
// Transforms
//
// The paths, gradients, patterns mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq region are transformed by an transformation
// matrix at the time when they are passed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the API.
// The current transformation matrix is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c affine matrix:
//   [sx kx tx]
//   [ky mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso ty]
//   [ 0  0  1]
// Where: sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso define scaling, kx,ky skewing, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 tx,ty translation.
// The last row is assumed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be 0,0,1 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 is not stored.
//
// Apart from mUeV2XTTGtaOEG60xg1zsHqdIPa0xH6jtb47MUsCj(), each transformation function first creates
// specific transformation matrix mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 pre-multiplies the current transformation by it.
//
// Current coordinate system (transformation) can be saved mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 restored using mVR6lH08KysBUg5DOx5I2fd9ZuJdf0q2bJ2VcfKOH() mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mEnzEy2XEJSfhYRPOiZFCfb9yNUhxaCG88bCZDY81().

// Resets current transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c identity matrix.
void mUeV2XTTGtaOEG60xg1zsHqdIPa0xH6jtb47MUsCj(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Premultiplies current coordinate system by specified matrix.
// The parameters are interpreted as matrix as follows:
//   [mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c c e]
//   [b d f]
//   [0 0 1]
void mjCqcV3DaKw33h5bZnbN4Wbqo4WBZ184z1AyD3Tzt(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, float b, float c, float d, float e, float f);

// Translates current coordinate system.
void mxJ8JN3mQUb8SYBOCwER49aLArugU2iMzc9zWWahS(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Rotates current coordinate system. Angle is specified in radians.
void m2FkAsviO5JFkZoVtMnmv68YUh3iWILEXg18r9ak0(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle);

// Skews the current coordinate system along mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14 axis. Angle is specified in radians.
void m95o6iAOB11LcSKQtMvhWHfOE3GMQyJxH7BGtFJ7F(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle);

// Skews the current coordinate system along m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3 axis. Angle is specified in radians.
void m4vD8A06hXrQDUcfNq2lGBsfNzK2exZZEbYYVWqxx(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float angle);

// Scales the current coordinate system.
void mJc8eNjTvILdQejexiLH4VDMhKL4N2lwKfu4WPWna(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Stores the top part (mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c-f) of the current transformation matrix in myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the specified buffer.
//   [mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c c e]
//   [b d f]
//   [0 0 1]
// There should be space for 6 floats in the return buffer for the values mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c-f.
void mq5aMgQrQLkjIa6l6mM7SqgxFQWs5lzkpJqepviSm(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float* xform);


// The following functions can be used myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT make calculations on 2x3 transformation matrices.
// mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel 2x3 matrix is represented as float[6].

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT identity matrix.
void m2rY1wSzq6MDdrAKnoslJWHgcZczFZCjEgMaoYDsP(float* dst);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT translation matrix matrix.
void m5Iobq0jvOmr7hbArbk1JRu1DW8sDF6tTE97isYAJ(float* dst, float tx, float ty);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy matrix.
void mfCoEfOtuOAQaWLRUJvPvXh3SDigf79DxeIQDFdHg(float* dst, float sx, float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT rotate matrix. Angle is specified in radians.
void mLpXVZiXVxS5MbVcP3jCMPL5Jv4eQkE3qEz5tczYN(float* dst, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT skew-m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp matrix. Angle is specified in radians.
void mtzKezl3wA0Q54G3S1Uj6Z2pVMhKjLJA2OQmFmyMB(float* dst, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT skew-y matrix. Angle is specified in radians.
void mEeopHSnOUtdDNpMtE8lqO3FLzi0UHCEjmOz37nRA(float* dst, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP of multiplication of two transforms, of mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel = mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel*mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG.
void m3iSnqYd21zzRRWx2srINKQwl34Wf4ZrBYPyAsxQO(float* dst, const float* src);

// Sets the transform myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP of multiplication of two transforms, of mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel = mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG*mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel.
void mfZW9YVawlcYFw7ivdx1Ni3DWtqjFY8Ql1DPiDL9M(float* dst, const float* src);

// Sets the destination myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT inverse of specified transform.
// Returns 1 if the inverse could be calculated, else 0.
int mpNbp6trrCIvxxyuw1kA1rMxSBEWTeI35ptrmqBAy(float* dst, const float* src);

// Transform mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c point by given transform.
void mEV3hrcbuH99WPNLX65f3bk4ooM8tsQRwXS4kDfXf(float* dstx, float* dsty, const float* xform, float srcx, float srcy);

// Converts degrees myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT radians mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 vice versa.
float msovUz6tSFPDjNau73Hv8zCuKnIiy9FCvmv8j10GH(float deg);
float mhIdjpwbJP38fC6MXWYQQY2wbEfbBWEwf4t4deMxC(float rad);

//
// Images
//
// MRKUI allows you myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT load jpg, png, psd, tga, pic mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 gif files myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be used for rendering.
// In addition you can upload your own mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R. The mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R loading is provided by stb_image.
// The parameter imageFlags is combination of m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf defined in MRKUIimageFlags.

// Creates mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R by loading it from the disk from specified file name.
// Returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
int mH1mXETCQjcvT0fCPw3rQdO3F5MjIdt6YXdCyFfE6(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* filename, int imageFlags);

// Creates mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R by loading it from the specified chunk of memory.
// Returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
int mX5bz4Hu68LYvxJQYx8ZTPm5PkePDnX48Ox3HRx9R(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int imageFlags, unsigned char* data, int ndata);

// Creates mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R from specified mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R data.
// Returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
int m9DDyetlwzFY4GtL4vo798SeRDjHh1vw7w67ABcpj(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int w, int h, int imageFlags, const unsigned char* data);

// Updates mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R data specified by mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R handle.
void mr9NuxqW5TtGama1YyvxXmDsvSWld8V6wK6xWUJ2o(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, const unsigned char* data);

// Returns the dimensions of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c created mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
void mqeb5tn3uvo5L5rBdEuuGEbLD7n7ruoV0CCTlL66S(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int* w, int* h);

// Deletes created mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R.
void mgLGIfY89sBwjoJBwt0hJq4zsDcjF7sLvkTQCny6Z(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);

//
// Paints
//
// MRKUI supports four types of paints: linear gradient, box gradient, radial gradient mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R pattern.
// These can be used as paints for strokes mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 fills.

// Creates mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c linear gradient. Parameters (sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso)-(ex,mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg) specify the start mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 end coordinates
// of the linear gradient, icol specifies the start mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 ocol the end mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.
// The gradient is transformed by the current transform when it is passed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY() or mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7().
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mBOlgW8laJBK8LsBl4rKj12wJoIXDAWuhVsRnv1qn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float sx, float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso, float ex, float mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg,
   mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol);

// Creates mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c box gradient. mCgrnxbU6R93i96clDS8GQYfOOmFT9e7ymGK1AbcV gradient is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c feathered rounded rectangle, it is useful for rendering
// drop shadows or highlights for boxes. Parameters (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y) define the top-left corner of the rectangle,
// (w,h) define the size of the rectangle, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC defines the corner mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 f mOiQzR3L1KTXKMmUv5X2qyKVACaChiFPmXg41e7Tl. Feather defines how blurry
// the border of the rectangle is. Parameter icol specifies the inner mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 ocol the outer mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP of the gradient.
// The gradient is transformed by the current transform when it is passed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY() or mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7().
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mdyvG2rNfeGQixvCtRbnCNlhHLX7ozeMWHpAmvGwv(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h,
float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float f, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol);

// Creates mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c radial gradient. Parameters (cx,cy) specify the center, inr mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 outr specify
// the inner mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 outer mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA of the gradient, icol specifies the start mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 ocol the end mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP.
// The gradient is transformed by the current transform when it is passed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY() or mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7().
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ m0LFjxsxkBL5djdSrTBFTbHUtDq0oaTge4L5cfTTJ(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float inr, float outr,
   mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk icol, mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk ocol);

// Creates mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns an mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R patter. Parameters (ox,oy) specify the left-top location of the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R pattern,
// (ex,mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg) the size of one mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, angle rotation around the top-left corner, mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R is handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render.
// The gradient is transformed by the current transform when it is passed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY() or mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7().
m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ mSwnb5D9th8QoPkkDkyiUUi0DZauFnSLsB88o1Whq(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float ox, float oy, float ex, float mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg,
 float angle, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, float mLUiqxyiZPZ9h5CQ3XFuogOOuERsYItD7atp1c29E);

//
// Scissoring
//
// Scissoring allows you myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT clip the rendering into mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c rectangle. This is useful for various
// user interface cases like rendering mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c text edit or mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c timeline.

// Sets the current mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rectangle.
// The mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rectangle is transformed by the current transform.
void mh0nqh0yXHlHpsSLPnDkPmPJBimq6DEi4dtTV2I1v(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h);

// Intersects current mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rectangle with the specified rectangle.
// The mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rectangle is transformed by the current transform.
// Note: in case the rotation of mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58 mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rect differs from
// the current one, the intersection will be done between the specified
// rectangle mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 the mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58 mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq rectangle transformed in the current
// transform space. The resulting shape is always rectangle.
void mPKwO5dlf39LoRMOBK7rTW94momIFpL4fJuN8geuN(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h);

// Reset mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 disables scissoring.
void mq46HZ4sgiUDLCotOLMENnQnv55HgOpu5j8dwovp3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

//
// Paths
//
// Drawing mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c new shape starts with m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(), it clears all the currently defined paths.
// Then you define one or more paths mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 sub-paths which describe the shape. The are functions
// myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw common shapes like rectangles mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 circles, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 lower level step-by-step functions,
// which allow myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT define mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c path curve by curve.
//
// MRKUI uses even-odd m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB rule myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw the shapes. Solid shapes should have counter clockwise
// mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 holes should have counter clockwise order. To specify mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c path you can
// call mMpOiLjNtM3NKwGDIVibdVvuR4j5kOSi2F4HtykIa(). This is useful especially for the common shapes, which are drawn CCW.
//
// Finally you can m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB the path using current m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB style by calling mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(), mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 it
// with current mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style by calling m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX().
//
// The curve segments mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 sub-paths are transformed by the current transform.

// Clears the current path mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 sub-paths.
void m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Starts new sub-path with specified point as first point.
void mnXY5sFv1yWENQJH4Cfds6nQTfYQ1YEOdmrKRBoIh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Adds line segment from the last point in the path myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the specified point.
void mnvQT0XESunqaW0WDt1e3i5Afxvr2I0HeVciDi9qR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Adds cubic bezier segment from last point in the path via two control points myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the specified point.
void maIlF1yQjLFyjdQrK54pywyvSsM3PdRFPp6wifS7V(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float c1x, float c1y, float c2x, float c2y, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Adds quadratic bezier segment from last point in the path via mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c control point myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the specified point.
void mDPFPb3pHtj5N2Ncf0Ep7QJcGDdCEboxRFbmYjWRh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y);

// Adds an arc segment at the corner defined by the last path point, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 two specified points.
void mM3OSf7JThNjD61wm18Eijghjq8TZ4XgFyclkcHzc(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float x1, float y1, float x2, float y2, float mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA);

// Closes current sub-path with mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c line segment.
void ms07Giq2JzZ7IGMZgUiMKM4Ji21IsaTrCq6IbdeSz(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Sets the current sub-path mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94, see MRKUIwinding mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 MRKUIsolidity.
void mMpOiLjNtM3NKwGDIVibdVvuR4j5kOSi2F4HtykIa(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG);

// Creates new circle arc shaped sub-path. The arc center is at cx,cy, the arc mCaK1DpNs8VV0U7D8qJIUIPrQ6JHliKRjgSKki0EA is mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC,
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 the arc is drawn from angle a0 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT a1, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 swept in mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG (MRKUI_CCW, or MRKUI_CW).
// Angles are specified in radians.
void m2lRILpDMm6QDNwKu9HDaQpGldexernFQzFbEnHq3(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float a0, float a1, int mC8fP5ZZMPAZEjk8RWJQMWm2tqcMczRPXhQ9XHRsG);

// Creates new rectangle shaped sub-path.
void mbdzVdcmDPpti0WQVy5cqYRzWcIAY8juY3gINMaKR(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h);

// Creates new rounded rectangle shaped sub-path.
void mfEKIaL94HRGW1PVm6mFSruo4HDpunzmJoIspWRcu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC);

// Creates new rounded rectangle shaped sub-path with varying radii for each corner.
void mGrvPRwH9AWqJLHf8VhulgE3a7PTI8nocuAuYJ6i1(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);

// Creates new ellipse shaped sub-path.
void mdswyh7B2rHkksI3POM6yOQ4jmTJozgo0AaNKD4z8(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float rx, float ry);

// Creates new circle shaped sub-path.
void mHFyOk07XkLTtFw0zawwr10sM43Bn57rxgfN7QgDK(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float cx, float cy, float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC);

// Fills the current path with current m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB style.
void mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Fills the current path with current mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6 style.
void m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);


//
// Text
//
// MRKUI allows you myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT load .ttf files mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render text.
//
// The appearance of the text can be defined by setting the current text style
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 by specifying the m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP. Common text mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh settings such as
// mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size, letter mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 text miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz are supported. Font m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 allows you
// myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT create simple text effects such as drop shadows.
//
// At render time the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh face can be set based on the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh handles or name.
//
// Font measure functions return values in local space, the calculations are
// carried in the same resolution as the final rendering. This is done because
// the text glyph positions are snapped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the nearest m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam sharp rendering.
//
// The local space means that values are not rotated or ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy as per the current
// transformation. For example if you set mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT 12, which would mean that
// line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc is 16, then regardless of the current scaling mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 rotation, the
// returned line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc is always 16. Some measures may vary because of the scaling
// since aforementioned pixel snapping.
//
// While this may sound mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c little odd, the setup allows you myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT always render the
// same way regardless of scaling. I.e. following works regardless of scaling:
//
//const char* txt = "Text me up.";
//mn7QRzZxAXSev1fD8gaV5NKb8sR9fPlOP9kwXpXb8(vg, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, txt, NULL, bounds);
//m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(vg);
//mfEKIaL94HRGW1PVm6mFSruo4HDpunzmJoIspWRcu(vg, bounds[0],bounds[1], bounds[2]-bounds[0], bounds[3]-bounds[1]);
//mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(vg);
//
// Note: currently only solid mHkmxON1v9Trl1ewEkAfLJMfddsTarf26nEfPRgRP m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB is supported for text.

// Creates mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh by loading it from the disk from specified file name.
// Returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh.
int mbskZGF4cD9os92z8lNen3B8rdAeQFBnJMClX0tQk(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name, const char* filename);

// Creates mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh by loading it from the specified memory chunk.
// Returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh.
int mbJ3kB9gPNC1YiAZVvHGaan3n6En5fXdPGDP2dGXq(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name, unsigned char* data, int ndata, int m5rIqsP5AtKqyRSTO9UYGAAs8JhqbjuTHQ6ewyGCs);

// Finds mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c loaded mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh of specified name, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns handle myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT it, or -1 if the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh is not found.
int mJNOhvufOnyeEOedMkPmdvoNWVrjPBUKDID1O6PGw(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* name);

// Adds mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c fallback mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh by handle.
int ms8YvT518GOoXhraGol4MvxdXcuArkka49UW8fKJo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int baseFont, int fallbackFont);

// Adds mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c fallback mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh by name.
int mszOMbQOEAEG6nyfRYCqz9p2ydGYflvGR5zYNQR6R(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* baseFont, const char* fallbackFont);

// Sets the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size of current text style.
void mjNjN168G2bSWj18cM4zcrPY7ni4eaiYrbzWELo06(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float size);

// Sets the m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8 of current text style.
void mxjmFUvEoFJbhg2lPQS55TvXUj7bSzWU8jCCCCQUo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m27SraHJbxPh0qE2woGZj41MFjqLiZqBUQYPMxPO8);

// Sets the letter mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s of current text style.
void m9Dcq9MVgxDLCmEaTH50A5jd486udOmW5pQR50Loh(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s);

// Sets the proportional line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of current text style. The line mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc is specified as multiple of mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size.
void m64byjh6deGqridOdonlIETpOqijhLAqPyPxMg8mV(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float mBBPgjEhD3b2uPMrf6HrLJKqZMfde9CUeS8UvJUGi);

// Sets the text miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz of current text style, see MRKUIalign for options.
void mycndqGrNMF9dZ5US9CfM249LUbM2GP2pD1APR4Nr(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int miUIqiMY3ndMWWuZqH8rwtnIvgnChCahLtijXGFiz);

// Sets the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh face based on specified ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl of current text style.
void merC4jTWVp3RwPCCSrTZkKxjzwJzOSa0cOHjdUbgW(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, int mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);

// Sets the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh face based on specified name of current text style.
void mGsQx3ATSmaIicqFfQwJiZrqi6Wlf57qZbKidHsNn(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh);

// Draws text string at specified location. If end is specified only the sub-string up myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the end is drawn.
float mD7BGE6tD15Q5JVrQe9kvq1unJq8YyOeJI9TYQO33(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end);

// Draws multi-line text string at specified location wrapped at the specified myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn. If end is specified only the sub-string up myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the end is drawn.
// mVFxviKhn0pYE7O2WQsAqAQWPx8Q4rVF9chjhuZdb space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line characters are encountered.
// Words longer than the max myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn are slit at nearest character (i.e. no hyphenation).
void mlDDINOiSAzPEsR6fOSUm1OPckjtObbytWmEuqkol(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float breakRowWidth, const char* string, const char* end);

// Measures the specified text string. Parameter bounds should be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Returns the horizontal mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa of the measured text (i.e. where the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 character should drawn).
// Measured values are returned in local coordinate space.
float mn7QRzZxAXSev1fD8gaV5NKb8sR9fPlOP9kwXpXb8(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end, float* bounds);

// Measures the specified multi-text string. Parameter bounds should be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Measured values are returned in local coordinate space.
void mSiUIizxsnUBv6UFRjysvmtlYFdivNlDKpcDli8AV(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float breakRowWidth, const char* string, const char* end, float* bounds);

// Calculates the glyph m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp positions of the specified text. If end is specified only the sub-string will be used.
// Measured values are returned in local coordinate space.
int mjH2QqdlRvG7u6XA83F5uLKLhzXUzE10wAjVGVVlo(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, const char* string, const char* end, mEc0XjUKIeWy3xadDd0enfrDKINh4p3Bap6Gmn0ag* positions, int maxPositions);

// Returns the vertical metrics based on the current text style.
// Measured values are returned in local coordinate space.
void mQgXnBH9OJw8GqGMIMxCz10HumRGPpIdwcouPGuxu(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, float* m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi, float* mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr, float* m8SpwX8uFkoTxU7s1CORsWeasV1eln0bv5HBWCen9);

// Breaks the specified text into m5RtqEm8VqdvN2MxHFxp8N6bkwFEegsbelmVWAFCI. If end is specified only the sub-string will be used.
// mVFxviKhn0pYE7O2WQsAqAQWPx8Q4rVF9chjhuZdb space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line characters are encountered.
// Words longer than the max myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn are slit at nearest character (i.e. no hyphenation).
int mch8m96TeGdu8qfsSSpZGy0pKPFqF2aK7SoOQse2M(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx, const char* string, const char* end, float breakRowWidth, mc4akzWRsa39XSZEuqdxYztfd8kNPE8Mz5gAfstlb* rows, int maxRows);

//
// Internal Render API
//
enum MRKUItexture {
MRKUI_TEXTURE_ALPHA = 0x01,
MRKUI_TEXTURE_RGBA = 0x02,
};

struct mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn {
float xform[6];
float extent[2];
};
typedef struct mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn;

struct mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv {
float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,u,v;
};
typedef struct mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv;

struct mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz {
int first;
int count;
unsigned char mbDY50o6oSxgnUCdVmSynQ2vEJSNZ7ORrQNIt6Khj;
int mbW2zKXR3PW2UtFCxLR14x2VoGz2xkPlec6GgU4Q4;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB;
int mTDwaCPKZIkzOo06Ft72c5RhRLPVjIlsJsJtujybZ;
mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* mInpsZUDUOBqfhJoJpehzngI404qNcIKTB8UZI1v6;
int maAfQJYhozxfwypxyg3EjeofYcfBBmFqFu3AX6Kza;
int mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94;
int m7Iolu7nriLBNBsCqFeGRYYGKgckypfWoFbuTW5W1;
};
typedef struct mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz;

struct mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az {
void* userPtr;
int mdFwDLRZbeFsqCZz9pURAan4Yu9PfxsoA1NcxRnS8;
int (*renderCreate)(void* uptr);
int (*renderCreateTexture)(void* uptr, int mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, int w, int h, int imageFlags, const unsigned char* data);
int (*renderDeleteTexture)(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R);
int (*renderUpdateTexture)(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, int y, int w, int h, const unsigned char* data);
int (*renderGetTextureSize)(void* uptr, int mtngA0EUA5X2cgilHPSYwFRlzicHYPWDt7Kk2Z94R, int* w, int* h);
void (*renderViewport)(void* uptr, float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, float mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, float devicePixelRatio);
void (*renderCancel)(void* uptr);
void (*renderFlush)(void* uptr);
void (*renderFill)(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, float fringe, const float* bounds, const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths, int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
void (*renderStroke)(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, float fringe, float mwnwsKG5SjXMbatbTWTypqgaquozsPF5QHOT85iGa, const mbHH7xj2gwTLfcgDBf8CMtbneFTP2P7WyJq9VyGCz* paths, int m9duZPkpKiwD1eTM3i8T4tKqigdigEeWAf5mnpyAz);
void (*renderTriangles)(void* uptr, m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ* paint, mLQzOScB6e0xoKJnp463HJ7cdeHYtSVctz7uplibS mVBciU5Pm3rGizMtK0Ua9lNeB2RI17GKTSv0fmXGG, mpz4iF7IEjuCDMhD8tCfPQTJs7G3y2UlzQbUskoHn* mCfgZRyNBVJxRL4IUwAn5cOQoMhAaoxs43dGGjeeq, const mNUsm5lFLNHByMgZY9P3BKE7sATwn4mtTH79fzMHv* verts, int mzuEpQL4EQN9Vjbry6IUsdangxoC1QMmIVJiRcdUA);
void (*renderDelete)(void* uptr);
};
typedef struct mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az;

// Constructor mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 destructor, called by the render back-end.
my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* mxdzgKV0758RY1Q0kyyt9xf633PmvdswzqoLIlrys(mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az* m1j0Z7Fb1TcX8bl2bYrdmoOdzSnlSglSM0oVgE8Rk);
void mfXpYSpM8LFr5mH6eVqGB66hc83LpRVTAoGij4Rdt(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

mSM3Cs7nLnCxF5PmH4fxG0FSZX4KlK7PCGvdD45Az* m4wxdT9dKFfcmz4hiilC50tOQEk9Fof4hR6BfAXRF(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

// Debug function myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT dump cached path data.
void mXBTgV2Be9oifB3yCBGvWvMZlummY106SmVme4Aby(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx* ctx);

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#define mJCUP56gwGXnoULGzksGf9fJeSCCM1A5udNtCkySs(v) for (;;) { (void)(1 ? (void)0 : ( (void)(v) ) ); break; }

#ifdef __cplusplus
}
#endif

#endif // MRKUI_H
