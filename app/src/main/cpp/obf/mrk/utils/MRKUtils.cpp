#include <cmath>

#include "MRKUtils.h"

namespace MRK
{
    namespace Utils
    {
        const float S9_PLUS_FHDPLUS_WIDTH = 2220;
        const float S9_PLUS_FHDPLUS_HEIGHT = 1080;

        float myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV;
        float majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT;
        float miZ08M4Zt7FR9OtHAgzqDAdd0e7Xh6CmaSx2agbxs;
        float mxPGDE93g6xVjGDvyYEEzWYEfCiPGYn2I199UqPk2;
        float mB4BiJygEKUBPRVAlzdommwqo2wn2BiXa1LcASE32;

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

        float m8Dvs3abAMm7X9qOteFfsTkBxTduOZPdmWxKa69AW(float fhdPlus)
        {
            return fhdPlus * mxPGDE93g6xVjGDvyYEEzWYEfCiPGYn2I199UqPk2;
        }

        float mmFXr87sDx8o2q3BSIuvHNA21DnLdHEFerrgxLcTe(float fhdPlus)
        {
            return fhdPlus * miZ08M4Zt7FR9OtHAgzqDAdd0e7Xh6CmaSx2agbxs;
        }

        float mIyZLcO7BYivHIeNv97IgZrE1sxYuBHiLsMgRl3JH(float size)
        {
            return fmin(roundf(floor(myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV * size / 1000.f)),
                        roundf(floor(majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT * size / 1000.f)));
        }

        float me5S3ecX8RGQB2NItV1yYENnRngJgLTi1sS7WJ2Cp(float relative)
        {
            return relative / mxPGDE93g6xVjGDvyYEEzWYEfCiPGYn2I199UqPk2;
        }

        float mlxaGu5gabFKjlllT8xmxwfmeQxYjv48oygp13qo2(float relative)
        {
            return relative / miZ08M4Zt7FR9OtHAgzqDAdd0e7Xh6CmaSx2agbxs;
        }

        _STD string ResolutionString()
        {
            return _STD to_string((int)myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV) + MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483509,"I", new unsigned char [1] { (unsigned char)0 }).c_str() + _STD to_string((int)majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT);
        }

        _STD string ModifiersString()
        {
            return _STD to_string(miZ08M4Zt7FR9OtHAgzqDAdd0e7Xh6CmaSx2agbxs) + MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483508,"I", new unsigned char [1] { (unsigned char)0 }).c_str() + _STD to_string(mxPGDE93g6xVjGDvyYEEzWYEfCiPGYn2I199UqPk2);
        }

        _STD string FontModifierString()
        {
            return _STD to_string(mB4BiJygEKUBPRVAlzdommwqo2wn2BiXa1LcASE32);
        }

        void miP3KeKvoVScIVeve6CKg8uDWbAttakSwZs0HYK37(float myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn, float mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc)
        {
            myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV = myWunBjPT84nyspRAGizpyM06p5W0VB6F1rfgT1tn;
            majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT = mPiAyRciNli8RQr5B05JFiUEnITXqQ7JYZt8YH6dc;
            miZ08M4Zt7FR9OtHAgzqDAdd0e7Xh6CmaSx2agbxs = myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV / S9_PLUS_FHDPLUS_WIDTH;
            mxPGDE93g6xVjGDvyYEEzWYEfCiPGYn2I199UqPk2 = majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT / S9_PLUS_FHDPLUS_HEIGHT;
            mB4BiJygEKUBPRVAlzdommwqo2wn2BiXa1LcASE32 =
                    (S9_PLUS_FHDPLUS_WIDTH / S9_PLUS_FHDPLUS_HEIGHT) / (myySKTZLOBFysBBFVO0KsDEdOBJUMNzrt0KNjrfpV / majr1JD9xuzgg5eZOPxhQngVUcqehfJt9MHWXTaxT);
        }

        char *AllocateFile(const char *path)
        {
            FILE *fl = fopen(path, "r");
            fseek(fl, 0, SEEK_END);
            long mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0 = ftell(fl);
            char *ret = (char*)malloc(mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0);
            fseek(fl, 0, SEEK_SET);
            fread(ret, 1, mrKCCQJoUu7QZg9NZRnUvATYi0IdGcipYE3oxKlm0, fl);
            fclose(fl);
            return ret;
        }

        _STD string Vector3_ToString(_MATH m3HFtZu14QzkyQb62StxaeHcjHNlRiTaCmka0upJN vector3)
        {
            _STD string str = _STD to_string(vector3.mABe9PWiNoeGuc5pHr5SL3So3Ywd7C4skAsgg9c14()) + MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483507,"", new unsigned char [1] { (unsigned char)0 }).c_str();
            str += _STD to_string(vector3.m5pgf9f1mdcywbtyUSLfsf1IcVpRHGqH3mgz4aqs3()) + MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483506,"", new unsigned char [1] { (unsigned char)0 }).c_str();
            str += _STD to_string(vector3.Z());
            return str;
        }
    }
}