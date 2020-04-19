#pragma once

#include <exception>

#include "../MRKColor.h"
#include "../MRKResources.h"
#include "Entypo.h"
#include "../MRKCommon.h"
#include "../../mrkui/MRKUI.h"

namespace MRK
{
    namespace GUI
    {
        class MRKTheme
        {
        public:
            MRKTheme(MRKUIcontext *context);
            int FontNormal;
            int FontBold;
            int FontIcons;
            int FontCustom_seasrn;
            int FontExo2Bold;
            int FontExo2Regular;
            int FontLBF;
            float IconScale;
            int StandardFontSize;
            int ButtonFontSize;
            int TextBoxFontSize;
            int WindowCornerRadius;
            int WindowHeaderHeight;
            int WindowDropShadowSize;
            int ButtonCornerRadius;
            float TabBorderWidth;
            int TabInnerMargin;
            int TabMinButtonWidth;
            int TabMaxButtonWidth;
            int TabControlWidth;
            int TabButtonHorizontalPadding;
            int TabButtonVerticalPadding;
            MRKColor DropShadow;
            MRKColor Transparent;
            MRKColor BorderDark;
            MRKColor BorderLight;
            MRKColor BorderMedium;
            MRKColor TextColor;
            MRKColor DisabledTextColor;
            MRKColor TextColorShadow;
            MRKColor IconColor;
            MRKColor ButtonGradientTopFocused;
            MRKColor ButtonGradientBotFocused;
            MRKColor ButtonGradientTopUnfocused;
            MRKColor ButtonGradientBotUnfocused;
            MRKColor ButtonGradientTopPushed;
            MRKColor ButtonGradientBotPushed;
            MRKColor WindowFillUnfocused;
            MRKColor WindowFillFocused;
            MRKColor WindowTitleUnfocused;
            MRKColor WindowTitleFocused;
            MRKColor WindowHeaderGradientTop;
            MRKColor WindowHeaderGradientBot;
            MRKColor WindowHeaderSepTop;
            MRKColor WindowHeaderSepBot;
            MRKColor WindowPopup;
            MRKColor WindowPopupTransparent;
            int CheckBoxIcon;
            int MessageInformationIcon;
            int MessageQuestionIcon;
            int MessageWarningIcon;
            int MessageAltButtonIcon;
            int MessagePrimaryButtonIcon;
            int PopupChevronRightIcon;
            int PopupChevronLeftIcon;
            int TabHeaderLeftIcon;
            int TabHeaderRightIcon;
            int TextBoxUpIcon;
            int TextBoxDownIcon;
        };
    }
}