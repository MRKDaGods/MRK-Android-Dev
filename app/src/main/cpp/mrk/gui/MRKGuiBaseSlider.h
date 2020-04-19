#pragma once

#include <functional>

#include "MRKGuiBaseWidget.h"

namespace MRK
{
    namespace GUI
    {
        class MRKGuiBaseSlider : public MRKGuiBaseWidget
        {
        private:
            _STD pair<float, float> m_Range;
            _STD pair<float, float> m_HighlightedRange;
            _STD pair<float, float> m_RealRange;
            float m_Value;
            MRKColor m_HighlightColor;
            _STD function<void(float)> m_OnValueChangedCallback;
            _STD function<void(float)> m_OnLiveValueChangedCallback;
        public:
            MRKGuiBaseSlider(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect, float min = -1,
                             float max = -1);
            float Value();
            void Draw(MRKUIcontext *context) override;
            bool HandleTouchEvent(MRKTouchEvent &event) override;
            void SetCallback(_STD function<void(float)> callback);
            void SetLiveCallback(_STD function<void(float)> callback);
            void SetRange(float min, float max);
            virtual int Id() override;
        };
    }
}