#include "MRKGuiBaseWindow.h"
#include "MRKDisplay.h"

namespace MRK
{
    namespace GUI
    {
        MRKGuiBaseWindow::MRKGuiBaseWindow(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect, _STD string title) :
                MRKGuiBaseWidget(parent, anchor, rect)
        {
            m_Title = title;
        }

        void MRKGuiBaseWindow::Draw(MRKUIcontext *context)
        {
            int ds = m_Theme->WindowDropShadowSize;
            int cr = m_Theme->WindowCornerRadius;
            int hh = m_Theme->WindowHeaderHeight;

            /* Draw window */
            MRKUISave(context);
            MRKUIBeginPath(context);
            MRKUIRoundedRect(context, Position().X(), Position().Y(), m_Size.X(), m_Size.Y(), cr);

            MRKUIFillColor(context, m_Focused ? &m_Theme->WindowFillFocused
                                          : &m_Theme->WindowFillUnfocused);
            MRKUIFill(context);


            /* Draw a drop shadow */
            MRKUIpaint shadowPaint = MRKUIBoxGradient(
                    context, Position().X(), Position().Y(), m_Size.X(), m_Size.Y(), cr*2, ds*2,
                    &m_Theme->DropShadow, &m_Theme->Transparent);

            MRKUISave(context);
            MRKUIResetScissor(context);
            MRKUIBeginPath(context);
            MRKUIRect(context, Position().X()-ds,Position().Y()-ds, m_Size.X()+2*ds, m_Size.Y()+2*ds);
            MRKUIRoundedRect(context, Position().X(), Position().Y(), m_Size.X(), m_Size.Y(), cr);
            MRKUIPathWinding(context, MRKUI_HOLE);
            MRKUIFillPaint(context, shadowPaint);
            MRKUIFill(context);
            MRKUIRestore(context);

            if (!m_Title.empty()) {
                /* Draw header */
                MRKUIpaint headerPaint = MRKUILinearGradient(
                        context, Position().X(), Position().Y(), Position().X(),
                        Position().Y() + hh,
                        &m_Theme->WindowHeaderGradientTop,
                        &m_Theme->WindowHeaderGradientBot);

                MRKUIBeginPath(context);
                MRKUIRoundedRect(context, Position().X(), Position().Y(), m_Size.X(), hh, cr);

                MRKUIFillPaint(context, headerPaint);
                MRKUIFill(context);

                MRKUIBeginPath(context);
                MRKUIRoundedRect(context, Position().X(), Position().Y(), m_Size.X(), hh, cr);
                MRKUIStrokeColor(context, &m_Theme->WindowHeaderSepTop);

                MRKUISave(context);
                MRKUIIntersectScissor(context, Position().X(), Position().Y(), m_Size.X(), 0.5f);
                MRKUIStroke(context);
                MRKUIRestore(context);

                MRKUIBeginPath(context);
                MRKUIMoveTo(context, Position().X() + 0.5f, Position().Y() + hh - 1.5f);
                MRKUILineTo(context, Position().X() + m_Size.X() - 0.5f, Position().Y() + hh - 1.5);
                MRKUIStrokeColor(context, &m_Theme->WindowHeaderSepBot);
                MRKUIStroke(context);

                MRKUIFontSize(context, _UTILITY CalculateRelativeFont(30.0f));
                MRKUIFontFace(context, "sans-bold");
                MRKUITextAlign(context, MRKUI_ALIGN_CENTER | MRKUI_ALIGN_MIDDLE);

                MRKUIFontBlur(context, 2);
                MRKUIFillColor(context, &m_Theme->DropShadow);
                MRKUIText(context, Position().X() + m_Size.X() / 2,
                        Position().Y() + hh / 2, m_Title.c_str(), nullptr);

                MRKUIFontBlur(context, 0);
                MRKUIFillColor(context, m_Focused ? &m_Theme->WindowTitleFocused
                                           : &m_Theme->WindowTitleUnfocused);
                MRKUIText(context, Position().X() + m_Size.X() / 2, Position().Y() + hh / 2 - 1,
                        m_Title.c_str(), nullptr);
            }

            MRKUIRestore(context);
        }

        bool MRKGuiBaseWindow::HandleTouchEvent(MRKTouchEvent &event)
        {
            if (MRKGuiBaseWidget::HandleTouchEvent(event))
                return false;
            switch (event.Type())
            {
                case MRKTouchEventType::Down:
                    if (m_Draggable)
                        m_Drag = true;
                    break;
                case MRKTouchEventType::Drag:
                    if (m_Drag)
                    {
                        m_Position += event.Delta();
                        DisplayInfo *displayInfo = MRKDisplay::RenderingDisplay->Info();
                        m_Position = _MATH Vector2(_MATH MRKMath::Clamp(m_Position.X(), 0.f, (float)displayInfo->Width - m_Size.X()),
                            _MATH MRKMath::Clamp(m_Position.Y(), 0.f, (float)displayInfo->Height - m_Size.Y()));
                        event.Consume();
                        NotifyPositionChanged();
                    }
                    break;
                case MRKTouchEventType::Up:
                    m_Drag = false;
                    break;
            }
            return true;
        }

        void MRKGuiBaseWindow::SetDraggable(bool drag)
        {
            m_Draggable = drag;
        }
    }
}