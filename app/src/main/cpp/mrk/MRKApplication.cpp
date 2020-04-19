#include "MRKApplication.h"
#include "components/MRKGuiComponent.h"
#include "components/MRKGuiComponentDebugger.h"
#include "components/MRKGuiComponentLoader.h"
#include "gui/MRKGUI.h"
#include "../mrkui/MRKUI.h"
#include "gui/MRKGuiBaseLabel.h"

namespace MRK {
    int MRKApplication::ms_Framerate = 0;
    pthread_t MRKApplication::ms_ComponentsThread;
    int MRKApplication::ms_InitStatus;
    bool MRKApplication::ms_Running;
    bool MRKApplication::ms_FramesDirty;
    _STD chrono::milliseconds MRKApplication::ms_SleepTime;
    _GUI MRKDisplay *MRKApplication::ms_UiDisplay;
    float MRKApplication::ms_LoadProgress;
    FramerateInfo MRKApplication::ms_UIFramerateInfo;
    FramerateInfo MRKApplication::ms_UpdateFramerateInfo;
    float MRKApplication::ms_TimeSinceLaunch;
    _STD vector<void (*)()> MRKApplication::ms_GUICallbacks;
    _GUI MRKGuiBaseLabel *ms_BuildLabel = 0;

    void MRKApplication::SetFramerate(int framerate) {
        if (ms_Framerate == framerate)
            return;
        ms_Framerate = framerate;
        ms_SleepTime = _STD chrono::milliseconds((int) ((1.f / ((float) framerate)) * 1000));
        ms_FramesDirty = true;
    }

    void MRKApplication::Init(int framerate, _GUI MRKDisplay *uidisplay) {
        if (Initialized())
            throw _STD runtime_error("MRKApplication already intialized");
        ms_InitStatus |= 1;
        ms_Running = true;
        ms_UiDisplay = uidisplay;
        ms_LoadProgress = 0;
        ms_UIFramerateInfo = FramerateInfo{
                _STD chrono::system_clock::now(),
                _STD chrono::system_clock::now()
        };
        ms_UpdateFramerateInfo = FramerateInfo{
                _STD chrono::system_clock::now(),
                _STD chrono::system_clock::now()
        };
        SetFramerate(framerate);
        ms_TimeSinceLaunch = 0.f;

        ms_BuildLabel = new _GUI MRKGuiBaseLabel(ms_UiDisplay, _GUI MRK_ANCHOR_BOTTOM_LEFT,
                                                 _MATH Rect(5.f, 30.f, 200.f, 30.f),
                                                 "MRKDaGods GL (1.0.25b.291)", 22,
                                                 _GUI MRKLabelAlignment::MRK_ALIGN_LEFT,
                                                 _GUI MRKFont::Exo2Bold,
                                                 _GUI MRKLabelFlags::DropShadow);
    }

    void *MRKApplication::UpdateComponents(void *) {
        int loaderState = 1;
        _COMPONENT MRKGuiComponentLoader *loader = new _COMPONENT MRKGuiComponentLoader(
                ms_UiDisplay,
                &ms_LoadProgress,
                &loaderState);
        loader->SetVisible(true);
        _COMPONENT MRKGuiComponentLoader::RuntimeMRKGuiComponents.push_back(loader);
        for (int i = 1; i <= 300; i++) {
            ms_LoadProgress = ((float) i) / 300.f;
            _STD this_thread::sleep_for(_STD chrono::milliseconds(10));
        }
        loaderState = 2;
        for (int i = 1; i <= 100; i++) {
            ms_LoadProgress = ((float) i) / 100.f;
            _STD this_thread::sleep_for(_STD chrono::milliseconds(10));
        }
        loader->SetVisible(false);
        //sglmain();
        ms_InitStatus |= 2;
        //_COMPONENT MRKGuiComponent::RuntimeMRKGuiComponents.push_back(
        //        new _COMPONENT MRKGuiComponentBase(ms_UiDisplay));
        //_COMPONENT MRKGuiComponent::RuntimeMRKGuiComponents.push_back(
        //        new _COMPONENT MRKGuiComponentDebugger(ms_UiDisplay));
        //_COMPONENT MRKGuiComponent::RuntimeMRKGuiComponents.push_back(
        //        new _COMPONENT MRKGuiComponentLocalStats(ms_UiDisplay));
        while (ms_Running) {
            ms_UpdateFramerateInfo.Tp2 = _STD chrono::system_clock::now();
            ms_UpdateFramerateInfo.Elapsed = ((_STD chrono::duration<float>) (
                    ms_UpdateFramerateInfo.Tp2 - ms_UpdateFramerateInfo.Tp1)).count();
            ms_UpdateFramerateInfo.Tp1 = ms_UpdateFramerateInfo.Tp2;
            ms_UpdateFramerateInfo.Fps = 1.f / ms_UpdateFramerateInfo.Elapsed;
            _STD this_thread::sleep_for(ms_SleepTime);
            if (ms_FramesDirty)
                ms_FramesDirty = false;
            for (_COMPONENT MRKGuiComponent *component : _COMPONENT MRKGuiComponent::RuntimeMRKGuiComponents) {
                //a concurrent thread could've modified the framerate
                //so we instantly skip all pending updates
                //until we update the framerate
                if (ms_FramesDirty || !component->CanUpdate())
                    continue;
                component->Update();
            }
        }
        pthread_exit(NULL);
    }

    void MRKApplication::CallGuiEvent() {
        ms_UIFramerateInfo.Tp2 = _STD chrono::system_clock::now();
        ms_UIFramerateInfo.Elapsed = ((_STD chrono::duration<float>) (
                ms_UIFramerateInfo.Tp2 - ms_UIFramerateInfo.Tp1)).count();
        ms_UIFramerateInfo.Tp1 = ms_UIFramerateInfo.Tp2;
        ms_UIFramerateInfo.Fps = 1.f / ms_UIFramerateInfo.Elapsed;
        _GUI DisplayInfo *displayInfo = GetUIDisplayInfo();
        MRKUIBeginFrame(_GUI MRKDisplay::Context(), displayInfo->Width, displayInfo->Height,
                        displayInfo->PixelRatio);
        //only the components can use the MRKGUI api for now
        _GUI MRKGUI::StartFrame(_GUI MRKDisplay::Context());
        for (_COMPONENT MRKGuiComponent *component : _COMPONENT MRKGuiComponent::RuntimeMRKGuiComponents) {
            if (component->CanUpdate())
                component->GUI(_GUI MRKDisplay::Context());
        }

        if (FullyInitialized()) {
            for (auto proxyComponent : ms_GUICallbacks)
                proxyComponent();
        }

        _GUI MRKDisplay::InjectRenderEvent();

        _GUI MRKGUI::EndFrame();
        MRKUIEndFrame(_GUI MRKDisplay::Context());
    }

    _GUI DisplayInfo *MRKApplication::GetUIDisplayInfo() {
        return ms_UiDisplay->Info();
    }

    bool MRKApplication::Initialized() {
        return (ms_InitStatus & 1) != 0;
    }

    void MRKApplication::StartThread() {
        pthread_create(&ms_ComponentsThread, NULL, UpdateComponents, (void *) 0);
    }

    FramerateInfo *MRKApplication::GetUIFramerateInfo() {
        return &ms_UIFramerateInfo;
    }

    FramerateInfo *MRKApplication::GetUpdateFramerateInfo() {
        return &ms_UpdateFramerateInfo;
    }

    bool MRKApplication::FullyInitialized() {
        return Initialized() && (ms_InitStatus & 2) != 0;
    }

    float MRKApplication::GetTimeSinceLaunch() {
        return ms_TimeSinceLaunch;
    }

    int MRKApplication::RegisterProxyGUI(void (*callback)()) {
        ms_GUICallbacks.push_back(callback);
        return ms_GUICallbacks.size() - 1;
    }
}