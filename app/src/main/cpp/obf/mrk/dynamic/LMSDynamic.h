#pragma once

#include <dlfcn.h>
#include <string>

#include "src/main/cpp/lms/LMSCommon.h"

namespace MRK
{
    namespace Dynamic
    {
        typedef void *DynamicLibrary;

        struct myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3
        {
            _STD string Name;
            void*(*Ptr)(...);
        };

        struct mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj
        {
            size_t FunctionCount;
            myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3 *Functions;
            float mVsb5nRAxfEd43aG8l9i5F9vcQC9HiSqU8QblPQl3;
            size_t SuccessfulCount;

            ~mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj();
        };

        struct mQ1FxlOQbaQkseyw28pcV4BzGKMu7R0A97iL98sp7
        {
            size_t QuerySize;
            _STD string *Functions;
        };

        _STD string GetPackageName();
        void mrc2DN1QsUKocr83NHbuVGH4149u73JC6Kcks6uv5(_STD string pkg);
        DynamicLibrary LoadLibrary(_STD string name);
        DynamicLibrary LoadLibraryEx(_STD string container, _STD string name);
        mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj m6rtXStwWZAxqVgGHFGaSN4iJKTjfC0UHDiJZnATV(DynamicLibrary library, mQ1FxlOQbaQkseyw28pcV4BzGKMu7R0A97iL98sp7 query);
    }
}