#include "MRKGuiBaseButtonEx.h"

namespace MRK
{
    namespace GUI
    {

        MRKGuiBaseButtonEx::MRKGuiBaseButtonEx(MRKGuiBaseWidget *parent, MRKAnchor anchor,
                                               _MATH Rect rect, _STD string label, bool gBg,
                                               bool gT, int fontsize, int icon) : MRKGuiBaseButton(
                parent, anchor, rect, label, fontsize, icon), m_GradientModifier(2)
        {
            m_GradientBg = gBg;
            m_GradientText = gT;
        }

        void MRKGuiBaseButtonEx::Draw(MRKUIcontext *context)
        {
            if (m_GradientBg || m_GradientText)
                m_GradientModifier.Update();
            MRKUIcolor gradTop = m_GradientBg ? &m_GradientModifier.GetColor(0, 0)
                                            : &m_Theme->ButtonGradientTopUnfocused;
            MRKUIcolor gradBot = m_GradientBg ? &m_GradientModifier.GetColor(1, 0)
                                            : &m_Theme->ButtonGradientBotUnfocused;

            if (m_ForceDown || m_Down)
            {
                gradTop = &m_Theme->ButtonGradientTopPushed;
                gradBot = &m_Theme->ButtonGradientBotPushed;
            }

            MRKUIBeginPath(context);

            MRKUIRoundedRect(context, Position().X() + 1, Position().Y() + 1.0f, m_Size.X() - 2,
                           m_Size.Y() - 2, m_Theme->ButtonCornerRadius - 1);

            if (m_BackgroundColor.A())
            {
                MRKUIFillColor(context, &MRKColor(m_BackgroundColor.A(), 255));
                MRKUIFill(context);
                if (m_Down)
                {
                    gradTop.a = gradBot.a = 0.8f;
                }
                else
                {
                    double v = 1 - ((float) m_BackgroundColor.A()) / 255.f;
                    gradTop.a = gradBot.a = m_Interactable ? v : v * .5f + .5f;
                }
            }

            MRKUIpaint bg = MRKUILinearGradient(context, Position().X(), Position().Y(), Position().X(),
                                            Position().Y() + m_Size.Y(), gradTop, gradBot);

            MRKUIFillPaint(context, bg);
            MRKUIFill(context);

            MRKUIBeginPath(context);
            MRKUIStrokeWidth(context, 1.0f);
            MRKUIRoundedRect(context, Position().X() + 0.5f, Position().Y() + (m_Down ? 0.5f : 1.5f),
                           m_Size.X() - 1,
                           m_Size.Y() - 1 - (m_Down ? 0.0f : 1.0f), m_Theme->ButtonCornerRadius);
            MRKUIStrokeColor(context, &m_Theme->BorderLight);
            MRKUIStroke(context);

            MRKUIBeginPath(context);
            MRKUIRoundedRect(context, Position().X() + 0.5f, Position().Y() + 0.5f, m_Size.X() - 1,
                           m_Size.Y() - 2, m_Theme->ButtonCornerRadius);
            MRKUIStrokeColor(context, &m_Theme->BorderDark);
            MRKUIStroke(context);

            int fontSize = m_FontSize == -1 ? m_Theme->ButtonFontSize : m_FontSize;
            MRKUIFontSize(context, fontSize);
            MRKUIFontFace(context, m_Font ? m_Font->FontFaceStr : "sans-bold");
            float tw = MRKUITextBounds(context, 0, 0, m_Text.c_str(), nullptr, nullptr);

            _MATH Vector2 center = Position() + m_Size * 0.5f;
            _MATH Vector2 textPos(center.X() - tw * 0.5f, center.Y() - 1);
            MRKUIcolor textColor = m_TextColor.A() == 0 ? &m_Theme->TextColor : &m_TextColor;
            if (!m_Interactable)
                textColor = &m_Theme->DisabledTextColor;

            if (m_Icon)
            {
                auto icon = _UTILITY UTF8(m_Icon);

                float iw, ih = fontSize;
                if (1024 > m_Icon)
                {
                    ih *= m_IconScale;
                    MRKUIFontSize(context, ih);
                    MRKUIFontFace(context, "icons");
                    iw = MRKUITextBounds(context, 0, 0, icon.data(), nullptr, nullptr);
                }
                else
                {
                    int w, h;
                    ih *= 0.9f;
                    MRKUIImageSize(context, m_Icon, &w, &h);
                    iw = w * ih / h;
                }
                if (m_Text != "")
                    iw += m_Size.Y() * 0.15f;
                MRKUIFillColor(context, textColor);
                MRKUITextAlign(context, MRKUI_ALIGN_LEFT | MRKUI_ALIGN_MIDDLE);
                _MATH Vector2 iconPos = center;
                iconPos.Y() -= 1;

                if (m_IconPosition == IconPosition::LeftCentered)
                {
                    iconPos.X() -= (tw + iw) * 0.5f;
                    textPos.X() += iw * 0.5f;
                }
                else if (m_IconPosition == IconPosition::RightCentered)
                {
                    textPos.X() -= iw * 0.5f;
                    iconPos.X() += tw * 0.5f;
                }
                else if (m_IconPosition == IconPosition::Left)
                {
                    iconPos.X() = Position().X() + 8;
                }
                else if (m_IconPosition == IconPosition::Right)
                {
                    iconPos.X() = Position().X() + m_Size.X() - iw - 8;
                }

                if (1024 > m_Icon)
                {
                    MRKUIText(context, iconPos.X(), iconPos.Y() + 1, icon.data(), nullptr);
                }
                else
                {
                    MRKUIpaint imgPaint = MRKUIImagePattern(context,
                                                        iconPos.X(), iconPos.Y() - ih / 2, iw, ih,
                                                        0, m_Icon, m_Interactable ? 0.5f : 0.25f);
                    MRKUIFillPaint(context, imgPaint);
                    MRKUIFill(context);
                }
            }
            MRKUIFontSize(context, _UTILITY CalculateRelativeFont(fontSize));
            MRKUIFontFace(context, m_Font ? m_Font->FontFaceStr : "sans-bold");
            MRKUITextAlign(context, MRKUI_ALIGN_LEFT | MRKUI_ALIGN_MIDDLE);
            MRKUIFillColor(context, &m_Theme->TextColorShadow);
            MRKUIText(context, textPos.X(), textPos.Y(), m_Text.c_str(), nullptr);
            MRKUIFillColor(context, textColor);
            MRKUIText(context, textPos.X(), textPos.Y() + 1, m_Text.c_str(), nullptr);
        }
    }
}