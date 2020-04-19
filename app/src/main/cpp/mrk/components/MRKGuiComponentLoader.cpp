#include "MRKGuiComponentLoader.h"
#include "../MRKApplication.h" //included in the cpp file to avoid circular headers

namespace MRK
{
    namespace Components
    {
        MRKGuiComponentLoader::MRKGuiComponentLoader(_GUI MRKDisplay *display, float *progress, int *state)
                : MRKGuiComponent(display)
        {
            m_Progress = progress;
            m_State = state;
        }

        void MRKGuiComponentLoader::GUI(MRKUIcontext *context)
        {
            _GUI DisplayInfo *displayInfo = MRKApplication::GetUIDisplayInfo();
            float y = displayInfo->Height / 2.f - 150;
            /*MRKUIpaint paint = MRKUILinearGradient(context, 0.f, y,
                0.f, y + 150.f, &MRKColor(255, 0, 0, 255), &MRKColor(0, 0, 255, 255));
            MRKUIBeginPath(context);
            MRKUIFillColor(context, &MRKColor::Black);
            MRKUIRect(context, 0.f, 0.f, displayInfo->Width, displayInfo->Height);
            MRKUIFill(context);
            MRKUIClosePath(context);
            MRKUIBeginPath(context);
            MRKUIRect(context, 0.f, y, ((float)displayInfo->Width) * *m_Progress, 300.f);
            MRKUIFillPaint(context, paint);
            MRKUIFill(context);
            MRKUIClosePath(context);*/
            MRKUIpaint imgPaint = MRKUIImagePattern(context, 0.f, 0.f, displayInfo->Width,
                    displayInfo->Height, 0.f, MRK_BASE_PIC_HANDLE, *m_State == 1 ? 1.f : 1.f - *m_Progress);
            MRKUIBeginPath(context);
            MRKUIRect(context, 0.f, 0.f, displayInfo->Width, displayInfo->Height);
            MRKUIFillPaint(context, imgPaint);
            MRKUIFill(context);
            MRKUIClosePath(context);
            if (*m_State == 1)
            {
                float h = _UTILITY CalculateRelativeFont(72.f);
                _STD string txt = "Loading " + _STD to_string((int) (*m_Progress * 100.f)) + "%";
                _GUI MRKGUI::SetColor(MRKColor(255, 255));
                _GUI MRKGUI::Label(_MATH Rect(0.f, displayInfo->Height - h - 30.f,
                                              MRKUITextBounds(context, 0, 0, txt.c_str(), 0, 0), h),
                                   txt, 72.f);
            }
        }
    }
}