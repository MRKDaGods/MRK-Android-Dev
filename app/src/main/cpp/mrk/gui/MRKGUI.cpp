#include "MRKGUI.h"

namespace MRK
{
    namespace GUI
    {
        MRKUIcontext *MRKGUI::ms_Context = 0;
        MRKColor MRKGUI::ms_DrawColor;

        void MRKGUI::StartFrame(MRKUIcontext *context)
        {
            ms_Context = context;
            MRKUIBeginPath(context);
        }

        void MRKGUI::EndFrame()
        {
            MRKUIEndFrame(ms_Context);
            ms_Context = 0;
        }

        void MRKGUI::Box(_MATH Rect rect)
        {
            MRKUIBeginPath(ms_Context);

            MRKUIRect(ms_Context, rect.X(), rect.Y(), rect.Width(), rect.Height());
            MRKUIFillColor(ms_Context, &ms_DrawColor);
            MRKUIFill(ms_Context);

            MRKUIClosePath(ms_Context);
        }

        void MRKGUI::Label(_MATH Rect rect, _STD string text, float fontSize)
        {
            MRKUIBeginPath(ms_Context);

            MRKUIFontFace(ms_Context, "sans");
            MRKUIFontSize(ms_Context, _UTILITY CalculateRelativeFont(fontSize));
            MRKUIFillColor(ms_Context, &ms_DrawColor);
            MRKUITextAlign(ms_Context, MRKUI_ALIGN_MIDDLE | MRKUI_ALIGN_LEFT);
            MRKUIText(ms_Context, rect.X(), rect.Y(), text.c_str(), 0);

            MRKUIClosePath(ms_Context);
        }

        void MRKGUI::SetColor(MRKColor color)
        {
            ms_DrawColor = color;
        }

        void MRKGUI::Picture(_MATH Rect rect, int picture)
        {
            MRKUIBeginPath(ms_Context);

            MRKUIpaint paint = MRKUIImagePattern(ms_Context, rect.X(), rect.Y(), rect.Width(),
                                             rect.Height(), 0.f, picture, 1.f);
            MRKUIRect(ms_Context, rect.X(), rect.Y(), rect.Width(), rect.Height());
            MRKUIFillPaint(ms_Context, paint);
            MRKUIFill(ms_Context);

            MRKUIClosePath(ms_Context);
        }

        void MRKGUI::Line(_MATH Vector2 start, _MATH Vector2 end, float width)
        {
            MRKUIBeginPath(ms_Context);

            MRKUIMoveTo(ms_Context, start.X(), start.Y());
            MRKUILineTo(ms_Context, end.X(), end.Y());
            MRKUIStrokeWidth(ms_Context, width);
            MRKUIStrokeColor(ms_Context, &ms_DrawColor);
            MRKUIStroke(ms_Context);

            MRKUIClosePath(ms_Context);
        }
    }
}