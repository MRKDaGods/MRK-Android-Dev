#include "MRKProxyDynamic.h"
#include "Concat.hpp"
#include "MRKProxyGUI.h"
#include "MRKProxyMGUI.h"

#include <dlfcn.h>

namespace MRK {
    typedef int (*__MRKProxyRegisterGUICallback)(GUI::MRKProxyGUICallback);

    typedef void (*__MRKProxySetColor)(float, float, float, float);

    typedef void (*__MRKProxyLabel)(float, float, float, float, const char *, float);

    typedef void (*__MRKProxyBox)(float, float, float, float);

    typedef void (*__MRKProxyLine)(float, float, float, float, float);

    typedef void (*__MRKProxyGetScreenInfo)(float *, float *, float *);

    typedef void (*__MRKGUIGetMainDisplay)(void**, int*); //handle, id
    typedef void (*__MRKGUIDisplayRegisterWidget)();

    __MRKProxyRegisterGUICallback _MRKProxyRegisterGUICallback;
    __MRKProxySetColor _MRKProxySetColor;
    __MRKProxyLabel _MRKProxyLabel;
    __MRKProxyBox _MRKProxyBox;
    __MRKProxyLine _MRKProxyLine;
    __MRKProxyGetScreenInfo _MRKProxyGetScreenInfo;
    __MRKGUIGetMainDisplay _MRKGUIGetMainDisplay;

    bool MRKProxyInitialize(const char *pkg) {

        void *mrk = dlopen(Utils::concat("/data/data/", pkg, "/lib/libmrk.so").c_str(), RTLD_LAZY);
        if (!mrk)
            return false;

        _MRKProxyRegisterGUICallback = (__MRKProxyRegisterGUICallback) dlsym(mrk,
                                                                             "MRKProxyRegisterGUICallback");
        _MRKProxySetColor = (__MRKProxySetColor) dlsym(mrk, "MRKProxySetColor");
        _MRKProxyLabel = (__MRKProxyLabel) dlsym(mrk, "MRKProxyLabel");
        _MRKProxyBox = (__MRKProxyBox) dlsym(mrk, "MRKProxyBox");
        _MRKProxyLine = (__MRKProxyLine) dlsym(mrk, "MRKProxyLine");
        _MRKProxyGetScreenInfo = (__MRKProxyGetScreenInfo) dlsym(mrk, "MRKProxyGetScreenInfo");
        _MRKGUIGetMainDisplay = (__MRKGUIGetMainDisplay) dlsym(mrk, "MRKGUIGetMainDisplay");
        return true;
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
            return _MRKProxyRegisterGUICallback(callback);
        }

        void MRKProxySetColor(float r, float g, float b, float a) {
            _MRKProxySetColor(r, g, b, a);
        }

        void MRKProxyLabel(float x, float y, float w, float h, const char *txt, float fontsize) {
            _MRKProxyLabel(x, y, w, h, txt, fontsize);
        }

        void MRKProxyBox(float x, float y, float w, float h) {
            _MRKProxyBox(x, y, w, h);
        }

        void MRKProxyLine(float x1, float y1, float x2, float y2, float width) {
            _MRKProxyLine(x1, y1, x2, y2, width);
        }

        void MRKProxyGetScreenInfo(float *w, float *h, float *pr) {
            _MRKProxyGetScreenInfo(w, h, pr);
        }

        //MGUI
        MRKGUIDisplay* ms_Display;

        MRKGUIWidget::MRKGUIWidget(MRK::GUI::MRKGUIWidget *parent, MRK::GUI::MRKAnchor anchor,
                                   MRK::Rect rect) : Parent(parent), Anchor(anchor), Rect(rect) {
        }

        MRKGUIDisplay::MRKGUIDisplay() : MRKGUIWidget(0, MRK_ANCHOR_NONE, Rect()) {
        }

        MRKGUILabel *MRKGUIDisplay::RegisterWidget(MRKGUILabel *widget) {

        }

        MRKGUIDisplay* MRKGUIGetMainDisplay() {
            if (!ms_Display)
                ms_Display = new MRKGUIDisplay;

            void *handle = 0;
            int id = -1;

            _MRKGUIGetMainDisplay(&handle, &id);

            ms_Display->Handle = handle;
            ms_Display->ID = id;

            return ms_Display;
        }
    }
}