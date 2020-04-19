#include <jni.h>
#include <android/log.h>

#include "../MRKTouchEvent.h"
#include "../gui/MRKDisplay.h"
#include "../LMSExports.h"
#include "../utils/MRKUtils.h"
#include "../MRKApplication.h"
#include "../logger/MRKLogcatLogger.hpp"
#include "../MRKLog.h"

int LMS_BASE_PIC_HANDLE;
int MRK_PIC;
int SHANGO_PIC;
int DT2MS_PIC;

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_LMSInitJNI(JNIEnv *env, jobject instance, jint w, jint h, jfloat dpr)
{
    if (MRK::MRKApplication::Initialized())
        return;
    MRK::LMSRegisterLogCallback(MRK::Logger::MRKLogcatLogger::Log);
    _UTILITY SetLocalResolution(w, h);
    _GUI MRKDisplay::Init(); //init GLES2
    _GUI MRKDisplay *display = new _GUI MRKDisplay(_GUI LMS_ANCHOR_TOP_LEFT, _MATH Vector2(w, h), 2.f);
    MRK::MRKApplication::Init(60, display);
    MRK::LMSLog(MRK::LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE, "MRK started");
    //display->AddLabel("MRK MRK");
    LMS_BASE_PIC_HANDLE = nvgCreateImageMem(_GUI MRKDisplay::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::lms_base_pic, MRK::lms_base_pic_length);
    MRK_PIC = nvgCreateImageMem(_GUI MRKDisplay::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::mrkpic, MRK::mrkpic_length);
    SHANGO_PIC = nvgCreateImageMem(_GUI MRKDisplay::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::shangopic, MRK::shangopic_length);
    DT2MS_PIC = nvgCreateImageMem(_GUI MRKDisplay::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::dt2mspic, MRK::dt2mspic_length);
    MRK::MRKApplication::StartThread();
}

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_LMSGLJobs(JNIEnv *env, jobject instance)
{
    MRK::MRKApplication::CallGuiEvent();
    /*NVGcontext *vg = _GUI MRKDisplay::Context();
    nvgBeginFrame(vg, wx, hx, 1);
    nvgBeginPath(vg);
    nvgRect(vg, 0, 200, 100 + 100, 100);
    nvgFillColor(vg, nvgRGBA(123, 192, 0, 255));
    nvgFill(vg);
    // nvgText(vg, 120, 120, "MRK ARE HERE", "test");
    nvgEndFrame(vg);*/
}

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_OnTouchEvent(JNIEnv *env, jobject instance, jint x, jint y,
                                                               jint type)
{
    if (type > 2 || type < 0)
        return;
    MRK::MRKTouchEvent ev = MRK::MRKTouchEvent(x, y, (MRK::LMSTouchEventType)type);
    _GUI MRKDisplay::InjectTouchEvent(ev);
}

JNIEXPORT void LMS_NATIVE_LOG(char *log)
{
    //__android_log_print(ANDROID_LOG_INFO, "MRK", "MRK-Managed, %s", log);
}