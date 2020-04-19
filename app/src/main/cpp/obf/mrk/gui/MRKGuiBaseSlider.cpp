#include <cmath>

#include "MRKGuiBaseSlider.h"

namespace MRK
{
    namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
    {

        m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt(mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf *parent, MRKAnchor anchor,
                                           _MATH m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz rect, float min, float max)
                : mf5j4d4QTc453JlK5pU2pmtmWJpy6bAnssHtxJsjf(parent, anchor, rect),
                  mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE(0.f, 1.f),
                  msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1(0.f, 0.f), mX83A6nECP9b2bIl3IQOfyRUyPJg4Dg0zIuHGPVxN(0.f, 1.f)
        {
            mAL1X5ce1PquK3XzvUmseHHD20R2ZABlc88itFTF8 = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 80, 80, 70);
        }

        float m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::mDOGVATBpZgxwQAdW3VczLS8xxQFqxDnlcR603YTv()
        {
            return mADPzC4p1ApTNjGXQUY7YepH5QaNz7ru2hRjUptzI * (mX83A6nECP9b2bIl3IQOfyRUyPJg4Dg0zIuHGPVxN.second - mX83A6nECP9b2bIl3IQOfyRUyPJg4Dg0zIuHGPVxN.first) + mX83A6nECP9b2bIl3IQOfyRUyPJg4Dg0zIuHGPVxN.first;
        }

        void m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::mXPee6OwaQmBifzVLGqjWFERnZDxrFM2yrIWWQJaD(my0yvw2Lk9PuEED3qmYBLV3K16gEZN6xs3x2W7EVx *context)
        {
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR center = mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6() + mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC * 0.5f;
            float kr = (int) (mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() * 0.4f), kshadow = 3;
            float startX = kr + kshadow + mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14();
            float widthX = mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - 2 * (kr + kshadow);
            float bh = 20.f;
            _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w(startX + (mADPzC4p1ApTNjGXQUY7YepH5QaNz7ru2hRjUptzI - mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.first) /
                                           (mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.second - mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.first) * widthX,
                                  center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + 0.5f);

            m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ bg = mdyvG2rNfeGQixvCtRbnCNlhHLX7ozeMWHpAmvGwv(
                    context, startX, center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - bh / 2.f + 1, widthX, bh, bh / 2.f, bh / 2.f,
                    &mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(100, mdZNRiARXGUdjPW07vWus5CE4DsFOkdB4zgGqB71x ? 32 : 10),
                    &mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(100, mdZNRiARXGUdjPW07vWus5CE4DsFOkdB4zgGqB71x ? 128 : 210));

            m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(context);
            mfEKIaL94HRGW1PVm6mFSruo4HDpunzmJoIspWRcu(context, startX, center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - bh / 2.f + 1, widthX, bh, 2);
            mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY(context, bg);
            mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(context);

            if (msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1.second != msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1.first)
            {
                m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(context);
                mfEKIaL94HRGW1PVm6mFSruo4HDpunzmJoIspWRcu(context, startX + msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1.first * mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(),
                               center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - kshadow + 1,
                               widthX *
                               (msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1.second - msZdsrby6XuOmt6DGH9scJ1JQJp9Tv4PNhYfMuTX1.first),
                               kshadow * 2, 2);
                mAHZCgiUiBLU8QKhJI72eKDqcmhASKdOOw9NUPTcS(context, &mAL1X5ce1PquK3XzvUmseHHD20R2ZABlc88itFTF8);
                mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(context);
            }

            m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ knobShadow =
                    m0LFjxsxkBL5djdSrTBFTbHUtDq0oaTge4L5cfTTJ(context, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), kr - kshadow,
                                      kr + kshadow, &mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 64), &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mGOpc8pSnMJVxf7T2OeQgKfS3Gy22WmKjI3HLVgjq);

            m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(context);
            mbdzVdcmDPpti0WQVy5cqYRzWcIAY8juY3gINMaKR(context, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - kr - 5, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - kr - 5, kr * 2 + 10,
                    kr * 2 + 10 + kshadow);
            mHFyOk07XkLTtFw0zawwr10sM43Bn57rxgfN7QgDK(context, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), kr);
            mMpOiLjNtM3NKwGDIVibdVvuR4j5kOSi2F4HtykIa(context, MRKUI_HOLE);
            mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY(context, knobShadow);
            mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(context);

            m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ knob = mBOlgW8laJBK8LsBl4rKj12wJoIXDAWuhVsRnv1qn(context,
                                              mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - kr, mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(),
                                              center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + kr,
                                              &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mQgM30csssPM9LIjK4EFQMhcNvc4qHdSx6fhreeju, &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mBgqJbVJhmmNy8vPqPMxc2x86lSKWX0PvRhi4ScFQ);
            m1S7NYdr2N4g0dVCDZQDZBZBFM7Ygrwi5kinjOoeJ knobReverse = mBOlgW8laJBK8LsBl4rKj12wJoIXDAWuhVsRnv1qn(context,
                                                     mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - kr,
                                                     mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), center.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + kr,
                                                     &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mBgqJbVJhmmNy8vPqPMxc2x86lSKWX0PvRhi4ScFQ,
                                                     &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mQgM30csssPM9LIjK4EFQMhcNvc4qHdSx6fhreeju);

            m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(context);
            mHFyOk07XkLTtFw0zawwr10sM43Bn57rxgfN7QgDK(context, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), kr);
            m04M6uiH0JLlLn2jInACI76VOPXadkfCAWk3Y2RjR(context, &mXhCOkGHHk2CfobIQt8ckmqqIjBEmqIKv86zbBK9X->mPVbkrnD4ioC9BToEttoRnJ84gr7bKAHlVnrrSYzd);
            mVmOmVC8TLhyNk3o8xlxMxnqfy1TqKQo5hfsWk5pY(context, knob);
            m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX(context);
            mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(context);
            m9836F2a7CCWfCQwr0cgITUCi4KQ5tQxKU9yyjDtH(context);
            mHFyOk07XkLTtFw0zawwr10sM43Bn57rxgfN7QgDK(context, mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), mglIyHH317LV9EhKRpyjiHUV68pOPJyD3uBzOGG3w.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), kr / 2);
            mAHZCgiUiBLU8QKhJI72eKDqcmhASKdOOw9NUPTcS(context, &mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(150, mdZNRiARXGUdjPW07vWus5CE4DsFOkdB4zgGqB71x ? 255 : 100));
            mAaX49jkqFd3E9cZ65v4d8SrP4XgLDYnUWxkzc3K7(context, knobReverse);
            m6Fwce4JwU94qoD0dQjI47z2xJraMzqa2xVTwc0LX(context);
            mO3ajcNkMnrHTUymTAtaM9sHWGSxrnKRHXJPsZXve(context);
        }

        bool m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::mIV0igL3AOWNzMxThbbR0FhPNGpMBlBoVNGnl7UO6(mYJIpIJflgU0wmUiBglo5Jw2pgMsgxHinINndYT8C &event)
        {
            if (!mdZNRiARXGUdjPW07vWus5CE4DsFOkdB4zgGqB71x)
                return true;

            const float kr = (int) (mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() * 0.4f), kshadow = 3;
            const float startX = kr + kshadow + mxPWtV10Gl6mHt8RJpKlZWbOr84Gzlbs4N3GVRSb6().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - 1;
            const float widthX = mZKtapmHN2SWOhcKMbuyHbLYabyludnmaJJjUo9EC.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - 2 * (kr + kshadow);
            float value = (event.menHpOjyreg9sEpVaHTn1n3ojqez88faIusetCQFC().mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - startX) / widthX;
            value = value * (mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.second - mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.first) + mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.first;
            mADPzC4p1ApTNjGXQUY7YepH5QaNz7ru2hRjUptzI = _STD min(_STD max(value, mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.first), mZsQEYnXgguK8gSBlrb6A1nyKHBMxsLgQx2D5e2PE.second);
            if (m31la3EvxTcSUu6wuVlilKIt338vgZZ1mIgkMcg6W)
                m31la3EvxTcSUu6wuVlilKIt338vgZZ1mIgkMcg6W(mDOGVATBpZgxwQAdW3VczLS8xxQFqxDnlcR603YTv());
            if (event.mJw6LMY7RT6uveK5bYg9kvu8rdGPNHmrnzAzOAir0() == mlf9SjSTCkTlATQXJCmOiXzArXZZJ14efg5xRKkkJ::Up && mZ52e56gBTionhSqKtmrVvQaTkn7nhUuslpwIed1b)
                mZ52e56gBTionhSqKtmrVvQaTkn7nhUuslpwIed1b(mDOGVATBpZgxwQAdW3VczLS8xxQFqxDnlcR603YTv());
            return true;
        }

        void m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::m0DazfkcBiqZKKSGzv7nDkQJ7dI0DIbCreKCUgOH5(_STD function<void(float)> callback)
        {
            mZ52e56gBTionhSqKtmrVvQaTkn7nhUuslpwIed1b = callback;
        }

        void m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::m1iK0xnUk1pa3DkwqgnpOwfiJT0t5AZC6jVFEUolw(_STD function<void(float)> callback)
        {
            m31la3EvxTcSUu6wuVlilKIt338vgZZ1mIgkMcg6W = callback;
        }

        int m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::m4jCennAXbjlLVw5t3fMhvKrtbgDPUR0qnY7hwXO9()
        {
            return 2;
        }

        void m7z37oBYmaXoaZkVSjwUgZ9JNklsqZkC3wJg5EOrt::meWc3aq5PNUZQJQAsEVoR4qJ7cr3CUKpRmsLwtwcT(float min, float max)
        {
            mX83A6nECP9b2bIl3IQOfyRUyPJg4Dg0zIuHGPVxN = _STD make_pair(min, max);
        }
    }
}