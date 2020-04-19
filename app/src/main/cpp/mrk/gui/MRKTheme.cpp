 #include "MRKTheme.h"
#include "../MRKLog.h"

namespace MRK
{
    namespace GUI
    {
        MRKTheme::MRKTheme(MRKUIcontext *context)
        {
            StandardFontSize = 16;
            ButtonFontSize = 20;
            TextBoxFontSize = 20;
            IconScale = 0.77f;

            WindowCornerRadius = 3;
            WindowHeaderHeight = 30;
            WindowDropShadowSize = 10;
            ButtonCornerRadius = 2;
            TabBorderWidth = 0.75f;
            TabInnerMargin = 5;
            TabMinButtonWidth = 20;
            TabMaxButtonWidth = 160;
            TabControlWidth = 20;
            TabButtonHorizontalPadding = 10;
            TabButtonVerticalPadding = 2;

            DropShadow = MRKColor(0, 128);
            Transparent = MRKColor(0, 0);
            BorderDark = MRKColor(29, 255);
            BorderLight = MRKColor(92, 255);
            BorderMedium = MRKColor(35, 255);
            TextColor = MRKColor(255, 160);
            DisabledTextColor = MRKColor(255, 80);
            TextColorShadow = MRKColor(0, 160);
            IconColor = TextColor;

            ButtonGradientTopFocused = MRKColor(64, 255);
            ButtonGradientBotFocused = MRKColor(48, 255);
            ButtonGradientTopUnfocused = MRKColor(74, 255);
            ButtonGradientBotUnfocused = MRKColor(58, 255);
            ButtonGradientTopPushed = MRKColor(41, 255);
            ButtonGradientBotPushed = MRKColor(29, 255);

            /* Window-related */
            WindowFillUnfocused = MRKColor(43, 230);
            WindowFillFocused = MRKColor(28, 30, 34, 192); //MRKColor(45, 230);
            WindowTitleUnfocused = MRKColor(220, 160);
            WindowTitleFocused = MRKColor(255, 190);

            WindowHeaderGradientTop = ButtonGradientTopUnfocused;
            WindowHeaderGradientBot = ButtonGradientBotUnfocused;
            WindowHeaderSepTop = BorderLight;
            WindowHeaderSepBot = BorderDark;

            WindowPopup = MRKColor(50, 255);
            WindowPopupTransparent = MRKColor(50, 0);

            CheckBoxIcon = ENTYPO_ICON_CHECK;
            MessageInformationIcon = ENTYPO_ICON_INFO_WITH_CIRCLE;
            MessageQuestionIcon = ENTYPO_ICON_HELP_WITH_CIRCLE;
            MessageWarningIcon = ENTYPO_ICON_WARNING;
            MessageAltButtonIcon = ENTYPO_ICON_CIRCLE_WITH_CROSS;
            MessagePrimaryButtonIcon = ENTYPO_ICON_CHECK;
            PopupChevronRightIcon = ENTYPO_ICON_CHEVRON_RIGHT;
            PopupChevronLeftIcon = ENTYPO_ICON_CHEVRON_LEFT;
            TabHeaderLeftIcon = ENTYPO_ICON_ARROW_BOLD_LEFT;
            TabHeaderRightIcon = ENTYPO_ICON_ARROW_BOLD_RIGHT;
            TextBoxUpIcon = ENTYPO_ICON_CHEVRON_UP;
            TextBoxDownIcon = ENTYPO_ICON_CHEVRON_DOWN;
            FontNormal = MRKUICreateFontMem(context, "sans", roboto_regular_ttf,
                                          roboto_regular_ttf_size, 0);
            FontBold = MRKUICreateFontMem(context, "sans-bold", roboto_bold_ttf,
                                        roboto_bold_ttf_size, 0);
            FontIcons = MRKUICreateFontMem(context, "icons", entypo_ttf,
                                         entypo_ttf_size, 0);
            FontCustom_seasrn = MRKUICreateFontMem(context, "seasrn", seasrn___ttf,
                                                 seasrn___ttf_size, 0);
            FontExo2Bold = MRKUICreateFontMem(context, "exo2bold", exo2bold_ttf, exo2bold_ttf_length,
                                            0);
            FontExo2Regular = MRKUICreateFontMem(context, "exo2regular", exo2regular_ttf, exo2regular_ttf_length, 0);
            FontLBF = MRKUICreateFontMem(context, "lbf", lbf_ttf, lbf_ttf_length, 0);
            if (FontNormal == -1 || FontBold == -1 || FontIcons == -1 || FontCustom_seasrn == -1 ||
                FontExo2Bold == -1 || FontExo2Regular == -1 || FontLBF == -1)
                MRKLog(MRK_LOGTYPE_ERROR, MRK_SENDER_NATIVE, "Cannot load fonts");
        }
    }
}