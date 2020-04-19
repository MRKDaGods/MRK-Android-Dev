#pragma once

#include "math/Vector2.h"
#include "MRKCommon.h"

namespace MRK
{
    enum class MRKTouchEventType
    {
        Down = 0,
        Up = 1,
        Drag = 2,
    };

    struct MRKTouchEvent
    {
    private:
        static _MATH Vector2 ms_LastMousePosition;

        _MATH Vector2 m_MousePosition;
        MRKTouchEventType m_Type;
    public:
        static void Clean();

        MRKTouchEvent(int x, int y, MRKTouchEventType type);
        _MATH Vector2 MousePosition();
        _MATH Vector2 Delta();
        MRKTouchEventType Type();
        void Consume();
    };

    inline _MATH Vector2 MRKTouchEvent::ms_LastMousePosition = _MATH Vector2::Zero;

    inline MRKTouchEvent::MRKTouchEvent(int x, int y, MRKTouchEventType type)
    {
        m_MousePosition = _MATH Vector2(x, y);
        m_Type = type;
        if (ms_LastMousePosition == _MATH Vector2::Zero)
            ms_LastMousePosition = m_MousePosition;
    }

    inline _MATH Vector2 MRKTouchEvent::MousePosition()
    {
        return m_MousePosition;
    }

    inline _MATH Vector2 MRKTouchEvent::Delta()
    {
        return m_MousePosition - ms_LastMousePosition;
    }

    inline MRKTouchEventType MRKTouchEvent::Type()
    {
        return m_Type;
    }

    inline void MRKTouchEvent::Consume()
    {
        ms_LastMousePosition = m_MousePosition;
    }

    inline void MRKTouchEvent::Clean()
    {
        ms_LastMousePosition = _MATH Vector2::Zero;
    }
}