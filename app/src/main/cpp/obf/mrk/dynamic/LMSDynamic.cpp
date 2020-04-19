#include "LMSDynamic.h"
#include "../MRKLog.h"
#include "../utils/MRKUtils.h"

#include <utility>

namespace MRK
{
    namespace Dynamic
    {
        static _STD string GPackageName;

        _STD string GetPackageName()
        {
            return GPackageName;
        }

        void mrc2DN1QsUKocr83NHbuVGH4149u73JC6Kcks6uv5(_STD string pkg)
        {
            GPackageName = pkg;
            LMSLog(LMS_LOGTYPE_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483628,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(),
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483627,"uH_P\XRx_XEXP]XKPEX^_jazv", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), pkg, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483626,"l", new unsigned char [1] { (unsigned char)0 }).c_str()));
        }

        DynamicLibrary LoadLibrary(_STD string name)
        {
            return LoadLibraryEx(_UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483625,"UPEPUPEP", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), GPackageName, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483624,"]XS", new unsigned char [1] { (unsigned char)0 }).c_str()), _STD move(name));
            //return dlopen(_UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483623,"UPEPUPEP", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), GPackageName, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483622,"]XS", new unsigned char [1] { (unsigned char)0 }).c_str(), name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483621,"B^", new unsigned char [1] { (unsigned char)0 }).c_str()).c_str(),
            //              RTLD_LAZY);
        }

        DynamicLibrary LoadLibraryEx(_STD string container, _STD string name)
        {
            return dlopen(_UTILITY concat(container, "/", name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483620,"B^", new unsigned char [1] { (unsigned char)0 }).c_str()).c_str(), RTLD_LAZY);
        }

        mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj m6rtXStwWZAxqVgGHFGaSN4iJKTjfC0UHDiJZnATV(DynamicLibrary library, mQ1FxlOQbaQkseyw28pcV4BzGKMu7R0A97iL98sp7 query)
        {
            myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3 *f = new myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3[query.QuerySize];
            size_t sc = 0;
            for (size_t i = 0; i < query.QuerySize; i++)
            {
                void *ptr = dlsym(library, query.Functions[i].c_str());
                if (ptr)
                    sc++;
                f[i] = myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3{
                        query.Functions[i],
                        (void *(*)(...)) ptr
                };
            }
            return mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj{
                    query.QuerySize,
                    f,
                    ((float) sc) / query.QuerySize * 100.f,
                    sc
            };
        }

        mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj::~mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj()
        {
            if (Functions)
                delete(Functions);
        }
    }
}