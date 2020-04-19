#include "MRKGuiBaseImageSelector.h"

namespace MRK
{
    namespace GUI
    {

        MRKGuiBaseImageSelector::MRKGuiBaseImageSelector(LMSGuiBaseWidget *parent, LMSAnchor anchor,
                                                         _MATH Rect rect, _STD vector<int> pictures)
                : LMSGuiBaseWidget(parent, anchor, rect)
        {
            m_Images = pictures;
            m_SelectedImage = 0;
        }

        void MRKGuiBaseImageSelector::Draw(NVGcontext *context)
        {
            float space = m_Size.X() / 10.f;
            float xOffset = space * 2.f;
            float width = m_Size.X() - (2.f * (space * 2.f) + (m_Images.size() - 1) * space);
            for (size_t i = 0; i < m_Images.size(); i++)
            {
                nvgBeginPath(context);
                if (i == m_SelectedImage)
                {
                    NVGpaint shadowPaint = nvgBoxGradient(
                            context, Position().X(), Position().Y(), m_Size.X(), m_Size.Y(), 6, 20,
                            &LMSColor::White, &m_Theme->Transparent);
                    nvgSave(context);
                    nvgResetScissor(context);
                    nvgBeginPath(context);
                    nvgRect(context, Position().X() - 20, Position().Y() - 20, m_Size.X() + 20,
                            m_Size.Y() + 20);
                    nvgRoundedRect(context, Position().X(), Position().Y(), m_Size.X(), m_Size.Y(),
                                   6);
                    nvgPathWinding(context, NVG_HOLE);
                    nvgFillPaint(context, shadowPaint);
                    nvgFill(context);
                    nvgRestore(context);
                }
            }
        }
    }
}