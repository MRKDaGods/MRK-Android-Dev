#pragma once

#include <jni.h>

extern "C"
{
    namespace MRK
    {
        namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
        {
            typedef void(*MRKProxyGUICallback)();

            JNIEXPORT int JNICALL MRKProxyRegisterGUICallback(MRKProxyGUICallback callback);
            JNIEXPORT void JNICALL MRKProxySetColor(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c);
            JNIEXPORT void JNICALL MRKProxyLabel(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h, const char* txt, float fontsize);
            JNIEXPORT void JNICALL MRKProxyBox(float m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, float y, float w, float h);
            JNIEXPORT void JNICALL MRKProxyLine(float x1, float y1, float x2, float y2, float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn);
            JNIEXPORT void JNICALL MRKProxyGetScreenInfo(float* w, float* h, float* pr);
        }
    }
}