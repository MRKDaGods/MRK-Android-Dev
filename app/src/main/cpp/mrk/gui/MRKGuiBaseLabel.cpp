#include <android/log.h>
#include "MRKGuiBaseLabel.h"

namespace MRK
{
    namespace GUI
    {
        MRKGuiBaseLabel::MRKGuiBaseLabel(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect,
                                         _STD string text, int fontSize, MRKLabelAlignment alignment,
                                         MRKFont *font,
                                         MRKLabelFlags flags) : MRKGuiBaseWidget(parent, anchor, rect)
        {
            m_Font = font;
            m_Text = text;
            m_Flags = flags;
            m_Alignment = alignment;
            if (m_Theme) {
                m_Color = m_Theme->TextColor;
                m_FontSize = m_Theme->StandardFontSize;
            }
            if (fontSize > 0)
                m_FontSize = fontSize;
        }

        void MRKGuiBaseLabel::SetTheme(MRKTheme *theme)
        {
            MRKGuiBaseWidget::SetTheme(theme);
            if (m_Theme) {
                m_FontSize = m_Theme->StandardFontSize;
                m_Color = m_Theme->TextColor;
            }
        }

        void MRKGuiBaseLabel::Draw(MRKUIcontext *context)
        {
            MRKUIFontFace(context, m_Font->FontFaceStr);
            MRKUIFontSize(context, _UTILITY CalculateRelativeFont(m_FontSize));
            MRKUIFillColor(context, &m_Color);
            MRKUITextAlign(context, m_Alignment);
            float xOffset = 0.f;
            if ((m_Alignment & MRKLabelAlignment::MRK_ALIGN_CENTER))
                xOffset = m_Size.X() / 2.f - MRKUITextBounds(context, 0.f, 0.f, m_Text.c_str(), 0, 0) / 4.f;
            MRKUIText(context, Position().X() + xOffset, Position().Y() + m_Size.Y() * 0.5f, m_Text.c_str(), nullptr);
            if ((m_Flags & MRKLabelFlags::DropShadow) != 0)
            {
                MRKUIFillColor(context, MRKToMRKUIColor(m_Theme->DropShadow));
                MRKUIText(context, Position().X() + 2 + xOffset, Position().Y() + 2 + m_Size.Y() * 0.5f, m_Text.c_str(), nullptr);
            }
        }

        void MRKGuiBaseLabel::SetText(_STD string text)
        {
            m_Text = text;
        }

        void MRKGuiBaseLabel::ReInit(WidgetInitOptions options)
        {
            MRKGuiBaseWidget::ReInit(options);
            LabelInitOptions loptions = *(LabelInitOptions*)&options;
            m_Font = loptions.Font;
            m_Text = loptions.Text;
            m_Flags = loptions.LabelFlags;
            m_Alignment = loptions.Alignment;
            if (m_Theme) {
                m_Color = m_Theme->TextColor;
                m_FontSize = m_Theme->StandardFontSize;
            }
            if (loptions.FontSize > 0)
                m_FontSize = loptions.FontSize;
        }

        _STD string MRKGuiBaseLabel::GetText()
        {
            return m_Text;
        }
    }
}