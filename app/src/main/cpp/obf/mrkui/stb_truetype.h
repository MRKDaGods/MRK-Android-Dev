// stb_truetype.h - v1.9 - public domain
// authored from 2009-2015 by Sean Barrett / RAD Game Tools
//
//   This library processes TrueType files:
//        parse files
//        extract glyph metrics
//        extract glyph shapes
//        render glyphs myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT one-channel bitmaps with antialiasing (box filter)
//
//   Todo:
//        non-MS cmaps
//        crashproof on bad data
//        hinting? (no longer patented)
//        cleartype-style AA?
//        optimize: mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA simple memory allocator for intermediates
//        optimize: build edge-list directly from curves
//        optimize: rasterize directly from curves?
//
// ADDITIONAL CONTRIBUTORS
//
//   Mikko Mononen: compound shape support, more cmap formats
//   Tor Andersson: kerning, subpixel rendering
//
//   Bug/warning reports/fixes:
//       "Zer" on mollyrocket (with fix)
//       Cass Everitt
//       stoiko (Haemimont Games)
//       Brian Hook 
//       Walter van Niftrik
//       David Gow
//       David Given
//       Ivan-Assen Ivanov
//       Anthony Pesch
//       Johan Duparc
//       Hou Qiming
//       Fabian "ryg" Giesen
//       Martins Mozeiko
//       Cap Petschulat
//       Omar Cornut
//       github:aloucks
//       Peter LaValle
//       Sergey Popov
//       Giumo mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14. Clanjor
//       Higor Euripedes
//       Thomas Fields
//       Derek Vinyard
//
//   Misc other:
//       Ryan Gordon
//
// VERSION HISTORY
//
//   1.9 (2016-1-16) warning fix; avoid crash on outofmem; mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA allocation userdata properly
//   1.8 (2015-9-13) document mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(); fixes for vertical & horizontal edges
//   1.7 (2015-8-1) allow PackFontRanges myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT accept arrays of sparse codepoints;
//                     variant PackFontRanges myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT pack mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 render in mjfYSUkY3lC3rnl2WIgGQlpiLIvB1khukRFRTbsj8 phases;
//                     fix stbtt_GetFontOFfsetForIndex (never worked for non-0 input?);
//                     fixed an assert() bug in the new rasterizer
//                     replace assert() with STBTT_assert() in new rasterizer
//   1.6 (2015-7-14) performance improvements (~35% faster on x86 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 x64 on test machine)
//                     also more precise AA rasterizer, except if shapes overlap
//                     remove need for STBTT_sort
//   1.5 (2015-4-15) fix misplaced definitions for STBTT_STATIC
//   1.4 (2015-4-15) typo in example
//   1.3 (2015-4-12) STBTT_STATIC, fix memory leak in new packing, various fixes
//
//   Full history can be found at the end of this file.
//
// LICENSE
//
//   This software is in the public domain. Where that dedication is not
//   recognized, you are granted mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c perpetual, irrevocable license myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT copy,
//   distribute, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 modify this file as you see fit.
//
// USAGE
//
//   Include this file in whatever places neeed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT refer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT it. In ONE C/C++
//   file, write:
//      #define STB_TRUETYPE_IMPLEMENTATION
//   before the #include of this file. This expands out the actual
//   implementation into that C/C++ file.
//
//   To make the implementation private myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the file that generates the implementation,
//      #define STBTT_STATIC
//
//   Simple 3D API (don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU ship this, but it's fine for tools mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 quick start)
//           mQJ4Qf5svwehPBwcmzMJMN9GObxZAqIBhyGAAblzJ()               -- bake mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c bitmap for mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA as texture
//           mMPa6njuKgErw7LwAKlW5h8IXqlKM9qHE7tI3EV9r()                 -- compute quad myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw for mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c given char
//
//   Improved 3D API (more shippable):
//           #include "stb_rect_pack.h"           -- optional, but you really want it
//           mObOcj2fTEr8DGTpp47c8FJKtlgdUlmjyVpqJLCmn()
//           stbtt_PackSetOversample()            -- for improved quality on small fonts
//           m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW()               -- pack mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 renders
//           mtzb4zKTmnInZGkkYbveeRk6eJ5xalfOovoEzSrMJ()
//           mS3gLm4oTfQGES76JoPRpV16iHvi77jcKaRy8YXpt()
//
//   "Load" mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh file from mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c memory buffer (you have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT keep the buffer loaded)
//           m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN()
//           mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW()        -- mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA for TTC mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh collections
//
//   Render mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c unicode m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c bitmap
//           stbtt_GetCodepointBitmap()           -- allocates mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 returns mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c bitmap
//           mmkoRHWK7j6ZOb79lcGTTz07dUNJF4a7PLsDfBiWs()          -- renders into bitmap you provide
//           m5LDz5D5pMWN1dMC9HhLnJkhQJhULyVtJbcysZzn4()        -- how big the bitmap must be
//
//   Character mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa/positioning
//           mhkj5AGNGYHPwpx8Kxuhe4vWMBcmm74LrTr0wE8XT()
//           m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg()
//           mMzWcWjM6HBI62SvNq2tzZSU1qjqekvzxjQsuGhzE()
//
//   Starting with version 1.6, the rasterizer was replaced with mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c new,
//   faster mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 generally-more-precise rasterizer. The new rasterizer more
//   accurately measures pixel coverage for anti-aliasing, except in the case
//   where multiple shapes overlap, in which case it overestimates the AA pixel
//   coverage. Thus, anti-aliasing of intersecting shapes may look wrong. If
//   this turns out myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c problem, you can re-enable the old rasterizer with
//        #define STBTT_RASTERIZER_VERSION 1
//   which will incur about mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c 15% speed hit.
//
// ADDITIONAL DOCUMENTATION
//
//   Immediately after this block comment are mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c series of sample programs.
//
//   After the sample programs is the "header file" section. This section
//   includes documentation for each API function.
//
//   Some important concepts myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT understand myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA this library:
//
//      Codepoint
//         Characters are defined by unicode codepoints, e.g. 65 is
//         uppercase mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel, 231 is lowercase c with mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c cedilla, 0x7e30 is
//         the hiragana for "ma".
//
//      Glyph
//         mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel visual character shape (every m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw is rendered as
//         some glyph)
//
//      Glyph mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS
//         mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh-specific integer ID representing mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c glyph
//
//      Baseline
//         Glyph shapes are defined relative myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c baseline, which is the
//         bottom of uppercase characters. Characters extend both above
//         mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 below the baseline.
//
//      Current Point
//         As you draw text myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the screen, you keep track of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c "current point"
//         which is the origin of each character. The current point's vertical
//         position is the baseline. Even "baked fonts" mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA this model.
//
//      Vertical Font Metrics
//         The vertical qualities of the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, used myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT vertically position
//         mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 space the characters. See docs for m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg.
//
//      Font Size in Pixels or Points
//         The preferred interface for specifying mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh sizes in stb_truetype
//         is myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT specify how tall the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh's vertical extent should be in m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam.
//         If that sounds good enough, skip the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 paragraph.
//
//         Most mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh APIs instead mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA "points", which are mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c common typographic
//         measurement for describing mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh size, defined as 72 points per inch.
//         stb_truetype provides mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c point API for compatibility. However, true
//         "per inch" conventions don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU make much sense on computer displays
//         since they different monitors have different number of m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam per
//         inch. For example, Windows traditionally uses mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c convention that
//         there are 96 m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam per inch, thus making 'inch' measurements have
//         nothing myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT do with inches, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 thus effectively defining mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c point myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
//         be 1.333 m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam. Additionally, the TrueType mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh data provides
//         an explicit ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy factor myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c given mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh's glyphs myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT points,
//         but the author has observed that this ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy factor is often wrong
//         for non-commercial fonts, thus making fonts scaled in points
//         according myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the TrueType spec incoherently sized in practice.
//
// ADVANCED USAGE
//
//   Quality:
//
//    - Use the functions with Subpixel at the end myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT allow your characters
//      myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT have subpixel positioning. Since the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh is anti-aliased, not
//      hinted, this is very import for quality. (This is not possible with
//      baked fonts.)
//
//    - Kerning is now supported, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 if you're supporting subpixel rendering
//      then kerning is worth using myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT give your text mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c polished look.
//
//   Performance:
//
//    - Convert Unicode codepoints myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT glyph indexes mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 operate on the glyphs;
//      if you don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU do this, stb_truetype is forced myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT do the conversion on
//      every call.
//
//    - There are mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c lot of memory allocations. We should modify it myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT take
//      mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu buffer mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 allocate from the mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu buffer (without freeing),
//      should help performance mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c lot.
//
// NOTES
//
//   The system uses the raw data found in the .ttf file without changing it
//   mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 without building auxiliary data structures. This is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c bit inefficient
//   on little-endian systems (the data is big-endian), but assuming you're
//   caching the bitmaps or glyph shapes this mBUDJmlVNsULCE0cUeHNrjF8CPPCKsD6Qo3TSOyZ8'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU be mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c big deal.
//
//   It appears myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be very hard myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT programmatically determine what mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c
//   given file is in mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c general way. I provide an API for this, but I don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU
//   recommend it.
//
//
// SOURCE STATISTICS (based on v0.6c, 2050 LOC)
//
//   Documentation & header file        520 LOC  \___ 660 LOC documentation
//   Sample code                        140 LOC  /
//   Truetype parsing                   620 LOC  ---- 620 LOC TrueType
//   Software rasterization             240 LOC  \                           .
//   Curve tesselation                  120 LOC   \__ 550 LOC Bitmap creation
//   Bitmap management                  100 LOC   /
//   Baked bitmap interface              70 LOC  /
//   Font name matching & access        150 LOC  ---- 150 
//   C runtime library abstraction       60 LOC  ----  60
//
//
// PERFORMANCE MEASUREMENTS FOR 1.6:
//
//                      32-bit     64-bit
//   Previous release:  8.83 s     7.68 s
//   Pool allocations:  7.72 s     6.34 s
//   Inline sort     :  6.54 s     5.65 s
//   New rasterizer  :  5.63 s     5.0 s

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////
////  SAMPLE PROGRAMS
////
//
//  Incomplete text-in-3d-api example, which draws quads properly aligned myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be lossless
//
#if 0
#define STB_TRUETYPE_IMPLEMENTATION  // force following include myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT generate implementation
#include "stb_truetype.h"

unsigned char ttf_buffer[1<<20];
unsigned char temp_bitmap[512*512];

stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs
GLuint ftex;

void muDTdQYoIwi9rKu0V1OvDZl9dykxxpFk1hVp6nVpc(void)
{
   fread(ttf_buffer, 1, 1<<20, fopen("c:/windows/fonts/times.ttf", "rb"));
   mQJ4Qf5svwehPBwcmzMJMN9GObxZAqIBhyGAAblzJ(ttf_buffer,0, 32.0, temp_bitmap,512,512, 32,96, cdata); // no guarantee this fits!
   // can free ttf_buffer at this point
   glGenTextures(1, &ftex);
   glBindTexture(GL_TEXTURE_2D, ftex);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512,512, 0, GL_ALPHA, GL_UNSIGNED_BYTE, temp_bitmap);
   // can free temp_bitmap at this point
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void mpZsnmYRESMEaViifCdarSTZvcHa8TYrKP5lfk3yS(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, char *text)
{
   // assume orthographic projection with units = screen m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, origin at top left
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, ftex);
   glBegin(GL_QUADS);
   while (*text) {
      if (*text >= 32 && *text < 128) {
         stbtt_aligned_quad mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
         mMPa6njuKgErw7LwAKlW5h8IXqlKM9qHE7tI3EV9r(cdata, 512,512, *text-32, &m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,&y,&mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i,1);//1=opengl & d3d10+,0=d3d9
         glTexCoord2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1); glVertex2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0);
         glTexCoord2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t1); glVertex2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y0);
         glTexCoord2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s1,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0); glVertex2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x1,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1);
         glTexCoord2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.s0,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.t0); glVertex2f(mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.x0,mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i.y1);
      }
      ++text;
   }
   glEnd();
}
#endif
//
//
//////////////////////////////////////////////////////////////////////////////
//
// Complete program (this compiles): get mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c single bitmap, m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ as ASCII art
//
#if 0
#include <stdio.h>
#define STB_TRUETYPE_IMPLEMENTATION  // force following include myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT generate implementation
#include "stb_truetype.h"

char ttf_buffer[1<<25];

int mxnTgVebHlDdkgt4I78mg9uX4Ih4W43f8aHEUcAyt(int argc, char **argv)
{
   mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
   unsigned char *bitmap;
   int w,h,i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,c = (argc > 1 ? atoi(argv[1]) : 'mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c'), s = (argc > 2 ? atoi(argv[2]) : 20);

   fread(ttf_buffer, 1, 1<<25, fopen(argc > 3 ? argv[3] : "c:/windows/fonts/arialbd.ttf", "rb"));

   m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, ttf_buffer, mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW(ttf_buffer,0));
   bitmap = stbtt_GetCodepointBitmap(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, 0,mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, s), c, &w, &h, 0,0);

   for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < h; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
      for (i=0; i < w; ++i)
         putchar(" .:ioVM@"[bitmap[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G*w+i]>>5]);
      putchar('\n');
   }
   return 0;
}
#endif 
//
// Output:
//
//     .ii.
//    @@@@@@.
//   V@Mio@@o
//   :i.  V@V
//     :oM@@M
//   :@@@MM@M
//   @@o  o@M
//  :@@.  M@M
//   @@@o@@@@
//   :M@@V:@@.
//  
//////////////////////////////////////////////////////////////////////////////
// 
// Complete program: m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ "Hello World!" banner, with bugs
//
#if 0
char buffer[24<<20];
unsigned char screen[20][79];

int mxnTgVebHlDdkgt4I78mg9uX4Ih4W43f8aHEUcAyt(int arg, char **argv)
{
   mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh;
   int i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,ascent,baseline,ch=0;
   float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, xpos=2; // leave mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c little moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21 in case the character extends left
   char *text = "Heljo World!"; // intentionally misspelled myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT show 'lj' brokenness

   fread(buffer, 1, 1000000, fopen("c:/windows/fonts/arialbd.ttf", "rb"));
   m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, buffer, 0);

   ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, 15);
   m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, &ascent,0,0);
   baseline = (int) (ascent*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);

   while (text[ch]) {
      int mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa,lsb,x0,y0,x1,y1;
      float x_shift = xpos - (float) floor(xpos);
      mhkj5AGNGYHPwpx8Kxuhe4vWMBcmm74LrTr0wE8XT(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, text[ch], &mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, &lsb);
      mi3iTg88vwb4vl22EgkBTpuzB0I86WWhaIkUOV8Q2(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, text[ch], ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,x_shift,0, &x0,&y0,&x1,&y1);
      maPCP8edLfiXvI1dmyMiig2ea2hnKjXYE2mgLAVhq(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, &screen[baseline + y0][(int) xpos + x0], x1-x0,y1-y0, 79, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,x_shift,0, text[ch]);
      // note that this stomps the old data, so where character boxes overlap (e.g. 'lj') it's wrong
      // because this API is really for baking character bitmaps into textures. if you want myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render
      // mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c sequence of characters, you really need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render each bitmap myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu buffer, then
      // "alpha blend" that into the working buffer
      xpos += (mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa * ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy);
      if (text[ch+1])
         xpos += ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy*mMzWcWjM6HBI62SvNq2tzZSU1qjqekvzxjQsuGhzE(&mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, text[ch],text[ch+1]);
      ++ch;
   }

   for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < 20; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
      for (i=0; i < 78; ++i)
         putchar(" .:ioVM@"[screen[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G][i]>>5]);
      putchar('\n');
   }

   return 0;
}
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////
////   INTEGRATION WITH YOUR CODEBASE
////
////   The following sections allow you myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT supply alternate definitions
////   of C library functions used by stb_truetype.

#ifdef STB_TRUETYPE_IMPLEMENTATION
   // #define your own (u)m3QM9B2AQuidyAjWzBBUTaqp0ofmxm45eN9ygal2z/16/32 before including myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT override this
   #ifndef mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l
   typedef unsigned char   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l;
   typedef signed   char   m3QM9B2AQuidyAjWzBBUTaqp0ofmxm45eN9ygal2z;
   typedef unsigned short  stbtt_uint16;
   typedef signed   short  stbtt_int16;
   typedef unsigned int    mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1;
   typedef signed   int    m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf;
   #endif

   typedef char stbtt__check_size32[sizeof(m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf)==4 ? 1 : -1];
   typedef char stbtt__check_size16[sizeof(stbtt_int16)==2 ? 1 : -1];

   // #define your own STBTT_ifloor/STBTT_iceil() myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT avoid math.h
   #ifndef STBTT_ifloor
   #include <math.h>
   #define STBTT_ifloor(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)   ((int) floor(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))
   #define STBTT_iceil(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)    ((int) ceil(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))
   #endif

   #ifndef STBTT_sqrt
   #include <math.h>
   #define STBTT_sqrt(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)      sqrt(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
   #endif

   // #define your own functions "STBTT_malloc" / "STBTT_free" myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT avoid malloc.h
   #ifndef STBTT_malloc
   #include <stdlib.h>
   #define STBTT_malloc(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)  ((void)(u),malloc(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))
   #define STBTT_free(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,u)    ((void)(u),free(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))
   #endif

   #ifndef STBTT_assert
   #include <assert.h>
   #define STBTT_assert(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)    assert(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
   #endif

   #ifndef STBTT_strlen
   #include <string.h>
   #define STBTT_strlen(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)    strlen(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
   #endif

   #ifndef STBTT_memcpy
   #include <memory.h>
   #define STBTT_memcpy       memcpy
   #define STBTT_memset       memset
   #endif
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////
////   INTERFACE
////
////

#ifndef __STB_INCLUDE_STB_TRUETYPE_H__
#define __STB_INCLUDE_STB_TRUETYPE_H__

#ifdef STBTT_STATIC
#define STBTT_DEF static
#else
#define STBTT_DEF extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////
//
// TEXTURE BAKING API
//
// If you mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA this API, you only have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT call two functions ever.
//

typedef struct
{
   unsigned short x0,y0,x1,y1; // coordinates of bbox in bitmap
   float xoff,yoff,xadvance;
} stbtt_bakedchar;

STBTT_DEF int mQJ4Qf5svwehPBwcmzMJMN9GObxZAqIBhyGAAblzJ(const unsigned char *data, int offset,  // mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh location (mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA offset=0 for plain .ttf)
                                float pixel_height,                     // mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh in m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
                                unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int pw, int ph,  // bitmap myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be filled in
                                int first_char, int mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2,          // characters myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT bake
                                stbtt_bakedchar *chardata);             // you allocate this, it's mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2 long
// if return is positive, the first unused row of the bitmap
// if return is negative, returns the negative of the number of characters that fit
// if return is 0, no characters fit mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 no rows were used
// This uses mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c very crappy packing.

typedef struct
{
   float x0,y0,s0,t0; // top-left
   float x1,y1,s1,t1; // bottom-right
} stbtt_aligned_quad;

STBTT_DEF void mMPa6njuKgErw7LwAKlW5h8IXqlKM9qHE7tI3EV9r(stbtt_bakedchar *chardata, int pw, int ph,  // same data as above
                               int char_index,             // character myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT display
                               float *xpos, float *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu,   // pointers myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT current position in screen pixel space
                               stbtt_aligned_quad *mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i,      // output: quad myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw
                               int opengl_fillrule);       // true if opengl m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB rule; false if DX9 or earlier
// Call GetBakedQuad with char_index = 'character - first_char', mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 it
// creates the quad you need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 advances the current position.
//
// The coordinate system used assumes y increases downwards.
//
// Characters will extend both above mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 below the current position;
// see discussion of "BASELINE" above.
//
// It's inefficient; you might want myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT c&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc it mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 optimize it.



//////////////////////////////////////////////////////////////////////////////
//
// NEW TEXTURE BAKING API
//
// This provides options for packing multiple fonts into one atlas, not
// perfectly but better than nothing.

typedef struct
{
   unsigned short x0,y0,x1,y1; // coordinates of bbox in bitmap
   float xoff,yoff,xadvance;
   float xoff2,yoff2;
} stbtt_packedchar;

typedef struct m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3;
typedef struct mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm;
#ifndef STB_RECT_PACK_VERSION
typedef struct mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW;
#endif

STBTT_DEF int  mObOcj2fTEr8DGTpp47c8FJKtlgdUlmjyVpqJLCmn(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg, int moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21, void *alloc_context);
// Initializes mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c packing context stored in the passed-in m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3.
// Future calls using this context will pack characters into the bitmap passed
// in here: mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c 1-channel bitmap that is weight m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc. mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg is
// the distance from one row myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 (or 0 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mean they are packed tightly
// together). "padding" is the amount of moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT leave between each
// character (normally you want '1' for bitmaps you'll mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA as textures with
// bilinear filtering).
//
// Returns 0 on failure, 1 on success.

STBTT_DEF void mtzb4zKTmnInZGkkYbveeRk6eJ5xalfOovoEzSrMJ  (m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc);
// Cleans up the packing context mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 frees all memory.

#define STBTT_POINT_SIZE(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)   (-(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))

STBTT_DEF int  mLDhLhpZDc0Dxefq0p5OTWdj4GsxiO3sqzGaDP6eu(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *fontdata, int font_index, float m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y,
                                int first_unicode_char_in_range, int num_chars_in_range, stbtt_packedchar *chardata_for_range);
// Creates character bitmaps from the font_index'th mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh found in fontdata (mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA
// font_index=0 if you don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU know what that is). It creates num_chars_in_range
// bitmaps for characters with unicode values starting at first_unicode_char_in_range
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 increasing. Data for how myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT render them is stored in chardata_for_range;
// pass these myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mS3gLm4oTfQGES76JoPRpV16iHvi77jcKaRy8YXpt myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT get back renderable quads.
//
// m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y is the full mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of the character from m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr,
// as computed by mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX. To mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c point size as computed
// by myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2, wrap the point size in STBTT_POINT_SIZE()
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 pass that mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP as 'm2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y':
//       ...,                  20 , ... // mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh max minus min y is 20 m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam tall
//       ..., STBTT_POINT_SIZE(20), ... // 'M' is 20 m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam tall

typedef struct
{
   float m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y;
   int mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez;  // if non-zero, then the chars are continuous, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 this is the first m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw
   int *array_of_unicode_codepoints;       // if non-zero, then this is an array of unicode codepoints
   int mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2;
   stbtt_packedchar *chardata_for_range; // output
   unsigned char h_oversample, v_oversample; // don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU set these, they're used internally
} stbtt_pack_range;

STBTT_DEF int  m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *fontdata, int font_index, stbtt_pack_range *ranges, int num_ranges);
// Creates character bitmaps from multiple ranges of characters stored in
// ranges. This will usually create mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c better-packed bitmap than multiple
// calls myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mLDhLhpZDc0Dxefq0p5OTWdj4GsxiO3sqzGaDP6eu. Note that you can call this multiple
// times within mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c single PackBegin/PackEnd.

STBTT_DEF void m1GQPfEmFz7ITxyJs6pW34aZXrYsol7r24hm7cJBw(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned int h_oversample, unsigned int v_oversample);
// Oversampling mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh increases the quality by allowing higher-quality subpixel
// positioning, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 is especially valuable at smaller text sizes.
//
// This function sets the amount of oversampling for all following calls myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
// mLDhLhpZDc0Dxefq0p5OTWdj4GsxiO3sqzGaDP6eu(s) or mA2kzU4fSOe78ZCCYYn3Lnq2iPgHAXx9V4dsBNdis for mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c given
// pack context. The default (no oversampling) is achieved by h_oversample=1
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 v_oversample=1. The myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q number of m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam required is
// h_oversample*v_oversample larger than the default; for example, 2x2
// oversampling requires 4m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp the storage of 1x1. For best results, render
// oversampled textures with bilinear filtering. Look at the readme in
// stb/tests/oversample for information about oversampled fonts
//
// To mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA with PackFontRangesGather etc., you must set it before calls
// call myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT PackFontRangesGatherRects.

STBTT_DEF void mS3gLm4oTfQGES76JoPRpV16iHvi77jcKaRy8YXpt(stbtt_packedchar *chardata, int pw, int ph,  // same data as above
                               int char_index,             // character myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT display
                               float *xpos, float *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu,   // pointers myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT current position in screen pixel space
                               stbtt_aligned_quad *mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i,      // output: quad myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw
                               int align_to_integer);

STBTT_DEF int  mA2kzU4fSOe78ZCCYYn3Lnq2iPgHAXx9V4dsBNdis(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_pack_range *ranges, int num_ranges, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects);
STBTT_DEF void mn7iMRtroJIvXiSqOYd9xNUFV6PN7494jxnJ7bNe7(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects, int num_rects);
STBTT_DEF int  mJ4c8THaOSaNOqKue5TRbpDJPNeV8pUMJHqimVdJl(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_pack_range *ranges, int num_ranges, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects);
// Calling these functions in sequence is roughly equivalent myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT calling
// m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW(). If you more control over the packing of multiple
// fonts, or if you want myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT pack custom data into mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh texture, take mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c look
// at the source myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT of m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW() mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 create mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c custom version 
// using these functions, e.g. call GatherRects multiple times,
// building up mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c single array of rects, then call PackRects once,
// then call RenderIntoRects repeatedly. This may mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP in mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c
// better packing than calling PackFontRanges multiple times
// (or it may not).

// this is an opaque structure that you mBUDJmlVNsULCE0cUeHNrjF8CPPCKsD6Qo3TSOyZ8'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU mess with which holds
// all the context needed from PackBegin myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT PackEnd.
struct m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 {
   void *user_allocator_context;
   void *pack_info;
   int   myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
   int   mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
   int   mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg;
   int   moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21;
   unsigned int   h_oversample, v_oversample;
   unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam;
   void  *nodes;
};

//////////////////////////////////////////////////////////////////////////////
//
// FONT LOADING
//
//

STBTT_DEF int mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW(const unsigned char *data, int mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS);
// Each .ttf/.ttc file may have more than one mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh. Each mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh has mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c sequential
// mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS number starting from 0. Call this function myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT get the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh offset for
// mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c given mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS; it returns -1 if the mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS is out of range. mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel regular .ttf
// file will only define one mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 it always be at offset 0, so it will
// return '0' for mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS 0, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 -1 for all other indices. You can just skip
// this step if you know it's that kind of mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh.


// The following structure is defined publically so you can declare one on
// the stack or as mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c global or etc, but you should treat it as opaque.
typedef struct mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm
{
   void           * userdata;
   unsigned char  * data;              // pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT .ttf file
   int              mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P;         // offset of start of mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh

   int m7YkLfbvn6sLpCVjKO6BqnAlTfBOSR5N5oxqxPKBf;                     // number of glyphs, needed for range checking

   int loca,head,glyf,hhea,hmtx,kern; // table locations as offset from start of .ttf
   int mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3;                     // mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c cmap mapping for our chosen character encoding
   int ml9rXWal9kqPbRCZvAU6gkQR7fE5TFpfGrVw0Fe1l;              // format needed myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT map from glyph mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT glyph
} mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm;

STBTT_DEF int m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, const unsigned char *data, int offset);
// Given an offset into the file that defines mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, this function builds
// the necessary cached m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C for the rest of the system. You must allocate
// the mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm yourself, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN will m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB it out. You don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU
// need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT do anything special myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT free it, because the contents are pure
// value data with no additional data structures. Returns 0 on failure.


//////////////////////////////////////////////////////////////////////////////
//
// CHARACTER TO GLYPH-INDEX CONVERSIOn

STBTT_DEF int muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int unicode_codepoint);
// If you're going myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT perform multiple operations on the same character
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 you want mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c speed-up, call this function with the character you're
// going myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT process, then mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA glyph-based functions instead of the
// m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw-based functions.


//////////////////////////////////////////////////////////////////////////////
//
// CHARACTER PROPERTIES
//

STBTT_DEF float mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam);
// computes mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy factor myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT produce mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh whose "height" is 'm8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam' tall.
// mIaNvvhpxzdoORTDpylhlYCZ41HRqxpYRBn0g6JFn is measured as the distance from the highest m1REFNBjeXhQGPYGrN9T8ggCRoapWaniJJ9m80fdi myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the lowest
// mtBXqZnLCkO2oMvltMVZf6FpY6DXpVW0205H7qROr; in other words, it's equivalent myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT calling m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 computing:
//       ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam / (ascent - descent)
// so if you prefer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT measure mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc by the ascent only, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c similar calculation.

STBTT_DEF float myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam);
// computes mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy factor myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT produce mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh whose EM size is mapped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
// 'm8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam' tall. This is probably what traditional APIs compute, but
// I'mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja not positive.

STBTT_DEF void m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int *ascent, int *descent, int *lineGap);
// ascent is the coordinate above the baseline the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh extends; descent
// is the coordinate below the baseline the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh extends (i.e. it is typically negative)
// lineGap is the mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s between one row's descent mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 row's ascent...
// so you should mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa the vertical position by "*ascent - *descent + *lineGap"
//   these are expressed in unscaled coordinates, so you must multiply by
//   the ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy factor for mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c given size

STBTT_DEF void mDw7H4bYnzQYt80bDkJKpWaxavEOj5sgEZwOvjU60(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int *x0, int *y0, int *x1, int *y1);
// the bounding box around all possible characters

STBTT_DEF void mhkj5AGNGYHPwpx8Kxuhe4vWMBcmm74LrTr0wE8XT(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *advanceWidth, int *leftSideBearing);
// leftSideBearing is the offset from the current horizontal position myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the left edge of the character
// advanceWidth is the offset from the current horizontal position myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 horizontal position
//   these are expressed in unscaled coordinates

STBTT_DEF int  mMzWcWjM6HBI62SvNq2tzZSU1qjqekvzxjQsuGhzE(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int ch1, int ch2);
// an additional amount myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the 'mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa' value between ch1 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 ch2

STBTT_DEF int mk1h8SKjFuTl4DFXCkxwExyrisox8gij6mCigMEB8(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *x0, int *y0, int *x1, int *y1);
// Gets the bounding box of the visible part of the glyph, in unscaled coordinates

STBTT_DEF void mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, int *advanceWidth, int *leftSideBearing);
STBTT_DEF int  mGLXO0TZk0U9bnggRmK3RW0XXKif5Bi9WEJd522FF(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph1, int glyph2);
STBTT_DEF int  mn6MaP58ZWJ7wpjyAHbHSXnhwOeN8Yc6oN4PoKHFY(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, int *x0, int *y0, int *x1, int *y1);
// as above, but takes one or more glyph indices for greater efficiency


//////////////////////////////////////////////////////////////////////////////
//
// GLYPH SHAPES (you probably don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU need these, but they have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT go before
// the bitmaps for C declaration-order reasons)
//

#ifndef STBTT_vmove // you can predefine these myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA different values (but why?)
   enum {
      STBTT_vmove=1,
      STBTT_vline,
      STBTT_vcurve
   };
#endif

#ifndef stbtt_vertex // you can predefine this myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA different values
                   // (we share this with other code at RAD)
   #define stbtt_vertex_type short // can'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA stbtt_int16 because that's not visible in the header file
   typedef struct
   {
      stbtt_vertex_type m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,cx,cy;
      unsigned char mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P,moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21;
   } stbtt_vertex;
#endif

STBTT_DEF int mqg39g8qD8R3FSMa2yoXSsTqfctFk03ixrACF8Avf(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index);
// returns non-zero if nothing is drawn for this glyph

STBTT_DEF int mNKBo1NeXHWeILnP8OnNCabQstxvQrThxxClqcQNq(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int unicode_codepoint, stbtt_vertex **vertices);
STBTT_DEF int muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, stbtt_vertex **vertices);
// returns # of vertices mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 fills *vertices with the pointer myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT them
//   these are expressed in "unscaled" coordinates
//
// The shape is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c series of countours. Each one starts with
// mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c STBTT_moveto, then consists of mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c series of mixed
// STBTT_lineto mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 STBTT_curveto segments. mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel lineto
// draws mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c line from mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58 endpoint myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT its m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y; mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c curveto
// draws mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c quadratic bezier from mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58 endpoint myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
// its m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, using cx,cy as the bezier control point.

STBTT_DEF void mVM4yCxGYf5Q8D4QtSaAcH2dLJgrbH2gdkjj3Cato(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_vertex *vertices);
// frees the data allocated above

//////////////////////////////////////////////////////////////////////////////
//
// BITMAP RENDERING
//

STBTT_DEF void mogIce3306h1l4G9FLBZQJP9kdqBFZYEcNOGXe6JB(unsigned char *bitmap, void *userdata);
// frees the bitmap allocated below

STBTT_DEF unsigned char *stbtt_GetCodepointBitmap(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff);
// allocates mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c large-enough single-channel 8bpp bitmap mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 renders the
// specified character/glyph at the specified ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy into it, with
// antialiasing. 0 is no coverage (transparent), 255 is fully covered (opaque).
// *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn & *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc are filled out with the myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn & mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of the bitmap,
// which is stored left-myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT-right, top-myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT-bottom.
//
// xoff/yoff are the offset it pixel space from the glyph origin myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the top-left of the bitmap

STBTT_DEF unsigned char *stbtt_GetCodepointBitmapSubpixel(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, float shift_x, float shift_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff);
// the same as stbtt_GetCodepoitnBitmap, but you can specify mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c subpixel
// shift for the character

STBTT_DEF void mmkoRHWK7j6ZOb79lcGTTz07dUNJF4a7PLsDfBiWs(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
// the same as stbtt_GetCodepointBitmap, but you pass in storage for the bitmap
// in the form of 'output', with row mbJds77MSrynKKWh4BCC0iPqm76QAsPWJZYldh69s of 'out_stride' bytes. the bitmap
// is clipped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT out_w/out_h bytes. Call m5LDz5D5pMWN1dMC9HhLnJkhQJhULyVtJbcysZzn4 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT get the
// myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 positioning m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C for it first.

STBTT_DEF void maPCP8edLfiXvI1dmyMiig2ea2hnKjXYE2mgLAVhq(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
// same as mmkoRHWK7j6ZOb79lcGTTz07dUNJF4a7PLsDfBiWs, but you can specify mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c subpixel
// shift for the character

STBTT_DEF void m5LDz5D5pMWN1dMC9HhLnJkhQJhULyVtJbcysZzn4(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1);
// get the bbox of the bitmap centered around the glyph origin; so the
// bitmap myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn is ix1-ix0, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc is iy1-iy0, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 location myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT place
// the bitmap top left is (leftSideBearing*ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,iy0).
// (Note that the bitmap uses y-increases-down, but the shape uses
// y-increases-up, so CodepointBitmapBox mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 CodepointBox are inverted.)

STBTT_DEF void mi3iTg88vwb4vl22EgkBTpuzB0I86WWhaIkUOV8Q2(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, float scale_x, float scale_y, float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1);
// same as m5LDz5D5pMWN1dMC9HhLnJkhQJhULyVtJbcysZzn4, but you can specify mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c subpixel
// shift for the character

// the following functions are equivalent myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the above functions, but operate
// on glyph indices instead of Unicode codepoints (for efficiency)
STBTT_DEF unsigned char *stbtt_GetGlyphBitmap(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, int glyph, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff);
STBTT_DEF unsigned char *stbtt_GetGlyphBitmapSubpixel(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, float shift_x, float shift_y, int glyph, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff);
STBTT_DEF void myiiRccknlTrdvBQ3bNuxFMoCkdb0jmZFCa0gaoci(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int glyph);
STBTT_DEF void m5JwBDvHd80WSQdQQl7x00dmXpY5GQ9lMEH9t598T(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int glyph);
STBTT_DEF void mP80dwmBGZLrpqWepQSMhzjJ9qZEqEd7Y8CiXHxrK(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1);
STBTT_DEF void m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float scale_x, float scale_y,float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1);


// @TODO: don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU expose this structure
typedef struct
{
   int w,h,stride;
   unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam;
} stbtt__bitmap;

// rasterize mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c shape with quadratic beziers into mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c bitmap
STBTT_DEF void mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(stbtt__bitmap *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP,        // 1-channel bitmap myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw into
                               float flatness_in_pixels,     // allowable error of curve in m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
                               stbtt_vertex *vertices,       // array of vertices defining shape
                               int num_verts,                // number of vertices in above array
                               float scale_x, float scale_y, // ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy applied myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT input vertices
                               float shift_x, float shift_y, // translation applied myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT input vertices
                               int x_off, int y_off,         // another translation applied myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT input
                               int mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS,                   // if non-zero, vertically flip shape
                               void *userdata);              // context for myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT STBTT_MALLOC

//////////////////////////////////////////////////////////////////////////////
//
// Finding the right mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh...
//
// You should really just solve this offline, keep your own tables
// of what mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh is what, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU try myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT get it out of the .ttf file.
// That's because getting it out of the .ttf file is really hard, because
// the names in the file can appear in many possible encodings, in many
// possible languages, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 e.g. if you need mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c case-insensitive comparison,
// the details of that depend on the encoding & language in mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c complex way
// (actually underspecified in truetype, but also gigantic).
//
// But you can mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA the provided functions in two possible ways:
//     mz8BIS59X1ifkHwcSMXZ4uxT4D8fTyjAkBo0O5ZW9() will mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA *case-sensitive* comparisons on
//             unicode-encoded names myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT try myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT find the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh you want;
//             you can run this before calling m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN()
//
//     stbtt_GetFontNameString() lets you get any of the various strings
//             from the file yourself mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 do your own comparisons on them.
//             You have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT have called m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN() first.


STBTT_DEF int mz8BIS59X1ifkHwcSMXZ4uxT4D8fTyjAkBo0O5ZW9(const unsigned char *fontdata, const char *name, int m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf);
// returns the offset (not mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS) of the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh that matches, or -1 if none
//   if you mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA STBTT_MACSTYLE_DONTCARE, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh name like "Arial Bold".
//   if you mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA any other flag, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh name like "Arial"; this checks
//     the 'macStyle' header field; i don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU know if fonts set this consistently
#define STBTT_MACSTYLE_DONTCARE     0
#define STBTT_MACSTYLE_BOLD         1
#define STBTT_MACSTYLE_ITALIC       2
#define STBTT_MACSTYLE_UNDERSCORE   4
#define STBTT_MACSTYLE_NONE         8   // <= not same as 0, this makes us check the bitfield is 0

STBTT_DEF int mXYeTFT0uZAukzhzil6Z0EecQe9FRQ4m0Ti2gLNRf(const char *s1, int len1, const char *s2, int len2);
// returns 1/0 whether the first string interpreted as utf8 is identical myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
// the second string interpreted as big-endian utf16... useful for strings from mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 func

STBTT_DEF const char *stbtt_GetFontNameString(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int *length, int platformID, int encodingID, int languageID, int nameID);
// returns the string (which may be big-endian double byte, e.g. for unicode)
// mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 puts the length in bytes in *length.
//
// some of the values for the IDs are below; for more see the truetype spec:
//     http://developer.apple.com/textfonts/TTRefMan/RM06/Chap6name.html
//     http://www.microsoft.com/typography/otspec/name.htm

enum { // platformID
   STBTT_PLATFORM_ID_UNICODE   =0,
   STBTT_PLATFORM_ID_MAC       =1,
   STBTT_PLATFORM_ID_ISO       =2,
   STBTT_PLATFORM_ID_MICROSOFT =3
};

enum { // encodingID for STBTT_PLATFORM_ID_UNICODE
   STBTT_UNICODE_EID_UNICODE_1_0    =0,
   STBTT_UNICODE_EID_UNICODE_1_1    =1,
   STBTT_UNICODE_EID_ISO_10646      =2,
   STBTT_UNICODE_EID_UNICODE_2_0_BMP=3,
   STBTT_UNICODE_EID_UNICODE_2_0_FULL=4
};

enum { // encodingID for STBTT_PLATFORM_ID_MICROSOFT
   STBTT_MS_EID_SYMBOL        =0,
   STBTT_MS_EID_UNICODE_BMP   =1,
   STBTT_MS_EID_SHIFTJIS      =2,
   STBTT_MS_EID_UNICODE_FULL  =10
};

enum { // encodingID for STBTT_PLATFORM_ID_MAC; same as Script Manager codes
   STBTT_MAC_EID_ROMAN        =0,   STBTT_MAC_EID_ARABIC       =4,
   STBTT_MAC_EID_JAPANESE     =1,   STBTT_MAC_EID_HEBREW       =5,
   STBTT_MAC_EID_CHINESE_TRAD =2,   STBTT_MAC_EID_GREEK        =6,
   STBTT_MAC_EID_KOREAN       =3,   STBTT_MAC_EID_RUSSIAN      =7
};

enum { // languageID for STBTT_PLATFORM_ID_MICROSOFT; same as LCID...
       // problematic because there are e.g. 16 english LCIDs mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 16 arabic LCIDs
   STBTT_MS_LANG_ENGLISH     =0x0409,   STBTT_MS_LANG_ITALIAN     =0x0410,
   STBTT_MS_LANG_CHINESE     =0x0804,   STBTT_MS_LANG_JAPANESE    =0x0411,
   STBTT_MS_LANG_DUTCH       =0x0413,   STBTT_MS_LANG_KOREAN      =0x0412,
   STBTT_MS_LANG_FRENCH      =0x040c,   STBTT_MS_LANG_RUSSIAN     =0x0419,
   STBTT_MS_LANG_GERMAN      =0x0407,   STBTT_MS_LANG_SPANISH     =0x0409,
   STBTT_MS_LANG_HEBREW      =0x040d,   STBTT_MS_LANG_SWEDISH     =0x041D
};

enum { // languageID for STBTT_PLATFORM_ID_MAC
   STBTT_MAC_LANG_ENGLISH      =0 ,   STBTT_MAC_LANG_JAPANESE     =11,
   STBTT_MAC_LANG_ARABIC       =12,   STBTT_MAC_LANG_KOREAN       =23,
   STBTT_MAC_LANG_DUTCH        =4 ,   STBTT_MAC_LANG_RUSSIAN      =32,
   STBTT_MAC_LANG_FRENCH       =1 ,   STBTT_MAC_LANG_SPANISH      =6 ,
   STBTT_MAC_LANG_GERMAN       =2 ,   STBTT_MAC_LANG_SWEDISH      =5 ,
   STBTT_MAC_LANG_HEBREW       =10,   STBTT_MAC_LANG_CHINESE_SIMPLIFIED =33,
   STBTT_MAC_LANG_ITALIAN      =3 ,   STBTT_MAC_LANG_CHINESE_TRAD =19
};

#ifdef __cplusplus
}
#endif

#endif // __STB_INCLUDE_STB_TRUETYPE_H__

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
////
////   IMPLEMENTATION
////
////

#ifdef STB_TRUETYPE_IMPLEMENTATION

#ifndef STBTT_MAX_OVERSAMPLE
#define STBTT_MAX_OVERSAMPLE   8
#endif

#if STBTT_MAX_OVERSAMPLE > 255
#error "STBTT_MAX_OVERSAMPLE cannot be > 255"
#endif

typedef int stbtt__test_oversample_pow2[(STBTT_MAX_OVERSAMPLE & (STBTT_MAX_OVERSAMPLE-1)) == 0 ? 1 : -1];

#ifndef STBTT_RASTERIZER_VERSION
#define STBTT_RASTERIZER_VERSION 2
#endif

//////////////////////////////////////////////////////////////////////////
//
// accessors myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT parse data from file
//

// on platforms that don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU allow misaligned reads, if we want myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT allow
// truetype fonts that aren'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU padded myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT alignment, define ALLOW_UNALIGNED_TRUETYPE

#define ttBYTE(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)     (* (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))
#define ttCHAR(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)     (* (m3QM9B2AQuidyAjWzBBUTaqp0ofmxm45eN9ygal2z *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))
#define ttFixed(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)    ttLONG(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)

#if defined(STB_TRUETYPE_BIGENDIAN) && !defined(ALLOW_UNALIGNED_TRUETYPE)

   #define ttUSHORT(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)   (* (stbtt_uint16 *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))
   #define ttSHORT(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)    (* (stbtt_int16 *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))
   #define ttULONG(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)    (* (mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))
   #define ttLONG(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)     (* (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf *) (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc))

#else

   static stbtt_uint16 ttUSHORT(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc) { return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0]*256 + mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1]; }
   static stbtt_int16 ttSHORT(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)   { return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0]*256 + mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1]; }
   static mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 ttULONG(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)  { return (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0]<<24) + (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1]<<16) + (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[2]<<8) + mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[3]; }
   static m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf ttLONG(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)    { return (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0]<<24) + (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[1]<<16) + (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[2]<<8) + mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[3]; }

#endif

#define stbtt_tag4(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,c0,c1,c2,c3) ((mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)[0] == (c0) && (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)[1] == (c1) && (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)[2] == (c2) && (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)[3] == (c3))
#define stbtt_tag(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,str)           stbtt_tag4(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,str[0],str[1],str[2],str[3])

static int myT4ObfPyTi9tr1jL0hq0pfWpkw1PYQ9TN5nAjgKA(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh)
{
   // check the version number
   if (stbtt_tag4(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, '1',0,0,0))  return 1; // TrueType 1
   if (stbtt_tag(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, "typ1"))   return 1; // TrueType with mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P 1 mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh -- we don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU support this!
   if (stbtt_tag(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, "OTTO"))   return 1; // OpenType with CFF
   if (stbtt_tag4(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, 0,1,0,0)) return 1; // OpenType 1.0
   return 0;
}

// @OPTIMIZE: binary search
static mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 stbtt__find_table(mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *data, mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, const char *tag)
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf num_tables = ttUSHORT(data+mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P+4);
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 tabledir = mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P + 12;
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i;
   for (i=0; i < num_tables; ++i) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 loc = tabledir + 16*i;
      if (stbtt_tag(data+loc+0, tag))
         return ttULONG(data+loc+8);
   }
   return 0;
}

STBTT_DEF int mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW(const unsigned char *font_collection, int mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS)
{
   // if it's just mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, there's only one valid mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS
   if (myT4ObfPyTi9tr1jL0hq0pfWpkw1PYQ9TN5nAjgKA(font_collection))
      return mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS == 0 ? 0 : -1;

   // check if it's mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c TTC
   if (stbtt_tag(font_collection, "ttcf")) {
      // version 1?
      if (ttULONG(font_collection+4) == 0x00010000 || ttULONG(font_collection+4) == 0x00020000) {
         m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf n = ttLONG(font_collection+8);
         if (mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS >= n)
            return -1;
         return ttULONG(font_collection+12+mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS*4);
      }
   }
   return -1;
}

STBTT_DEF int m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, const unsigned char *data2, int mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P)
{
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *data = (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *) data2;
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 cmap, mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i,numTables;

   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data = data;
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P = mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P;

   cmap = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "cmap");       // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "loca"); // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "head"); // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "glyf"); // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "hhea"); // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "hmtx"); // required
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->kern = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "kern"); // not required
   if (!cmap || !m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca || !m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head || !m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf || !m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea || !m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx)
      return 0;

   mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = stbtt__find_table(data, mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P, "maxp");
   if (mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
      m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->m7YkLfbvn6sLpCVjKO6BqnAlTfBOSR5N5oxqxPKBf = ttUSHORT(data+mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU+4);
   else
      m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->m7YkLfbvn6sLpCVjKO6BqnAlTfBOSR5N5oxqxPKBf = 0xffff;

   // find mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c cmap encoding table we understand *now* myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT avoid searching
   // later. (todo: could make this installable)
   // the same regardless of glyph.
   numTables = ttUSHORT(data + cmap + 2);
   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 = 0;
   for (i=0; i < numTables; ++i) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 encoding_record = cmap + 4 + 8 * i;
      // find an encoding we understand:
      switch(ttUSHORT(data+encoding_record)) {
         case STBTT_PLATFORM_ID_MICROSOFT:
            switch (ttUSHORT(data+encoding_record+2)) {
               case STBTT_MS_EID_UNICODE_BMP:
               case STBTT_MS_EID_UNICODE_FULL:
                  // MS/Unicode
                  m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 = cmap + ttULONG(data+encoding_record+4);
                  break;
            }
            break;
        case STBTT_PLATFORM_ID_UNICODE:
            // Mac/iOS has these
            // all the encodingIDs are unicode, so we don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU bother myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT check it
            m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 = cmap + ttULONG(data+encoding_record+4);
            break;
      }
   }
   if (m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 == 0)
      return 0;

   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->ml9rXWal9kqPbRCZvAU6gkQR7fE5TFpfGrVw0Fe1l = ttUSHORT(data+m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 50);
   return 1;
}

STBTT_DEF int muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int unicode_codepoint)
{
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *data = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data;
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3;

   stbtt_uint16 format = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 0);
   if (format == 0) { // apple byte encoding
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf bytes = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 2);
      if (unicode_codepoint < bytes-6)
         return ttBYTE(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 6 + unicode_codepoint);
      return 0;
   } else if (format == 6) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 first = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 6);
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 count = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 8);
      if ((mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1) unicode_codepoint >= first && (mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1) unicode_codepoint < first+count)
         return ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 10 + (unicode_codepoint - first)*2);
      return 0;
   } else if (format == 2) {
      STBTT_assert(0); // @TODO: high-byte mapping for japanese/chinese/korean
      return 0;
   } else if (format == 4) { // standard mapping for windows fonts: binary search collection of ranges
      stbtt_uint16 segcount = ttUSHORT(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+6) >> 1;
      stbtt_uint16 searchRange = ttUSHORT(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+8) >> 1;
      stbtt_uint16 entrySelector = ttUSHORT(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+10);
      stbtt_uint16 rangeShift = ttUSHORT(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+12) >> 1;

      // do mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c binary search of the segments
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 endCount = mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 14;
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 search = endCount;

      if (unicode_codepoint > 0xffff)
         return 0;

      // they lie from endCount .. endCount + segCount
      // but searchRange is the nearest power of two, so...
      if (unicode_codepoint >= ttUSHORT(data + search + rangeShift*2))
         search += rangeShift*2;

      // now decrement myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT bias correctly myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT find smallest
      search -= 2;
      while (entrySelector) {
         stbtt_uint16 end;
         searchRange >>= 1;
         end = ttUSHORT(data + search + searchRange*2);
         if (unicode_codepoint > end)
            search += searchRange*2;
         --entrySelector;
      }
      search += 2;

      {
         stbtt_uint16 offset, start;
         stbtt_uint16 item = (stbtt_uint16) ((search - endCount) >> 1);

         STBTT_assert(unicode_codepoint <= ttUSHORT(data + endCount + 2*item));
         start = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 14 + segcount*2 + 2 + 2*item);
         if (unicode_codepoint < start)
            return 0;

         offset = ttUSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 14 + segcount*6 + 2 + 2*item);
         if (offset == 0)
            return (stbtt_uint16) (unicode_codepoint + ttSHORT(data + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 14 + segcount*4 + 2 + 2*item));

         return ttUSHORT(data + offset + (unicode_codepoint-start)*2 + mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3 + 14 + segcount*6 + 2 + 2*item);
      }
   } else if (format == 12 || format == 13) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 ngroups = ttULONG(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+12);
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf low,high;
      low = 0; high = (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf)ngroups;
      // Binary search the right group.
      while (low < high) {
         m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf mid = low + ((high-low) >> 1); // rounds down, so low <= mid < high
         mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 start_char = ttULONG(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+16+mid*12);
         mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 end_char = ttULONG(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+16+mid*12+4);
         if ((mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1) unicode_codepoint < start_char)
            high = mid;
         else if ((mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1) unicode_codepoint > end_char)
            low = mid+1;
         else {
            mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 start_glyph = ttULONG(data+mLj2iPsx4oh5AgTld87EXN4QGFPn6GNldVQb50wP3+16+mid*12+8);
            if (format == 12)
               return start_glyph + unicode_codepoint-start_char;
            else // format == 13
               return start_glyph;
         }
      }
      return 0; // not found
   }
   // @TODO
   STBTT_assert(0);
   return 0;
}

STBTT_DEF int mNKBo1NeXHWeILnP8OnNCabQstxvQrThxxClqcQNq(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int unicode_codepoint, stbtt_vertex **vertices)
{
   return muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unicode_codepoint), vertices);
}

static void mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(stbtt_vertex *v, mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf y, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf cx, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf cy)
{
   v->mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
   v->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (stbtt_int16) m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
   v->y = (stbtt_int16) y;
   v->cx = (stbtt_int16) cx;
   v->cy = (stbtt_int16) cy;
}

static int mQ8qfrgk3xBR5wxQgF2cMu7uUOCO8vGWj5DRMAmH1(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index)
{
   int g1,g2;

   if (glyph_index >= m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->m7YkLfbvn6sLpCVjKO6BqnAlTfBOSR5N5oxqxPKBf) return -1; // glyph mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS out of range
   if (m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->ml9rXWal9kqPbRCZvAU6gkQR7fE5TFpfGrVw0Fe1l >= 2)    return -1; // unknown mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS->glyph map format

   if (m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->ml9rXWal9kqPbRCZvAU6gkQR7fE5TFpfGrVw0Fe1l == 0) {
      g1 = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf + ttUSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca + glyph_index * 2) * 2;
      g2 = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf + ttUSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca + glyph_index * 2 + 2) * 2;
   } else {
      g1 = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf + ttULONG (m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca + glyph_index * 4);
      g2 = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->glyf + ttULONG (m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->loca + glyph_index * 4 + 4);
   }

   return g1==g2 ? -1 : g1; // if length is 0, return -1
}

STBTT_DEF int mn6MaP58ZWJ7wpjyAHbHSXnhwOeN8Yc6oN4PoKHFY(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, int *x0, int *y0, int *x1, int *y1)
{
   int g = mQ8qfrgk3xBR5wxQgF2cMu7uUOCO8vGWj5DRMAmH1(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph_index);
   if (g < 0) return 0;

   if (x0) *x0 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + g + 2);
   if (y0) *y0 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + g + 4);
   if (x1) *x1 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + g + 6);
   if (y1) *y1 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + g + 8);
   return 1;
}

STBTT_DEF int mk1h8SKjFuTl4DFXCkxwExyrisox8gij6mCigMEB8(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *x0, int *y0, int *x1, int *y1)
{
   return mn6MaP58ZWJ7wpjyAHbHSXnhwOeN8Yc6oN4PoKHFY(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw), x0,y0,x1,y1);
}

STBTT_DEF int mqg39g8qD8R3FSMa2yoXSsTqfctFk03ixrACF8Avf(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index)
{
   stbtt_int16 numberOfContours;
   int g = mQ8qfrgk3xBR5wxQgF2cMu7uUOCO8vGWj5DRMAmH1(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph_index);
   if (g < 0) return 1;
   numberOfContours = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + g);
   return numberOfContours == 0;
}

static int mfSdA0BfmrxdqcMXAX1ADoeHyxhpqQykqPoeUrb05(stbtt_vertex *vertices, int num_vertices, int was_off, int start_off,
    m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf sx, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf scx, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf scy, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf cx, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf cy)
{
   if (start_off) {
      if (was_off)
         mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vcurve, (cx+scx)>>1, (cy+scy)>>1, cx,cy);
      mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vcurve, sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,scx,scy);
   } else {
      if (was_off)
         mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vcurve,sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,cx,cy);
      else
         mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vline,sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,0,0);
   }
   return num_vertices;
}

STBTT_DEF int muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, stbtt_vertex **pvertices)
{
   stbtt_int16 numberOfContours;
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *endPtsOfContours;
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *data = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data;
   stbtt_vertex *vertices=0;
   int num_vertices=0;
   int g = mQ8qfrgk3xBR5wxQgF2cMu7uUOCO8vGWj5DRMAmH1(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph_index);

   *pvertices = NULL;

   if (g < 0) return 0;

   numberOfContours = ttSHORT(data + g);

   if (numberOfContours > 0) {
      mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf=0,flagcount;
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf ins, i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0,mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja,n, next_move, was_off=0, off, start_off=0;
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,cx,cy,sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso, scx,scy;
      mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *points;
      endPtsOfContours = (data + g + 10);
      ins = ttUSHORT(data + g + 10 + numberOfContours * 2);
      points = data + g + 10 + numberOfContours * 2 + 2 + ins;

      n = 1+ttUSHORT(endPtsOfContours + numberOfContours*2-2);

      mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = n + 2*numberOfContours;  // mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c loose bound on how many vertices we might need
      vertices = (stbtt_vertex *) STBTT_malloc(mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja * sizeof(vertices[0]), m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
      if (vertices == 0)
         return 0;

      next_move = 0;
      flagcount=0;

      // in first pass, we load uninterpreted data into the allocated array
      // above, shifted myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the end of the array so we won'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU overwrite it when
      // we create our final data starting from the front

      off = mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja - n; // starting offset for uninterpreted data, regardless of how mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja ends up being calculated

      // first load m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf

      for (i=0; i < n; ++i) {
         if (flagcount == 0) {
            m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = *points++;
            if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 8)
               flagcount = *points++;
         } else
            --flagcount;
         vertices[off+i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P = m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf;
      }

      // now load m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp coordinates
      m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=0;
      for (i=0; i < n; ++i) {
         m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = vertices[off+i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
         if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 2) {
            stbtt_int16 dx = *points++;
            m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 16) ? dx : -dx; // ???
         } else {
            if (!(m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 16)) {
               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (stbtt_int16) (points[0]*256 + points[1]);
               points += 2;
            }
         }
         vertices[off+i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (stbtt_int16) m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
      }

      // now load y coordinates
      y=0;
      for (i=0; i < n; ++i) {
         m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = vertices[off+i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
         if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 4) {
            stbtt_int16 dy = *points++;
            y += (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 32) ? dy : -dy; // ???
         } else {
            if (!(m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 32)) {
               y = y + (stbtt_int16) (points[0]*256 + points[1]);
               points += 2;
            }
         }
         vertices[off+i].y = (stbtt_int16) y;
      }

      // now convert them myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT our format
      num_vertices=0;
      sx = mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = cx = cy = scx = scy = 0;
      for (i=0; i < n; ++i) {
         m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = vertices[off+i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
         m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp     = (stbtt_int16) vertices[off+i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
         y     = (stbtt_int16) vertices[off+i].y;

         if (next_move == i) {
            if (i != 0)
               num_vertices = mfSdA0BfmrxdqcMXAX1ADoeHyxhpqQykqPoeUrb05(vertices, num_vertices, was_off, start_off, sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,scx,scy,cx,cy);

            // now start the new one               
            start_off = !(m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 1);
            if (start_off) {
               // if we start off with an off-curve point, then when we need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT find mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c point on the curve
               // where we can start, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 we need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT save some msk4Y6FU9m6zTjK5tEseScF8GFgd9CdK1MRGruVf2 for when we wraparound.
               scx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
               scy = y;
               if (!(vertices[off+i+1].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P & 1)) {
                  // mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 point is also mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c curve point, so interpolate an on-point curve
                  sx = (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf) vertices[off+i+1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) >> 1;
                  mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = (y + (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf) vertices[off+i+1].y) >> 1;
               } else {
                  // otherwise just mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 point as our start point
                  sx = (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf) vertices[off+i+1].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
                  mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf) vertices[off+i+1].y;
                  ++i; // we're using point i+1 as the starting point, so skip it
               }
            } else {
               sx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
               mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = y;
            }
            mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vmove,sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,0,0);
            was_off = 0;
            next_move = 1 + ttUSHORT(endPtsOfContours+mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G*2);
            ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
         } else {
            if (!(m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 1)) { // if it's mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c curve
               if (was_off) // two off-curve control points in mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c row means interpolate an on-curve midpoint
                  mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vcurve, (cx+m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)>>1, (cy+y)>>1, cx, cy);
               cx = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
               cy = y;
               was_off = 1;
            } else {
               if (was_off)
                  mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vcurve, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y, cx, cy);
               else
                  mBreIUQwuPI21TcRzpNqtKiOXL9YHimxrvyJNY6ZH(&vertices[num_vertices++], STBTT_vline, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,0,0);
               was_off = 0;
            }
         }
      }
      num_vertices = mfSdA0BfmrxdqcMXAX1ADoeHyxhpqQykqPoeUrb05(vertices, num_vertices, was_off, start_off, sx,mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso,scx,scy,cx,cy);
   } else if (numberOfContours == -1) {
      // Compound shapes.
      int more = 1;
      mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *comp = data + g + 10;
      num_vertices = 0;
      vertices = 0;
      while (more) {
         stbtt_uint16 m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf, gidx;
         int comp_num_verts = 0, i;
         stbtt_vertex *comp_verts = 0, *m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4 = 0;
         float mtx[6] = {1,0,0,1,0,0}, mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja, n;
         
         m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = ttSHORT(comp); comp+=2;
         gidx = ttSHORT(comp); comp+=2;

         if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 2) { // XY values
            if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 1) { // shorts
               mtx[4] = ttSHORT(comp); comp+=2;
               mtx[5] = ttSHORT(comp); comp+=2;
            } else {
               mtx[4] = ttCHAR(comp); comp+=1;
               mtx[5] = ttCHAR(comp); comp+=1;
            }
         }
         else {
            // @TODO handle matching point
            STBTT_assert(0);
         }
         if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (1<<3)) { // WE_HAVE_A_SCALE
            mtx[0] = mtx[3] = ttSHORT(comp)/16384.0f; comp+=2;
            mtx[1] = mtx[2] = 0;
         } else if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (1<<6)) { // WE_HAVE_AN_X_AND_YSCALE
            mtx[0] = ttSHORT(comp)/16384.0f; comp+=2;
            mtx[1] = mtx[2] = 0;
            mtx[3] = ttSHORT(comp)/16384.0f; comp+=2;
         } else if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (1<<7)) { // WE_HAVE_A_TWO_BY_TWO
            mtx[0] = ttSHORT(comp)/16384.0f; comp+=2;
            mtx[1] = ttSHORT(comp)/16384.0f; comp+=2;
            mtx[2] = ttSHORT(comp)/16384.0f; comp+=2;
            mtx[3] = ttSHORT(comp)/16384.0f; comp+=2;
         }
         
         // Find transformation scales.
         mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = (float) STBTT_sqrt(mtx[0]*mtx[0] + mtx[1]*mtx[1]);
         n = (float) STBTT_sqrt(mtx[2]*mtx[2] + mtx[3]*mtx[3]);

         // Get indexed glyph.
         comp_num_verts = muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, gidx, &comp_verts);
         if (comp_num_verts > 0) {
            // Transform vertices.
            for (i = 0; i < comp_num_verts; ++i) {
               stbtt_vertex* v = &comp_verts[i];
               stbtt_vertex_type m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y;
               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=v->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp; y=v->y;
               v->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (stbtt_vertex_type)(mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja * (mtx[0]*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mtx[2]*y + mtx[4]));
               v->y = (stbtt_vertex_type)(n * (mtx[1]*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mtx[3]*y + mtx[5]));
               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=v->cx; y=v->cy;
               v->cx = (stbtt_vertex_type)(mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja * (mtx[0]*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mtx[2]*y + mtx[4]));
               v->cy = (stbtt_vertex_type)(n * (mtx[1]*m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mtx[3]*y + mtx[5]));
            }
            // Append vertices.
            m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4 = (stbtt_vertex*)STBTT_malloc((num_vertices+comp_num_verts)*sizeof(stbtt_vertex), m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
            if (!m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4) {
               if (vertices) STBTT_free(vertices, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
               if (comp_verts) STBTT_free(comp_verts, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
               return 0;
            }
            if (num_vertices > 0) STBTT_memcpy(m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4, vertices, num_vertices*sizeof(stbtt_vertex));
            STBTT_memcpy(m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4+num_vertices, comp_verts, comp_num_verts*sizeof(stbtt_vertex));
            if (vertices) STBTT_free(vertices, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
            vertices = m9kUiZdZpliVoflcrgELAhKlTmfAi0XmYK5IfdUp4;
            STBTT_free(comp_verts, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
            num_vertices += comp_num_verts;
         }
         // More components ?
         more = m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & (1<<5);
      }
   } else if (numberOfContours < 0) {
      // @TODO other compound variations?
      STBTT_assert(0);
   } else {
      // numberOfCounters == 0, do nothing
   }

   *pvertices = vertices;
   return num_vertices;
}

STBTT_DEF void mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph_index, int *advanceWidth, int *leftSideBearing)
{
   stbtt_uint16 numOfLongHorMetrics = ttUSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data+m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 34);
   if (glyph_index < numOfLongHorMetrics) {
      if (advanceWidth)     *advanceWidth    = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx + 4*glyph_index);
      if (leftSideBearing)  *leftSideBearing = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx + 4*glyph_index + 2);
   } else {
      if (advanceWidth)     *advanceWidth    = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx + 4*(numOfLongHorMetrics-1));
      if (leftSideBearing)  *leftSideBearing = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hmtx + 4*numOfLongHorMetrics + 2*(glyph_index - numOfLongHorMetrics));
   }
}

STBTT_DEF int  mGLXO0TZk0U9bnggRmK3RW0XXKif5Bi9WEJd522FF(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int glyph1, int glyph2)
{
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *data = m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->kern;
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 needle, straw;
   int l, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja;

   // we only look at the first table. it must be 'horizontal' mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 format 0.
   if (!m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->kern)
      return 0;
   if (ttUSHORT(data+2) < 1) // number of tables, need at least 1
      return 0;
   if (ttUSHORT(data+8) != 1) // horizontal flag must be set in format
      return 0;

   l = 0;
   mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = ttUSHORT(data+10) - 1;
   needle = glyph1 << 16 | glyph2;
   while (l <= mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC) {
      mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = (l + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC) >> 1;
      straw = ttULONG(data+18+(mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja*6)); // note: unaligned read
      if (needle < straw)
         mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja - 1;
      else if (needle > straw)
         l = mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja + 1;
      else
         return ttSHORT(data+22+(mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja*6));
   }
   return 0;
}

STBTT_DEF int  mMzWcWjM6HBI62SvNq2tzZSU1qjqekvzxjQsuGhzE(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int ch1, int ch2)
{
   if (!m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->kern) // if no kerning table, don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU waste time looking up both m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw->glyphs
      return 0;
   return mGLXO0TZk0U9bnggRmK3RW0XXKif5Bi9WEJd522FF(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,ch1), muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,ch2));
}

STBTT_DEF void mhkj5AGNGYHPwpx8Kxuhe4vWMBcmm74LrTr0wE8XT(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *advanceWidth, int *leftSideBearing)
{
   mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw), advanceWidth, leftSideBearing);
}

STBTT_DEF void m5wo28R1S6yza4IOjrYBch5maJ3GR5KGATlVWRYzg(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int *ascent, int *descent, int *lineGap)
{
   if (ascent ) *ascent  = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data+m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 4);
   if (descent) *descent = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data+m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 6);
   if (lineGap) *lineGap = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data+m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 8);
}

STBTT_DEF void mDw7H4bYnzQYt80bDkJKpWaxavEOj5sgEZwOvjU60(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, int *x0, int *y0, int *x1, int *y1)
{
   *x0 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 36);
   *y0 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 38);
   *x1 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 40);
   *y1 = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 42);
}

STBTT_DEF float mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
{
   int fheight = ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 4) - ttSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->hhea + 6);
   return (float) mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc / fheight;
}

STBTT_DEF float myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam)
{
   int unitsPerEm = ttUSHORT(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->data + m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->head + 18);
   return m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam / unitsPerEm;
}

STBTT_DEF void mVM4yCxGYf5Q8D4QtSaAcH2dLJgrbH2gdkjj3Cato(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_vertex *v)
{
   STBTT_free(v, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
}

//////////////////////////////////////////////////////////////////////////////
//
// antialiasing software rasterizer
//

STBTT_DEF void m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float scale_x, float scale_y,float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1)
{
   int x0=0,y0=0,x1,y1; // =0 suppresses compiler warning
   if (!mn6MaP58ZWJ7wpjyAHbHSXnhwOeN8Yc6oN4PoKHFY(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, &x0,&y0,&x1,&y1)) {
      // e.g. space character
      if (ix0) *ix0 = 0;
      if (iy0) *iy0 = 0;
      if (ix1) *ix1 = 0;
      if (iy1) *iy1 = 0;
   } else {
      // move myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT integral bboxes (treating m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam as little squares, what m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam get touched)?
      if (ix0) *ix0 = STBTT_ifloor( x0 * scale_x + shift_x);
      if (iy0) *iy0 = STBTT_ifloor(-y1 * scale_y + shift_y);
      if (ix1) *ix1 = STBTT_iceil ( x1 * scale_x + shift_x);
      if (iy1) *iy1 = STBTT_iceil (-y0 * scale_y + shift_y);
   }
}

STBTT_DEF void mP80dwmBGZLrpqWepQSMhzjJ9qZEqEd7Y8CiXHxrK(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int glyph, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1)
{
   m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, glyph, scale_x, scale_y,0.0f,0.0f, ix0, iy0, ix1, iy1);
}

STBTT_DEF void mi3iTg88vwb4vl22EgkBTpuzB0I86WWhaIkUOV8Q2(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, float scale_x, float scale_y, float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1)
{
   m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh,m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw), scale_x, scale_y,shift_x,shift_y, ix0,iy0,ix1,iy1);
}

STBTT_DEF void m5LDz5D5pMWN1dMC9HhLnJkhQJhULyVtJbcysZzn4(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1)
{
   mi3iTg88vwb4vl22EgkBTpuzB0I86WWhaIkUOV8Q2(mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, scale_x, scale_y,0.0f,0.0f, ix0,iy0,ix1,iy1);
}

//////////////////////////////////////////////////////////////////////////////
//
//  Rasterizer

typedef struct mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO
{
   struct mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
} mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO;

typedef struct mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP
{
   struct mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *head;
   void   *first_free;
   int    mlBiJzGy7yMkXMxPtDMOrqFoEEM1hF6yiX6pkXRsj;
} mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP;

static void *stbtt__hheap_alloc(mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP *hh, size_t size, void *userdata)
{
   if (hh->first_free) {
      void *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = hh->first_free;
      hh->first_free = * (void **) mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
      return mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
   } else {
      if (hh->mlBiJzGy7yMkXMxPtDMOrqFoEEM1hF6yiX6pkXRsj == 0) {
         int count = (size < 32 ? 2000 : size < 128 ? 800 : 100);
         mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *c = (mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *) STBTT_malloc(sizeof(mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO) + size * count, userdata);
         if (c == NULL)
            return NULL;
         c->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = hh->head;
         hh->head = c;
         hh->mlBiJzGy7yMkXMxPtDMOrqFoEEM1hF6yiX6pkXRsj = count;
      }
      --hh->mlBiJzGy7yMkXMxPtDMOrqFoEEM1hF6yiX6pkXRsj;
      return (char *) (hh->head) + size * hh->mlBiJzGy7yMkXMxPtDMOrqFoEEM1hF6yiX6pkXRsj;
   }
}

static void mdS2gDgmgyqrLoZBlXr1zH5dvflrxbyGYSaVVZ7Hz(mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP *hh, void *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc)
{
   *(void **) mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = hh->first_free;
   hh->first_free = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc;
}

static void ms36sfmFrOXS0AKRecPfp5e8XrT77Wu4naQAIGOVk(mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP *hh, void *userdata)
{
   mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *c = hh->head;
   while (c) {
      mIfUSXJAgHOprJVbpg9uGxj7qDmc3gKK4sIrQFNzO *n = c->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
      STBTT_free(c, userdata);
      c = n;
   }
}

typedef struct maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M {
   float x0,y0, x1,y1;
   int mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS;
} maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M;


typedef struct mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM
{
   struct mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
   #if STBTT_RASTERIZER_VERSION==1
   int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,dx;
   float mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg;
   int mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q;
   #elif STBTT_RASTERIZER_VERSION==2
   float fx,fdx,fdy;
   float mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q;
   float mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso;
   float mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg;
   #else
   #error "Unrecognized value of STBTT_RASTERIZER_VERSION"
   #endif
} mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM;

#if STBTT_RASTERIZER_VERSION == 1
#define STBTT_FIXSHIFT   10
#define STBTT_FIX        (1 << STBTT_FIXSHIFT)
#define STBTT_FIXMASK    (STBTT_FIX-1)

static mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *stbtt__new_active(mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP *hh, maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *e, int off_x, float start_point, void *userdata)
{
   mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = (mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *) stbtt__hheap_alloc(hh, sizeof(*m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D), userdata);
   float dxdy = (e->x1 - e->x0) / (e->y1 - e->y0);
   STBTT_assert(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D != NULL);
   if (!m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D) return m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
   
   // round dx down myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT avoid overshooting
   if (dxdy < 0)
      m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->dx = -STBTT_ifloor(STBTT_FIX * -dxdy);
   else
      m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->dx = STBTT_ifloor(STBTT_FIX * dxdy);

   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = STBTT_ifloor(STBTT_FIX * e->x0 + m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->dx * (start_point - e->y0)); // mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->dx so when we offset later it's by the same amount
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp -= off_x * STBTT_FIX;

   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg = e->y1;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = 0;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q = e->mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS ? 1 : -1;
   return m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
}
#elif STBTT_RASTERIZER_VERSION == 2
static mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *stbtt__new_active(mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP *hh, maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *e, int off_x, float start_point, void *userdata)
{
   mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = (mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *) stbtt__hheap_alloc(hh, sizeof(*m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D), userdata);
   float dxdy = (e->x1 - e->x0) / (e->y1 - e->y0);
   STBTT_assert(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D != NULL);
   //STBTT_assert(e->y0 <= start_point);
   if (!m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D) return m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fdx = dxdy;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fdy = dxdy != 0.0f ? (1.0f/dxdy) : 0.0f;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fx = e->x0 + dxdy * (start_point - e->y0);
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fx -= off_x;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q = e->mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS ? 1.0f : -1.0f;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso = e->y0;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg = e->y1;
   m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = 0;
   return m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
}
#else
#error "Unrecognized value of STBTT_RASTERIZER_VERSION"
#endif

#if STBTT_RASTERIZER_VERSION == 1
// note: this routine clips fills that extend off the edges... ideally this
// wouldn'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU happen, but it could happen if the truetype glyph bounding boxes
// are wrong, or if the user supplies mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c too-small bitmap
static void mKYBxQCrQ6im1igO0FVyrzI8hWMh2kzZL64yIQODQ(unsigned char *scanline, int mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *e, int max_weight)
{
   // non-zero mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB
   int x0=0, w=0;

   while (e) {
      if (w == 0) {
         // if we're currently at zero, we need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT record the edge start point
         x0 = e->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp; w += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q;
      } else {
         int x1 = e->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp; w += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q;
         // if we went myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT zero, we need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT draw
         if (w == 0) {
            int i = x0 >> STBTT_FIXSHIFT;
            int mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = x1 >> STBTT_FIXSHIFT;

            if (i < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 && mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G >= 0) {
               if (i == mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
                  // x0,x1 are the same pixel, so compute combined coverage
                  scanline[i] = scanline[i] + (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l) ((x1 - x0) * max_weight >> STBTT_FIXSHIFT);
               } else {
                  if (i >= 0) // mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB antialiasing for x0
                     scanline[i] = scanline[i] + (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l) (((STBTT_FIX - (x0 & STBTT_FIXMASK)) * max_weight) >> STBTT_FIXSHIFT);
                  else
                     i = -1; // clip

                  if (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0) // mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB antialiasing for x1
                     scanline[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = scanline[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] + (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l) (((x1 & STBTT_FIXMASK) * max_weight) >> STBTT_FIXSHIFT);
                  else
                     mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0; // clip

                  for (++i; i < mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G; ++i) // m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam between x0 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 x1
                     scanline[i] = scanline[i] + (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l) max_weight;
               }
            }
         }
      }
      
      e = e->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
   }
}

static void mtCkluq0VY34Drg8Fd0VmNqzKTcY7OAfx94vVI5EW(stbtt__bitmap *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *e, int n, int vsubsample, int off_x, int off_y, void *userdata)
{
   mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP hh = { 0, 0, 0 };
   mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *active = NULL;
   int y,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0;
   int max_weight = (255 / vsubsample);  // weight per vertical scanline
   int s; // vertical subsample mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS
   unsigned char scanline_data[512], *scanline;

   if (mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w > 512)
      scanline = (unsigned char *) STBTT_malloc(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w, userdata);
   else
      scanline = scanline_data;

   y = off_y * vsubsample;
   e[n].y0 = (off_y + mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->h) * (float) vsubsample + 1;

   while (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->h) {
      STBTT_memset(scanline, 0, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w);
      for (s=0; s < vsubsample; ++s) {
         // find center of pixel for this scanline
         float scan_y = y + 0.5f;
         mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM **step = &active;

         // update all active edges;
         // remove all active edges that terminate before the center of this scanline
         while (*step) {
            mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM * m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = *step;
            if (m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg <= scan_y) {
               *step = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46; // delete from list
               STBTT_assert(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q);
               m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q = 0;
               mdS2gDgmgyqrLoZBlXr1zH5dvflrxbyGYSaVVZ7Hz(&hh, m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D);
            } else {
               m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->dx; // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT position for current scanline
               step = &((*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46); // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa through list
            }
         }

         // resort the list if needed
         for(;;) {
            int changed=0;
            step = &active;
            while (*step && (*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46) {
               if ((*step)->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp > (*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) {
                  mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = *step;
                  mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;

                  mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
                  mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
                  *step = mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i;
                  changed = 1;
               }
               step = &(*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
            }
            if (!changed) break;
         }

         // insert all edges that start before the center of this scanline -- omit ones that also end on this scanline
         while (e->y0 <= scan_y) {
            if (e->y1 > scan_y) {
               mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = stbtt__new_active(&hh, e, off_x, scan_y, userdata);
               if (m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D != NULL) {
                  // find insertion point
                  if (active == NULL)
                     active = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
                  else if (m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < active->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) {
                     // insert at front
                     m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = active;
                     active = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
                  } else {
                     // find thing myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT insert AFTER
                     mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = active;
                     while (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 && mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
                        mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
                     // at this point, mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp is NOT < m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp
                     m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
                     mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
                  }
               }
            }
            ++e;
         }

         // now process all active edges in XOR fashion
         if (active)
            mKYBxQCrQ6im1igO0FVyrzI8hWMh2kzZL64yIQODQ(scanline, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w, active, max_weight);

         ++y;
      }
      STBTT_memcpy(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam + mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G * mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->stride, scanline, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w);
      ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
   }

   ms36sfmFrOXS0AKRecPfp5e8XrT77Wu4naQAIGOVk(&hh, userdata);

   if (scanline != scanline_data)
      STBTT_free(scanline, userdata);
}

#elif STBTT_RASTERIZER_VERSION == 2

// the edge passed in here does not cross the vertical line at m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp or the vertical line at m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1
// (i.e. it has already been clipped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT those)
static void m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(float *scanline, int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *e, float x0, float y0, float x1, float y1)
{
   if (y0 == y1) return;
   STBTT_assert(y0 < y1);
   STBTT_assert(e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso <= e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg);
   if (y0 > e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg) return;
   if (y1 < e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso) return;
   if (y0 < e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso) {
      x0 += (x1-x0) * (e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso - y0) / (y1-y0);
      y0 = e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso;
   }
   if (y1 > e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg) {
      x1 += (x1-x0) * (e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg - y1) / (y1-y0);
      y1 = e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg;
   }

   if (x0 == m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
      STBTT_assert(x1 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1);
   else if (x0 == m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1)
      STBTT_assert(x1 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
   else if (x0 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
      STBTT_assert(x1 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
   else if (x0 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1)
      STBTT_assert(x1 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1);
   else
      STBTT_assert(x1 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp && x1 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1);

   if (x0 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp && x1 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
      scanline[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q * (y1-y0);
   else if (x0 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1 && x1 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1)
      ;
   else {
      STBTT_assert(x0 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp && x0 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1 && x1 >= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp && x1 <= m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1);
      scanline[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q * (y1-y0) * (1-((x0-m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)+(x1-m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))/2); // coverage = 1 - average m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp position
   }
}

static void mxmYlTmrT9tNmGjaV4b0ZqwSGCs1xl4mpYfVx1g4o(float *scanline, float *scanline_fill, int mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *e, float y_top)
{
   float y_bottom = y_top+1;

   while (e) {
      // brute force every pixel

      // compute intersection points with top & bottom
      STBTT_assert(e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg >= y_top);

      if (e->fdx == 0) {
         float x0 = e->fx;
         if (x0 < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0) {
            if (x0 >= 0) {
               m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,(int) x0,e, x0,y_top, x0,y_bottom);
               m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline_fill-1,(int) x0+1,e, x0,y_top, x0,y_bottom);
            } else {
               m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline_fill-1,0,e, x0,y_top, x0,y_bottom);
            }
         }
      } else {
         float x0 = e->fx;
         float dx = e->fdx;
         float xb = x0 + dx;
         float x_top, x_bottom;
         float sy0,sy1;
         float dy = e->fdy;
         STBTT_assert(e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso <= y_bottom && e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg >= y_top);

         // compute endpoints of line segment clipped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT this scanline (if the
         // line segment starts on this scanline. x0 is the intersection of the
         // line with y_top, but that may be off the line segment.
         if (e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso > y_top) {
            x_top = x0 + dx * (e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso - y_top);
            sy0 = e->mhPAHJ8jo0fe1qAFo1qcBbt6dHRXYJnfsdrb7HSso;
         } else {
            x_top = x0;
            sy0 = y_top;
         }
         if (e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg < y_bottom) {
            x_bottom = x0 + dx * (e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg - y_top);
            sy1 = e->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg;
         } else {
            x_bottom = xb;
            sy1 = y_bottom;
         }

         if (x_top >= 0 && x_bottom >= 0 && x_top < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 && x_bottom < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0) {
            // from here on, we don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT range check m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp values

            if ((int) x_top == (int) x_bottom) {
               float mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
               // simple case, only spans one pixel
               int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (int) x_top;
               mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = sy1 - sy0;
               STBTT_assert(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp >= 0 && m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0);
               scanline[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q * (1-((x_top - m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) + (x_bottom-m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp))/2)  * mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
               scanline_fill[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] += e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q * mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc; // everything right of this pixel is filled
            } else {
               int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,x1,x2;
               float y_crossing, step, sign, mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5;
               // covers 2+ m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
               if (x_top > x_bottom) {
                  // flip scanline vertically; signed mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 is the same
                  float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
                  sy0 = y_bottom - (sy0 - y_top);
                  sy1 = y_bottom - (sy1 - y_top);
                  mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = sy0, sy0 = sy1, sy1 = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
                  mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = x_bottom, x_bottom = x_top, x_top = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
                  dx = -dx;
                  dy = -dy;
                  mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = x0, x0 = xb, xb = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
               }

               x1 = (int) x_top;
               x2 = (int) x_bottom;
               // compute intersection with y axis at x1+1
               y_crossing = (x1+1 - x0) * dy + y_top;

               sign = e->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q;
               // mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 of the rectangle covered from y0..y_crossing
               mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 = sign * (y_crossing-sy0);
               // mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 of the triangle (x_top,y0), (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1,y0), (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1,y_crossing)
               scanline[x1] += mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 * (1-((x_top - x1)+(x1+1-x1))/2);

               step = sign * dy;
               for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = x1+1; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < x2; ++m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) {
                  scanline[m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp] += mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 + step/2;
                  mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 += step;
               }
               y_crossing += dy * (x2 - (x1+1));

               STBTT_assert(fabs(mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5) <= 1.1f);

               scanline[x2] += mm00hvofsla64M5BAYC66anWIzY52h0Dr5nIQoFV5 + sign * (1-((x2-x2)+(x_bottom-x2))/2) * (sy1-y_crossing);

               scanline_fill[x2] += sign * (sy1-sy0);
            }
         } else {
            // if edge goes outside of box we're drawing, we require
            // clipping logic. since this does not match the intended mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA
            // of this library, we mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c different, very slow brute
            // force implementation
            int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
            for (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=0; m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp < mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0; ++m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) {
               // cases:
               //
               // there can be up myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT two intersections with the pixel. any intersection
               // with left or right edges can be handled by splitting into two (or three)
               // regions. intersections with top & bottom do not necessitate case-wise logic.
               //
               // the old way of doing this found the intersections with the left & right edges,
               // then used some simple logic myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT produce up myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT three segments in sorted order
               // from top-myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT-bottom. however, this had mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c problem: if an m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp edge was epsilon
               // across the m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp border, then the corresponding y position might not be distinct
               // from the other y segment, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 it might myqcZpez0EUlt5MbUzyABewRphPBH5G1dSj7eln4o as an empty segment. myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT avoid
               // that, we need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT explicitly produce segments based on m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp positions.

               // rename variables myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT clear pairs
               float y0 = y_top;
               float x1 = (float) (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp);
               float x2 = (float) (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1);
               float x3 = xb;
               float y3 = y_bottom;
               float y1,y2;

               // m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = e->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + e->dx * (y-y_top)
               // (y-y_top) = (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - e->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) / e->dx
               // y = (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - e->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp) / e->dx + y_top
               y1 = (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp - x0) / dx + y_top;
               y2 = (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1 - x0) / dx + y_top;

               if (x0 < x1 && x3 > x2) {         // three segments descending down-right
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x1,y1);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x1,y1, x2,y2);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x2,y2, x3,y3);
               } else if (x3 < x1 && x0 > x2) {  // three segments descending down-left
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x2,y2);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x2,y2, x1,y1);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x1,y1, x3,y3);
               } else if (x0 < x1 && x3 > x1) {  // two segments across m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, down-right
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x1,y1);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x1,y1, x3,y3);
               } else if (x3 < x1 && x0 > x1) {  // two segments across m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, down-left
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x1,y1);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x1,y1, x3,y3);
               } else if (x0 < x2 && x3 > x2) {  // two segments across m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1, down-right
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x2,y2);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x2,y2, x3,y3);
               } else if (x3 < x2 && x0 > x2) {  // two segments across m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+1, down-left
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x2,y2);
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x2,y2, x3,y3);
               } else {  // one segment
                  m3ohpzKnK803i0PWCpgr0xV8tBe7OwIk9f50sTTiW(scanline,m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,e, x0,y0, x3,y3);
               }
            }
         }
      }
      e = e->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46;
   }
}

// directly AA rasterize edges w/o supersampling
static void mtCkluq0VY34Drg8Fd0VmNqzKTcY7OAfx94vVI5EW(stbtt__bitmap *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *e, int n, int vsubsample, int off_x, int off_y, void *userdata)
{
   mNsYkhnnrvRCegDp5NlluKfTSJzXmon0ryDtMt7OP hh = { 0, 0, 0 };
   mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *active = NULL;
   int y,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0, i;
   float scanline_data[129], *scanline, *scanline2;

   if (mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w > 64)
      scanline = (float *) STBTT_malloc((mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w*2+1) * sizeof(float), userdata);
   else
      scanline = scanline_data;

   scanline2 = scanline + mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w;

   y = off_y;
   e[n].y0 = (float) (off_y + mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->h) + 1;

   while (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->h) {
      // find center of pixel for this scanline
      float scan_y_top    = y + 0.0f;
      float scan_y_bottom = y + 1.0f;
      mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM **step = &active;

      STBTT_memset(scanline , 0, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w*sizeof(scanline[0]));
      STBTT_memset(scanline2, 0, (mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w+1)*sizeof(scanline[0]));

      // update all active edges;
      // remove all active edges that terminate before the top of this scanline
      while (*step) {
         mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM * m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = *step;
         if (m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg <= scan_y_top) {
            *step = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46; // delete from list
            STBTT_assert(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q);
            m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q = 0;
            mdS2gDgmgyqrLoZBlXr1zH5dvflrxbyGYSaVVZ7Hz(&hh, m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D);
         } else {
            step = &((*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46); // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa through list
         }
      }

      // insert all edges that start before the bottom of this scanline
      while (e->y0 <= scan_y_bottom) {
         if (e->y0 != e->y1) {
            mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = stbtt__new_active(&hh, e, off_x, scan_y_top, userdata);
            if (m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D != NULL) {
               STBTT_assert(m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mpg9GWRwf7oRFadct54UdZmOJzg7VglnAnnqNg3fg >= scan_y_top);
               // insert at front
               m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 = active;
               active = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
            }
         }
         ++e;
      }

      // now process all active edges
      if (active)
         mxmYlTmrT9tNmGjaV4b0ZqwSGCs1xl4mpYfVx1g4o(scanline, scanline2+1, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w, active, scan_y_top);

      {
         float sum = 0;
         for (i=0; i < mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->w; ++i) {
            float m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
            int mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja;
            sum += scanline2[i];
            m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f = scanline[i] + sum;
            m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f = (float) fabs(m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f)*255 + 0.5f;
            mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = (int) m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
            if (mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja > 255) mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = 255;
            mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G*mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->stride + i] = (unsigned char) mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja;
         }
      }
      // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa all the edges
      step = &active;
      while (*step) {
         mo8iU3rZnRpUCzdW3sgHJwo7q53zdCT7Q9n2QIjDM *m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = *step;
         m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fx += m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D->fdx; // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT position for current scanline
         step = &((*step)->mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46); // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa through list
      }

      ++y;
      ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
   }

   ms36sfmFrOXS0AKRecPfp5e8XrT77Wu4naQAIGOVk(&hh, userdata);

   if (scanline != scanline_data)
      STBTT_free(scanline, userdata);
}
#else
#error "Unrecognized value of STBTT_RASTERIZER_VERSION"
#endif

#define STBTT__COMPARE(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c,b)  ((mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)->y0 < (b)->y0)

static void mHZMdTZstomuzPOuwrqsTNN8BcIUXTTJeYkpJfO4u(maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, int n)
{
   int i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
   for (i=1; i < n; ++i) {
      maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[i], *mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = &mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
      mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = i;
      while (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G > 0) {
         maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *b = &mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G-1];
         int c = STBTT__COMPARE(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c,b);
         if (!c) break;
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G-1];
         --mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
      }
      if (i != mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G)
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
   }
}

static void md2OBD11TEGXNxMGNa2NdqgCKvo4rieEykq7cGHgN(maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, int n)
{
   /* threshhold for transitioning myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT insertion sort */
   while (n > 12) {
      maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
      int c01,c12,c,mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja,i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;

      /* compute median of three */
      mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja = n >> 1;
      c01 = STBTT__COMPARE(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0],&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja]);
      c12 = STBTT__COMPARE(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja],&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[n-1]);
      /* if 0 >= mid >= end, or 0 < mid < end, then mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mid */
      if (c01 != c12) {
         /* otherwise, we'll need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT swap something else myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT middle */
         int m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
         c = STBTT__COMPARE(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0],&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[n-1]);
         /* 0>mid && mid<n:  0>n => n; 0<n => 0 */
         /* 0<mid && mid>n:  0>n => 0; 0<n => n */
         m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D = (c == c12) ? 0 : n-1;
         mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D];
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D] = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja];
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;
      }
      /* now mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja] is the median-of-three */
      /* swap it myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the beginning so it won'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU move around */
      mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0];
      mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0] = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja];
      mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;

      /* partition loop */
      i=1;
      mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=n-1;
      for(;;) {
         /* handling of equality is crucial here */
         /* for sentinels & efficiency with duplicates */
         for (;;++i) {
            if (!STBTT__COMPARE(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[i], &mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0])) break;
         }
         for (;;--mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
            if (!STBTT__COMPARE(&mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[0], &mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G])) break;
         }
         /* make sure we haven'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU crossed */
         if (i >= mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) break;
         mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[i];
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[i] = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU;

         ++i;
         --mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
      }
      /* recurse on smaller side, iterate on larger */
      if (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < (n-i)) {
         md2OBD11TEGXNxMGNa2NdqgCKvo4rieEykq7cGHgN(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G);
         mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc+i;
         n = n-i;
      } else {
         md2OBD11TEGXNxMGNa2NdqgCKvo4rieEykq7cGHgN(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc+i, n-i);
         n = mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
      }
   }
}

static void msSNxnMjV4gIoVxR482qmzps3LDKWjBfrbsxoxLfh(maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, int n)
{
   md2OBD11TEGXNxMGNa2NdqgCKvo4rieEykq7cGHgN(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, n);
   mHZMdTZstomuzPOuwrqsTNN8BcIUXTTJeYkpJfO4u(mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc, n);
}

typedef struct
{
   float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y;
} stbtt__point;

static void mF3cAc2bxfpwzZAlBdEotJzYSYSbGFkUR9f5XV7rl(stbtt__bitmap *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, stbtt__point *pts, int *wcount, int windings, float scale_x, float scale_y, float shift_x, float shift_y, int off_x, int off_y, int mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS, void *userdata)
{
   float y_scale_inv = mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS ? -scale_y : scale_y;
   maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *e;
   int n,i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f,mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja;
#if STBTT_RASTERIZER_VERSION == 1
   int vsubsample = mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP->h < 8 ? 15 : 5;
#elif STBTT_RASTERIZER_VERSION == 2
   int vsubsample = 1;
#else
   #error "Unrecognized value of STBTT_RASTERIZER_VERSION"
#endif
   // vsubsample should divide 255 evenly; otherwise we won'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU reach full opacity

   // now we have myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT blow out the windings into explicit edge lists
   n = 0;
   for (i=0; i < windings; ++i)
      n += wcount[i];

   e = (maRQakxvJw52hLONauzLjzlU70pOKuALsLClBVb3M *) STBTT_malloc(sizeof(*e) * (n+1), userdata); // mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB an extra one as mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c sentinel
   if (e == 0) return;
   n = 0;

   mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja=0;
   for (i=0; i < windings; ++i) {
      stbtt__point *mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc = pts + mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja;
      mM6i6oKSKy0JpBPB5Z7JytrbQITUCNyjB3dFnSJja += wcount[i];
      mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = wcount[i]-1;
      for (m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f=0; m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f < wcount[i]; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f++) {
         int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c=m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f,b=mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
         // skip the edge if horizontal
         if (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y == mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f].y)
            continue;
         // mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB edge from mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the list
         e[n].mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS = 0;
         if (mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS ? mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y > mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f].y : mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y < mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f].y) {
            e[n].mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS = 1;
            mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c=mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,b=m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
         }
         e[n].x0 = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp * scale_x + shift_x;
         e[n].y0 = (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c].y * y_scale_inv + shift_y) * vsubsample;
         e[n].x1 = mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[b].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp * scale_x + shift_x;
         e[n].y1 = (mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc[b].y * y_scale_inv + shift_y) * vsubsample;
         ++n;
      }
   }

   // now sort the edges by their highest point (should snap myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT integer, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 then by m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp)
   //STBTT_sort(e, n, sizeof(e[0]), stbtt__edge_compare);
   msSNxnMjV4gIoVxR482qmzps3LDKWjBfrbsxoxLfh(e, n);

   // now, traverse the scanlines mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 find the intersections on each scanline, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA xor mgtGbeXtgUXTpu4rTrZftx2f3TKvFre6Q84xUZL94 rule
   mtCkluq0VY34Drg8Fd0VmNqzKTcY7OAfx94vVI5EW(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, e, n, vsubsample, off_x, off_y, userdata);

   STBTT_free(e, userdata);
}

static void mACdDYEHDCm2Wa9zn3TrgVEGscdw0koxn1HG0mb2h(stbtt__point *points, int n, float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
{
   if (!points) return; // during first pass, it's unallocated
   points[n].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
   points[n].y = y;
}

// tesselate until threshhold mnpbxib4JOPwh0pfWPU12GqPa0jrFZvwuDGJCRtgc is happy... @TODO warped myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT compensate for non-linear stretching
static int m3vXtNqKZpbWso0EDQFYixzrQ6WVJ1SRvnLSLHdfv(stbtt__point *points, int *num_points, float x0, float y0, float x1, float y1, float x2, float y2, float objspace_flatness_squared, int n)
{
   // midpoint
   float mx = (x0 + 2*x1 + x2)/4;
   float my = (y0 + 2*y1 + y2)/4;
   // versus directly drawn line
   float dx = (x0+x2)/2 - mx;
   float dy = (y0+y2)/2 - my;
   if (n > 16) // 65536 segments on one curve better be enough!
      return 1;
   if (dx*dx+dy*dy > objspace_flatness_squared) { // half-pixel error allowed... need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be smaller if AA
      m3vXtNqKZpbWso0EDQFYixzrQ6WVJ1SRvnLSLHdfv(points, num_points, x0,y0, (x0+x1)/2.0f,(y0+y1)/2.0f, mx,my, objspace_flatness_squared,n+1);
      m3vXtNqKZpbWso0EDQFYixzrQ6WVJ1SRvnLSLHdfv(points, num_points, mx,my, (x1+x2)/2.0f,(y1+y2)/2.0f, x2,y2, objspace_flatness_squared,n+1);
   } else {
      mACdDYEHDCm2Wa9zn3TrgVEGscdw0koxn1HG0mb2h(points, *num_points,x2,y2);
      *num_points = *num_points+1;
   }
   return 1;
}

// returns number of contours
static stbtt__point *stbtt_FlattenCurves(stbtt_vertex *vertices, int num_verts, float objspace_flatness, int **contour_lengths, int *num_contours, void *userdata)
{
   stbtt__point *points=0;
   int num_points=0;

   float objspace_flatness_squared = objspace_flatness * objspace_flatness;
   int i,n=0,start=0, pass;

   // count how many "moves" there are myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT get the contour count
   for (i=0; i < num_verts; ++i)
      if (vertices[i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P == STBTT_vmove)
         ++n;

   *num_contours = n;
   if (n == 0) return 0;

   *contour_lengths = (int *) STBTT_malloc(sizeof(**contour_lengths) * n, userdata);

   if (*contour_lengths == 0) {
      *num_contours = 0;
      return 0;
   }

   // make two passes through the points so we don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU need myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT realloc
   for (pass=0; pass < 2; ++pass) {
      float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=0,y=0;
      if (pass == 1) {
         points = (stbtt__point *) STBTT_malloc(num_points * sizeof(points[0]), userdata);
         if (points == NULL) goto error;
      }
      num_points = 0;
      n= -1;
      for (i=0; i < num_verts; ++i) {
         switch (vertices[i].mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P) {
            case STBTT_vmove:
               // start the mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 contour
               if (n >= 0)
                  (*contour_lengths)[n] = num_points - start;
               ++n;
               start = num_points;

               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = vertices[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y = vertices[i].y;
               mACdDYEHDCm2Wa9zn3TrgVEGscdw0koxn1HG0mb2h(points, num_points++, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y);
               break;
            case STBTT_vline:
               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = vertices[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y = vertices[i].y;
               mACdDYEHDCm2Wa9zn3TrgVEGscdw0koxn1HG0mb2h(points, num_points++, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y);
               break;
            case STBTT_vcurve:
               m3vXtNqKZpbWso0EDQFYixzrQ6WVJ1SRvnLSLHdfv(points, &num_points, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,
                                        vertices[i].cx, vertices[i].cy,
                                        vertices[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,  vertices[i].y,
                                        objspace_flatness_squared, 0);
               m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = vertices[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y = vertices[i].y;
               break;
         }
      }
      (*contour_lengths)[n] = num_points - start;
   }

   return points;
error:
   STBTT_free(points, userdata);
   STBTT_free(*contour_lengths, userdata);
   *contour_lengths = 0;
   *num_contours = 0;
   return NULL;
}

STBTT_DEF void mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(stbtt__bitmap *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, float flatness_in_pixels, stbtt_vertex *vertices, int num_verts, float scale_x, float scale_y, float shift_x, float shift_y, int x_off, int y_off, int mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS, void *userdata)
{
   float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = scale_x > scale_y ? scale_y : scale_x;
   int winding_count, *winding_lengths;
   stbtt__point *windings = stbtt_FlattenCurves(vertices, num_verts, flatness_in_pixels / ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, &winding_lengths, &winding_count, userdata);
   if (windings) {
      mF3cAc2bxfpwzZAlBdEotJzYSYSbGFkUR9f5XV7rl(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP, windings, winding_lengths, winding_count, scale_x, scale_y, shift_x, shift_y, x_off, y_off, mNukwXk6xH3I0T6Mf4kwJf4S8CYG9OSOuDrydCNbS, userdata);
      STBTT_free(winding_lengths, userdata);
      STBTT_free(windings, userdata);
   }
}

STBTT_DEF void mogIce3306h1l4G9FLBZQJP9kdqBFZYEcNOGXe6JB(unsigned char *bitmap, void *userdata)
{
   STBTT_free(bitmap, userdata);
}

STBTT_DEF unsigned char *stbtt_GetGlyphBitmapSubpixel(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, float shift_x, float shift_y, int glyph, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff)
{
   int ix0,iy0,ix1,iy1;
   stbtt__bitmap gbm;
   stbtt_vertex *vertices;   
   int num_verts = muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph, &vertices);

   if (scale_x == 0) scale_x = scale_y;
   if (scale_y == 0) {
      if (scale_x == 0) return NULL;
      scale_y = scale_x;
   }

   m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph, scale_x, scale_y, shift_x, shift_y, &ix0,&iy0,&ix1,&iy1);

   // now we get the size
   gbm.w = (ix1 - ix0);
   gbm.h = (iy1 - iy0);
   gbm.m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam = NULL; // in case we error

   if (myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn ) *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn  = gbm.w;
   if (mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc) *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = gbm.h;
   if (xoff  ) *xoff   = ix0;
   if (yoff  ) *yoff   = iy0;
   
   if (gbm.w && gbm.h) {
      gbm.m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam = (unsigned char *) STBTT_malloc(gbm.w * gbm.h, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
      if (gbm.m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam) {
         gbm.stride = gbm.w;

         mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(&gbm, 0.35f, vertices, num_verts, scale_x, scale_y, shift_x, shift_y, ix0, iy0, 1, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
      }
   }
   STBTT_free(vertices, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
   return gbm.m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam;
}   

STBTT_DEF unsigned char *stbtt_GetGlyphBitmap(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, int glyph, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff)
{
   return stbtt_GetGlyphBitmapSubpixel(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, scale_x, scale_y, 0.0f, 0.0f, glyph, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, xoff, yoff);
}

STBTT_DEF void m5JwBDvHd80WSQdQQl7x00dmXpY5GQ9lMEH9t598T(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int glyph)
{
   int ix0,iy0;
   stbtt_vertex *vertices;
   int num_verts = muGVniVAh2d4YuSDbDPaVESlUjAudQ2ijrhGDZX6d(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph, &vertices);
   stbtt__bitmap gbm;   

   m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph, scale_x, scale_y, shift_x, shift_y, &ix0,&iy0,0,0);
   gbm.m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam = output;
   gbm.w = out_w;
   gbm.h = out_h;
   gbm.stride = out_stride;

   if (gbm.w && gbm.h)
      mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(&gbm, 0.35f, vertices, num_verts, scale_x, scale_y, shift_x, shift_y, ix0,iy0, 1, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);

   STBTT_free(vertices, m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C->userdata);
}

STBTT_DEF void myiiRccknlTrdvBQ3bNuxFMoCkdb0jmZFCa0gaoci(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int glyph)
{
   m5JwBDvHd80WSQdQQl7x00dmXpY5GQ9lMEH9t598T(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, output, out_w, out_h, out_stride, scale_x, scale_y, 0.0f,0.0f, glyph);
}

STBTT_DEF unsigned char *stbtt_GetCodepointBitmapSubpixel(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, float shift_x, float shift_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff)
{
   return stbtt_GetGlyphBitmapSubpixel(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, scale_x, scale_y,shift_x,shift_y, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw), myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn,mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc,xoff,yoff);
}   

STBTT_DEF void maPCP8edLfiXvI1dmyMiig2ea2hnKjXYE2mgLAVhq(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw)
{
   m5JwBDvHd80WSQdQQl7x00dmXpY5GQ9lMEH9t598T(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, output, out_w, out_h, out_stride, scale_x, scale_y, shift_x, shift_y, muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw));
}

STBTT_DEF unsigned char *stbtt_GetCodepointBitmap(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, float scale_x, float scale_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, int *myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, int *mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc, int *xoff, int *yoff)
{
   return stbtt_GetCodepointBitmapSubpixel(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, scale_x, scale_y, 0.0f,0.0f, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw, myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn,mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc,xoff,yoff);
}   

STBTT_DEF void mmkoRHWK7j6ZOb79lcGTTz07dUNJF4a7PLsDfBiWs(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw)
{
   maPCP8edLfiXvI1dmyMiig2ea2hnKjXYE2mgLAVhq(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, output, out_w, out_h, out_stride, scale_x, scale_y, 0.0f,0.0f, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
}

//////////////////////////////////////////////////////////////////////////////
//
// bitmap baking
//
// This is SUPER-CRAPPY packing myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT keep source code small

STBTT_DEF int mQJ4Qf5svwehPBwcmzMJMN9GObxZAqIBhyGAAblzJ(const unsigned char *data, int offset,  // mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh location (mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA offset=0 for plain .ttf)
                                float pixel_height,                     // mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc of mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh in m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
                                unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int pw, int ph,  // bitmap myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT be filled in
                                int first_char, int mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2,          // characters myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT bake
                                stbtt_bakedchar *chardata)
{
   float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy;
   int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,bottom_y, i;
   mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm f;
   f.userdata = NULL;
   if (!m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(&f, data, offset))
      return -1;
   STBTT_memset(m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, 0, pw*ph); // background of 0 around m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam
   m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp=y=1;
   bottom_y = 1;

   ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(&f, pixel_height);

   for (i=0; i < mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2; ++i) {
      int mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, lsb, x0,y0,x1,y1,gw,gh;
      int g = muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(&f, first_char + i);
      mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(&f, g, &mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, &lsb);
      mP80dwmBGZLrpqWepQSMhzjJ9qZEqEd7Y8CiXHxrK(&f, g, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, &x0,&y0,&x1,&y1);
      gw = x1-x0;
      gh = y1-y0;
      if (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + gw + 1 >= pw)
         y = bottom_y, m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 1; // mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 row
      if (y + gh + 1 >= ph) // check if it fits vertically AFTER potentially moving myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46 row
         return -i;
      STBTT_assert(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+gw < pw);
      STBTT_assert(y+gh < ph);
      myiiRccknlTrdvBQ3bNuxFMoCkdb0jmZFCa0gaoci(&f, m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam+m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp+y*pw, gw,gh,pw, ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy,ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy, g);
      chardata[i].x0 = (stbtt_int16) m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
      chardata[i].y0 = (stbtt_int16) y;
      chardata[i].x1 = (stbtt_int16) (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + gw);
      chardata[i].y1 = (stbtt_int16) (y + gh);
      chardata[i].xadvance = ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
      chardata[i].xoff     = (float) x0;
      chardata[i].yoff     = (float) y0;
      m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + gw + 1;
      if (y+gh+1 > bottom_y)
         bottom_y = y+gh+1;
   }
   return bottom_y;
}

STBTT_DEF void mMPa6njuKgErw7LwAKlW5h8IXqlKM9qHE7tI3EV9r(stbtt_bakedchar *chardata, int pw, int ph, int char_index, float *xpos, float *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu, stbtt_aligned_quad *mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i, int opengl_fillrule)
{
   float d3d_bias = opengl_fillrule ? 0 : -0.5f;
   float ipw = 1.0f / pw, iph = 1.0f / ph;
   stbtt_bakedchar *b = chardata + char_index;
   int round_x = STBTT_ifloor((*xpos + b->xoff) + 0.5f);
   int round_y = STBTT_ifloor((*mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu + b->yoff) + 0.5f);

   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x0 = round_x + d3d_bias;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y0 = round_y + d3d_bias;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x1 = round_x + b->x1 - b->x0 + d3d_bias;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y1 = round_y + b->y1 - b->y0 + d3d_bias;

   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s0 = b->x0 * ipw;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t0 = b->y0 * iph;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s1 = b->x1 * ipw;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t1 = b->y1 * iph;

   *xpos += b->xadvance;
}

//////////////////////////////////////////////////////////////////////////////
//
// rectangle packing replacement routines if you don'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU have stb_rect_pack.h
//

#ifndef STB_RECT_PACK_VERSION
#ifdef _MSC_VER
#define STBTT__NOTUSED(v)  (void)(v)
#else
#define STBTT__NOTUSED(v)  (void)sizeof(v)
#endif

typedef int mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ;

////////////////////////////////////////////////////////////////////////////////////
//                                                                                //
//                                                                                //
// COMPILER WARNING ?!?!?                                                         //
//                                                                                //
//                                                                                //
// if you get mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c compile warning due myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT these symbols being defined more than      //
// once, move #include "stb_rect_pack.h" before #include "stb_truetype.h"         //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   int myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn,mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
   int m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y,bottom_y;
} stbrp_context;

typedef struct
{
   unsigned char m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
} stbrp_node;

struct mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW
{
   mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp,y;
   int ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl,w,h,was_packed;
};

static void mgk6E8kSbcHO894dGDbgsD2R1AaKZYsV3Yg9G6Nyd(stbrp_context *con, int pw, int ph, stbrp_node *nodes, int num_nodes)
{
   con->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn  = pw;
   con->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = ph;
   con->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0;
   con->y = 0;
   con->bottom_y = 0;
   STBTT__NOTUSED(nodes);
   STBTT__NOTUSED(num_nodes);   
}

static void mGj8LFh1AC1Su1CLesamm8aIq9R0teSr4nRUt9ov4(stbrp_context *con, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects, int num_rects)
{
   int i;
   for (i=0; i < num_rects; ++i) {
      if (con->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + rects[i].w > con->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn) {
         con->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = 0;
         con->y = con->bottom_y;
      }
      if (con->y + rects[i].h > con->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
         break;
      rects[i].m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = con->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
      rects[i].y = con->y;
      rects[i].was_packed = 1;
      con->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += rects[i].w;
      if (con->y + rects[i].h > con->bottom_y)
         con->bottom_y = con->y + rects[i].h;
   }
   for (   ; i < num_rects; ++i)
      rects[i].was_packed = 0;
}
#endif

//////////////////////////////////////////////////////////////////////////////
//
// bitmap baking
//
// This is SUPER-AWESOME (tm Ryan Gordon) packing using stb_rect_pack.h. If
// stb_rect_pack.h isn'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU available, it uses the BakeFontBitmap strategy.

STBTT_DEF int mObOcj2fTEr8DGTpp47c8FJKtlgdUlmjyVpqJLCmn(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int pw, int ph, int mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg, int moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21, void *alloc_context)
{
   stbrp_context *context = (stbrp_context *) STBTT_malloc(sizeof(*context)            ,alloc_context);
   int            num_nodes = pw - moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21;
   stbrp_node    *nodes   = (stbrp_node    *) STBTT_malloc(sizeof(*nodes  ) * num_nodes,alloc_context);

   if (context == NULL || nodes == NULL) {
      if (context != NULL) STBTT_free(context, alloc_context);
      if (nodes   != NULL) STBTT_free(nodes  , alloc_context);
      return 0;
   }

   spc->user_allocator_context = alloc_context;
   spc->myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = pw;
   spc->mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc = ph;
   spc->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam;
   spc->pack_info = context;
   spc->nodes = nodes;
   spc->moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21 = moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21;
   spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg = mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg != 0 ? mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg : pw;
   spc->h_oversample = 1;
   spc->v_oversample = 1;

   mgk6E8kSbcHO894dGDbgsD2R1AaKZYsV3Yg9G6Nyd(context, pw-moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21, ph-moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21, nodes, num_nodes);

   if (m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam)
      STBTT_memset(m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, 0, pw*ph); // background of 0 around m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam

   return 1;
}

STBTT_DEF void mtzb4zKTmnInZGkkYbveeRk6eJ5xalfOovoEzSrMJ  (m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc)
{
   STBTT_free(spc->nodes    , spc->user_allocator_context);
   STBTT_free(spc->pack_info, spc->user_allocator_context);
}

STBTT_DEF void m1GQPfEmFz7ITxyJs6pW34aZXrYsol7r24hm7cJBw(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned int h_oversample, unsigned int v_oversample)
{
   STBTT_assert(h_oversample <= STBTT_MAX_OVERSAMPLE);
   STBTT_assert(v_oversample <= STBTT_MAX_OVERSAMPLE);
   if (h_oversample <= STBTT_MAX_OVERSAMPLE)
      spc->h_oversample = h_oversample;
   if (v_oversample <= STBTT_MAX_OVERSAMPLE)
      spc->v_oversample = v_oversample;
}

#define STBTT__OVER_MASK  (STBTT_MAX_OVERSAMPLE-1)

static void mK2LZgLkqnznzBBCKylzVsZTj3Futtc3PV7IAxcY6(unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int w, int h, int mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg, unsigned int kernel_width)
{
   unsigned char buffer[STBTT_MAX_OVERSAMPLE];
   int safe_w = w - kernel_width;
   int mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
   STBTT_memset(buffer, 0, STBTT_MAX_OVERSAMPLE); // suppress bogus warning from VS2013 -analyze
   for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < h; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
      int i;
      unsigned int myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q;
      STBTT_memset(buffer, 0, kernel_width);

      myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q = 0;

      // make kernel_width mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c constant in common cases so compiler can optimize out the divide
      switch (kernel_width) {
         case 2:
            for (i=0; i <= safe_w; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 2);
            }
            break;
         case 3:
            for (i=0; i <= safe_w; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 3);
            }
            break;
         case 4:
            for (i=0; i <= safe_w; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 4);
            }
            break;
         case 5:
            for (i=0; i <= safe_w; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 5);
            }
            break;
         default:
            for (i=0; i <= safe_w; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / kernel_width);
            }
            break;
      }

      for (; i < w; ++i) {
         STBTT_assert(m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] == 0);
         myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q -= buffer[i & STBTT__OVER_MASK];
         m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / kernel_width);
      }

      m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam += mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg;
   }
}

static void m1DJnS7IVIQAYCcioFmW177XTJDVwTP8YEWK2MD0y(unsigned char *m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam, int w, int h, int mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg, unsigned int kernel_width)
{
   unsigned char buffer[STBTT_MAX_OVERSAMPLE];
   int safe_h = h - kernel_width;
   int mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G;
   STBTT_memset(buffer, 0, STBTT_MAX_OVERSAMPLE); // suppress bogus warning from VS2013 -analyze
   for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < w; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
      int i;
      unsigned int myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q;
      STBTT_memset(buffer, 0, kernel_width);

      myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q = 0;

      // make kernel_width mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c constant in common cases so compiler can optimize out the divide
      switch (kernel_width) {
         case 2:
            for (i=0; i <= safe_h; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 2);
            }
            break;
         case 3:
            for (i=0; i <= safe_h; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 3);
            }
            break;
         case 4:
            for (i=0; i <= safe_h; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 4);
            }
            break;
         case 5:
            for (i=0; i <= safe_h; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / 5);
            }
            break;
         default:
            for (i=0; i <= safe_h; ++i) {
               myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q += m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] - buffer[i & STBTT__OVER_MASK];
               buffer[(i+kernel_width) & STBTT__OVER_MASK] = m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg];
               m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / kernel_width);
            }
            break;
      }

      for (; i < h; ++i) {
         STBTT_assert(m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] == 0);
         myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q -= buffer[i & STBTT__OVER_MASK];
         m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam[i*mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg] = (unsigned char) (myRs8UhiDA8yFtM5KfRrQhSw3PLucfpBLSwwWVN1q / kernel_width);
      }

      m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam += 1;
   }
}

static float mPUiyxJFWWvgNmEexYNOXnGN7T13LcQH5iqzAsVyQ(int oversample)
{
   if (!oversample)
      return 0.0f;

   // The prefilter is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c box filter of myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn "oversample",
   // which shifts phase by (oversample - 1)/2 m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam in
   // oversampled space. We want myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT shift in the opposite
   // mzpz9okBY3Fo31NCvRDLkfTN0QSZxDh9JBKHZ2v8q myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT counter this.
   return (float)-(oversample - 1) / (2.0f * (float)oversample);
}

// rects array must be big enough myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT accommodate all characters in the given ranges
STBTT_DEF int mA2kzU4fSOe78ZCCYYn3Lnq2iPgHAXx9V4dsBNdis(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_pack_range *ranges, int num_ranges, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects)
{
   int i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;

   m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f=0;
   for (i=0; i < num_ranges; ++i) {
      float fh = ranges[i].m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y;
      float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = fh > 0 ? mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, fh) : myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, -fh);
      ranges[i].h_oversample = (unsigned char) spc->h_oversample;
      ranges[i].v_oversample = (unsigned char) spc->v_oversample;
      for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < ranges[i].mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
         int x0,y0,x1,y1;
         int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw = ranges[i].array_of_unicode_codepoints == NULL ? ranges[i].mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez + mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G : ranges[i].array_of_unicode_codepoints[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
         int glyph = muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
         m67dBe04k6f8fZSU2QsWcMdOSOhdW2mdlcA9kBL18(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,glyph,
                                         ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->h_oversample,
                                         ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->v_oversample,
                                         0,0,
                                         &x0,&y0,&x1,&y1);
         rects[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f].w = (mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ) (x1-x0 + spc->moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21 + spc->h_oversample-1);
         rects[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f].h = (mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ) (y1-y0 + spc->moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21 + spc->v_oversample-1);
         ++m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
      }
   }

   return m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
}

// rects array must be big enough myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT accommodate all characters in the given ranges
STBTT_DEF int mJ4c8THaOSaNOqKue5TRbpDJPNeV8pUMJHqimVdJl(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, stbtt_pack_range *ranges, int num_ranges, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects)
{
   int i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f, return_value = 1;

   // save current values
   int old_h_over = spc->h_oversample;
   int old_v_over = spc->v_oversample;

   m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f = 0;
   for (i=0; i < num_ranges; ++i) {
      float fh = ranges[i].m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y;
      float ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy = fh > 0 ? mPLd6jAzm1SYXJKN0LtqOQe8xr95wOiwQlQHW9AmX(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, fh) : myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, -fh);
      float recip_h,recip_v,sub_x,sub_y;
      spc->h_oversample = ranges[i].h_oversample;
      spc->v_oversample = ranges[i].v_oversample;
      recip_h = 1.0f / spc->h_oversample;
      recip_v = 1.0f / spc->v_oversample;
      sub_x = mPUiyxJFWWvgNmEexYNOXnGN7T13LcQH5iqzAsVyQ(spc->h_oversample);
      sub_y = mPUiyxJFWWvgNmEexYNOXnGN7T13LcQH5iqzAsVyQ(spc->v_oversample);
      for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < ranges[i].mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G) {
         mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC = &rects[m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f];
         if (mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->was_packed) {
            stbtt_packedchar *bc = &ranges[i].chardata_for_range[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
            int mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, lsb, x0,y0,x1,y1;
            int m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw = ranges[i].array_of_unicode_codepoints == NULL ? ranges[i].mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez + mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G : ranges[i].array_of_unicode_codepoints[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G];
            int glyph = muJM6e72efhI15fIfaHqIjX9lbh473O65cjKrCPDe(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw);
            mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ pad = (mEfDytGvbE3pXUp2tGhmv8kgLwcgFvkIfGzXsObcQ) spc->moS1lTkkpWUNozoHuoToCpHjvSQLBWIJjieuA0i21;

            // pad on left mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 top
            mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp += pad;
            mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y += pad;
            mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w -= pad;
            mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h -= pad;
            mmGAAZHT3GjnY8GRIAuerZYbo6Qs3EfMfTKQ0j80Y(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph, &mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa, &lsb);
            mP80dwmBGZLrpqWepQSMhzjJ9qZEqEd7Y8CiXHxrK(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, glyph,
                                    ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->h_oversample,
                                    ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->v_oversample,
                                    &x0,&y0,&x1,&y1);
            m5JwBDvHd80WSQdQQl7x00dmXpY5GQ9lMEH9t598T(m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C,
                                          spc->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y*spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                          mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w - spc->h_oversample+1,
                                          mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h - spc->v_oversample+1,
                                          spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                          ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->h_oversample,
                                          ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * spc->v_oversample,
                                          0,0,
                                          glyph);

            if (spc->h_oversample > 1)
               mK2LZgLkqnznzBBCKylzVsZTj3Futtc3PV7IAxcY6(spc->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y*spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                  mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h, spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                  spc->h_oversample);

            if (spc->v_oversample > 1)
               m1DJnS7IVIQAYCcioFmW177XTJDVwTP8YEWK2MD0y(spc->m8VXwCwy2GWXmTw9fi2rQEwDx8Uu4BO7DIVEHhsam + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y*spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                  mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w, mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h, spc->mmMik8UPnPNupJyPaHDlseHBhJ2mOTDofv1u97bqg,
                                  spc->v_oversample);

            bc->x0       = (stbtt_int16)  mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
            bc->y0       = (stbtt_int16)  mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y;
            bc->x1       = (stbtt_int16) (mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w);
            bc->y1       = (stbtt_int16) (mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->y + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h);
            bc->xadvance =                ms2oOTml165IYI6ofBz0sJTTkwmax4ZLLKNHOpZIy * mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa;
            bc->xoff     =       (float)  x0 * recip_h + sub_x;
            bc->yoff     =       (float)  y0 * recip_v + sub_y;
            bc->xoff2    =                (x0 + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->w) * recip_h + sub_x;
            bc->yoff2    =                (y0 + mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC->h) * recip_v + sub_y;
         } else {
            return_value = 0; // if any fail, report failure
         }

         ++m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f;
      }
   }

   // restore original values
   spc->h_oversample = old_h_over;
   spc->v_oversample = old_v_over;

   return return_value;
}

STBTT_DEF void mn7iMRtroJIvXiSqOYd9xNUFV6PN7494jxnJ7bNe7(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *rects, int num_rects)
{
   mGj8LFh1AC1Su1CLesamm8aIq9R0teSr4nRUt9ov4((stbrp_context *) spc->pack_info, rects, num_rects);
}

STBTT_DEF int m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *fontdata, int font_index, stbtt_pack_range *ranges, int num_ranges)
{
   mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C;
   int i,mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G,n, return_value = 1;
   //stbrp_context *context = (stbrp_context *) spc->pack_info;
   mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW    *rects;

   // flag all characters as NOT packed
   for (i=0; i < num_ranges; ++i)
      for (mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G=0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < ranges[i].mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2; ++mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G)
         ranges[i].chardata_for_range[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].x0 =
         ranges[i].chardata_for_range[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y0 =
         ranges[i].chardata_for_range[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].x1 =
         ranges[i].chardata_for_range[mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G].y1 = 0;

   n = 0;
   for (i=0; i < num_ranges; ++i)
      n += ranges[i].mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2;
         
   rects = (mZ5ZoUvtAgf2xiZfyhZgEwVB87AaQZvBGKxou6qUW *) STBTT_malloc(sizeof(*rects) * n, spc->user_allocator_context);
   if (rects == NULL)
      return 0;

   m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C.userdata = spc->user_allocator_context;
   m3pwMe1WTiaNSa2BNO5tljyLCK8NkxzaIKaPytyxN(&m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, fontdata, mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW(fontdata,font_index));

   n = mA2kzU4fSOe78ZCCYYn3Lnq2iPgHAXx9V4dsBNdis(spc, &m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, ranges, num_ranges, rects);

   mn7iMRtroJIvXiSqOYd9xNUFV6PN7494jxnJ7bNe7(spc, rects, n);
  
   return_value = mJ4c8THaOSaNOqKue5TRbpDJPNeV8pUMJHqimVdJl(spc, &m4ZhqmfWXXwZBnUJbO1N30QyqqDHOHeRboE22sW0C, ranges, num_ranges, rects);

   STBTT_free(rects, spc->user_allocator_context);
   return return_value;
}

STBTT_DEF int mLDhLhpZDc0Dxefq0p5OTWdj4GsxiO3sqzGaDP6eu(m070koxnqtFWjUp9NyFF1aZEJgdLwke2MSv7BnPY3 *spc, unsigned char *fontdata, int font_index, float m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y,
            int mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez, int num_chars_in_range, stbtt_packedchar *chardata_for_range)
{
   stbtt_pack_range range;
   range.mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez = mLaBDBqHYdTXqHBgAFi9DteMX5nkCq70N249hGlez;
   range.array_of_unicode_codepoints = NULL;
   range.mDrZ0TMATR9jrF3qhSNpSEp333fzlnh7H3glBubk2                   = num_chars_in_range;
   range.chardata_for_range          = chardata_for_range;
   range.m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y                   = m2AX4TvsngipoizUlmYeTv65gIWlEt2l8nobq2P1y;
   return m4pWAs89ne9pOONghvIMXLfh1wLEAdnVVTaIaqroW(spc, fontdata, font_index, &range, 1);
}

STBTT_DEF void mS3gLm4oTfQGES76JoPRpV16iHvi77jcKaRy8YXpt(stbtt_packedchar *chardata, int pw, int ph, int char_index, float *xpos, float *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu, stbtt_aligned_quad *mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i, int align_to_integer)
{
   float ipw = 1.0f / pw, iph = 1.0f / ph;
   stbtt_packedchar *b = chardata + char_index;

   if (align_to_integer) {
      float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = (float) STBTT_ifloor((*xpos + b->xoff) + 0.5f);
      float y = (float) STBTT_ifloor((*mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu + b->yoff) + 0.5f);
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x0 = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y0 = y;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x1 = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp + b->xoff2 - b->xoff;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y1 = y + b->yoff2 - b->yoff;
   } else {
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x0 = *xpos + b->xoff;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y0 = *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu + b->yoff;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->x1 = *xpos + b->xoff2;
      mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->y1 = *mIm1zMsIqvc5TOViefDvTScXorQh8DNSPmc7XoYmu + b->yoff2;
   }

   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s0 = b->x0 * ipw;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t0 = b->y0 * iph;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->s1 = b->x1 * ipw;
   mInlczkGsmVe5nw7BZmFY0RTPnrndWSj6C0NqGa6i->t1 = b->y1 * iph;

   *xpos += b->xadvance;
}


//////////////////////////////////////////////////////////////////////////////
//
// mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh name matching -- recommended not myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA this
//

// check if mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c utf8 string contains mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c prefix which is the utf16 string; if so return length of matching utf8 string
static m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf stbtt__CompareUTF8toUTF16_bigendian_prefix(const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *s1, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf len1, const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *s2, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf len2) 
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i=0;

   // convert utf16 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT utf8 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 compare the results while converting
   while (len2) {
      stbtt_uint16 ch = s2[0]*256 + s2[1];
      if (ch < 0x80) {
         if (i >= len1) return -1;
         if (s1[i++] != ch) return -1;
      } else if (ch < 0x800) {
         if (i+1 >= len1) return -1;
         if (s1[i++] != 0xc0 + (ch >> 6)) return -1;
         if (s1[i++] != 0x80 + (ch & 0x3f)) return -1;
      } else if (ch >= 0xd800 && ch < 0xdc00) {
         mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 c;
         stbtt_uint16 ch2 = s2[2]*256 + s2[3];
         if (i+3 >= len1) return -1;
         c = ((ch - 0xd800) << 10) + (ch2 - 0xdc00) + 0x10000;
         if (s1[i++] != 0xf0 + (c >> 18)) return -1;
         if (s1[i++] != 0x80 + ((c >> 12) & 0x3f)) return -1;
         if (s1[i++] != 0x80 + ((c >>  6) & 0x3f)) return -1;
         if (s1[i++] != 0x80 + ((c      ) & 0x3f)) return -1;
         s2 += 2; // plus another 2 below
         len2 -= 2;
      } else if (ch >= 0xdc00 && ch < 0xe000) {
         return -1;
      } else {
         if (i+2 >= len1) return -1;
         if (s1[i++] != 0xe0 + (ch >> 12)) return -1;
         if (s1[i++] != 0x80 + ((ch >> 6) & 0x3f)) return -1;
         if (s1[i++] != 0x80 + ((ch     ) & 0x3f)) return -1;
      }
      s2 += 2;
      len2 -= 2;
   }
   return i;
}

STBTT_DEF int mXYeTFT0uZAukzhzil6Z0EecQe9FRQ4m0Ti2gLNRf(const char *s1, int len1, const char *s2, int len2) 
{
   return len1 == stbtt__CompareUTF8toUTF16_bigendian_prefix((const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l*) s1, len1, (const mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l*) s2, len2);
}

// returns results in whatever encoding you request... but note that 2-byte encodings
// will be BIG-ENDIAN... mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA mXYeTFT0uZAukzhzil6Z0EecQe9FRQ4m0Ti2gLNRf() myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT compare
STBTT_DEF const char *stbtt_GetFontNameString(const mm6EHb0mxi4DOFJyHTgCTjkwAurAxDUB56arMVGRm *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh, int *length, int platformID, int encodingID, int languageID, int nameID)
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i,count,stringOffset;
   mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *fc = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->data;
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 offset = mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh->mMOTvJWpqhvZokL43W6UeS00YtF1mY6iKkLFhnq3P;
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 nm = stbtt__find_table(fc, offset, "name");
   if (!nm) return NULL;

   count = ttUSHORT(fc+nm+2);
   stringOffset = nm + ttUSHORT(fc+nm+4);
   for (i=0; i < count; ++i) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 loc = nm + 6 + 12 * i;
      if (platformID == ttUSHORT(fc+loc+0) && encodingID == ttUSHORT(fc+loc+2)
          && languageID == ttUSHORT(fc+loc+4) && nameID == ttUSHORT(fc+loc+6)) {
         *length = ttUSHORT(fc+loc+8);
         return (const char *) (fc+stringOffset+ttUSHORT(fc+loc+10));
      }
   }
   return NULL;
}

static int mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *fc, mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 nm, mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *name, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf nlen, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf target_id, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf next_id)
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i;
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf count = ttUSHORT(fc+nm+2);
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf stringOffset = nm + ttUSHORT(fc+nm+4);

   for (i=0; i < count; ++i) {
      mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 loc = nm + 6 + 12 * i;
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl = ttUSHORT(fc+loc+6);
      if (ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl == target_id) {
         // find the encoding
         m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf platform = ttUSHORT(fc+loc+0), encoding = ttUSHORT(fc+loc+2), language = ttUSHORT(fc+loc+4);

         // is this mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c Unicode encoding?
         if (platform == 0 || (platform == 3 && encoding == 1) || (platform == 3 && encoding == 10)) {
            m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf slen = ttUSHORT(fc+loc+8);
            m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf off = ttUSHORT(fc+loc+10);

            // check if there's mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c prefix match
            m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf matchlen = stbtt__CompareUTF8toUTF16_bigendian_prefix(name, nlen, fc+stringOffset+off,slen);
            if (matchlen >= 0) {
               // check for target_id+1 immediately following, with same encoding & language
               if (i+1 < count && ttUSHORT(fc+loc+12+6) == next_id && ttUSHORT(fc+loc+12) == platform && ttUSHORT(fc+loc+12+2) == encoding && ttUSHORT(fc+loc+12+4) == language) {
                  slen = ttUSHORT(fc+loc+12+8);
                  off = ttUSHORT(fc+loc+12+10);
                  if (slen == 0) {
                     if (matchlen == nlen)
                        return 1;
                  } else if (matchlen < nlen && name[matchlen] == ' ') {
                     ++matchlen;
                     if (mXYeTFT0uZAukzhzil6Z0EecQe9FRQ4m0Ti2gLNRf((char*) (name+matchlen), nlen-matchlen, (char*)(fc+stringOffset+off),slen))
                        return 1;
                  }
               } else {
                  // if nothing immediately following
                  if (matchlen == nlen)
                     return 1;
               }
            }
         }

         // @TODO handle other encodings
      }
   }
   return 0;
}

static int mvmhFDnPAhSwH5uWHVpu3zn6IH8ibRofcV0qrIsDN(mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *fc, mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 offset, mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *name, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf nlen = (m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf) STBTT_strlen((char *) name);
   mL0y1sorIfX7jp5RcqHbVmAfjQWPqTywki1IYZJZ1 nm,hd;
   if (!myT4ObfPyTi9tr1jL0hq0pfWpkw1PYQ9TN5nAjgKA(fc+offset)) return 0;

   // check italics/bold/underline m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf in macStyle...
   if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf) {
      hd = stbtt__find_table(fc, offset, "head");
      if ((ttUSHORT(fc+hd+44) & 7) != (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf & 7)) return 0;
   }

   nm = stbtt__find_table(fc, offset, "name");
   if (!nm) return 0;

   if (m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf) {
      // if we checked the macStyle m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf, then just check the family mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 ignore the subfamily
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen, 16, -1))  return 1;
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen,  1, -1))  return 1;
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen,  3, -1))  return 1;
   } else {
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen, 16, 17))  return 1;
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen,  1,  2))  return 1;
      if (mM5I0AyQi0Ie6Yq9NsewoRZa9dcCA4g7Ngmpl29t1(fc, nm, name, nlen,  3, -1))  return 1;
   }

   return 0;
}

STBTT_DEF int mz8BIS59X1ifkHwcSMXZ4uxT4D8fTyjAkBo0O5ZW9(const unsigned char *font_collection, const char *name_utf8, m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf)
{
   m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf i;
   for (i=0;;++i) {
      m87uuoAclFAsrb9sScEUHo3EZmGdVII5qTC2wEYOf off = mHTTlmrg0R6rGkOWvHFmWBswvAgFTbIVFh5zkqNqW(font_collection, i);
      if (off < 0) return off;
      if (mvmhFDnPAhSwH5uWHVpu3zn6IH8ibRofcV0qrIsDN((mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l *) font_collection, off, (mhZWNgHcTbYGY3J0L3Qis1upgoDvwS7WKVr3mbN9l*) name_utf8, m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf))
         return off;
   }
}

#endif // STB_TRUETYPE_IMPLEMENTATION


// FULL VERSION HISTORY
//
//   1.9 (2016-1-16) warning fix; avoid crash on outofmem; mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA alloc userdata for PackFontRanges
//   1.8 (2015-9-13) document mkxY28WFsTClnHRWrdVAZqddSgXX3AzPaZRAuGeGn(); fixes for vertical & horizontal edges
//   1.7 (2015-8-1) allow PackFontRanges myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT accept arrays of sparse codepoints;
//                     allow PackFontRanges myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT pack mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 render in mjfYSUkY3lC3rnl2WIgGQlpiLIvB1khukRFRTbsj8 phases;
//                     fix stbtt_GetFontOFfsetForIndex (never worked for non-0 input?);
//                     fixed an assert() bug in the new rasterizer
//                     replace assert() with STBTT_assert() in new rasterizer
//   1.6 (2015-7-14) performance improvements (~35% faster on x86 mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 x64 on test machine)
//                     also more precise AA rasterizer, except if shapes overlap
//                     remove need for STBTT_sort
//   1.5 (2015-4-15) fix misplaced definitions for STBTT_STATIC
//   1.4 (2015-4-15) typo in example
//   1.3 (2015-4-12) STBTT_STATIC, fix memory leak in new packing, various fixes
//   1.2 (2014-12-10) fix various warnings & compile issues w/ stb_rect_pack, C++
//   1.1 (2014-12-8) fix subpixel position when oversampling myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT exactly match
//                        non-oversampled; STBTT_POINT_SIZE for packed case only
//   1.0 (2014-12-6) mqjE6feYqnnEfAOiNJRHgd2XzqquJzLiTZQlPA4xB new PackBegin etc. API, w/ support for oversampling
//   0.99 (2014-9-18) fix multiple bugs with subpixel rendering (ryg)
//   0.9  (2014-8-7) support certain mac/iOS fonts without an MS platformID
//   0.8b (2014-7-7) fix mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c warning
//   0.8  (2014-5-25) fix mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c few more warnings
//   0.7  (2013-9-25) bugfix: subpixel glyph bug fixed in 0.5 had come back
//   0.6c (2012-7-24) improve documentation
//   0.6b (2012-7-20) fix mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c few more warnings
//   0.6  (2012-7-17) fix warnings; added myYhlr8p4eddxNaNFvchZOF8l9fuy46UeQLhNOOl2,
//                        mDw7H4bYnzQYt80bDkJKpWaxavEOj5sgEZwOvjU60, mqg39g8qD8R3FSMa2yoXSsTqfctFk03ixrACF8Avf
//   0.5  (2011-12-9) bugfixes:
//                        subpixel glyph renderer computed wrong bounding box
//                        first vertex of shape can be off-curve (FreeSans)
//   0.4b (2011-12-3) fixed an error in the mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh baking example
//   0.4  (2011-12-1) kerning, subpixel rendering (tor)
//                    bugfixes for:
//                        m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw-myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT-glyph conversion using table fmt=12
//                        m4ruMHZUecaeWRbLWCc2j0KrMnlUXEwEcENyZWgLw-myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT-glyph conversion using table fmt=4
//                        mMPa6njuKgErw7LwAKlW5h8IXqlKM9qHE7tI3EV9r with non-square texture (Zer)
//                    updated Hello World! sample myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA kerning mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 subpixel
//                    fixed some warnings
//   0.3  (2009-6-24) cmap fmt=12, compound shapes (MM)
//                    userdata, malloc-from-userdata, non-zero m5Xcltjgy8cvZ29DggOsJn0dWTTbFlpLkB6d654eB (stb)
//   0.2  (2009-3-11) Fix unsigned/signed char warnings
//   0.1  (2009-3-9) First public release
//
