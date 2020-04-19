#include <cmath>

#include "MRKGuiBaseSlider.h"

namespace MRK {
    namespace GUI {

        MRKGuiBaseSlider::MRKGuiBaseSlider(MRKGuiBaseWidget *parent, MRKAnchor anchor,
                                           _MATH Rect rect, float min, float max)
                : MRKGuiBaseWidget(parent, anchor, rect),
                  m_Range(0.f, 1.f),
                  m_HighlightedRange(0.f, 0.f), m_RealRange(0.f, 1.f) {
            m_HighlightColor = MRKColor(255, 80, 80, 70);
        }

        float MRKGuiBaseSlider::Value() {
            return m_Value * (m_RealRange.second - m_RealRange.first) + m_RealRange.first;
        }

        void MRKGuiBaseSlider::Draw(MRKUIcontext *context) {
            _MATH Vector2 center = Position() + m_Size * 0.5f;
            float kr = (int) (m_Size.Y() * 0.4f), kshadow = 3;
            float startX = kr + kshadow + Position().X();
            float widthX = m_Size.X() - 2 * (kr + kshadow);
            float bh = 20.f;
            _MATH Vector2 knobPos(startX + (m_Value - m_Range.first) /
                                           (m_Range.second - m_Range.first) * widthX,
                                  center.Y() + 0.5f);

            MRKUIpaint bg = MRKUIBoxGradient(
                    context, startX, center.Y() - bh / 2.f + 1, widthX, bh, bh / 2.f, bh / 2.f,
                    &MRKColor(100, m_Interactable ? 32 : 10),
                    &MRKColor(100, m_Interactable ? 128 : 210));

            MRKUIBeginPath(context);
            MRKUIRoundedRect(context, startX, center.Y() - bh / 2.f + 1, widthX, bh, 2);
            MRKUIFillPaint(context, bg);
            MRKUIFill(context);

            if (m_HighlightedRange.second != m_HighlightedRange.first) {
                MRKUIBeginPath(context);
                MRKUIRoundedRect(context, startX + m_HighlightedRange.first * m_Size.X(),
                                 center.Y() - kshadow + 1,
                                 widthX *
                                 (m_HighlightedRange.second - m_HighlightedRange.first),
                                 kshadow * 2, 2);
                MRKUIFillColor(context, &m_HighlightColor);
                MRKUIFill(context);
            }

            MRKUIpaint knobShadow =
                    MRKUIRadialGradient(context, knobPos.X(), knobPos.Y(), kr - kshadow,
                                        kr + kshadow, &MRKColor(0, 64), &m_Theme->Transparent);

            MRKUIBeginPath(context);
            MRKUIRect(context, knobPos.X() - kr - 5, knobPos.Y() - kr - 5, kr * 2 + 10,
                      kr * 2 + 10 + kshadow);
            MRKUICircle(context, knobPos.X(), knobPos.Y(), kr);
            MRKUIPathWinding(context, MRKUI_HOLE);
            MRKUIFillPaint(context, knobShadow);
            MRKUIFill(context);

            MRKUIpaint knob = MRKUILinearGradient(context,
                                                  Position().X(), center.Y() - kr, Position().X(),
                                                  center.Y() + kr,
                                                  &m_Theme->BorderLight, &m_Theme->BorderMedium);
            MRKUIpaint knobReverse = MRKUILinearGradient(context,
                                                         Position().X(), center.Y() - kr,
                                                         Position().X(), center.Y() + kr,
                                                         &m_Theme->BorderMedium,
                                                         &m_Theme->BorderLight);

            MRKUIBeginPath(context);
            MRKUICircle(context, knobPos.X(), knobPos.Y(), kr);
            MRKUIStrokeColor(context, &m_Theme->BorderDark);
            MRKUIFillPaint(context, knob);
            MRKUIStroke(context);
            MRKUIFill(context);
            MRKUIBeginPath(context);
            MRKUICircle(context, knobPos.X(), knobPos.Y(), kr / 2);
            MRKUIFillColor(context, &MRKColor(150, m_Interactable ? 255 : 100));
            MRKUIStrokePaint(context, knobReverse);
            MRKUIStroke(context);
            MRKUIFill(context);
        }

        bool MRKGuiBaseSlider::HandleTouchEvent(MRKTouchEvent &event) {
            if (!m_Interactable)
                return true;

            const float kr = (int) (m_Size.Y() * 0.4f), kshadow = 3;
            const float startX = kr + kshadow + Position().X() - 1;
            const float widthX = m_Size.X() - 2 * (kr + kshadow);
            float value = (event.MousePosition().X() - startX) / widthX;
            value = value * (m_Range.second - m_Range.first) + m_Range.first;
            m_Value = _STD min(_STD max(value, m_Range.first), m_Range.second);
            if (m_OnLiveValueChangedCallback)
                m_OnLiveValueChangedCallback(Value());
            if (event.Type() == MRKTouchEventType::Up && m_OnValueChangedCallback)
                m_OnValueChangedCallback(Value());
            return true;
        }

        void MRKGuiBaseSlider::SetCallback(_STD function<void(float)> callback) {
            m_OnValueChangedCallback = callback;
        }

        void MRKGuiBaseSlider::SetLiveCallback(_STD function<void(float)> callback) {
            m_OnLiveValueChangedCallback = callback;
        }

        int MRKGuiBaseSlider::Id() {
            return 2;
        }

        void MRKGuiBaseSlider::SetRange(float min, float max) {
            m_RealRange = _STD make_pair(min, max);
        }
    }
}