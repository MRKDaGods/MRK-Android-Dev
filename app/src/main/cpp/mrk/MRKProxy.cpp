#include "MRKProxy.h"
#include "MRKApplication.h"
#include "gui/MRKGUI.h"
#include "gui/MRKDisplay.h"

namespace MRK {
    namespace GUI {
        extern "C" {
        MRK_EXPORT(void) MRKProxyRegisterGUICallback(MRKProxyGUICallback callback, int *id) {
            int _id = MRKApplication::RegisterProxyGUI(callback);

            if (id)
                *id = _id;
        }

        MRK_EXPORT(void) MRKProxySetColor(float r, float g, float b, float a) {
            MRKGUI::SetColor(MRKColor(r, g, b, a));
        }

        MRK_EXPORT(void) MRKProxyLabel(float x, float y, float w, float h, const char *txt,
                                       float fontsize) {
            MRKGUI::Label(_MATH Rect(x, y, w, h), txt, fontsize);
        }

        MRK_EXPORT(void) MRKProxyBox(float x, float y, float w, float h) {
            MRKGUI::Box(_MATH Rect(x, y, w, h));
        }

        MRK_EXPORT(void) MRKProxyLine(float x1, float y1, float x2, float y2, float width) {
            MRKGUI::Line(_MATH Vector2(x1, y1), _MATH Vector2(x2, y2), width);
        }

        MRK_EXPORT(void) MRKProxyGetScreenInfo(float *w, float *h, float *pr) {
            DisplayInfo *info = MRKApplication::GetUIDisplayInfo();

            if (w)
                *w = info->Width;

            if (h)
                *h = info->Height;

            if (pr)
                *pr = info->PixelRatio;
        }

        MRK_EXPORT(void) MRKProxyGetMainDisplay(void **display, int *id) {
            _GUI MRKDisplay *_display = MRKApplication::GetUIDisplay();

            if (display)
                *display = _display;

            if (id)
                *id = _display->DisplayId();
        }

        MRK_EXPORT(void) MRKProxyWidgetRegisterLabel(void *parent, MRKAnchor anchor, float x,
                                                     float y,
                                                     float w, float h, const char *txt,
                                                     int fontsize,
                                                     void **handle) {
            if (!handle)
                return;

            *handle = new MRKGuiBaseLabel((MRKGuiBaseWidget *) parent, anchor,
                                          _MATH Rect(x, y, w, h),
                                          txt, fontsize);
        }

        MRK_EXPORT(void) MRKProxyLabelGetText(void *handle, char **txt) {
            if (!handle || !txt)
                return;

            _STD string str = ((MRKGuiBaseLabel *) handle)->GetText();
            *txt = new char[str.size() + 1];
            strcpy(*txt, str.c_str());
            *txt[str.size()] = '\0';
        }

        MRK_EXPORT(void) MRKProxyLabelSetText(void *handle, const char *txt) {
            if (!handle)
                return;

            ((MRKGuiBaseLabel *) handle)->SetText(txt);
        }

        MRK_EXPORT(GenericContextualPtr) MRKProxyProcessCommand(MRKProxyCommand command) {
            switch (command) {

                case MRKProxyCommand::RegisterGUICallback:
                    return (GenericContextualPtr) MRKProxyRegisterGUICallback;

                case MRKProxyCommand::SetColor:
                    return (GenericContextualPtr) MRKProxySetColor;

                case MRKProxyCommand::Label:
                    return (GenericContextualPtr) MRKProxyLabel;

                case MRKProxyCommand::Box:
                    return (GenericContextualPtr) MRKProxyBox;

                case MRKProxyCommand::Line:
                    return (GenericContextualPtr) MRKProxyLine;

                case MRKProxyCommand::GetScreenInfo:
                    return (GenericContextualPtr) MRKProxyGetScreenInfo;

                case MRKProxyCommand::GetMainDisplay:
                    return (GenericContextualPtr) MRKProxyGetMainDisplay;

                case MRKProxyCommand::RegisterLabel:
                    return (GenericContextualPtr) MRKProxyWidgetRegisterLabel;

                case MRKProxyCommand::LabelGetText:
                    return (GenericContextualPtr) MRKProxyLabelGetText;

                case MRKProxyCommand::LabelSetText:
                    return (GenericContextualPtr) MRKProxyLabelSetText;

            }

            return 0;
        }
        }
    }
}