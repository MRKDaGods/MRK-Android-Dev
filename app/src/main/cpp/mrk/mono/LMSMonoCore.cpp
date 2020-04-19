#include <android/log.h>
#include "LMSMonoAPI.h"
#include "../MRKLog.h"
#include "../dynamic/LMSDynamic.h"
#include "../utils/MRKUtils.h"

#define DT2_BUILD

namespace MRK
{
    namespace Mono
    {
        _STD string LMS_PACKAGE_NAME_MONO = "com.madfingergames.deadtrigger2";
        //_STD string LMS_PACKAGE_NAME_MONO = "io.github.MRK";

        void *NATIVE_PIPE_SENDMESSAGEF;
        void *NATIVE_PIPE_SENDMESSAGEI;
        void *NATIVE_PIPE_SENDMESSAGEB;
        void *NATIVE_PIPE_SENDMESSAGEPFPF;

        void *ASM_RECEIVER;
        void *ASM_DT2;

        void AsmIterator(void *asmz, void *)
        {
            void *img = mono_assembly_get_image(asmz);
            const char *name = mono_image_get_name(img);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat("Discovered image [Name=", name, "] [Address=", img, "]"));
            if (!strcmp(name, "LMSDT2"))
                ASM_DT2 = img;
            else if (!strcmp(name, "LMSReceiverServiceProvider"))
                ASM_RECEIVER = img;
        }

        void LMSCoreInit()
        {
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE, "Initializing LMSCore [MONO]");
            _DYNAMIC InitializeDynamic(LMS_PACKAGE_NAME_MONO);
            LMS_INIT_API();
            void *domain;
            if (!mono_get_root_domain || !(domain = mono_get_root_domain()))
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch domain!");
                return;
            }
            if (!mono_thread_attach)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not attach thread to mono!");
                return;
            }
            mono_thread_attach(domain);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat("Fetched domain [Address=", domain, "]"));
            if (!mono_assembly_foreach)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch assemblies!");
                return;
            }
            mono_assembly_foreach(AsmIterator, 0);
            if (!ASM_RECEIVER)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch receiver");
                return;
            }
            if (!mono_class_from_name)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch classes!");
                return;
            }
            void *nativepipe_class = mono_class_from_name(ASM_RECEIVER,
                                                          "LMSReceiverServiceProvider",
                                                          "NativePipe");
            if (!nativepipe_class)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch proxy native pipe");
                return;
            }
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat("Fetched proxy native pipe [Address=", nativepipe_class, "]"));
            if (!mono_class_get_method_from_name)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, "Could not fetch methods");
                return;
            }
            NATIVE_PIPE_SENDMESSAGEF = mono_class_get_method_from_name(nativepipe_class,
                                                                       "SendMessageF", 4);
            NATIVE_PIPE_SENDMESSAGEI = mono_class_get_method_from_name(nativepipe_class,
                                                                       "SendMessageI", 4);
            NATIVE_PIPE_SENDMESSAGEB = mono_class_get_method_from_name(nativepipe_class,
                                                                       "SendMessageB", 4);
            NATIVE_PIPE_SENDMESSAGEPFPF = mono_class_get_method_from_name(nativepipe_class,
                                                                          "SendMessagePFPF", 5);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat("Fetched proxy native pipe handlers [F=",
                                   NATIVE_PIPE_SENDMESSAGEF, "] [I=",
                                   NATIVE_PIPE_SENDMESSAGEI, "] [B=",
                                   NATIVE_PIPE_SENDMESSAGEB, "] [PFPF=",
                                   NATIVE_PIPE_SENDMESSAGEPFPF, "]"));
#ifdef DT2_BUILD
            mono_runtime_invoke(
                    mono_class_get_method_from_name(
                            mono_class_from_name(ASM_DT2,
                                                 "LMSDT2",
                                                 "HackManager"),
                            "NativeInit", 0), 0, 0, 0);
#endif
        }

        void SendMessageF(unsigned short c, unsigned short h, unsigned short o, float v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEF)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat("Pipe fault, [TYPE=F] [", c, ", ", h, ", ", o, ", ", v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEF, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void SendMessageI(unsigned short c, unsigned short h, unsigned short o, int v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEI)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat("Pipe fault, [TYPE=I] [", c, ", ", h, ", ", o, ", ", v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEI, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void SendMessageB(unsigned short c, unsigned short h, unsigned short o, bool v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEB)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat("Pipe fault, [TYPE=B] [", c, ", ", h, ", ", o, ", ", v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEB, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void SendMessagePFPF(unsigned short c, unsigned short h, unsigned short o, float *pF1,
                             float *pF2)
        {
            if (!NATIVE_PIPE_SENDMESSAGEPFPF)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat("Pipe fault, [TYPE=PFPF] [", c, ", ", h, ", ", o, ", ", pF1,
                                       ", ", pF2, "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEPFPF, 0,
                                new void *[5]{&c, &h, &o, pF1, pF2}, 0);
        }
    }
}