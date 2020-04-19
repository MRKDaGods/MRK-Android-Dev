#include <algorithm>

#include "MRKGuiBaseWidget.h"
#include "MRKDisplay.h"
#include "../MRKApplication.h"

namespace MRK
{
    namespace GUI
    {
        static int ms_GlobalIDs = -1;

        MRKGuiBaseWidget::MRKGuiBaseWidget(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect, MRKWidgetInitFlags flags) : m_Size(_MATH Vector2::Zero),
                                                                       m_FixedSize(_MATH Vector2::Zero),
                                                                       m_Position(_MATH Vector2::Zero),
                                                                       m_Focused(false),
                                                                       m_Interactable(true),
                                                                       m_Visible(true),
                                                                       m_Tooltip("")
        {
            m_Anchor = anchor;
            m_Parent = parent;
            if (parent)
            {
                parent->AddChild(this);
                SetTheme(parent->Theme());
            }
            m_Rect = rect;
            m_Position = _MATH Vector2(m_Rect.X(), m_Rect.Y());
            m_Size = _MATH Vector2(m_Rect.Width(), m_Rect.Height());
            if ((flags & MRK_WIDGET_INIT_FLAG_NO_ANCHOR) == 0)
                RecalculateAnchors();
            if ((flags & MRK_WIDGET_INIT_FLAG_NO_SIZE) == 0)
                RecalculateSize();
            if (m_Theme)
            {
                m_IconScale = m_Theme->IconScale;
            }
            m_Interactable = true;
        }

        bool MRKGuiBaseWidget::Visible()
        {
            return m_Visible;
        }

        void MRKGuiBaseWidget::SetVisible(bool visible)
        {
            m_Visible = visible;
            //for (MRKGuiBaseWidget *widget : m_Children)
            //    widget->SetVisible(visible);
        }

        _MATH Vector2 MRKGuiBaseWidget::Position()
        {
            if (m_Parent)
                return m_Parent->Position() + m_Position;
            return m_Position;
        }

        _MATH Rect MRKGuiBaseWidget::Rectangle()
        {
            return m_Rect;
        }

        void MRKGuiBaseWidget::Draw(MRKUIcontext *context)
        {
        }

        bool MRKGuiBaseWidget::HandleTouchEvent(MRKTouchEvent &event)
        {
            MRKGuiBaseWidget *widget = FindWidget(event.MousePosition());
            if (widget)
            {
                widget->HandleTouchEvent(event);
                return true;
            }
            return false;
        }

        void MRKGuiBaseWidget::SetTheme(MRKTheme *theme)
        {
            if (!theme)
                return;
            m_Theme = theme;
            for (MRKGuiBaseWidget *widget : m_Children)
                widget->SetTheme(theme);
        }

        MRKTheme* MRKGuiBaseWidget::Theme()
        {
            return m_Theme;
        }

        void MRKGuiBaseWidget::NotifyPositionChanged()
        {
            m_Rect = _MATH Rect(m_Position.X(), m_Position.Y(), m_Size.X(), m_Size.Y());
        }

        void MRKGuiBaseWidget::NotifyRectangleChanged()
        {
            m_Position = _MATH Vector2(m_Rect.X(), m_Rect.Y());
            m_Size = _MATH Vector2(m_Rect.Width(), m_Rect.Height());
        }

        void MRKGuiBaseWidget::NotifySizeChanged()
        {
            m_Rect = _MATH Rect(m_Position.X(), m_Position.Y(), m_Size.X(), m_Size.Y());
        }

        void MRKGuiBaseWidget::UpdateFocusState(bool focused)
        {
            m_Focused = focused;
            if (m_Children.size() > 0)
                for (MRKGuiBaseWidget *widget : m_Children)
                    widget->UpdateFocusState(focused);
        }

        bool MRKGuiBaseWidget::Focused()
        {
            return m_Focused;
        }

        void MRKGuiBaseWidget::AddChild(MRKGuiBaseWidget *widget)
        {
            if (typeid(MRKDisplay*) != typeid(this))
                m_Children.push_back(widget);
        }

        MRKGuiBaseWidget *MRKGuiBaseWidget::FindWidget(_MATH Vector2 pos)
        {
            for (MRKGuiBaseWidget *widget : m_Children)
            {
                if (!widget->Visible())
                    continue;
                if (widget->ScreenRect().Contains(pos))
                    return widget;
            }
            return 0;
        }

        _MATH Rect MRKGuiBaseWidget::ScreenRect()
        {
            return _MATH Rect(Position().X(), Position().Y(), m_Size.X(), m_Size.Y());
        }

        void MRKGuiBaseWidget::RecalculateAnchors()
        {
            float x = 0;
            float y = 0;
            if (m_Anchor == MRK_ANCHOR_NONE)
            {
                x = _UTILITY CalculateRelativeWidth(m_Position.X());
                y = _UTILITY CalculateRelativeHeight(m_Position.Y());
            }
            else
            {
                DisplayInfo *displayInfo = MRKApplication::GetUIDisplayInfo();
                if ((m_Anchor & MRK_ANCHOR_LEFT))
                {
                    x = _UTILITY CalculateRelativeWidth(m_Position.X());
                }
                else if ((m_Anchor & MRK_ANCHOR_CENTER))
                {
                    x = ((float) displayInfo->Width) / 2.f +
                        _UTILITY CalculateRelativeWidth(m_Position.X());
                }
                else if ((m_Anchor & MRK_ANCHOR_RIGHT))
                {
                    x = ((float) displayInfo->Width) -
                        _UTILITY CalculateRelativeWidth(m_Position.X());
                }
                if ((m_Anchor & MRK_ANCHOR_TOP))
                {
                    y = _UTILITY CalculateRelativeHeight(m_Position.Y());
                }
                else if ((m_Anchor & MRK_ANCHOR_MIDDLE))
                {
                    y = ((float) displayInfo->Height) / 2.f +
                        _UTILITY CalculateRelativeHeight(m_Position.Y());
                }
                else if ((m_Anchor & MRK_ANCHOR_BOTTOM))
                {
                    y = ((float) displayInfo->Height) -
                        _UTILITY CalculateRelativeHeight(m_Position.Y());
                }
            }
            m_Position = _MATH Vector2(x, y);
            NotifyPositionChanged();
        }

        void MRKGuiBaseWidget::RecalculateSize()
        {
            m_Size = _MATH Vector2(_UTILITY CalculateRelativeWidth(m_Size.X()),
                                   _UTILITY CalculateRelativeHeight(m_Size.Y()));
            NotifySizeChanged();
        }

        _MATH Vector2 MRKGuiBaseWidget::S9Plus_FHDPLUS_Position()
        {
            _MATH Vector2 relative = Position();
            return _MATH Vector2(_UTILITY CalculateInverseWidth(relative.X()), _UTILITY CalculateInverseHeight(relative.Y()));
        }

        _MATH Vector2 MRKGuiBaseWidget::S9Plus_FHDPLUS_Size()
        {
            return _MATH Vector2(_UTILITY CalculateInverseWidth(m_Size.X()), _UTILITY CalculateInverseHeight(m_Size.Y()));
        }

        _MATH Rect MRKGuiBaseWidget::S9Plus_FHDPLUS_Rect()
        {
            _MATH Vector2 pos = S9Plus_FHDPLUS_Position();
            _MATH Vector2 size = S9Plus_FHDPLUS_Size();
            return _MATH Rect(pos.X(), pos.Y(), size.X(), size.Y());
        }

        void MRKGuiBaseWidget::ReInit(WidgetInitOptions options)
        {
            m_Size = _MATH Vector2::Zero;
            m_FixedSize = _MATH Vector2::Zero;
            m_Position = _MATH Vector2::Zero;
            m_Focused = false;
            m_Interactable = true;
            m_Visible = true;
            m_Tooltip = "";
            m_Anchor = options.Anchor;
            m_Parent = options.Parent;
            if (m_Parent)
            {
                m_Parent->AddChild(this);
                SetTheme(m_Parent->Theme());
            }
            m_Rect = options.Rect;
            m_Position = _MATH Vector2(m_Rect.X(), m_Rect.Y());
            m_Size = _MATH Vector2(m_Rect.Width(), m_Rect.Height());
            if ((options.Flags & MRK_WIDGET_INIT_FLAG_NO_ANCHOR) == 0)
                RecalculateAnchors();
            if ((options.Flags & MRK_WIDGET_INIT_FLAG_NO_SIZE) == 0)
                RecalculateSize();
            if (m_Theme)
            {
                m_IconScale = m_Theme->IconScale;
            }
            m_Interactable = true;
        }

        MRKGuiBaseWidget::~MRKGuiBaseWidget() {
            if (m_Parent)
                m_Parent->m_Children.erase(
                        _STD remove(m_Parent->m_Children.begin(), m_Parent->m_Children.end(), this),
                        m_Parent->m_Children.end());
        }

        void MRKGuiBaseWidget::SetS9Plus_FHDPLUS_Size(_MATH Vector2 size)
        {
            m_Size = size;
            RecalculateSize();
        }

        void MRKGuiBaseWidget::SetS9Plus_FHDPLUS_Position(_MATH Vector2 pos)
        {
            m_Position = pos;
            RecalculateAnchors();
        }

        int MRKGuiBaseWidget::Id()
        {
            return -1;
        }
    }
}