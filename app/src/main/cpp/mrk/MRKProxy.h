#pragma once

#include <jni.h>

extern "C"
{
    namespace MRK
    {
        namespace GUI
        {
            typedef void(*MRKProxyGUICallback)();

            JNIEXPORT int JNICALL MRKProxyRegisterGUICallback(MRKProxyGUICallback callback);
            JNIEXPORT void JNICALL MRKProxySetColor(float r, float g, float b, float a);
            JNIEXPORT void JNICALL MRKProxyLabel(float x, float y, float w, float h, const char* txt, float fontsize);
            JNIEXPORT void JNICALL MRKProxyBox(float x, float y, float w, float h);
            JNIEXPORT void JNICALL MRKProxyLine(float x1, float y1, float x2, float y2, float width);
            JNIEXPORT void JNICALL MRKProxyGetScreenInfo(float* w, float* h, float* pr);
        }
    }
}