#include "MRKProxy.h"
#include "MRKApplication.h"
#include "gui/MRKGUI.h"
#include "gui/MRKDisplay.h"

namespace MRK {
    namespace GUI {
        JNIEXPORT int JNICALL MRKProxyRegisterGUICallback(MRKProxyGUICallback callback) {
            return MRKApplication::RegisterProxyGUI(callback);
        }

        JNIEXPORT void JNICALL MRKProxySetColor(float r, float g, float b, float a) {
            MRKGUI::SetColor(MRKColor(r, g, b, a));
        }

        JNIEXPORT void JNICALL
        MRKProxyLabel(float x, float y, float w, float h, const char *txt, float fontsize) {
            MRKGUI::Label(_MATH Rect(x, y, w, h), txt, fontsize);
        }

        JNIEXPORT void JNICALL MRKProxyBox(float x, float y, float w, float h) {
            MRKGUI::Box(_MATH Rect(x, y, w, h));
        }

        JNIEXPORT void JNICALL MRKProxyLine(float x1, float y1, float x2, float y2, float width) {
            MRKGUI::Line(_MATH Vector2(x1, y1), _MATH Vector2(x2, y2), width);
        }

        JNIEXPORT void JNICALL MRKProxyGetScreenInfo(float *w, float *h, float *pr) {
            DisplayInfo *info = MRKApplication::GetUIDisplayInfo();

            if (w)
                *w = info->Width;

            if (h)
                *h = info->Height;

            if (pr)
                *pr = info->PixelRatio;
        }
    }
}