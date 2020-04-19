#pragma once

#include <string>

#include "../MRKCommon.h"
#include "../MRKColor.h"
#include "../math/Rect.h"
#include "../utils/MRKUtils.h"

namespace MRK
{
    namespace GUI
    {
        class MRKGUI
        {
        private:
            static MRKColor ms_DrawColor;
            static MRKUIcontext *ms_Context;
        public:
            static void StartFrame(MRKUIcontext *context);
            static void EndFrame();
            static void Box(_MATH Rect rect);
            static void Label(_MATH Rect rect, _STD string text, float fontSize = 24);
            static void SetColor(MRKColor color);
            static void Picture(_MATH Rect rect, int picture);
            static void Line(_MATH Vector2 start, _MATH Vector2 end, float width);
        };
    }
}