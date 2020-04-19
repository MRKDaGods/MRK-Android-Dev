#pragma once

#include <vector>

#include "../MRKCommon.h"
#include "../gui/MRKDisplay.h"

namespace MRK
{
    namespace Components
    {
        class MRKGuiComponent
        {
        protected:
            bool m_Visible;
            _GUI MRKDisplay *m_Display;
            _STD vector<_GUI MRKGuiBaseWidget*> m_Widgets;
        public:
            static _STD vector<MRKGuiComponent*> RuntimeMRKGuiComponents;

            MRKGuiComponent(_GUI MRKDisplay *display);
            virtual void Update();
            virtual void GUI(MRKUIcontext *context);
            bool CanUpdate();
            void SetVisible(bool visible);
            _GUI MRKDisplay *GetDisplay();
            void AddWidget(_GUI MRKGuiBaseWidget *container, _GUI MRKGuiBaseWidget *widget);
        };
    }
}