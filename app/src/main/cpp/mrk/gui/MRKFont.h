#pragma once

namespace MRK
{
    namespace GUI
    {
        struct MRKFont
        {
            static MRKFont *Sans;
            static MRKFont *SansBold;
            static MRKFont *Exo2Bold;
            static MRKFont *Exo2Regular;
            static MRKFont *LBF;

            MRKFont(const char *name);
            const char *FontFaceStr;
        };

        inline MRKFont *MRKFont::Sans = new MRKFont("sans");
        inline MRKFont *MRKFont::SansBold = new MRKFont("sans-bold");
        inline MRKFont *MRKFont::Exo2Bold = new MRKFont("exo2bold");
        inline MRKFont *MRKFont::Exo2Regular = new MRKFont("exo2regular");
        inline MRKFont *MRKFont::LBF = new MRKFont("lbf");

        inline MRKFont::MRKFont(const char *name)
        {
            //copy the string over
            FontFaceStr = strcpy(new char[strlen(name) + 1],  name);
        }
    }
}