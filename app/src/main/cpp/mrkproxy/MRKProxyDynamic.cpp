#include "MRKProxyDynamic.h"
#include "Concat.hpp"
#include "MRKProxyGUI.h"
#include "MRKProxyMGUI.h"
#include "MRKDynamic.h"

#include <dlfcn.h>

namespace MRK {
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

    namespace Dynamic {
        bool MRKProxyInitialize(const char *pkg) {


        }
    }

    Rect::Rect() : Rect(0.f, 0.f, 0.f, 0.f) {
    }

    Rect::Rect(float x, float y, float w, float h) {
        m_X = x;
        m_Y = y;
        m_W = w;
        m_H = h;
    }

    float Rect::X() {
        return m_X;
    }

    float Rect::Y() {
        return m_Y;
    }

    float Rect::Width() {
        return m_W;
    }

    float Rect::Height() {
        return m_H;
    }

    namespace GUI {
        int MRKProxyRegisterGUICallback(MRKProxyGUICallback callback) {
            int _id = -1;
            MRKProxyProcessCommand(MRKProxyCommand::RegisterGUICallback)(callback, &_id);

            return _id;
        }

        void MRKProxySetColor(float r, float g, float b, float a) {
            MRKProxyProcessCommand(MRKProxyCommand::SetColor)(r, g, b, a);
        }

        void MRKProxyLabel(float x, float y, float w, float h, const char *txt, float fontsize) {
            //((__MRKProxyLabel)dlsym(dlopen(Utils::concat("/data/data/", "io.github.mrkdagods.mrkandroidhaxexternal", "/lib/libmrk.so").c_str(), RTLD_LAZY), "MRKProxyLabel"))(x, y, w, h, txt, fontsize);
            //MRKProxyProcessCommand(MRKProxyCommand::Label)(x, y, w, h, txt, fontsize);
        }

        void MRKProxyBox(float x, float y, float w, float h) {
            mkkk(x, y, w, h);
            //MRKProxyProcessCommand(MRKProxyCommand::Box)(x, y, w, h);
        }

        void MRKProxyLine(float x1, float y1, float x2, float y2, float width) {
            MRKProxyProcessCommand(MRKProxyCommand::Line)(x1, y1, x2, y2, width);
        }

        void MRKProxyGetScreenInfo(float *w, float *h, float *pr) {
            MRKProxyProcessCommand(MRKProxyCommand::GetScreenInfo)(w, h, pr);
        }

        //MGUI
        MRKGUIDisplay* ms_Display;

        //DISPLAY
        MRKGUIWidget::MRKGUIWidget(MRK::GUI::MRKGUIWidget *parent, MRK::GUI::MRKAnchor anchor,
                                   MRK::Rect rect) : Parent(parent), Anchor(anchor), WRect(rect) {
        }

        MRKGUIDisplay::MRKGUIDisplay() : MRKGUIWidget(0, MRK_ANCHOR_NONE, Rect()) {
        }

        MRKGUILabel *
        MRKGUIDisplay::RegisterLabel(MRKAnchor anchor, Rect rect, const char *txt, float fontsize,
                                     MRKGUIWidget *parent) {
            if (!parent)
                parent = this;

            void *handle = 0;

            MRKProxyProcessCommand(MRKProxyCommand::RegisterLabel)(parent->Handle, anchor, rect.X(),
                                                                   rect.Y(), rect.Width(),
                                                                   rect.Height(), txt, fontsize,
                                                                   &handle);

            if (!handle)
                return 0;

            MRKGUILabel *label = new MRKGUILabel(parent, anchor, rect);
            label->Handle = handle;

            return label;
        }

        MRKGUIDisplay* MRKGUIGetMainDisplay() {
            if (!ms_Display)
                ms_Display = new MRKGUIDisplay;

            void *handle = 0;
            int id = -1;

            MRKProxyProcessCommand(MRKProxyCommand::GetMainDisplay)(&handle, &id);

            ms_Display->Handle = handle;
            ms_Display->ID = id;

            return ms_Display;
        }

        //LABEL
        const char *MRKGUILabel::GetText() {
            char *chz = 0;
            MRKProxyProcessCommand(MRKProxyCommand::LabelGetText)(Handle, &chz);

            return chz;
        }

        void MRKGUILabel::SetText(const char *text) {
            MRKProxyProcessCommand(MRKProxyCommand::LabelSetText)(Handle, text);
        }

        MRKGUILabel::MRKGUILabel(MRKGUIWidget *parent, MRKAnchor anchor, Rect rect) : MRKGUIWidget(
                parent, anchor, rect) {
        }
    }
}