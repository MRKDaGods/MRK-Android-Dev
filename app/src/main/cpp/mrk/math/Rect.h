#pragma once

#include "Vector2.h"

namespace MRK
{
    namespace Math
    {
        struct Rect
        {
        private:
            float m_X;
            float m_Y;
            float m_W;
            float m_H;
        public:
            Rect();
            Rect(float x, float y, float w, float h);
            float X();
            float Y();
            float Width();
            float Height();
            bool Contains(Vector2 point);
        };
    }
}