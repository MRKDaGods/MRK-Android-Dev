#pragma once

namespace MRK
{
    namespace mHRlREm68AHCNb4IjMWn0zNCsS7o4vrHFJ3yLTRCH
    {
        struct myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB
        {
            static myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *Sans;
            static myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *SansBold;
            static myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *Exo2Bold;
            static myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *Exo2Regular;
            static myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *LBF;

            myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(const char *name);
            const char *FontFaceStr;
        };

        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::Sans = new myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483614,"BP_B", new unsigned char [1] { (unsigned char)0 }).c_str());
        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::SansBold = new myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483613,"BP_BS^]U", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str());
        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::Exo2Bold = new myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483612,"TI^VS^]U", new unsigned char [1] { (unsigned char)8 }).c_str());
        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::Exo2Regular = new myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483611,"TI^VCTVD]PC", new unsigned char [2] { (unsigned char)8, (unsigned char)0 }).c_str());
        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB *myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::LBF = new myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483610,"]SW", new unsigned char [1] { (unsigned char)0 }).c_str());

        inline myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB::myRWG6Xhws2jYnEDyHhxIoUJQ0EX9b37yLNICo6GB(const char *name)
        {
            //copy the string over
            FontFaceStr = strcpy(new char[strlen(name) + 1],  name);
        }
    }
}