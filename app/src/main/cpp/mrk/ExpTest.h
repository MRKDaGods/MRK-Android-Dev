#include <jni.h>

extern "C"
{

JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeInit
(JNIEnv *env, jclass clazz, jint width, jint height, jfloat dpr);

JNIEXPORT void JNICALL Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeRender(
        JNIEnv *env, jclass instance);

JNIEXPORT void Java_io_github_mrkdagods_mrkandroidhaxexternal_MRKNativeBridge_MRKNativeTouchEvent(
        JNIEnv *env, jclass instance, jint x, jint y, jint type);
}