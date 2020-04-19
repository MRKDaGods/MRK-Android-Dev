#pragma once

#include "../mrkui/MRKUI.h"

#define MRK_COLOR_RAINBOW_COUNT 6

namespace MRK
{
    struct MRKColor
    {
    private:
        int m_R;
        int m_G;
        int m_B;
        int m_A;
        bool m__G;
    public:
        static MRKColor Black;
        static MRKColor White;
        static MRKColor Gradient;

        static MRKColor *Rainbow;
        static MRKColor *InvRainbow;

        static MRKColor Random();
        static MRKColor Lerp(MRKColor a, MRKColor b, float t);

        MRKColor(bool grad = false);

        MRKColor(float r, float g, float b, float a);

        MRKColor(int r, int g, int b, int a);

        MRKColor(int intensity, int a);

        int R();

        int G();

        int B();

        int A();

        float RF();
        float GF();
        float BF();
        float AF();

        bool &_G();
    };

    MRKUIcolor MRKToMRKUIColor(MRKColor MRKColor);

    MRKUIcolor operator&(MRKColor MRKColor);

    MRKUIcolor operator!(MRKColor MRKColor);

    bool operator ==(MRKColor rhf, MRKColor lfh);

    class ColorModifierGradient
    {
    private:
        unsigned int m_Alloc;
        MRKColor **m_Colors;
        MRKColor **m_Targets;
        float **m_Deltas;
        MRKColor m_PrevTarget;
        unsigned int m_Idx;

    public:
        ColorModifierGradient(unsigned int alloc);
        void Update();
        MRKColor GetColor(unsigned int _, unsigned int __);
    };
}