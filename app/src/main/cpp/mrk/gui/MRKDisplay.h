#pragma once

#include <vector>
#include <string>

#include "../MRKCommon.h"
#include "MRKGuiBaseWidget.h"
#include "MRKGuiBaseLabel.h"
#include "MRKGuiBaseWindow.h"
#include "MRKGuiBaseButton.h"
#include "MRKGuiBaseSlider.h"
#include "MRKGuiBaseButtonEx.h"

//#define MRK_DRAW_BOUNDS
#define MAKE_REGISTER_WIDGET(widget) widget *RegisterWidget(widget *wid);
#define MAKE_REGISTER_WIDGET_IMPL(widget) widget *MRKDisplay::RegisterWidget(widget *wid) \
    { m_Children.add(wid); return wid; }

namespace MRK
{
    namespace GUI
    {
        struct DisplayInfo
        {
        public:
            int DisplayId;
            float PixelRatio;
            int Width;
            int Height;
        };

        class MRKDisplay : public MRKGuiBaseWidget
        {
        private:
            static MRKUIcontext *ms_Context;
            static _STD vector<MRKDisplay*> ms_Displays;
            static int ms_GlobalDisplayIndex;
            static MRKTheme *ms_DefaultTheme;

            int m_DisplayId;
            float m_PixelRatio;
            bool m_Down;
            MRKGuiBaseWidget *m_DownWidget;
            MRKGuiBaseWidget *m_FocusWidget;
            DisplayInfo m_Info;
            _STD vector<_STD function<void(MRKTouchEvent&)>> m_TouchCallbacks;
        public:
            static MRKDisplay *RenderingDisplay;

            static void Init();
            static MRKUIcontext *Context();
            static void InjectTouchEvent(MRKTouchEvent &event);
            static void InjectRenderEvent();
            static _GUI MRKTheme *DefaultTheme();

            MRKGuiBaseWindow *TEST_WINDOW;

            MRKDisplay(MRKAnchor anchor, _MATH Vector2 size, float dpr);
            ~MRKDisplay();
            void Update();
            int DisplayId();
            DisplayInfo *Info();
            bool HandleTouchEvent(MRKTouchEvent &event) override;
            void AddLabel(_STD string txt);
            void RegisterTouchCallback(_STD function<void(MRKTouchEvent&)> function);

            MAKE_REGISTER_WIDGET(_GUI MRKGuiBaseLabel)
            MAKE_REGISTER_WIDGET(_GUI MRKGuiBaseWindow)
            MAKE_REGISTER_WIDGET(_GUI MRKGuiBaseButton)
            MAKE_REGISTER_WIDGET(_GUI MRKGuiBaseSlider)
        };
    }
}