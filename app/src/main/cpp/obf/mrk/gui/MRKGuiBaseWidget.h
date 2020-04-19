#pragma once

#include <vector>
#include <string>

#include "../MRKCommon.h"
#include "../math/Vector2.h"
#include "../math/Rect.h"
#include "MRKTheme.h"
#include "../MRKTouchEvent.h"
#include "../utils/MRKUtils.h"
#include "../utils/DupSafeVector.hpp"

namespace MRK
{
    namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
    {
        class mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf;

        enum MRKAnchor
        {
            MRK_ANCHOR_NONE = 0, //hack elements
            MRK_ANCHOR_TOP = 1,
            MRK_ANCHOR_MIDDLE = 2,
            MRK_ANCHOR_BOTTOM = 4,
            MRK_ANCHOR_CENTER = 8,
            MRK_ANCHOR_LEFT = 16,
            MRK_ANCHOR_RIGHT = 32,

            MRK_ANCHOR_TOP_LEFT = MRK_ANCHOR_TOP | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_TOP_CENTER = MRK_ANCHOR_TOP | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_TOP_RIGHT = MRK_ANCHOR_TOP | MRK_ANCHOR_RIGHT,
            MRK_ANCHOR_MIDDLE_LEFT = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_MIDDLE_CENTER = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_MIDDLE_RIGHT = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_RIGHT,
            MRK_ANCHOR_BOTTOM_LEFT = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_BOTTOM_CENTER = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_BOTTOM_RIGHT = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_RIGHT
        };

        enum MRKWidgetInitFlags
        {
            MRK_WIDGET_INIT_FLAG_NONE = 0,
            MRK_WIDGET_INIT_FLAG_NO_SIZE = 1,
            MRK_WIDGET_INIT_FLAG_NO_ANCHOR = 2
        };

        struct mEuIMUNuljzZP2gCULOBizuzVu4qlV9vEVM4kyqHV
        {
            mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *Parent;
            MRKAnchor Anchor;
            _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz;
            MRKWidgetInitFlags Flags;
        };

        class mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf
        {
        protected:
            mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *m7pAFkR5r3rT5KGxzPqQ7ZZ7NQIT5kopQrRlLzQbc;
            _UTILITY m2uo3i9unkFXdAvt7G9a6xuLevDPvwwv1aiaQHGi0<mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf*> mA7cMyUuRc3a72UPVpZ4xUQ7cIVdaZDbQPLdgLS9g;
            bool mGDMA4Itfy2nDVV64xOj1dE1SrXKNUxPr84r0HIK5;
            bool mSYP5RyzRchIA9cEVKM4dlW0TYofY7hxb5oR3DBIH;
            bool mdZNRiARXGUdjPW07vWus5CE4DsFOkdB4zgGqB71x;
            bool mwvrCtvKhddVTkfY6spW70PcmB1bV1QCKDot258DA;
            _STD string mkdqlzva1PfLGrznpiJcoDk6escMfWbRH4r9HD5YG;
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC;
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mvV4i5o9Wh9cwiNvUDDfSwGsHczG78zKbNRCDqXyq;
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR m3eW6SQmMs3FfUwQRQmi8dqtFfYBffTZh7zhJE5AE;
            mlrcjmWdyBIUP2TBJnN7gvMZHddObsy7GBc5Kk4JF *mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X;
            _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz m4yJ3qNFksc2Tiwe01T8ChuegvChX3JPiYYHtuS5w;
            float mvguiitlSilZiaC5bHfXsgbBRKUg9GIVnxCYNP2Aa;
            MRKAnchor mMcrLenzJZ8O77iK1FFUSXsITk0tZqdA1yjxbOxJy;

            void mpDXDJCQagFnQqbpNmfN9qoc1Ger6TlBJFC4N77mE();
            void m0mQGWaYYTBJPfvnp07t3oUqblJENGZg3KRcT00Tp();
        public:
            mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf(mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *parent, MRKAnchor anchor, _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz rect, MRKWidgetInitFlags m95wGYjCEKu7Y2E8Ld1FMJSdTtRLq6KnSTUCOl5Wf = MRK_WIDGET_INIT_FLAG_NONE);
            ~mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf();
            virtual void mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx *context);
            virtual void mxM2de8DP4aNhQRJlGk6h6yKH29QgttgjORkJiuSa(mlrcjmWdyBIUP2TBJnN7gvMZHddObsy7GBc5Kk4JF *theme);
            virtual void mj3zc7OxU3hFJHqVXx12y6Z7xYSG1YdYr6ienALRu(mEuIMUNuljzZP2gCULOBizuzVu4qlV9vEVM4kyqHV options);
            bool myY7QWrVZLV9n7y61KsOQU2YzDJJz9OJTm0suk4Kl();
            void mG9PNSp7le3kPWGBjIemzfbnI03nKguFKnHk1gCrk(bool visible);
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6();
            _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz m0QnY0ypEef8st71UdJBGJeuqXBeJMm4hThwqC11S();
            mlrcjmWdyBIUP2TBJnN7gvMZHddObsy7GBc5Kk4JF *Theme();
            virtual bool mIV0igL3AOWNzMxThbbR0FhPNGpMBlBoVNGnl7UO6(mYJIpIJflgU0wmUiBglo5Jw2pgMsgxHinINndYT8C &event);
            void ma1JpEnhlA6aDzGe3FmNp3NQKS87ljN9mm3XaauDw(bool focused);
            void mABpPJiclE7f2XLgRpW6EBgxJYjYWRppXZVidwHWK();
            void mUIDDy2kNgijmWrD49NQQpKPo52DFOvJ8ARyp26Fn();
            void mf8aavpozRtyxga4W01Ef3xJiuHzIm9Q1heMTsR1X();
            bool mOYkpoTYEhUN3zM7eEP7tuY4Qunwmnxb9mOLnIPtj();
            void mny9AGztBc6jeQL14w2oyJ4SKGbjNLAADTbLOJTFv(mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *widget);
            mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *FindWidget(_MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR pos);
            _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz mdPLbPH1PWid56iGKnn8ehCPyksi8UZvfQNBZsHtg();
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mrwr6RVhe4ro4DGAiJtHeXYZuaYf3tWUD7XIw7JKU();
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mDidGHxQUoxIuyrCIB9B0EFl5MGLzjoFQW6ThKxFm();
            _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz moCWVfbYakKQq7DzobY7rWx5fTJ5SNueTnH6R9OE0();
            void mPu4OZmYrXD70wkPHoILuXI9mU5Rl9gYS3yb79sdX(_MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR size);
            void mxnCNYh34tuS9KfumNtg1A7jPaAxAOL1n7pPW6zRq(_MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR pos);
            virtual int m4jCennAXbjlLVw5t3fMhvKrtbgDPUR0qnY7hwXO9();
        };
    }
}