#include "MRKDisplay.h"
#include "../MRKApplication.h"

#define MRKUI_GLES2_IMPLEMENTATION
#include "../../mrkui/MRKUIGL.h"

//#define MRK_DRAW_BOUNDS

namespace MRK
{
    namespace GUI
    {
        MRKUIcontext *MRKDisplay::ms_Context = 0;
        _STD vector<MRKDisplay*> MRKDisplay::ms_Displays;
        int MRKDisplay::ms_GlobalDisplayIndex = 0;
        MRKDisplay *MRKDisplay::RenderingDisplay = 0;
        MRKTheme *MRKDisplay::ms_DefaultTheme = 0;

        void MRKDisplay::Init()
        {
            ms_Context = MRKUICreateGLES2(MRKUI_ANTIALIAS | MRKUI_STENCIL_STROKES);
            if (!ms_Context)
                throw _STD runtime_error("Cannot create context");
            ms_DefaultTheme = new MRKTheme(ms_Context);
        }

        MRKUIcontext *MRKDisplay::Context()
        {
            return ms_Context;
        }

        void MRKDisplay::InjectTouchEvent(MRKTouchEvent &event)
        {
            if (MRKApplication::FullyInitialized())
                for (MRKDisplay *display : ms_Displays)
                    display->HandleTouchEvent(event);
        }

        MRKDisplay::MRKDisplay( MRKAnchor anchor, _MATH Vector2 size, float dpr) : MRKGuiBaseWidget(0, anchor, _MATH Rect(0.f, 0.f, size.X(), size.Y()),
                                                                                                    (MRKWidgetInitFlags)(MRK_WIDGET_INIT_FLAG_NO_SIZE | MRK_WIDGET_INIT_FLAG_NO_ANCHOR))
        {
            m_Size = size;
            m_PixelRatio = dpr;
            m_DisplayId = ms_GlobalDisplayIndex;
            m_Theme = DefaultTheme();
            ms_Displays.push_back(this);
            ms_GlobalDisplayIndex++;
            m_Info = DisplayInfo{
                    m_DisplayId,
                    m_PixelRatio,
                    (int) m_Size.X(),
                    (int) m_Size.Y()
            };
            m_FocusWidget = 0;

            //RecalculateAnchors();
            //RecalculateSize();
        }

        MRKDisplay::~MRKDisplay()
        {
            int idx = 0;
            int tIdx = -1;
            for (_STD vector<MRKDisplay*>::iterator it = ms_Displays.begin(); it != ms_Displays.end(); it++)
            {
                if ((*it)->DisplayId() == m_DisplayId)
                {
                    tIdx = idx;
                }
                idx++;
            }
            if (tIdx != -1)
                ms_Displays.erase(ms_Displays.begin() + tIdx);
            if (ms_Displays.size() == 0) //last screen removed
                MRKUIDeleteGLES2(ms_Context);
        }

        int MRKDisplay::DisplayId()
        {
            return m_DisplayId;
        }

        bool MRKDisplay::HandleTouchEvent(MRKTouchEvent &event)
        {
            if (!m_TouchCallbacks.empty())
            {
                _STD vector<_STD function<void(
                        MRKTouchEvent &)>>::iterator it = m_TouchCallbacks.begin();
                while (it != m_TouchCallbacks.end())
                {
                    (*it)(event);
                    it++;
                }
            }
            if (!m_Visible)
                return true;
            if (!m_Down)
                m_DownWidget = FindWidget(event.MousePosition());
            if (m_DownWidget == this || !m_DownWidget)
            {
                if (m_FocusWidget)
                {
                    m_FocusWidget->UpdateFocusState(false);
                    m_FocusWidget = 0;
                }
                m_DownWidget = 0;
            }
            if (m_DownWidget)
            {
                if (event.Type() == MRKTouchEventType::Down)
                {
                    m_Down = true;
                    if (m_FocusWidget && m_FocusWidget != m_DownWidget)
                        m_FocusWidget->UpdateFocusState(false);
                    m_FocusWidget = m_DownWidget;
                    m_FocusWidget->UpdateFocusState(true);
                }
                else if (event.Type() == MRKTouchEventType::Up)
                    m_Down = false;
                m_DownWidget->HandleTouchEvent(event);
            }
            if (event.Type() == MRKTouchEventType::Up)
                MRKTouchEvent::Clean();
            return true;
        }

        void MRKDisplay::Update()
        {
            RenderingDisplay = this;
            GLint viewport[4];
            glGetIntegerv(GL_VIEWPORT, viewport);
            MRKUIBeginFrame(ms_Context, m_Size.X(), m_Size.Y(), ((float)viewport[2]) / viewport[3]);
            for (MRKGuiBaseWidget *widget : m_Children)
            {
                if (widget->Visible())
                    widget->Draw(ms_Context);
#ifdef MRK_DRAW_BOUNDS
                MRKUIStrokeWidth(ms_Context, 1.0f);
                MRKUIBeginPath(ms_Context);
                MRKUIRect(ms_Context, widget->ScreenRect().X() - 0.5f, widget->ScreenRect().Y() - 0.5f, widget->ScreenRect().Width() + 1, widget->ScreenRect().Height() + 1);
                MRKUIStrokeColor(ms_Context, MRKUIRGBA(255, 0, 0, 255));
                MRKUIStroke(ms_Context);
#endif
            }
            MRKUIEndFrame(ms_Context);
        }

        DisplayInfo *MRKDisplay::Info()
        {
            return &m_Info;
        }

        void MRKDisplay::AddLabel(_STD string txt)
        {
            TEST_WINDOW = new MRKGuiBaseWindow(this, MRK_ANCHOR_MIDDLE_CENTER, _MATH Rect(-350.f, -250.f, 700.f, 500.f), "MRK TEST");
            MRKGuiBaseButton *button = new MRKGuiBaseButton(TEST_WINDOW, MRK_ANCHOR_NONE, _MATH Rect(0.f, 100.f, 400.f, 50.f), "Aimbot");
            button->SetCallback([] {
               // __android_log_print(ANDROID_LOG_INFO, "MRK", "THE BUTTON WORKS!");
            });
            //MRKGuiBaseLabel *label = new MRKGuiBaseLabel(this, MRK_ANCHOR_BOTTOM_LEFT, _MATH Rect(0.f, 250.f, 100.f, 100.f),
            //                                             txt, MRKFont::Sans, 52, MRKLabelFlags::DropShadow);
            m_Children.push_back(TEST_WINDOW);
            m_Children.push_back(button);
            //m_Children.push_back(label);
        }

        void MRKDisplay::InjectRenderEvent()
        {
            for (MRKDisplay *display : ms_Displays)
                if (display->Visible())
                    display->Update();
        }

        _GUI MRKTheme *MRKDisplay::DefaultTheme()
        {
            return ms_DefaultTheme;
        }

        MAKE_REGISTER_WIDGET_IMPL(_GUI MRKGuiBaseLabel)
        MAKE_REGISTER_WIDGET_IMPL(_GUI MRKGuiBaseWindow)
        MAKE_REGISTER_WIDGET_IMPL(_GUI MRKGuiBaseButton)
        MAKE_REGISTER_WIDGET_IMPL(_GUI MRKGuiBaseSlider)

        void MRKDisplay::RegisterTouchCallback(_STD function<void(MRKTouchEvent&)> function)
        {
            if (function)
                m_TouchCallbacks.push_back(function);
        }
    }
}