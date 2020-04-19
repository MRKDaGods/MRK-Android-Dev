#include <cmath>

#include "MRKUtils.h"

namespace MRK
{
    namespace Utils
    {
        const float S9_PLUS_FHDPLUS_WIDTH = 2220;
        const float S9_PLUS_FHDPLUS_HEIGHT = 1080;

        float LOCAL_WIDTH;
        float LOCAL_HEIGHT;
        float LOCAL_WIDTH_MODIFIER;
        float LOCAL_HEIGHT_MODIFIER;
        float LOCAL_FONT_MODIFIER;

        _STD array<char, 8> UTF8(int c)
        {
            _STD array<char, 8> seq;
            int n = 0;
            if (c < 0x80) n = 1;
            else if (c < 0x800) n = 2;
            else if (c < 0x10000) n = 3;
            else if (c < 0x200000) n = 4;
            else if (c < 0x4000000) n = 5;
            else if (c <= 0x7fffffff) n = 6;
            seq[n] = '\0';
            switch (n)
            {
                case 6:
                    seq[5] = 0x80 | (c & 0x3f);
                    c = c >> 6;
                    c |= 0x4000000;
                case 5:
                    seq[4] = 0x80 | (c & 0x3f);
                    c = c >> 6;
                    c |= 0x200000;
                case 4:
                    seq[3] = 0x80 | (c & 0x3f);
                    c = c >> 6;
                    c |= 0x10000;
                case 3:
                    seq[2] = 0x80 | (c & 0x3f);
                    c = c >> 6;
                    c |= 0x800;
                case 2:
                    seq[1] = 0x80 | (c & 0x3f);
                    c = c >> 6;
                    c |= 0xc0;
                case 1:
                    seq[0] = c;
            }
            return seq;
        }

        float CalculateRelativeHeight(float fhdPlus)
        {
            return fhdPlus * LOCAL_HEIGHT_MODIFIER;
        }

        float CalculateRelativeWidth(float fhdPlus)
        {
            return fhdPlus * LOCAL_WIDTH_MODIFIER;
        }

        float CalculateRelativeFont(float size)
        {
            return fmin(roundf(floor(LOCAL_WIDTH * size / 1000.f)),
                        roundf(floor(LOCAL_HEIGHT * size / 1000.f)));
        }

        float CalculateInverseHeight(float relative)
        {
            return relative / LOCAL_HEIGHT_MODIFIER;
        }

        float CalculateInverseWidth(float relative)
        {
            return relative / LOCAL_WIDTH_MODIFIER;
        }

        _STD string ResolutionString()
        {
            return _STD to_string((int)LOCAL_WIDTH) + " x " + _STD to_string((int)LOCAL_HEIGHT);
        }

        _STD string ModifiersString()
        {
            return _STD to_string(LOCAL_WIDTH_MODIFIER) + " x " + _STD to_string(LOCAL_HEIGHT_MODIFIER);
        }

        _STD string FontModifierString()
        {
            return _STD to_string(LOCAL_FONT_MODIFIER);
        }

        void SetLocalResolution(float width, float height)
        {
            LOCAL_WIDTH = width;
            LOCAL_HEIGHT = height;
            LOCAL_WIDTH_MODIFIER = LOCAL_WIDTH / S9_PLUS_FHDPLUS_WIDTH;
            LOCAL_HEIGHT_MODIFIER = LOCAL_HEIGHT / S9_PLUS_FHDPLUS_HEIGHT;
            LOCAL_FONT_MODIFIER =
                    (S9_PLUS_FHDPLUS_WIDTH / S9_PLUS_FHDPLUS_HEIGHT) / (LOCAL_WIDTH / LOCAL_HEIGHT);
        }

        char *AllocateFile(const char *path)
        {
            FILE *fl = fopen(path, "r");
            fseek(fl, 0, SEEK_END);
            long len = ftell(fl);
            char *ret = (char*)malloc(len);
            fseek(fl, 0, SEEK_SET);
            fread(ret, 1, len, fl);
            fclose(fl);
            return ret;
        }

        _STD string Vector3_ToString(_MATH Vector3 vector3)
        {
            _STD string str = _STD to_string(vector3.X()) + ", ";
            str += _STD to_string(vector3.Y()) + ", ";
            str += _STD to_string(vector3.Z());
            return str;
        }
    }
}