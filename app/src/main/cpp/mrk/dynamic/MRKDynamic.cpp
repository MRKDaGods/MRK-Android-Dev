#include "MRKDynamic.h"
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

        void InitializeDynamic(_STD string pkg)
        {
            GPackageName = pkg;
            MRKLog(MRK_LOGTYPE_INFO, "MRK-Dynamic",
                   _UTILITY concat("Dynamic Initialization [PKG='", pkg, "']"));
        }

        DynamicLibrary LoadLibrary(_STD string name)
        {
            return LoadLibraryEx(_UTILITY concat("/data/data/", GPackageName, "/lib"), _STD move(name));
            //return dlopen(_UTILITY concat("/data/data/", GPackageName, "/lib/", name, ".so").c_str(),
            //              RTLD_LAZY);
        }

        DynamicLibrary LoadLibraryEx(_STD string container, _STD string name)
        {
            return dlopen(_UTILITY concat(container, "/", name, ".so").c_str(), RTLD_LAZY);
        }

        DynamicSearchResult Search(DynamicLibrary library, DynamicSearchQuery query)
        {
            DynamicFunction *f = new DynamicFunction[query.QuerySize];
            size_t sc = 0;
            for (size_t i = 0; i < query.QuerySize; i++)
            {
                void *ptr = dlsym(library, query.Functions[i].c_str());
                if (ptr)
                    sc++;
                f[i] = DynamicFunction{
                        query.Functions[i],
                        (void *(*)(...)) ptr
                };
            }
            return DynamicSearchResult{
                    query.QuerySize,
                    f,
                    ((float) sc) / query.QuerySize * 100.f,
                    sc
            };
        }

        DynamicSearchResult::~DynamicSearchResult()
        {
            if (Functions)
                delete(Functions);
        }
    }
}