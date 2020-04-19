#pragma once

#include "MRKGuiBaseWidget.h"

namespace MRK
{
    namespace GUI
    {
        class MRKGuiBaseImageSelector : public LMSGuiBaseWidget
        {
        private:
            _STD vector<int> m_Images;
            int m_SelectedImage; //index
        public:
            MRKGuiBaseImageSelector(LMSGuiBaseWidget *parent, LMSAnchor anchor, _MATH Rect rect,
                                    _STD vector<int> pictures);
            void Draw(NVGcontext *context) override;
        };
    }
}