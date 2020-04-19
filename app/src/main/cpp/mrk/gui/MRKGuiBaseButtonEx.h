#pragma once

#include "MRKGuiBaseButton.h"

namespace MRK
{
    namespace GUI
    {
        class MRKGuiBaseButtonEx : public MRKGuiBaseButton
        {
        private:
            bool m_GradientBg;
            bool m_GradientText;
            ColorModifierGradient m_GradientModifier;
        public:
            MRKGuiBaseButtonEx(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect,
                               _STD string label, bool gBg, bool gT, int fontsize = -1,
                               int icon = 0);
            void Draw(MRKUIcontext *context) override;
        };
    }
}