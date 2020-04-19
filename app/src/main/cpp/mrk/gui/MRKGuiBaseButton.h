#pragma once

#include <string>
#include <functional>

#include "MRKGuiBaseWidget.h"
#include "../utils/MRKUtils.h"
#include "MRKFont.h"

namespace MRK {
    namespace GUI {
        enum IconPosition {
            Left,
            LeftCentered,
            RightCentered,
            Right
        };

        struct ButtonInitOptions : public WidgetInitOptions {
            _STD string Label;
            int FontSize;
            int Icon;
        };

        class MRKGuiBaseButton : public MRKGuiBaseWidget {
        protected:
            int m_Icon;
            _STD string m_Text;
            _STD function<void()> m_Callback;
            bool m_Down;
            MRKColor m_TextColor;
            MRKColor m_BackgroundColor;
            int m_FontSize;
            IconPosition m_IconPosition;
            bool m_ForceDown;
            MRKFont *m_Font;
        public:
            MRKGuiBaseButton(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect,
                             _STD string label, int fontsize = -1, int icon = 0);

            void Draw(MRKUIcontext *context) override;

            bool HandleTouchEvent(MRKTouchEvent &event) override;

            void SetCallback(_STD function<void()> callback);

            void SetBackgroundColor(MRKColor color);

            void SetTextColor(MRKColor color);

            void SetForceDown(bool down);

            void SetFontSize(int fontsize);

            void ReInit(WidgetInitOptions options) override;

            int Id() override;

            _STD string GetText();

            void SetText(_STD string text);

            void SetFont(MRKFont *font);
        };
    }
}