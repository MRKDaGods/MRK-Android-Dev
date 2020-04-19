#pragma once

#include <array>
#include <string>

#include "../MRKCommon.h"
#include "../math/Vector3.h"
#include "Concat.hpp"

namespace MRK
{
    namespace Utils
    {
        _STD array<char, 8> UTF8(int c);
        void SetLocalResolution(float width, float height);
        float CalculateRelativeHeight(float fhdPlus);
        float CalculateRelativeWidth(float fhdPlus);
        float CalculateRelativeFont(float size);
        float CalculateInverseHeight(float relative);
        float CalculateInverseWidth(float relative);
        _STD string ResolutionString();
        _STD string ModifiersString();
        _STD string FontModifierString();
        char *AllocateFile(const char *path);
        _STD string Vector3_ToString(_MATH Vector3 vector3);
    }
}