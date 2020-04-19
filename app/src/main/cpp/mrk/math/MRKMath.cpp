#include "MRKMath.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Rect.h"

namespace MRK
{
    namespace Math
    {
        Vector2 Vector2::Zero = Vector2(0.f, 0.f);

        int MRKMath::Clamp(int value, int min, int max)
        {
            return min > value ? min : value > max ? max : value;
        }

        float MRKMath::Clamp(float value, float min, float max)
        {
            return min > value ? min : value > max ? max : value;
        }

        uint32_t MRKMath::UnSign(int value)
        {
            return 0 > value ? value * -1 : value;
        }

        //Vector2 - float
        Vector2::Vector2() : Vector2(0.f, 0.f)
        {
        }
        Vector2::Vector2(float x, float y)
        {
            m_X = x;
            m_Y = y;
        }
        float &Vector2::X()
        {
            return m_X;
        }
        float &Vector2::Y()
        {
            return m_Y;
        }
        Vector2 operator +(Vector2 rhs, Vector2 lhs)
        {
            return Vector2(rhs.X() + lhs.X(), rhs.Y() + lhs.Y());
        }
        Vector2 operator -(Vector2 rhs, Vector2 lhs)
        {
            return Vector2(rhs.X() - lhs.X(), rhs.Y() - lhs.Y());
        }
        void operator +=(Vector2 &rhs, Vector2 lhs)
        {
            rhs = rhs + lhs;
        }
        bool operator ==(Vector2 rhs, Vector2 lhs)
        {
            return rhs.X() == lhs.X() && rhs.Y() == lhs.Y();
        }
        Vector2 operator *(Vector2 rhs, float lhs)
        {
            return Vector2(rhs.X() * lhs, rhs.Y() * lhs);
        }

        //Vector3 - float
        Vector3::Vector3() : Vector3(0.f, 0.f, 0.f)
        {
        }
        Vector3::Vector3(float x, float y, float z)
        {
            m_X = x;
            m_Y = y;
            m_Z = z;
        }
        float &Vector3::X()
        {
            return m_X;
        }
        float &Vector3::Y()
        {
            return m_Y;
        }
        float &Vector3::Z()
        {
            return m_Z;
        }
        Vector3 operator +(Vector3 rhs, Vector3 lhs)
        {
            return Vector3(rhs.X() + lhs.X(), rhs.Y() + lhs.Y(), rhs.Z() + lhs.Z());
        }
        Vector3 operator -(Vector3 rhs, Vector3 lhs)
        {
            return Vector3(rhs.X() - lhs.X(), rhs.Y() - lhs.Y(), rhs.Z() - lhs.Z());
        }
        void operator +=(Vector3 &rhs, Vector3 lhs)
        {
            rhs = rhs + lhs;
        }
        bool operator ==(Vector3 rhs, Vector3 lhs)
        {
            return rhs.X() == lhs.X() && rhs.Y() == lhs.Y() && rhs.Z() == lhs.Z();
        }
        Vector3 operator *(Vector3 rhs, float lhs)
        {
            return Vector3(rhs.X() * lhs, rhs.Y() * lhs, rhs.Z() * lhs);
        }

        //Rect
        Rect::Rect() : Rect(0.f, 0.f, 0.f, 0.f)
        {
        }
        Rect::Rect(float x, float y, float w, float h)
        {
            m_X = x;
            m_Y = y;
            m_W = w;
            m_H = h;
        }
        float Rect::X()
        {
            return m_X;
        }
        float Rect::Y()
        {
            return m_Y;
        }
        float Rect::Width()
        {
            return m_W;
        }
        float Rect::Height()
        {
            return m_H;
        }
        bool Rect::Contains(Vector2 point)
        {
            return point.X() >= X() && point.X() <= X() + Width() && point.Y() >= Y()
                   && point.Y() <= Y() + Height();
        }
    }
}