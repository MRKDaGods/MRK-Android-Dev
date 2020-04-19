#include "MRKMath.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Rect.h"

namespace MRK
{
    namespace Math
    {
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR::micRgrwakd1iAo2xI4ZTssPMbmaHTUfYEVSNKCdJJ = m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(0.f, 0.f);

        int mGf6g1mAx7GKo2kXqOz48f6dQIuLlUZhSoiDvWkJ5::mSJi5DgfL6Oz62AYnDMSAboOd6C8hZ64nKWNw0fpq(int value, int min, int max)
        {
            return min > value ? min : value > max ? max : value;
        }

        float mGf6g1mAx7GKo2kXqOz48f6dQIuLlUZhSoiDvWkJ5::mSJi5DgfL6Oz62AYnDMSAboOd6C8hZ64nKWNw0fpq(float value, float min, float max)
        {
            return min > value ? min : value > max ? max : value;
        }

        uint32_t mGf6g1mAx7GKo2kXqOz48f6dQIuLlUZhSoiDvWkJ5::m6951Wm9QXE607QAtyFyZgoxjTxD9xRMaQbJ8CayL(int value)
        {
            return 0 > value ? value * -1 : value;
        }

        //m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR - float
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR::m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR() : m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(0.f, 0.f)
        {
        }
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR::m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y)
        {
            mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
            mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i = y;
        }
        float &m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR::mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14()
        {
            return mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn;
        }
        float &m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR::m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3()
        {
            return mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i;
        }
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR operator +(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR rhs, m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR lhs)
        {
            return m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() + lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3());
        }
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR operator -(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR rhs, m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR lhs)
        {
            return m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3());
        }
        void operator +=(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR &rhs, m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR lhs)
        {
            rhs = rhs + lhs;
        }
        bool operator ==(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR rhs, m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR lhs)
        {
            return rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() == lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() && rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() == lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3();
        }
        m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR operator *(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR rhs, float lhs)
        {
            return m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() * lhs, rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() * lhs);
        }

        //m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN - float
        m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN::m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN() : m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN(0.f, 0.f, 0.f)
        {
        }
        m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN::m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D)
        {
            mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
            mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i = y;
            mAmr3SUq5Xe2oY8GXKgxKvgplXGOwuyvdvdOB3hGe = m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
        }
        float &m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN::mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14()
        {
            return mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn;
        }
        float &m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN::m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3()
        {
            return mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i;
        }
        float &m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN::Z()
        {
            return mAmr3SUq5Xe2oY8GXKgxKvgplXGOwuyvdvdOB3hGe;
        }
        m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN operator +(m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN rhs, m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN lhs)
        {
            return m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() + lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), rhs.Z() + lhs.Z());
        }
        m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN operator -(m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN rhs, m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN lhs)
        {
            return m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() - lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14(), rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() - lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3(), rhs.Z() - lhs.Z());
        }
        void operator +=(m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN &rhs, m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN lhs)
        {
            rhs = rhs + lhs;
        }
        bool operator ==(m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN rhs, m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN lhs)
        {
            return rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() == lhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() && rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() == lhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() && rhs.Z() == lhs.Z();
        }
        m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN operator *(m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN rhs, float lhs)
        {
            return m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN(rhs.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() * lhs, rhs.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() * lhs, rhs.Z() * lhs);
        }

        //m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz
        m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz() : m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz(0.f, 0.f, 0.f, 0.f)
        {
        }
        m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h)
        {
            mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn = m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp;
            mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i = y;
            mz5xs4GsGJ2TPMeEm3yGSdxdE229uJoCkz11CzhT6 = w;
            mBudbBsLOmT7xA9C0YpbsSJm3a3uNmC1P1eY4mwGt = h;
        }
        float m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14()
        {
            return mzmeCCndJiMRZeW0hDm1Et76b5ds6cUCPyivXjCFn;
        }
        float m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3()
        {
            return mDZLKgzV31aiuZ80IHZZZs8BPDDfNhX6iD5CVu04i;
        }
        float m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::mwUAIZwLSJTjCuLehA8VPpTXGZwHncc219d7ruNzi()
        {
            return mz5xs4GsGJ2TPMeEm3yGSdxdE229uJoCkz11CzhT6;
        }
        float m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::mIaNvvhpxzdoORTDpylhlYCZ41HRqxpYRBn0g6JFn()
        {
            return mBudbBsLOmT7xA9C0YpbsSJm3a3uNmC1P1eY4mwGt;
        }
        bool m6EWrFAq3DW6rO5ColwCzRcAgNAkT9euT3PCHpeIz::m09rDLmDhjHn4NBuke0HXSoKi5TeOzuDuJ5f0SwGv(m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR point)
        {
            return point.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() >= mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() && point.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() <= mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14() + mwUAIZwLSJTjCuLehA8VPpTXGZwHncc219d7ruNzi() && point.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() >= m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3()
                   && point.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() <= m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3() + mIaNvvhpxzdoORTDpylhlYCZ41HRqxpYRBn0g6JFn();
        }
    }
}