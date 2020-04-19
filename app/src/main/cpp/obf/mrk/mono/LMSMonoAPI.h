#pragma once

#include <string>

#include "../MRKCommon.h"

namespace MRK
{
    namespace Mono
    {
        extern _STD string LMS_PACKAGE_NAME_MONO;

        typedef void *(*__mono_class_from_name)(void *, const char *,
                                                const char *); //img, nms, name
        typedef void *(*__mono_get_root_domain)();

        typedef void (*__mono_thread_attach)(void *);

        typedef void *(*__mono_image_open_from_data)(char *, uint32_t, bool, void *);

        typedef void *(*__mono_assembly_name_new)(const char *);

        typedef void *(*__mono_assembly_loaded)(void *);

        typedef void *(*__mono_assembly_get_image)(void *);

        typedef void *(*__mono_class_get_method_from_name)(void *, const char *, int);

        typedef void *(*__mono_runtime_invoke)(void *, void *, void **, void *);

        typedef void *(*__mono_domain_assembly_open)(void *, const char *);

        typedef void (*__mono_gfunc)(void *, void *);

        typedef void (*__mono_assembly_foreach)(__mono_gfunc, void *);

        typedef const char *(*__mono_image_get_name)(void *);

        extern __mono_class_from_name mono_class_from_name;
        extern __mono_get_root_domain mono_get_root_domain;
        extern __mono_thread_attach mono_thread_attach;
        extern __mono_image_open_from_data mono_image_open_from_data;
        extern __mono_assembly_name_new mono_assembly_name_new;
        extern __mono_assembly_loaded mono_assembly_loaded;
        extern __mono_assembly_get_image mono_assembly_get_image;
        extern __mono_class_get_method_from_name mono_class_get_method_from_name;
        extern __mono_runtime_invoke mono_runtime_invoke;
        extern __mono_domain_assembly_open mono_domain_assembly_open;
        extern __mono_assembly_foreach mono_assembly_foreach;
        extern __mono_image_get_name mono_image_get_name;

        void mIMeGqUEEiP0qX67kgaIQEYThfv2XikUdiycywtzN();

        extern void mdJMZkBAtZsuWKYDhnUGUuVHPttLC66ZjKDPyp3M2(unsigned short c, unsigned short h, unsigned short o, float v);

        extern void mUyCwicArzzioEB11DR4bNn1mza4u9D6t51D8F8YM(unsigned short c, unsigned short h, unsigned short o, int v);

        extern void mm5LfKItqVttAfaUizk3HpjoEafnSbR48UQOTaGmu(unsigned short c, unsigned short h, unsigned short o, bool v);

        extern void
        mFTNbZStogxaCCBK8a61S0Fa2bMwhIFqppE6PA763(unsigned short c, unsigned short h, unsigned short o, float *pF1,
                        float *pF2);
    }
}