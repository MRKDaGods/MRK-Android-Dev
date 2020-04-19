#pragma once

namespace MRK
{
    namespace Math
    {
        struct Vector2
        {
        private:
            float m_X;
            float m_Y;
        public:
            static Vector2 Zero;

            Vector2();
            Vector2(float x, float y);
            float &X();
            float &Y();
        };

        Vector2 operator +(Vector2 rhs, Vector2 lhs);
        Vector2 operator -(Vector2 rhs, Vector2 lhs);
        void operator +=(Vector2 &rhs, Vector2 lhs);
        Vector2 operator *(Vector2 rhs, float lhs);
        bool operator ==(Vector2 rhs, Vector2 lhs);
    }
}