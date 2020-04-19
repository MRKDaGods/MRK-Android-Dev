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
        _STD string LMS_PACKAGE_NAME_MONO = MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483560,"R^\\PUWX_VTCVP\TBUTPUECXVVTCV", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)64 }).c_str();
        //_STD string LMS_PACKAGE_NAME_MONO = MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483559,"X^VXEYDS|cz", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str();

        void *NATIVE_PIPE_SENDMESSAGEF;
        void *NATIVE_PIPE_SENDMESSAGEI;
        void *NATIVE_PIPE_SENDMESSAGEB;
        void *NATIVE_PIPE_SENDMESSAGEPFPF;

        void *ASM_RECEIVER;
        void *ASM_DT2;

        void mv6bb6agbGe2KOXKjP5NQIS89oFgrXygtdGCQ3k6u(void *asmz, void *)
        {
            void *img = mono_assembly_get_image(asmz);
            const char *name = mono_image_get_name(img);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483558,"uXBR^GTCTUX\PVTjP\T", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483557,"ljpUUCTBB", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), img, "]"));
            if (!strcmp(name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483556,"}|bueV", new unsigned char [1] { (unsigned char)32 }).c_str()))
                ASM_DT2 = img;
            else if (!strcmp(name, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483555,"}|bcTRTXGTCbTCGXRTaC^GXUTC", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str()))
                ASM_RECEIVER = img;
        }

        void mzMMEmfl7CqR5qGRU4cAo3AuaAmS4J3YPSdTJpJZK()
        {
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483554,"x_XEXP]XKX_V}|br^CTj|~~l", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
            _DYNAMIC mrc2DN1QsUKocr83NHbuVGH4149u73JC6Kcks6uv5(LMS_PACKAGE_NAME_MONO);
            mIMeGqUEEiP0qX67kgaIQEYThfv2XikUdiycywtzN();
            void *domain;
            if (!mono_get_root_domain || !(domain = mono_get_root_domain()))
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483553,"r^D]U_^EWTERYU^\PX_", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            if (!mono_thread_attach)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483552,"r^D]U_^EPEEPRYEYCTPUE^\^_^", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            mono_thread_attach(domain);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483551,"wTERYTUU^\PX_jpUUCTBB", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), domain, "]"));
            if (!mono_assembly_foreach)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483550,"r^D]U_^EWTERYPBBT\S]XTB", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            mono_assembly_foreach(mv6bb6agbGe2KOXKjP5NQIS89oFgrXygtdGCQ3k6u, 0);
            if (!ASM_RECEIVER)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483549,"r^D]U_^EWTERYCTRTXGTC", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            if (!mono_class_from_name)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483548,"r^D]U_^EWTERYR]PBBTB", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            void *nativepipe_class = mono_class_from_name(ASM_RECEIVER,
                                                          MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483547,"}|bcTRTXGTCbTCGXRTaC^GXUTC", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                                                          MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483546,"PEXGTaXAT", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str());
            if (!nativepipe_class)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483545,"r^D]U_^EWTERYAC^IH_PEXGTAXAT", new unsigned char [5] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483544,"wTERYTUAC^IH_PEXGTAXATjpUUCTBB", new unsigned char [5] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), nativepipe_class, "]"));
            if (!mono_class_get_method_from_name)
            {
                LMSLog(LMS_LOGTYPE_ERROR, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483543,"r^D]U_^EWTERY\TEY^UB", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str());
                return;
            }
            NATIVE_PIPE_SENDMESSAGEF = mono_class_get_method_from_name(nativepipe_class,
                                                                       MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483542,"bT_U|TBBPVTw", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), 4);
            NATIVE_PIPE_SENDMESSAGEI = mono_class_get_method_from_name(nativepipe_class,
                                                                       MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483541,"bT_U|TBBPVTx", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), 4);
            NATIVE_PIPE_SENDMESSAGEB = mono_class_get_method_from_name(nativepipe_class,
                                                                       MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483540,"bT_U|TBBPVTs", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), 4);
            NATIVE_PIPE_SENDMESSAGEPFPF = mono_class_get_method_from_name(nativepipe_class,
                                                                          MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483539,"bT_U|TBBPVTawaw", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), 5);
            LMSLog(LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE,
                   _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483538,"wTERYTUAC^IH_PEXGTAXATYP_U]TCBjw", new unsigned char [5] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(),
                                   NATIVE_PIPE_SENDMESSAGEF, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483537,"ljx", new unsigned char [1] { (unsigned char)0 }).c_str(),
                                   NATIVE_PIPE_SENDMESSAGEI, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483536,"ljs", new unsigned char [1] { (unsigned char)0 }).c_str(),
                                   NATIVE_PIPE_SENDMESSAGEB, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483535,"ljawaw", new unsigned char [1] { (unsigned char)0 }).c_str(),
                                   NATIVE_PIPE_SENDMESSAGEPFPF, "]"));
#ifdef DT2_BUILD
            mono_runtime_invoke(
                    mono_class_get_method_from_name(
                            mono_class_from_name(ASM_DT2,
                                                 MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483534,"}|bueV", new unsigned char [1] { (unsigned char)32 }).c_str(),
                                                 MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483533,"yPRZ|P_PVTC", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str()),
                            MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483532,"PEXGTx_XE", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), 0), 0, 0, 0);
#endif
        }

        void mdJMZkBAtZsuWKYDhnUGUuVHPttLC66ZjKDPyp3M2(unsigned short c, unsigned short h, unsigned short o, float v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEF)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483531,"aXATWPD]Ejehatwlj", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), c, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483530,"", new unsigned char [1] { (unsigned char)0 }).c_str(), h, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483529,"", new unsigned char [1] { (unsigned char)0 }).c_str(), o, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483528,"", new unsigned char [1] { (unsigned char)0 }).c_str(), v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEF, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void mUyCwicArzzioEB11DR4bNn1mza4u9D6t51D8F8YM(unsigned short c, unsigned short h, unsigned short o, int v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEI)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483527,"aXATWPD]Ejehatxlj", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), c, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483526,"", new unsigned char [1] { (unsigned char)0 }).c_str(), h, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483525,"", new unsigned char [1] { (unsigned char)0 }).c_str(), o, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483524,"", new unsigned char [1] { (unsigned char)0 }).c_str(), v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEI, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void mm5LfKItqVttAfaUizk3HpjoEafnSbR48UQOTaGmu(unsigned short c, unsigned short h, unsigned short o, bool v)
        {
            if (!NATIVE_PIPE_SENDMESSAGEB)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483523,"aXATWPD]Ejehatslj", new unsigned char [3] { (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), c, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483522,"", new unsigned char [1] { (unsigned char)0 }).c_str(), h, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483521,"", new unsigned char [1] { (unsigned char)0 }).c_str(), o, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483520,"", new unsigned char [1] { (unsigned char)0 }).c_str(), v,
                                       "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEB, 0, new void *[4]{&c, &h, &o, &v}, 0);
        }

        void mFTNbZStogxaCCBK8a61S0Fa2bMwhIFqppE6PA763(unsigned short c, unsigned short h, unsigned short o, float *pF1,
                             float *pF2)
        {
            if (!NATIVE_PIPE_SENDMESSAGEPFPF)
            {
                LMSLog(LMS_LOGTYPE_WARNING, LMS_SENDER_NATIVE,
                       _UTILITY concat(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483519,"aXATWPD]Ejehatawawlj", new unsigned char [4] { (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0 }).c_str(), c, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483518,"", new unsigned char [1] { (unsigned char)0 }).c_str(), h, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483517,"", new unsigned char [1] { (unsigned char)0 }).c_str(), o, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483516,"", new unsigned char [1] { (unsigned char)0 }).c_str(), pF1,
                                       MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483515,"", new unsigned char [1] { (unsigned char)0 }).c_str(), pF2, "]"));
                return;
            }
            mono_thread_attach(mono_get_root_domain());
            mono_runtime_invoke(NATIVE_PIPE_SENDMESSAGEPFPF, 0,
                                new void *[5]{&c, &h, &o, pF1, pF2}, 0);
        }
    }
}