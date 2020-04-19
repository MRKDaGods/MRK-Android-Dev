#include "MRKGuiBaseImageSelector.h"

namespace MRK
{
    namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
    {

        mSXeWw8UMxJXG2MgRsHANM0HeP2aBw4S6FV6UsdCb::mSXeWw8UMxJXG2MgRsHANM0HeP2aBw4S6FV6UsdCb(LMSGuiBaseWidget *parent, LMSAnchor anchor,
                                                         _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz rect, _STD vector<int> pictures)
                : LMSGuiBaseWidget(parent, anchor, rect)
        {
            mOG5YrFpEPxusQwZEYQXPgR5L6mfqwgAFfU9DmfM1 = pictures;
            mjpEzQDSzAATq3DfbXNkcvNeZPfdHA3RZfrun1wOq = 0;
        }

        void mSXeWw8UMxJXG2MgRsHANM0HeP2aBw4S6FV6UsdCb::mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD(NVGcontext *context)
        {
            float space = mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() / 10.f;
            float xOffset = space * 2.f;
            float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn = mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - (2.f * (space * 2.f) + (mOG5YrFpEPxusQwZEYQXPgR5L6mfqwgAFfU9DmfM1.size() - 1) * space);
            for (size_t i = 0; i < mOG5YrFpEPxusQwZEYQXPgR5L6mfqwgAFfU9DmfM1.size(); i++)
            {
                nvgBeginPath(context);
                if (i == mjpEzQDSzAATq3DfbXNkcvNeZPfdHA3RZfrun1wOq)
                {
                    NVGpaint shadowPaint = nvgBoxGradient(
                            context, mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), 6, 20,
                            &LMSColor::mVFxviKhn0pYE7O2WQsAqAQWPx8Q4rVF9chjhuZdb, &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mGOpc8pSnMJVxf7T2OeQgKfS3Gy22WmKjI3HLVgjq);
                    nvgSave(context);
                    nvgResetScissor(context);
                    nvgBeginPath(context);
                    nvgRect(context, mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - 20, mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - 20, mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() + 20,
                            mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + 20);
                    nvgRoundedRect(context, mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(),
                                   6);
                    nvgPathWinding(context, NVG_HOLE);
                    nvgFillPaint(context, shadowPaint);
                    nvgFill(context);
                    nvgRestore(context);
                }
            }
        }
    }
}