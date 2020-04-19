#include <dlfcn.h>

#include "LMSMonoAPI.h"
#include "../dynamic/LMSDynamic.h"
#include "../MRKLog.h"
#include "../utils/MRKUtils.h"

#define DT2_BUILD
#define FUNCTION_COUNT 12

namespace MRK
{
    namespace Mono
    {
        __mono_class_from_name mono_class_from_name;
        __mono_get_root_domain mono_get_root_domain;
        __mono_thread_attach mono_thread_attach;
        __mono_image_open_from_data mono_image_open_from_data;
        __mono_assembly_name_new mono_assembly_name_new;
        __mono_assembly_loaded mono_assembly_loaded;
        __mono_assembly_get_image mono_assembly_get_image;
        __mono_class_get_method_from_name mono_class_get_method_from_name;
        __mono_runtime_invoke mono_runtime_invoke;
        __mono_domain_assembly_open mono_domain_assembly_open;
        __mono_assembly_foreach mono_assembly_foreach;
        __mono_image_get_name mono_image_get_name;

        static void ***IndexPointerMapping = new void**[FUNCTION_COUNT]{
                (void **) &mono_class_from_name,
                (void **) &mono_get_root_domain,
                (void **) &mono_thread_attach,
                (void **) &mono_image_open_from_data,
                (void **) &mono_assembly_name_new,
                (void **) &mono_assembly_loaded,
                (void **) &mono_assembly_get_image,
                (void **) &mono_class_get_method_from_name,
                (void **) &mono_runtime_invoke,
                (void **) &mono_domain_assembly_open,
                (void **) &mono_assembly_foreach,
                (void **) &mono_image_get_name
        };

        void LMS_INIT_API()
        {
#ifdef DT2_BUILD
            _DYNAMIC DynamicLibrary dynamicLibrary = _DYNAMIC LoadLibrary("libmono");
#else
            void *handle = dlopen(
                    ("/data/data/" + LMS_PACKAGE_NAME_MONO + "/lib/libmonobdwgc-2.0.so").c_str(),
                    RTLD_LAZY);
#endif
            if (!dynamicLibrary)
            {
                LMSLog(LMS_LOGTYPE_ERROR, "MRK-Dynamic", "Could not load libmono");
                return;
            }
            _DYNAMIC DynamicSearchQuery query = _DYNAMIC DynamicSearchQuery{
                    FUNCTION_COUNT,
                    new _STD string[FUNCTION_COUNT]{
                            "mono_class_from_name",
                            "mono_get_root_domain",
                            "mono_thread_attach",
                            "mono_image_open_from_data",
                            "mono_assembly_name_new",
                            "mono_assembly_loaded",
                            "mono_assembly_get_image",
                            "mono_class_get_method_from_name",
                            "mono_runtime_invoke",
                            "mono_domain_assembly_open",
                            "mono_assembly_foreach",
                            "mono_image_get_name"
                    }
            };
            _DYNAMIC DynamicSearchResult result = _DYNAMIC Search(dynamicLibrary, query);
            LMSLog(LMS_LOGTYPE_INFO, "MRK-Dynamic",
                   _UTILITY concat("Dynamics Fully Initialized [Consistency=",
                                   result.SuccessRate, "%] [SuccessCount=", result.SuccessfulCount,
                                   "/", query.QuerySize, "]"));
            if (result.SuccessfulCount != query.QuerySize)
            {
                LMSLog(LMS_LOGTYPE_WARNING, "MRK-Dynamic",
                       "Improper consistency... Crashes might occur!");
            }
            LMSLog(LMS_LOGTYPE_INFO, "MRK-Dynamic", "Functions:");
            for (size_t i = 0; i < result.FunctionCount; i++)
            {
                _DYNAMIC DynamicFunction *dynamicFunction = &result.Functions[i];
                LMSLog(LMS_LOGTYPE_INFO, "MRK-Dynamic",
                       _UTILITY concat("        ", dynamicFunction->Name, " [",
                                       (void *) dynamicFunction->Ptr, "]"));
                *IndexPointerMapping[i] = (void*)dynamicFunction->Ptr;
            }
        }
    }
}