#ifndef MRKUI_H
#define MRKUI_H

#ifdef __cplusplus
extern "C" {
#endif

#define MRKUI_PI 3.14159265358979323846264338327f

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#endif

typedef struct MRKUIcontext MRKUIcontext;

struct MRKUIcolor {
    union {
        float rgba[4];
        struct {
            float r, g, b, a;
        };
    };
};
typedef struct MRKUIcolor MRKUIcolor;

struct MRKUIpaint {
    float xform[6];
    float extent[2];
    float radius;
    float feather;
    MRKUIcolor innerColor;
    MRKUIcolor outerColor;
    int image;
};
typedef struct MRKUIpaint MRKUIpaint;

enum MRKUIwinding {
    MRKUI_CCW = 1,            // Winding for solid shapes
    MRKUI_CW = 2,                // Winding for holes
};

enum MRKUIsolidity {
    MRKUI_SOLID = 1,            // CCW
    MRKUI_HOLE = 2,            // CW
};

enum MRKUIlineCap {
    MRKUI_BUTT,
    MRKUI_ROUND,
    MRKUI_SQUARE,
    MRKUI_BEVEL,
    MRKUI_MITER,
};

enum MRKUIalign {
    // Horizontal align
            MRKUI_ALIGN_LEFT = 1 << 0,    // Default, align text horizontally to left.
    MRKUI_ALIGN_CENTER = 1 << 1,    // Align text horizontally to center.
    MRKUI_ALIGN_RIGHT = 1 << 2,    // Align text horizontally to right.
    // Vertical align
            MRKUI_ALIGN_TOP = 1 << 3,    // Align text vertically to top.
    MRKUI_ALIGN_MIDDLE = 1 << 4,    // Align text vertically to middle.
    MRKUI_ALIGN_BOTTOM = 1 << 5,    // Align text vertically to bottom.
    MRKUI_ALIGN_BASELINE = 1 << 6, // Default, align text vertically to baseline.
};

enum MRKUIblendFactor {
    MRKUI_ZERO = 1 << 0,
    MRKUI_ONE = 1 << 1,
    MRKUI_SRC_COLOR = 1 << 2,
    MRKUI_ONE_MINUS_SRC_COLOR = 1 << 3,
    MRKUI_DST_COLOR = 1 << 4,
    MRKUI_ONE_MINUS_DST_COLOR = 1 << 5,
    MRKUI_SRC_ALPHA = 1 << 6,
    MRKUI_ONE_MINUS_SRC_ALPHA = 1 << 7,
    MRKUI_DST_ALPHA = 1 << 8,
    MRKUI_ONE_MINUS_DST_ALPHA = 1 << 9,
    MRKUI_SRC_ALPHA_SATURATE = 1 << 10,
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

struct MRKUIcompositeOperationState {
    int srcRGB;
    int dstRGB;
    int srcAlpha;
    int dstAlpha;
};
typedef struct MRKUIcompositeOperationState MRKUIcompositeOperationState;

struct MRKUIglyphPosition {
    const char *str;    // Position of the glyph in the input string.
    float x;            // The x-coordinate of the logical glyph position.
    float minx, maxx;    // The bounds of the glyph shape.
};
typedef struct MRKUIglyphPosition MRKUIglyphPosition;

struct MRKUItextRow {
    const char *start;    // Pointer to the input text where the row starts.
    const char *end;    // Pointer to the input text where the row ends (one past the last character).
    const char *next;    // Pointer to the beginning of the next row.
    float width;        // Logical width of the row.
    float minx, maxx;    // Actual bounds of the row. Logical with and bounds can differ because of kerning and some parts over extending.
};
typedef struct MRKUItextRow MRKUItextRow;

enum MRKUIimageFlags {
    MRKUI_IMAGE_GENERATE_MIPMAPS = 1 << 0,     // Generate mipmaps during creation of the image.
    MRKUI_IMAGE_REPEATX = 1 << 1,        // Repeat image in X direction.
    MRKUI_IMAGE_REPEATY = 1 << 2,        // Repeat image in Y direction.
    MRKUI_IMAGE_FLIPY = 1 << 3,        // Flips (inverses) image in Y direction when rendered.
    MRKUI_IMAGE_PREMULTIPLIED = 1 << 4,        // Image data has premultiplied alpha.
    MRKUI_IMAGE_NEAREST = 1 << 5,        // Image interpolation is Nearest instead Linear
};

// Begin drawing a new frame
// Calls to MRKUI drawing API should be wrapped in MRKUIBeginFrame() & MRKUIEndFrame()
// MRKUIBeginFrame() defines the size of the window to render to in relation currently
// set viewport (i.e. glViewport on GL backends). Device pixel ration allows to
// control the rendering on Hi-DPI devices.
// For example, GLFW returns two dimension for an opened window: window size and
// frame buffer size. In that case you would set windowWidth/Height to the window size
// devicePixelRatio to: frameBufferWidth / windowWidth.
void
MRKUIBeginFrame(MRKUIcontext *ctx, float windowWidth, float windowHeight, float devicePixelRatio);

// Cancels drawing the current frame.
void MRKUICancelFrame(MRKUIcontext *ctx);

// Ends drawing flushing remaining render state.
void MRKUIEndFrame(MRKUIcontext *ctx);

//
// Composite operation
//
// The composite operations in MRKUI are modeled after HTML Canvas API, and
// the blend func is based on OpenGL (see corresponding manuals for more info).
// The colors in the blending state have premultiplied alpha.

// Sets the composite operation. The op parameter should be one of MRKUIcompositeOperation.
void MRKUIGlobalCompositeOperation(MRKUIcontext *ctx, int op);

// Sets the composite operation with custom pixel arithmetic. The parameters should be one of MRKUIblendFactor.
void MRKUIGlobalCompositeBlendFunc(MRKUIcontext *ctx, int sfactor, int dfactor);

// Sets the composite operation with custom pixel arithmetic for RGB and alpha components separately. The parameters should be one of MRKUIblendFactor.
void MRKUIGlobalCompositeBlendFuncSeparate(MRKUIcontext *ctx, int srcRGB, int dstRGB, int srcAlpha,
                                           int dstAlpha);

//
// Color utils
//
// Colors in MRKUI are stored as unsigned ints in ABGR format.

// Returns a color value from red, green, blue values. Alpha will be set to 255 (1.0f).
MRKUIcolor MRKUIRGB(unsigned char r, unsigned char g, unsigned char b);

// Returns a color value from red, green, blue values. Alpha will be set to 1.0f.
MRKUIcolor MRKUIRGBf(float r, float g, float b);


// Returns a color value from red, green, blue and alpha values.
MRKUIcolor MRKUIRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

// Returns a color value from red, green, blue and alpha values.
MRKUIcolor MRKUIRGBAf(float r, float g, float b, float a);


// Linearly interpolates from color c0 to c1, and returns resulting color value.
MRKUIcolor MRKUILerpRGBA(MRKUIcolor c0, MRKUIcolor c1, float u);

// Sets transparency of a color value.
MRKUIcolor MRKUITransRGBA(MRKUIcolor c0, unsigned char a);

// Sets transparency of a color value.
MRKUIcolor MRKUITransRGBAf(MRKUIcolor c0, float a);

// Returns color value specified by hue, saturation and lightness.
// HSL values are all in range [0..1], alpha will be set to 255.
MRKUIcolor MRKUIHSL(float h, float s, float l);

// Returns color value specified by hue, saturation and lightness and alpha.
// HSL values are all in range [0..1], alpha in range [0..255]
MRKUIcolor MRKUIHSLA(float h, float s, float l, unsigned char a);

//
// State Handling
//
// MRKUI contains state which represents how paths will be rendered.
// The state contains transform, fill and stroke styles, text and font styles,
// and scissor clipping.

// Pushes and saves the current render state into a state stack.
// A matching MRKUIRestore() must be used to restore the state.
void MRKUISave(MRKUIcontext *ctx);

// Pops and restores current render state.
void MRKUIRestore(MRKUIcontext *ctx);

// Resets current render state to default values. Does not affect the render state stack.
void MRKUIReset(MRKUIcontext *ctx);

//
// Render styles
//
// Fill and stroke render style can be either a solid color or a paint which is a gradient or a pattern.
// Solid color is simply defined as a color value, different kinds of paints can be created
// using MRKUILinearGradient(), MRKUIBoxGradient(), MRKUIRadialGradient() and MRKUIImagePattern().
//
// Current render style can be saved and restored using MRKUISave() and MRKUIRestore().

// Sets whether to draw antialias for MRKUIStroke() and MRKUIFill(). It's enabled by default.
void MRKUIShapeAntiAlias(MRKUIcontext *ctx, int enabled);

// Sets current stroke style to a solid color.
void MRKUIStrokeColor(MRKUIcontext *ctx, MRKUIcolor color);

// Sets current stroke style to a paint, which can be a one of the gradients or a pattern.
void MRKUIStrokePaint(MRKUIcontext *ctx, MRKUIpaint paint);

// Sets current fill style to a solid color.
void MRKUIFillColor(MRKUIcontext *ctx, MRKUIcolor color);

// Sets current fill style to a paint, which can be a one of the gradients or a pattern.
void MRKUIFillPaint(MRKUIcontext *ctx, MRKUIpaint paint);

// Sets the miter limit of the stroke style.
// Miter limit controls when a sharp corner is beveled.
void MRKUIMiterLimit(MRKUIcontext *ctx, float limit);

// Sets the stroke width of the stroke style.
void MRKUIStrokeWidth(MRKUIcontext *ctx, float size);

// Sets how the end of the line (cap) is drawn,
// Can be one of: MRKUI_BUTT (default), MRKUI_ROUND, MRKUI_SQUARE.
void MRKUILineCap(MRKUIcontext *ctx, int cap);

// Sets how sharp path corners are drawn.
// Can be one of MRKUI_MITER (default), MRKUI_ROUND, MRKUI_BEVEL.
void MRKUILineJoin(MRKUIcontext *ctx, int join);

// Sets the transparency applied to all rendered shapes.
// Already transparent paths will get proportionally more transparent as well.
void MRKUIGlobalAlpha(MRKUIcontext *ctx, float alpha);

//
// Transforms
//
// The paths, gradients, patterns and scissor region are transformed by an transformation
// matrix at the time when they are passed to the API.
// The current transformation matrix is a affine matrix:
//   [sx kx tx]
//   [ky sy ty]
//   [ 0  0  1]
// Where: sx,sy define scaling, kx,ky skewing, and tx,ty translation.
// The last row is assumed to be 0,0,1 and is not stored.
//
// Apart from MRKUIResetTransform(), each transformation function first creates
// specific transformation matrix and pre-multiplies the current transformation by it.
//
// Current coordinate system (transformation) can be saved and restored using MRKUISave() and MRKUIRestore().

// Resets current transform to a identity matrix.
void MRKUIResetTransform(MRKUIcontext *ctx);

// Premultiplies current coordinate system by specified matrix.
// The parameters are interpreted as matrix as follows:
//   [a c e]
//   [b d f]
//   [0 0 1]
void MRKUITransform(MRKUIcontext *ctx, float a, float b, float c, float d, float e, float f);

// Translates current coordinate system.
void MRKUITranslate(MRKUIcontext *ctx, float x, float y);

// Rotates current coordinate system. Angle is specified in radians.
void MRKUIRotate(MRKUIcontext *ctx, float angle);

// Skews the current coordinate system along X axis. Angle is specified in radians.
void MRKUISkewX(MRKUIcontext *ctx, float angle);

// Skews the current coordinate system along Y axis. Angle is specified in radians.
void MRKUISkewY(MRKUIcontext *ctx, float angle);

// Scales the current coordinate system.
void MRKUIScale(MRKUIcontext *ctx, float x, float y);

// Stores the top part (a-f) of the current transformation matrix in to the specified buffer.
//   [a c e]
//   [b d f]
//   [0 0 1]
// There should be space for 6 floats in the return buffer for the values a-f.
void MRKUICurrentTransform(MRKUIcontext *ctx, float *xform);


// The following functions can be used to make calculations on 2x3 transformation matrices.
// A 2x3 matrix is represented as float[6].

// Sets the transform to identity matrix.
void MRKUITransformIdentity(float *dst);

// Sets the transform to translation matrix matrix.
void MRKUITransformTranslate(float *dst, float tx, float ty);

// Sets the transform to scale matrix.
void MRKUITransformScale(float *dst, float sx, float sy);

// Sets the transform to rotate matrix. Angle is specified in radians.
void MRKUITransformRotate(float *dst, float a);

// Sets the transform to skew-x matrix. Angle is specified in radians.
void MRKUITransformSkewX(float *dst, float a);

// Sets the transform to skew-y matrix. Angle is specified in radians.
void MRKUITransformSkewY(float *dst, float a);

// Sets the transform to the result of multiplication of two transforms, of A = A*B.
void MRKUITransformMultiply(float *dst, const float *src);

// Sets the transform to the result of multiplication of two transforms, of A = B*A.
void MRKUITransformPremultiply(float *dst, const float *src);

// Sets the destination to inverse of specified transform.
// Returns 1 if the inverse could be calculated, else 0.
int MRKUITransformInverse(float *dst, const float *src);

// Transform a point by given transform.
void MRKUITransformPoint(float *dstx, float *dsty, const float *xform, float srcx, float srcy);

// Converts degrees to radians and vice versa.
float MRKUIDegToRad(float deg);

float MRKUIRadToDeg(float rad);

//
// Images
//
// MRKUI allows you to load jpg, png, psd, tga, pic and gif files to be used for rendering.
// In addition you can upload your own image. The image loading is provided by stb_image.
// The parameter imageFlags is combination of flags defined in MRKUIimageFlags.

// Creates image by loading it from the disk from specified file name.
// Returns handle to the image.
int MRKUICreateImage(MRKUIcontext *ctx, const char *filename, int imageFlags);

// Creates image by loading it from the specified chunk of memory.
// Returns handle to the image.
int MRKUICreateImageMem(MRKUIcontext *ctx, int imageFlags, unsigned char *data, int ndata);

// Creates image from specified image data.
// Returns handle to the image.
int
MRKUICreateImageRGBA(MRKUIcontext *ctx, int w, int h, int imageFlags, const unsigned char *data);

// Updates image data specified by image handle.
void MRKUIUpdateImage(MRKUIcontext *ctx, int image, const unsigned char *data);

// Returns the dimensions of a created image.
void MRKUIImageSize(MRKUIcontext *ctx, int image, int *w, int *h);

// Deletes created image.
void MRKUIDeleteImage(MRKUIcontext *ctx, int image);

//
// Paints
//
// MRKUI supports four types of paints: linear gradient, box gradient, radial gradient and image pattern.
// These can be used as paints for strokes and fills.

// Creates and returns a linear gradient. Parameters (sx,sy)-(ex,ey) specify the start and end coordinates
// of the linear gradient, icol specifies the start color and ocol the end color.
// The gradient is transformed by the current transform when it is passed to MRKUIFillPaint() or MRKUIStrokePaint().
MRKUIpaint MRKUILinearGradient(MRKUIcontext *ctx, float sx, float sy, float ex, float ey,
                               MRKUIcolor icol, MRKUIcolor ocol);

// Creates and returns a box gradient. Box gradient is a feathered rounded rectangle, it is useful for rendering
// drop shadows or highlights for boxes. Parameters (x,y) define the top-left corner of the rectangle,
// (w,h) define the size of the rectangle, r defines the corner radius, and f feather. Feather defines how blurry
// the border of the rectangle is. Parameter icol specifies the inner color and ocol the outer color of the gradient.
// The gradient is transformed by the current transform when it is passed to MRKUIFillPaint() or MRKUIStrokePaint().
MRKUIpaint MRKUIBoxGradient(MRKUIcontext *ctx, float x, float y, float w, float h,
                            float r, float f, MRKUIcolor icol, MRKUIcolor ocol);

// Creates and returns a radial gradient. Parameters (cx,cy) specify the center, inr and outr specify
// the inner and outer radius of the gradient, icol specifies the start color and ocol the end color.
// The gradient is transformed by the current transform when it is passed to MRKUIFillPaint() or MRKUIStrokePaint().
MRKUIpaint MRKUIRadialGradient(MRKUIcontext *ctx, float cx, float cy, float inr, float outr,
                               MRKUIcolor icol, MRKUIcolor ocol);

// Creates and returns an image patter. Parameters (ox,oy) specify the left-top location of the image pattern,
// (ex,ey) the size of one image, angle rotation around the top-left corner, image is handle to the image to render.
// The gradient is transformed by the current transform when it is passed to MRKUIFillPaint() or MRKUIStrokePaint().
MRKUIpaint MRKUIImagePattern(MRKUIcontext *ctx, float ox, float oy, float ex, float ey,
                             float angle, int image, float alpha);

//
// Scissoring
//
// Scissoring allows you to clip the rendering into a rectangle. This is useful for various
// user interface cases like rendering a text edit or a timeline.

// Sets the current scissor rectangle.
// The scissor rectangle is transformed by the current transform.
void MRKUIScissor(MRKUIcontext *ctx, float x, float y, float w, float h);

// Intersects current scissor rectangle with the specified rectangle.
// The scissor rectangle is transformed by the current transform.
// Note: in case the rotation of previous scissor rect differs from
// the current one, the intersection will be done between the specified
// rectangle and the previous scissor rectangle transformed in the current
// transform space. The resulting shape is always rectangle.
void MRKUIIntersectScissor(MRKUIcontext *ctx, float x, float y, float w, float h);

// Reset and disables scissoring.
void MRKUIResetScissor(MRKUIcontext *ctx);

//
// Paths
//
// Drawing a new shape starts with MRKUIBeginPath(), it clears all the currently defined paths.
// Then you define one or more paths and sub-paths which describe the shape. The are functions
// to draw common shapes like rectangles and circles, and lower level step-by-step functions,
// which allow to define a path curve by curve.
//
// MRKUI uses even-odd fill rule to draw the shapes. Solid shapes should have counter clockwise
// winding and holes should have counter clockwise order. To specify winding of a path you can
// call MRKUIPathWinding(). This is useful especially for the common shapes, which are drawn CCW.
//
// Finally you can fill the path using current fill style by calling MRKUIFill(), and stroke it
// with current stroke style by calling MRKUIStroke().
//
// The curve segments and sub-paths are transformed by the current transform.

// Clears the current path and sub-paths.
void MRKUIBeginPath(MRKUIcontext *ctx);

// Starts new sub-path with specified point as first point.
void MRKUIMoveTo(MRKUIcontext *ctx, float x, float y);

// Adds line segment from the last point in the path to the specified point.
void MRKUILineTo(MRKUIcontext *ctx, float x, float y);

// Adds cubic bezier segment from last point in the path via two control points to the specified point.
void MRKUIBezierTo(MRKUIcontext *ctx, float c1x, float c1y, float c2x, float c2y, float x, float y);

// Adds quadratic bezier segment from last point in the path via a control point to the specified point.
void MRKUIQuadTo(MRKUIcontext *ctx, float cx, float cy, float x, float y);

// Adds an arc segment at the corner defined by the last path point, and two specified points.
void MRKUIArcTo(MRKUIcontext *ctx, float x1, float y1, float x2, float y2, float radius);

// Closes current sub-path with a line segment.
void MRKUIClosePath(MRKUIcontext *ctx);

// Sets the current sub-path winding, see MRKUIwinding and MRKUIsolidity.
void MRKUIPathWinding(MRKUIcontext *ctx, int dir);

// Creates new circle arc shaped sub-path. The arc center is at cx,cy, the arc radius is r,
// and the arc is drawn from angle a0 to a1, and swept in direction dir (MRKUI_CCW, or MRKUI_CW).
// Angles are specified in radians.
void MRKUIArc(MRKUIcontext *ctx, float cx, float cy, float r, float a0, float a1, int dir);

// Creates new rectangle shaped sub-path.
void MRKUIRect(MRKUIcontext *ctx, float x, float y, float w, float h);

// Creates new rounded rectangle shaped sub-path.
void MRKUIRoundedRect(MRKUIcontext *ctx, float x, float y, float w, float h, float r);

// Creates new rounded rectangle shaped sub-path with varying radii for each corner.
void
MRKUIRoundedRectVarying(MRKUIcontext *ctx, float x, float y, float w, float h, float radTopLeft,
                        float radTopRight, float radBottomRight, float radBottomLeft);

// Creates new ellipse shaped sub-path.
void MRKUIEllipse(MRKUIcontext *ctx, float cx, float cy, float rx, float ry);

// Creates new circle shaped sub-path.
void MRKUICircle(MRKUIcontext *ctx, float cx, float cy, float r);

// Fills the current path with current fill style.
void MRKUIFill(MRKUIcontext *ctx);

// Fills the current path with current stroke style.
void MRKUIStroke(MRKUIcontext *ctx);


//
// Text
//
// MRKUI allows you to load .ttf files and use the font to render text.
//
// The appearance of the text can be defined by setting the current text style
// and by specifying the fill color. Common text and font settings such as
// font size, letter spacing and text align are supported. Font blur allows you
// to create simple text effects such as drop shadows.
//
// At render time the font face can be set based on the font handles or name.
//
// Font measure functions return values in local space, the calculations are
// carried in the same resolution as the final rendering. This is done because
// the text glyph positions are snapped to the nearest pixels sharp rendering.
//
// The local space means that values are not rotated or scale as per the current
// transformation. For example if you set font size to 12, which would mean that
// line height is 16, then regardless of the current scaling and rotation, the
// returned line height is always 16. Some measures may vary because of the scaling
// since aforementioned pixel snapping.
//
// While this may sound a little odd, the setup allows you to always render the
// same way regardless of scaling. I.e. following works regardless of scaling:
//
//		const char* txt = "Text me up.";
//		MRKUITextBounds(vg, x,y, txt, NULL, bounds);
//		MRKUIBeginPath(vg);
//		MRKUIRoundedRect(vg, bounds[0],bounds[1], bounds[2]-bounds[0], bounds[3]-bounds[1]);
//		MRKUIFill(vg);
//
// Note: currently only solid color fill is supported for text.

// Creates font by loading it from the disk from specified file name.
// Returns handle to the font.
int MRKUICreateFont(MRKUIcontext *ctx, const char *name, const char *filename);

// Creates font by loading it from the specified memory chunk.
// Returns handle to the font.
int MRKUICreateFontMem(MRKUIcontext *ctx, const char *name, unsigned char *data, int ndata,
                       int freeData);

// Finds a loaded font of specified name, and returns handle to it, or -1 if the font is not found.
int MRKUIFindFont(MRKUIcontext *ctx, const char *name);

// Adds a fallback font by handle.
int MRKUIAddFallbackFontId(MRKUIcontext *ctx, int baseFont, int fallbackFont);

// Adds a fallback font by name.
int MRKUIAddFallbackFont(MRKUIcontext *ctx, const char *baseFont, const char *fallbackFont);

// Sets the font size of current text style.
void MRKUIFontSize(MRKUIcontext *ctx, float size);

// Sets the blur of current text style.
void MRKUIFontBlur(MRKUIcontext *ctx, float blur);

// Sets the letter spacing of current text style.
void MRKUITextLetterSpacing(MRKUIcontext *ctx, float spacing);

// Sets the proportional line height of current text style. The line height is specified as multiple of font size.
void MRKUITextLineHeight(MRKUIcontext *ctx, float lineHeight);

// Sets the text align of current text style, see MRKUIalign for options.
void MRKUITextAlign(MRKUIcontext *ctx, int align);

// Sets the font face based on specified id of current text style.
void MRKUIFontFaceId(MRKUIcontext *ctx, int font);

// Sets the font face based on specified name of current text style.
void MRKUIFontFace(MRKUIcontext *ctx, const char *font);

// Draws text string at specified location. If end is specified only the sub-string up to the end is drawn.
float MRKUIText(MRKUIcontext *ctx, float x, float y, const char *string, const char *end);

// Draws multi-line text string at specified location wrapped at the specified width. If end is specified only the sub-string up to the end is drawn.
// White space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line characters are encountered.
// Words longer than the max width are slit at nearest character (i.e. no hyphenation).
void MRKUITextBox(MRKUIcontext *ctx, float x, float y, float breakRowWidth, const char *string,
                  const char *end);

// Measures the specified text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Returns the horizontal advance of the measured text (i.e. where the next character should drawn).
// Measured values are returned in local coordinate space.
float MRKUITextBounds(MRKUIcontext *ctx, float x, float y, const char *string, const char *end,
                      float *bounds);

// Measures the specified multi-text string. Parameter bounds should be a pointer to float[4],
// if the bounding box of the text should be returned. The bounds value are [xmin,ymin, xmax,ymax]
// Measured values are returned in local coordinate space.
void
MRKUITextBoxBounds(MRKUIcontext *ctx, float x, float y, float breakRowWidth, const char *string,
                   const char *end, float *bounds);

// Calculates the glyph x positions of the specified text. If end is specified only the sub-string will be used.
// Measured values are returned in local coordinate space.
int
MRKUITextGlyphPositions(MRKUIcontext *ctx, float x, float y, const char *string, const char *end,
                        MRKUIglyphPosition *positions, int maxPositions);

// Returns the vertical metrics based on the current text style.
// Measured values are returned in local coordinate space.
void MRKUITextMetrics(MRKUIcontext *ctx, float *ascender, float *descender, float *lineh);

// Breaks the specified text into lines. If end is specified only the sub-string will be used.
// White space is stripped at the beginning of the rows, the text is split at word boundaries or when new-line characters are encountered.
// Words longer than the max width are slit at nearest character (i.e. no hyphenation).
int MRKUITextBreakLines(MRKUIcontext *ctx, const char *string, const char *end, float breakRowWidth,
                        MRKUItextRow *rows, int maxRows);

//
// Internal Render API
//
enum MRKUItexture {
    MRKUI_TEXTURE_ALPHA = 0x01,
    MRKUI_TEXTURE_RGBA = 0x02,
};

struct MRKUIscissor {
    float xform[6];
    float extent[2];
};
typedef struct MRKUIscissor MRKUIscissor;

struct MRKUIvertex {
    float x, y, u, v;
};
typedef struct MRKUIvertex MRKUIvertex;

struct MRKUIpath {
    int first;
    int count;
    unsigned char closed;
    int nbevel;
    MRKUIvertex *fill;
    int nfill;
    MRKUIvertex *stroke;
    int nstroke;
    int winding;
    int convex;
};
typedef struct MRKUIpath MRKUIpath;

struct MRKUIparams {
    void *userPtr;
    int edgeAntiAlias;

    int (*renderCreate)(void *uptr);

    int (*renderCreateTexture)(void *uptr, int type, int w, int h, int imageFlags,
                               const unsigned char *data);

    int (*renderDeleteTexture)(void *uptr, int image);

    int (*renderUpdateTexture)(void *uptr, int image, int x, int y, int w, int h,
                               const unsigned char *data);

    int (*renderGetTextureSize)(void *uptr, int image, int *w, int *h);

    void (*renderViewport)(void *uptr, float width, float height, float devicePixelRatio);

    void (*renderCancel)(void *uptr);

    void (*renderFlush)(void *uptr);

    void
    (*renderFill)(void *uptr, MRKUIpaint *paint, MRKUIcompositeOperationState compositeOperation,
                  MRKUIscissor *scissor, float fringe, const float *bounds, const MRKUIpath *paths,
                  int npaths);

    void
    (*renderStroke)(void *uptr, MRKUIpaint *paint, MRKUIcompositeOperationState compositeOperation,
                    MRKUIscissor *scissor, float fringe, float strokeWidth, const MRKUIpath *paths,
                    int npaths);

    void (*renderTriangles)(void *uptr, MRKUIpaint *paint,
                            MRKUIcompositeOperationState compositeOperation, MRKUIscissor *scissor,
                            const MRKUIvertex *verts, int nverts);

    void (*renderDelete)(void *uptr);
};

typedef struct MRKUIparams MRKUIparams;

// Constructor and destructor, called by the render back-end.
MRKUIcontext *MRKUICreateInternal(MRKUIparams *params);

void MRKUIDeleteInternal(MRKUIcontext *ctx);

MRKUIparams *MRKUIInternalParams(MRKUIcontext *ctx);

// Debug function to dump cached path data.
void MRKUIDebugDumpPathCache(MRKUIcontext *ctx);

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#define MRKUI_NOTUSED(v) for (;;) { (void)(1 ? (void)0 : ( (void)(v) ) ); break; }

#ifdef __cplusplus
}
#endif

#endif // MRKUI_H
