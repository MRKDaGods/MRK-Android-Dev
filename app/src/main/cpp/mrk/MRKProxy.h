#pragma once

#include <jni.h>

#include "MRKCommon.h"

extern "C"
{
    namespace MRK
    {
        namespace GUI
        {
            //SHARED between Proxy and Core
            enum class MRKProxyCommand {
                None = 0,

                //UI-SPECIFIC
                        RegisterGUICallback, //registers a gui callback
                SetColor, //sets color in MRKGUI
                Label, //renders a generic label
                Box, //renders a generic box
                Line, //renders a line
                GetScreenInfo, //retrieve screen info

                //MGUI
                        GetMainDisplay,
                RegisterLabel,
                LabelGetText,
                LabelSetText
            };

            typedef void(*MRKProxyGUICallback)();

            typedef void (*GenericContextualPtr)(...);

            MRK_EXPORT(GenericContextualPtr) MRKProxyProcessCommand(MRKProxyCommand command);

            MRK_EXPORT(void) MRKProxyBox(float x, float y, float w, float h);

            MRK_EXPORT(void) MRKProxySetColor(float r, float g, float b, float a);
        }
    }
}