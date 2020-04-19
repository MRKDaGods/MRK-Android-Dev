#pragma once

#include <string>

#include "MRKGuiBaseWidget.h"
#include "../math/MRKMath.h"

namespace MRK
{
    namespace GUI
    {
        class MRKGuiBaseWindow : public MRKGuiBaseWidget
        {
        private:
            _STD string m_Title;
            bool m_Drag;
            bool m_Draggable;
        public:
            MRKGuiBaseWindow(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect, _STD string title);
            void Draw(MRKUIcontext *context) override;
            bool HandleTouchEvent(MRKTouchEvent &event) override;
            void SetDraggable(bool drag);
        };
    }
}