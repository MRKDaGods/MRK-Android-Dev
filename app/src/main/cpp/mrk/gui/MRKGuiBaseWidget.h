#pragma once

#include <vector>
#include <string>

#include "../MRKCommon.h"
#include "../math/Vector2.h"
#include "../math/Rect.h"
#include "MRKTheme.h"
#include "../MRKTouchEvent.h"
#include "../utils/MRKUtils.h"
#include "../utils/DupSafeVector.hpp"

namespace MRK {
    namespace GUI {
        class MRKGuiBaseWidget;

        enum MRKAnchor {
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

        enum MRKWidgetInitFlags {
            MRK_WIDGET_INIT_FLAG_NONE = 0,
            MRK_WIDGET_INIT_FLAG_NO_SIZE = 1,
            MRK_WIDGET_INIT_FLAG_NO_ANCHOR = 2
        };

        struct WidgetInitOptions {
            MRKGuiBaseWidget *Parent;
            MRKAnchor Anchor;
            _MATH Rect Rect;
            MRKWidgetInitFlags Flags;
        };

        class MRKGuiBaseWidget {
        protected:
            MRKGuiBaseWidget *m_Parent;
            _UTILITY DupSafeVector<MRKGuiBaseWidget *> m_Children;
            bool m_Visible;
            bool m_Focused;
            bool m_Interactable;
            bool m_MouseFocus;
            _STD string m_Tooltip;
            _MATH Vector2 m_Size;
            _MATH Vector2 m_FixedSize;
            _MATH Vector2 m_Position;
            MRKTheme *m_Theme;
            _MATH Rect m_Rect;
            float m_IconScale;
            MRKAnchor m_Anchor;

            void RecalculateAnchors();

            void RecalculateSize();

        public:
            MRKGuiBaseWidget(MRKGuiBaseWidget *parent, MRKAnchor anchor, _MATH Rect rect,
                             MRKWidgetInitFlags flags = MRK_WIDGET_INIT_FLAG_NONE);

            ~MRKGuiBaseWidget();

            virtual void Draw(MRKUIcontext *context);

            virtual void SetTheme(MRKTheme *theme);

            virtual void ReInit(WidgetInitOptions options);

            bool Visible();

            void SetVisible(bool visible);

            _MATH Vector2 Position();

            _MATH Rect Rectangle();

            MRKTheme *Theme();

            virtual bool HandleTouchEvent(MRKTouchEvent &event);

            void UpdateFocusState(bool focused);

            void NotifyPositionChanged();

            void NotifyRectangleChanged();

            void NotifySizeChanged();

            bool Focused();

            void AddChild(MRKGuiBaseWidget *widget);

            MRKGuiBaseWidget *FindWidget(_MATH Vector2 pos);

            _MATH Rect ScreenRect();

            _MATH Vector2 S9Plus_FHDPLUS_Position();

            _MATH Vector2 S9Plus_FHDPLUS_Size();

            _MATH Rect S9Plus_FHDPLUS_Rect();

            void SetS9Plus_FHDPLUS_Size(_MATH Vector2 size);

            void SetS9Plus_FHDPLUS_Position(_MATH Vector2 pos);

            virtual int Id();
        };
    }
}