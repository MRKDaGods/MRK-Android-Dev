#pragma once

#include "MRKGuiComponent.h"
#include "../gui/MRKGuiBaseWindow.h"
#include "../gui/MRKGuiBaseLabel.h"
#include "../math/Rect.h"
#include "../MRKApplication.h"

namespace MRK
{
    namespace Components
    {
        class MRKGuiComponentDebugger : public MRKGuiComponent
        {
        private:
            _GUI MRKGuiBaseWindow *m_Window;
            _GUI MRKGuiBaseLabel *m_StatusLabel;
            _GUI MRKGuiBaseLabel *m_StatusLabel2;
        public:
            MRKGuiComponentDebugger(_GUI MRKDisplay *display);
            virtual void Update() override;
            virtual void GUI(MRKUIcontext *context) override;
        };
    }
}