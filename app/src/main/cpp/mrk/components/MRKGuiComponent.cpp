#include "MRKGuiComponent.h"

namespace MRK
{
    namespace Components
    {
        _STD vector<MRKGuiComponent*> MRKGuiComponent::RuntimeMRKGuiComponents;

        MRKGuiComponent::MRKGuiComponent(_GUI MRKDisplay *display)
        {
            m_Display = display;
        }

        void MRKGuiComponent::Update()
        {
        }

        void MRKGuiComponent::GUI(MRKUIcontext *context)
        {
        }

        bool MRKGuiComponent::CanUpdate()
        {
            return m_Visible;
        }

        void MRKGuiComponent::SetVisible(bool visible)
        {
            if (m_Visible == visible)
                return;
            m_Visible = visible;
            for (_GUI MRKGuiBaseWidget *widget : m_Widgets)
                widget->SetVisible(m_Visible);
        }

        void MRKGuiComponent::AddWidget(_GUI MRKGuiBaseWidget *container, _GUI MRKGuiBaseWidget *widget)
        {
            //TODO: add auto positioning and alignment about container
            m_Widgets.push_back(widget);
        }

        _GUI MRKDisplay *MRKGuiComponent::GetDisplay()
        {
            return m_Display;
        }
    }
}