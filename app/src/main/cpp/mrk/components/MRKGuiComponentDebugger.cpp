#include "MRKGuiComponentDebugger.h"
#include "../gui/MRKGUI.h"

namespace MRK
{
    namespace Components
    {
        MRKGuiComponentDebugger::MRKGuiComponentDebugger(_GUI MRKDisplay *display) : MRKGuiComponent(display)
        {
            m_Visible = true;
            /*
            m_Window = new _GUI MRKGuiBaseWindow(display, _MATH Rect(20.f, 20.f, 700.f, 200.f), "Debugger");
            m_StatusLabel = new _GUI MRKGuiBaseLabel(m_Window, _MATH Rect(10.f, -100.f, 400.f, 20.f), "Focused: false",
                _GUI MRKFont::Sans, 24, _GUI LMSLabelFlags::None);
            m_StatusLabel2 = new _GUI MRKGuiBaseLabel(m_Window, _MATH Rect(10.f, 0.f, 400.f, 20.f), "FPS: 120",
                                                     _GUI MRKFont::Sans, 24, _GUI LMSLabelFlags::None);
            display->RegisterWidget(m_Window);
            display->RegisterWidget(m_StatusLabel);
            display->RegisterWidget(m_StatusLabel2);*/
        }

        void MRKGuiComponentDebugger::Update()
        {
        }

        void MRKGuiComponentDebugger::GUI(MRKUIcontext *context)
        {
            _GUI MRKGUI::SetColor(MRKColor(32, 255));
            _GUI MRKGUI::Box(_MATH Rect(50.f, 50.f, 500.f, 350.f));
            _GUI MRKGUI::SetColor(MRKColor(255, 255));
            _GUI MRKGUI::Label(_MATH Rect(55.f, 70.f, 0.f, 0.f),
                               "Resolution: " + _UTILITY ResolutionString(), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 100.f, 0.f, 0.f),
                               "W/H Modifier: " + _UTILITY ModifiersString(), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 130.f, 0.f, 0.f),
                               "Font Modifier: " + _UTILITY FontModifierString(), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 160.f, 0.f, 0.f), "Components: " + _STD to_string(
                    MRKGuiComponent::RuntimeMRKGuiComponents.size()), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 190.f, 0.f, 0.f),
                               "UI:", 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 220.f, 0.f, 0.f), "\tFPS: " + _STD to_string(
                    MRKApplication::GetUIFramerateInfo()->Fps), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 250.f, 0.f, 0.f), "\tFrame Time: " + _STD to_string(
                    MRKApplication::GetUIFramerateInfo()->Elapsed), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 280.f, 0.f, 0.f),
                               "Update:", 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 310.f, 0.f, 0.f), "\tFPS: " + _STD to_string(
                    MRKApplication::GetUpdateFramerateInfo()->Fps), 32.f);
            _GUI MRKGUI::Label(_MATH Rect(55.f, 340.f, 0.f, 0.f), "\tFrame Time: " + _STD to_string(
                    MRKApplication::GetUpdateFramerateInfo()->Elapsed), 32.f);
        }
    }
}