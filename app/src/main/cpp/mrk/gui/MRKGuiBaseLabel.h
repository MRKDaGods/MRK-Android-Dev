#pragma once

#include "MRKGuiBaseWidget.h"
#include "MRKFont.h"
#include "../MRKColor.h"

namespace MRK
{
    namespace GUI
    {
        enum MRKLabelFlags
        {
            None = 0,
            Bold = 1,
            Italic = 2,
            DropShadow = 4,
            Extrude = 8,
            Strikethrough = 16,
            Gradient = 32
        };

        enum MRKLabelAlignment
        {
            MRK_ALIGN_LEFT = 1,
            MRK_ALIGN_CENTER = 2,
            MRK_ALIGN_RIGHT = 4,
            MRK_ALIGN_TOP = 8,
            MRK_ALIGN_MIDDLE = 16,
            MRK_ALIGN_BOTTOM = 32,
            MRK_ALIGN_BASELINE = 64
        };

        struct LabelInitOptions : public WidgetInitOptions
        {
            _STD string Text;
            int FontSize;
            MRKLabelAlignment Alignment;
            MRKFont *Font;
            MRKLabelFlags LabelFlags;
        };

        class MRKGuiBaseLabel : public MRKGuiBaseWidget
        {
        private:
            MRKFont *m_Font;
            _STD string m_Text;
            int m_FontSize;
            MRKColor m_Color;
            MRKLabelFlags m_Flags;
            MRKLabelAlignment m_Alignment;
        public:
            MRKGuiBaseLabel(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect,
                            _STD string text, int fontSize = 0, MRKLabelAlignment alignment = MRK_ALIGN_LEFT,
                            MRKFont *font = MRKFont::Exo2Regular,
                            MRKLabelFlags flags = MRKLabelFlags::None);
            void Draw(MRKUIcontext *context) override;
            void SetTheme(MRKTheme *theme) override;
            void SetText(_STD string text);
            void ReInit(WidgetInitOptions options) override;
            _STD string GetText();
        };
    }
}