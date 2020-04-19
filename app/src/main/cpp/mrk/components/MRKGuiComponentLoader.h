#pragma once

#include "MRKGuiComponent.h"
#include "../gui/MRKGUI.h"

extern int MRK_BASE_PIC_HANDLE;

namespace MRK
{
    namespace Components
    {
        class MRKGuiComponentLoader : public MRKGuiComponent
        {
        private:
            float *m_Progress;
            int *m_State;
        public:
            MRKGuiComponentLoader(_GUI MRKDisplay *display, float *progress, int *state);
            virtual void GUI(MRKUIcontext *context) override;
        };
    }
}