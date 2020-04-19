#include "MRKProxy.h"
#include "MRKApplication.h"
#include "gui/MRKGUI.h"
#include "gui/MRKDisplay.h"

namespace MRK {
    namespace GUI {
        bool JNICALL MRKProxyProcessCommand(MRKProxyCommand command, ...) {
            va_list args;

            switch (command) {

                case MRKProxyCommand::RegisterGUICallback: { //(int*, MRKProxyGUICallback)
                    va_start(args, 2);
                    int *_idptr = va_arg(args, int*);
                    if (_idptr)
                        *_idptr = MRKApplication::RegisterProxyGUI(
                                va_arg(args, MRKProxyGUICallback));
                }
                    break;

                case MRKProxyCommand::SetColor: {
                    va_start(args, 4);
                    MRKGUI::SetColor(MRKColor(va_arg(args, float), va_arg(args, float),
                                              va_arg(args, float), va_arg(args, float)));
                }
                    break;

                case MRKProxyCommand::Label: {
                    va_start(args, 6);
                    MRKGUI::Label(_MATH Rect(va_arg(args, float), va_arg(args, float),
                                             va_arg(args, float), va_arg(args, float)),
                                  va_arg(args, const char*),
                                  va_arg(args, float));
                }
                    break;

                case MRKProxyCommand::Box: {
                    va_start(args, 4);
                    MRKGUI::Box(_MATH Rect(va_arg(args, float), va_arg(args, float),
                                           va_arg(args, float), va_arg(args, float)));
                }
                    break;

                case MRKProxyCommand::Line: {
                    va_start(args, 5);
                    MRKGUI::Line(_MATH Vector2(va_arg(args, float), va_arg(args, float)),
                                 _MATH Vector2(va_arg(args, float), va_arg(args, float)),
                                 va_arg(args, float));
                }
                    break;

                case MRKProxyCommand::GetScreenInfo: {
                    va_start(args, 3);
                    DisplayInfo *info = MRKApplication::GetUIDisplayInfo();

                    float *w = va_arg(args, float*);
                    if (w)
                        *w = info->Width;

                    float *h = va_arg(args, float*);
                    if (h)
                        *h = info->Height;

                    float *pr = va_arg(args, float*);
                    if (pr)
                        *pr = info->PixelRatio;
                }
                    break;

                case MRKProxyCommand::GetMainDisplay: { //(void**, int*)
                    va_start(args, 2);
                    _GUI MRKDisplay *display = MRKApplication::GetUIDisplay();

                    void **_dptr = va_arg(args, void**);
                    if (_dptr)
                        *_dptr = display;

                    int *_idptr = va_arg(args, int*);
                    if (_idptr)
                        *_idptr = display->DisplayId();
                }
                    break;

                case MRKProxyCommand::RegisterLabel: {
                    va_start(args, 6);
                    void *parent = va_arg(args, void*);
                    MRKAnchor anchor = va_arg(args, MRKAnchor);
                    _MATH Rect rect = va_arg(args, _MATH
                            Rect);
                    const char *txt = va_arg(args, const char*);
                    float fontsize = va_arg(args, float);
                    void **handle = va_arg(args, void**);

                    if (handle) {
                        //no handle, no shit
                        *handle = new MRKGuiBaseLabel((MRKGuiBaseWidget *) parent, anchor, rect,
                                                      txt,
                                                      fontsize);
                    }
                }
                    break;

                case MRKProxyCommand::LabelGetText: {
                    va_start(args, 2);
                    void *handle = va_arg(args, void*);
                    char **cptr = va_arg(args, char**);

                    if (handle && cptr) {
                        _STD string txt = ((MRKGuiBaseLabel *) handle)->GetText();
                        *cptr = new char[txt.size() + 1];
                        strcpy(*cptr, txt.c_str());
                        //TODO: potential memory leak, store old ptrs somewhere and delete when recall
                    }
                }
                    break;

                case MRKProxyCommand::LabelSetText: {
                    va_start(args, 2);
                    void *handle = va_arg(args, void*);
                    const char *txt = va_arg(args, const char*);

                    if (handle)
                        ((MRKGuiBaseLabel *) handle)->SetText(txt);
                }
                    break;

                default:
                    return false;

            }

            va_end(args);
            return true;
        }
    }
}