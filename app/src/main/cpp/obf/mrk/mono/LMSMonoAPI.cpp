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

        void mIMeGqUEEiP0qX67kgaIQEYThfv2XikUdiycywtzN()
        {
#ifdef DT2_BUILD
            _DYNAMIC DynamicLibrary dynamicLibrary = _DYNAMIC LoadLibrary(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483587,"]XS\^_^", new unsigned char [1] { (unsigned char)0 }).c_str());
#else
            void *handle = dlopen(
                    (MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483586,"UPEPUPEP", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str() + LMS_PACKAGE_NAME_MONO + MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483585,"]XS]XS\^_^SUFVRVTB^", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)20 }).c_str()).c_str(),
                    RTLD_LAZY);
#endif
            if (!dynamicLibrary)
            {
                LMSLog(LMS_LOGTYPE_ERROR, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483584,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483583,"r^D]U_^E]^PU]XS\^_^", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            _DYNAMIC mQ1FxlOQbaQkseyw28pcV4BzGKMu7R0A97iL98sp7 query = _DYNAMIC mQ1FxlOQbaQkseyw28pcV4BzGKMu7R0A97iL98sp7{
                    FUNCTION_COUNT,
                    new _STD string[FUNCTION_COUNT]{
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483582,"\^_^nR]PBBnWC^\n_P\T", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483581,"\^_^nVTEnC^^EnU^\PX_", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483580,"\^_^nEYCTPUnPEEPRY", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483579,"\^_^nX\PVTn^AT_nWC^\nUPEP", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483578,"\^_^nPBBT\S]Hn_P\Tn_TF", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483577,"\^_^nPBBT\S]Hn]^PUTU", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483576,"\^_^nPBBT\S]HnVTEnX\PVT", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483575,"\^_^nR]PBBnVTEn\TEY^UnWC^\n_P\T", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483574,"\^_^nCD_EX\TnX_G^ZT", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483573,"\^_^nU^\PX_nPBBT\S]Hn^AT_", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483572,"\^_^nPBBT\S]HnW^CTPRY", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483571,"\^_^nX\PVTnVTEn_P\T", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str()
                    }
            };
            _DYNAMIC mkn4W6G6xcavlrCUng12htbRkUDUEp6wkayCKjbOj mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP = _DYNAMIC m6rtXStwWZAxqVgGHFGaSN4iJKTjfC0UHDiJZnATV(dynamicLibrary, query);
            LMSLog(LMS_LOGTYPE_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483570,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(),
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483569,"uH_P\XRBwD]]Hx_XEXP]XKTUjr^_BXBET_RH", new unsigned char [5] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                                   mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP.mVsb5nRAxfEd43aG8l9i5F9vcQC9HiSqU8QblPQl3, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483568,"ljbDRRTBBr^D_E", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP.SuccessfulCount,
                                   "/", query.QuerySize, "]"));
            if (mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP.SuccessfulCount != query.QuerySize)
            {
                LMSLog(LMS_LOGTYPE_WARNING, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483567,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(),
                       MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483566,"x\AC^ATCR^_BXBET_RHrCPBYTB\XVYE^RRDC", new unsigned char [6] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
            }
            LMSLog(LMS_LOGTYPE_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483565,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483564,"wD_REX^_B", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str());
            for (size_t i = 0; i < mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP.FunctionCount; i++)
            {
                _DYNAMIC myAP8pI9a155LZm0shbwBFyQnUYiPXzIVKZN68VE3 *dynamicFunction = &mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP.Functions[i];
                LMSLog(LMS_LOGTYPE_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483563,"|czuH_P\XR", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(),
                       _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483562,"", new unsigned char [1] { (unsigned char)0 }).c_str(), dynamicFunction->Name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483561,"j", new unsigned char [1] { (unsigned char)0 }).c_str(),
                                       (void *) dynamicFunction->Ptr, "]"));
                *IndexPointerMapping[i] = (void*)dynamicFunction->Ptr;
            }
        }
    }
}