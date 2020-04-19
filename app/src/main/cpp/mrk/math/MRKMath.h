#pragma once

#include <cstdint>

namespace MRK
{
    namespace Math
    {
        class MRKMath
        {
        public:
            static int Clamp(int value, int min, int max);
            static float Clamp(float value, float min, float max);
            static uint32_t UnSign(int value);
        };
    }
}