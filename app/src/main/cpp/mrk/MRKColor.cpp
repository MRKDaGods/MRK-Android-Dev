#include "MRKColor.h"
#include "MRKApplication.h"
#include "math/MRKMath.h"
#include "MRKLog.h"

#include <cmath>

namespace MRK
{
    MRKColor MRKColor::Black = MRKColor(0, 255);
    MRKColor MRKColor::White = MRKColor(255, 255);
    MRKColor MRKColor::Gradient = MRKColor(true);
    MRKColor *MRKColor::Rainbow = new MRKColor[MRK_COLOR_RAINBOW_COUNT]{
        MRKColor(255, 0, 0, 255),
        MRKColor(255, 255, 0, 255),
        MRKColor(0, 255, 0, 255),
        MRKColor(0, 255, 255, 255),
        MRKColor(0, 0, 255, 255),
        MRKColor(255, 0, 255, 255)
    };
    MRKColor *MRKColor::InvRainbow = new MRKColor[MRK_COLOR_RAINBOW_COUNT]{
            MRKColor(255, 255, 0, 255),
            MRKColor(0, 255, 0, 255),
            MRKColor(0, 255, 255, 255),
            MRKColor(0, 0, 255, 255),
            MRKColor(255, 0, 255, 255),
            MRKColor(255, 0, 0, 255)
    };

    MRKUIcolor MRKToMRKUIColor(MRKColor MRKColor)
    {
        return MRKUIRGBA((unsigned char) MRKColor.R(), (unsigned char) MRKColor.G(),
                       (unsigned char) MRKColor.B(), (unsigned char) MRKColor.A());
    }

    MRKUIcolor operator&(MRKColor MRKColor)
    {
        return MRKToMRKUIColor(MRKColor);
    }

    MRKUIcolor operator!(MRKColor MRKColor)
    {
        MRKColor._G() = true;
        return MRKToMRKUIColor(MRKColor);
    }

    bool operator==(MRKColor rhf, MRKColor lhf)
    {
        return rhf.R() == lhf.R() && rhf.G() == lhf.G() && rhf.B() == lhf.B() && rhf.A() == lhf.A();
    }

    MRKColor::MRKColor(bool grad) : MRKColor(0, 0, 0, 255)
    {
        m__G = grad;
    }

    MRKColor::MRKColor(float r, float g, float b, float a)
    {
        m_R = r * 255.f;
        m_G = g * 255.f;
        m_B = b * 255.f;
        m_A = a * 255.f;
    }

    MRKColor::MRKColor(int r, int g, int b, int a)
    {
        m_R = r;
        m_G = g;
        m_B = b;
        m_A = a;
    }

    MRKColor::MRKColor(int intensity, int a)
    {
        m_R = intensity;
        m_G = intensity;
        m_B = intensity;
        m_A = a;
    }

    int MRKColor::R()
    {
        return m_R;
    }

    int MRKColor::G()
    {
        return m_G;
    }

    int MRKColor::B()
    {
        return m_B;
    }

    int MRKColor::A()
    {
        return m_A;
    }

    bool &MRKColor::_G()
    {
        return m__G;
    }

    float MRKColor::RF()
    {
        return m_R / 255.f;
    }

    float MRKColor::GF()
    {
        return m_G / 255.f;
    }

    float MRKColor::BF()
    {
        return m_B / 255.f;
    }

    float MRKColor::AF()
    {
        return m_A / 255.f;
    }

    MRKColor MRKColor::Random()
    {
        return MRKColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255);
    }

    MRKColor MRKColor::Lerp(MRKColor a, MRKColor b, float t)
    {
        t = _MATH MRKMath::Clamp(t, 0.f, 1.f);
        return MRKColor(a.RF() + ((b.RF() - a.RF()) * t), a.GF() + ((b.GF() - a.GF()) * t),
                        a.BF() + ((b.BF() - a.BF()) * t), a.AF() + ((b.AF() - a.AF()) * t));
    }

    ColorModifierGradient::ColorModifierGradient(unsigned int alloc)
    {
        m_Alloc = alloc;
        m_Colors = new MRKColor*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
            m_Colors[i] = new MRKColor[alloc / 2];
        m_Targets = new MRKColor*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
            m_Targets[i] = new MRKColor[alloc / 2];
        m_Deltas = new float*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
        {
            m_Deltas[i] = new float[alloc / 2];
            for (unsigned int j = 0; j < alloc / 2; j++)
                m_Deltas[i][j] = 0.f;
        }
        m_PrevTarget = MRKColor::Black;
        m_Idx = 0;
    }

    void ColorModifierGradient::Update()
    {
        for (unsigned int i = 0; i < m_Alloc; i++)
        {
            for (unsigned int j = 0; j < m_Alloc / 2; j++)
            {
                MRKColor *current = _STD addressof(m_Colors[i][j]); //& is overloaded :(
                MRKColor *target = _STD addressof(m_Targets[i][j]);
                float *delta = _STD addressof(m_Deltas[i][j]);
                *delta = fmod((*delta + MRKApplication::GetUIFramerateInfo()->Elapsed * 4.f),
                              (float) MRK_COLOR_RAINBOW_COUNT);
                int ilow = (int) floor(*delta);
                int ihigh = (ilow + 1) % MRK_COLOR_RAINBOW_COUNT;
                MRKColor *arr = i % 2 == 0 ? MRKColor::Rainbow : MRKColor::InvRainbow;
                *current = MRKColor::Lerp(arr[ilow], arr[ihigh], fmod(*delta, 1.f));
            }
        }
    }

    MRKColor ColorModifierGradient::GetColor(unsigned int _, unsigned int __)
    {
        return m_Colors[_][__];
    }
}