#include <jni.h>
#include "MRKProxyDynamic.h"
#include "MRKProxyMGUI.h"

using namespace MRK;
using namespace MRK::GUI;

MRKGUIDisplay* m_Display;

extern "C" JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKProxyInit(JNIEnv *env, jclass clazz) {
    if (!MRKProxyInitialize("io.github.mrkdagods.mrkandroidhaxexternal"))
        return;

    m_Display = MRKGUIGetMainDisplay();
}