#pragma once

namespace MRK
{
    namespace Math
    {
        struct Vector3
        {
        private:
            float m_X;
            float m_Y;
            float m_Z;
        public:
            static Vector3 Zero;

            Vector3();
            Vector3(float x, float y, float z);
            float &X();
            float &Y();
            float &Z();
        };

        Vector3 operator +(Vector3 rhs, Vector3 lhs);
        Vector3 operator -(Vector3 rhs, Vector3 lhs);
        void operator +=(Vector3 &rhs, Vector3 lhs);
        Vector3 operator *(Vector3 rhs, float lhs);
        bool operator ==(Vector3 rhs, Vector3 lhs);
    }
}