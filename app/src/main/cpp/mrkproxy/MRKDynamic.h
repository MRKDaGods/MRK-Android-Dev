#pragma once

#include <string>

#include "MRKCommon.h"

namespace MRK {
    namespace Dynamic {
        typedef void *DynamicLibrary;

        struct DynamicFunction {
            _STD string Name;

            void *(*Ptr)(...);
        };

        struct DynamicSearchResult {
            size_t FunctionCount;
            DynamicFunction *Functions;
            float SuccessRate;
            size_t SuccessfulCount;

            ~DynamicSearchResult();
        };

        struct DynamicSearchQuery {
            size_t QuerySize;
            _STD string *Functions;
        };

        _STD string GetPackageName();

        void InitializeDynamic(_STD string pkg);

        DynamicLibrary LoadLibrary(_STD string name);

        DynamicLibrary LoadLibraryEx(_STD string container, _STD string name);

        DynamicSearchResult Search(DynamicLibrary library, DynamicSearchQuery query);
    }
}