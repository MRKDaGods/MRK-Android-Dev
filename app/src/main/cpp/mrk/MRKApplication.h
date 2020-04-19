#pragma once

#include <pthread.h>
#include <thread>
#include <chrono>
#include <vector>

#include "MRKCommon.h"
#include "gui/MRKDisplay.h"

namespace MRK
{
    struct FramerateInfo
    {
        _STD chrono::time_point<_STD chrono::system_clock> Tp1;
        _STD chrono::time_point<_STD chrono::system_clock> Tp2;
        float Elapsed;
        float Fps;
    };

    class MRKApplication
    {
    private:
        static int ms_Framerate;
        static pthread_t ms_ComponentsThread;
        static int ms_InitStatus;
        static bool ms_Running;
        static bool ms_FramesDirty;
        static _STD chrono::milliseconds ms_SleepTime;
        static _GUI MRKDisplay *ms_UiDisplay;
        static float ms_LoadProgress;
        static FramerateInfo ms_UIFramerateInfo;
        static FramerateInfo ms_UpdateFramerateInfo;
        static float ms_TimeSinceLaunch;
        static _STD vector<void(*)()> ms_GUICallbacks;

        static void *UpdateComponents(void*);
    public:
        static void SetFramerate(int framerate);
        static void Init(int framerate, _GUI MRKDisplay *uidisplay);
        static bool Initialized();
        static bool FullyInitialized();
        static void CallGuiEvent();
        static _GUI DisplayInfo *GetUIDisplayInfo();
        static void StartThread();
        static FramerateInfo *GetUIFramerateInfo();
        static FramerateInfo *GetUpdateFramerateInfo();
        static float GetTimeSinceLaunch();
        static int RegisterProxyGUI(void(*callback)());

        static _GUI MRKDisplay *GetUIDisplay();
    };
}