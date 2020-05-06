#include <jni.h>
#include "MRKProxyDynamic.h"
#include "MRKProxyGUI.h"
#include "MRKProxyMGUI.h"

using namespace MRK;
using namespace MRK::GUI;

MRKGUIDisplay* m_Display;

void cb();

bool x = false;

extern "C" JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKProxyInit(JNIEnv *env, jclass clazz) {
    if (!MRKProxyInitialize("io.github.mrkdagods.mrkandroidhaxexternal"))
        return;

MRKProxyRegisterGUICallback(cb);
}

void cb() {
    if (!x) {
        x = true;
        m_Display = MRKGUIGetMainDisplay();
        MRKGUILabel *label = m_Display->RegisterLabel(MRK_ANCHOR_MIDDLE_CENTER,
                                                      Rect(0.f, 0.f, 100.f, 100.f),
                                                      "MRK-TEST-LABEL", 50.f);


    }

    MRKProxySetColor(0.12549f, 0.12549f, 0.12549f, 1.f);
    MRKProxyBox(10.f, 10.f, 200.f, 100.f);

    MRKProxySetColor(1.f, 1.f, 0.f, 1.f);
    MRKProxyLabel(15.f, 20.f, 90.f, 30.f, "MRKDaGods", 35.f);

    MRKProxySetColor(1.f, 1.f, 1.f, 1.f);
    MRKProxyLabel(15.f, 55.f, 90.f, 30.f, "Well", 35.f);

    MRKProxySetColor(0.f, 1.f, 0.f, 1.f);
    MRKProxyLabel(15.f, 90.f, 90.f, 30.f, "Test GL", 35.f);

    //get screen info
    float width;
    float height;
    MRKProxyGetScreenInfo(&width, &height, 0);

    MRKProxySetColor(0.f, 0.f, 1.f, 1.f);
    MRKProxyLine(0.f, 0.f, width, height, 2.f);

    MRKProxySetColor(1.f, 0.f, 1.f, 1.f);
    MRKProxyLine(0.f, height / 2.f, width, height / 2.f, 4.f);
}