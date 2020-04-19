#pragma once

namespace MRK {
    struct Rect {
    private:
        float m_X;
        float m_Y;
        float m_W;
        float m_H;

    public:
        Rect();
        Rect(float x, float y, float w, float h);
        float X();
        float Y();
        float Width();
        float Height();
    };

    namespace GUI {
        struct MRKGUIDisplay;
        struct MRKGUILabel;

        enum MRKAnchor
        {
            MRK_ANCHOR_NONE = 0, //hack elements
            MRK_ANCHOR_TOP = 1,
            MRK_ANCHOR_MIDDLE = 2,
            MRK_ANCHOR_BOTTOM = 4,
            MRK_ANCHOR_CENTER = 8,
            MRK_ANCHOR_LEFT = 16,
            MRK_ANCHOR_RIGHT = 32,

            MRK_ANCHOR_TOP_LEFT = MRK_ANCHOR_TOP | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_TOP_CENTER = MRK_ANCHOR_TOP | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_TOP_RIGHT = MRK_ANCHOR_TOP | MRK_ANCHOR_RIGHT,
            MRK_ANCHOR_MIDDLE_LEFT = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_MIDDLE_CENTER = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_MIDDLE_RIGHT = MRK_ANCHOR_MIDDLE | MRK_ANCHOR_RIGHT,
            MRK_ANCHOR_BOTTOM_LEFT = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_LEFT,
            MRK_ANCHOR_BOTTOM_CENTER = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_CENTER,
            MRK_ANCHOR_BOTTOM_RIGHT = MRK_ANCHOR_BOTTOM | MRK_ANCHOR_RIGHT
        };

        struct MRKGUIWidget {
            void* Handle;
            MRKGUIDisplay* Display;
            MRKGUIWidget* Parent;
            MRKAnchor Anchor;

            MRKGUIWidget(MRKGUIWidget* parent, MRKAnchor anchor, Rect rect);
        };

        struct MRKGUIDisplay : public MRKGUIWidget {
            int ID;

            MRKGUIDisplay();
            MRKGUILabel* RegisterWidget(MRKGUILabel* widget);
        };

        struct MRKGUILabel : public MRKGUIWidget {
            const char* GetText();
            void SetText(const char* text);

            MRKGUILabel(MRKGUIWidget* parent, MRKAnchor anchor, Rect rect);
        };

        extern MRKGUIDisplay* MRKGUIGetMainDisplay();
    }
}