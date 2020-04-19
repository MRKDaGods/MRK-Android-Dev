#pragma once

#include "MRKGuiBaseWidget.h"
#include "MRKFont.h"
#include "../MRKColor.h"

namespace MRK
{
    namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
    {
        enum MRKLabelFlags
        {
            None = 0,
            Bold = 1,
            Italic = 2,
            mOYULCKMSJUHTR75v2BSJtYiMGFGBHk7bQKiB5kex = 4,
            Extrude = 8,
            Strikethrough = 16,
            mJ7rYE5kTaqwuVQoAdFhnAoM7TIiT09Zp5JqC3hid = 32
        };

        enum MRKLabelAlignment
        {
            MRK_ALIGN_LEFT = 1,
            MRK_ALIGN_CENTER = 2,
            MRK_ALIGN_RIGHT = 4,
            MRK_ALIGN_TOP = 8,
            MRK_ALIGN_MIDDLE = 16,
            MRK_ALIGN_BOTTOM = 32,
            MRK_ALIGN_BASELINE = 64
        };

        struct mGC8004RpI1qoNUFZOuQrKtfzbPtHoaIw1b7OjAvc : public mEuIMUNuljzZP2gCULOBizuzVu4qlV9vEVM4kyqHV
        {
            _STD string Text;
            int mRGgVrAtx21tW6wSeCLfd75b6YwwEyApIRguaxN6R;
            MRKLabelAlignment Alignment;
            myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *Font;
            MRKLabelFlags LabelFlags;
        };

        class miK2pdCvvX9dauu0Sr4BLyoc5i16tzdlgES5bQtad : public mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf
        {
        private:
            myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *mRWQZGyBefQROoBchucRDuzGBZE9NMAitaDPU76fO;
            _STD string mWEigxR5s09t7axJvuib08pWSHmmlXwMY9zXh5xVi;
            int m8yxgzZTo0VVu08qBBWCv8zfV8dCb6mpuYPh6vCtc;
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mWVa3VPAOeS5RYBaQDqL10pFeoApHBM8StveYC89C;
            MRKLabelFlags mviFfafFI6JDc9K4V1OGQvIBqzpgnUIedTCD8DQeF;
            MRKLabelAlignment mNMY43DdjVuDBVOJnJPcDvjl8f1UV78Q66BoSwt64;
        public:
            miK2pdCvvX9dauu0Sr4BLyoc5i16tzdlgES5bQtad(mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *parent, MRKAnchor anchor, _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz rect,
                            _STD string text, int munQvBxiVYVZjBhataTudMxRQT0iSOVE9odi0V3L0 = 0, MRKLabelAlignment alignment = MRK_ALIGN_LEFT,
                            myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *mEXonE6jDgKEersSGrAdqZwo5nwi4srE7uzUIQHPh = myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::Exo2Regular,
                            MRKLabelFlags m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = MRKLabelFlags::None);
            void mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx *context) override;
            void mxM2de8DP4aNhQRJlGk6h6yKH29QgttgjORkJiuSa(mlrcjmWdyBIUP2TBJnN7gvMZHddObsy7GBc5Kk4JF *theme) override;
            void mxu0FV1O4hpp3CxEFZ9csadVytTyZ5zBrEzhSzQGM(_STD string text);
            void mj3zc7OxU3hFJHqVXx12y6Z7xYSG1YdYr6ienALRu(mEuIMUNuljzZP2gCULOBizuzVu4qlV9vEVM4kyqHV options) override;
            _STD string GetText();
        };
    }
}