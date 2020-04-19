#pragma once

#include <map>
#include <vector>

#include "../../MRKLog.h"
#include "../MRKGuiComponent.h"

extern int MRK_PIC;
extern int SHANGO_PIC;
extern int DT2MS_PIC;

#define MRK_BUILD_VERSION "MRK(UI API v2.2)(MONO API v0.5)(IL2CPP API v2) - DT2(MONO) v1.5b [BETA BUILD]"

namespace MRK {
    namespace Components {
        class MRKGuiComponentBaseDT2_REF : public MRKGuiComponent {
        private:
            enum WidgetType {
                WIDGET_TYPE_BUTTON = 0,
                WIDGET_TYPE_LABEL = 1,
                WIDGET_TYPE_SLIDER = 2,
                WIDGET_TYPE_WINDOW = 3
            };

            struct HackOption {
                _STD string m_Name;
                _GUI MRKGuiBaseWidget *m_Widget;
                _GUI MRKGuiBaseLabel *m_WidgetLabel;
            };

            struct Hack {
                _STD string m_Name;
                _STD string m_Description;
                size_t m_OptionCount;
                HackOption *m_Options;
                _GUI MRKGuiBaseButton *m_Button;
            };

            struct Category {
                _STD string m_Name;
                _GUI MRKGuiBaseButton *m_Button;
                int m_HackCount;
                Hack *m_Hacks;
                Hack *m_SelectedHack;
            };

            struct DescriptorArray {
                size_t size;
                _STD string *desc;
            };

            class LogView {
            private:
                _STD vector<MRKLogEntry> *m_Logs;
                MRKGuiComponentBaseDT2_REF *m_Base;
                unsigned int m_ScrollValue;
            public:
                LogView(MRKGuiComponentBaseDT2_REF *base);

                void Draw(MRKUIcontext *ctx);

                unsigned int &ScrollOffset();
            };

#define CATEGORY_COUNT 5
#define DESCRIPTORS_COUNT 8

            Category *m_Categories;
            Category *m_SelectedCategory;
            _GUI MRKGuiBaseWindow *m_Container;
            _GUI MRKGuiBaseWindow *m_DescriptionWindow;
            _GUI MRKTheme m_DescWindowTheme;
            _STD map<WidgetType, _STD vector<_GUI MRKGuiBaseWidget *>> m_FreeWdigets;
            Hack *m_SelectedHack;
            _GUI MRKGuiBaseLabel *m_HackDescriptionLabel;
            DescriptorArray *m_Descriptors;
            _MATH Rect m_ButtonRect;
            _GUI MRKGuiBaseLabel *m_BuildLabel;
            LogView m_LogView;

            _GUI MRKGuiBaseWidget *GetFreeWidget(WidgetType type);

            void FreeWidget(_GUI MRKGuiBaseWidget *widget, WidgetType type);

            DescriptorArray *FindDescriptor(_STD string s);

            _STD string NextDescriptor(DescriptorArray *array, _STD string now, size_t *_i);

        public:
            MRKGuiComponentBaseDT2_REF(_GUI MRKDisplay *display);

            void GUI(MRKUIcontext *context) override;

            void SelectedHackChanged(Hack *newHack);
            //void SendMessageFloat(size_t category, size_t hack, size_t option, float value);
        };
    }
}