#include <jni.h>

#include "MRKApplication.h"
#include "logger/MRKLogcatLogger.hpp"
#include "ExpTest.h"

using namespace MRK;

int MRK_BASE_PIC_HANDLE;

//extern "C"
//{

    JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeInit
    (JNIEnv *env, jclass clazz, jint width, jint height, jfloat dpr) {
        if (MRKApplication::Initialized())
            return;

        MRKRegisterLogCallback(Logger::MRKLogcatLogger::Log);
        _UTILITY SetLocalResolution(width, height);
        _GUI MRKDisplay::Init(); //init GLES2
        _GUI MRKDisplay *display = new _GUI MRKDisplay(_GUI MRK_ANCHOR_TOP_LEFT,
                                                       _MATH Vector2(width, height), dpr);
        MRKApplication::Init(60, display);
        MRKLog(MRK_LOGTYPE_INFO, MRK_SENDER_NATIVE, "MRK started");
        MRK_BASE_PIC_HANDLE = MRKUICreateImageMem(_GUI MRKDisplay::Context(),
                                                MRKUI_IMAGE_GENERATE_MIPMAPS, MRK_base_pic,
                                                MRK_base_pic_length);

        MRKApplication::StartThread();
    }

    JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeRender(
        JNIEnv *env, jclass instance) {
        MRKApplication::CallGuiEvent();
    }

    JNIEXPORT void Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeTouchEvent(
            JNIEnv *env, jclass instance, jint x, jint y, jint type) {
            if (type > 2 || type < 0)
                return;
            MRKTouchEvent ev = MRKTouchEvent(x, y, (MRKTouchEventType) type);
            _GUI MRKDisplay::InjectTouchEvent(ev);
    }
//}