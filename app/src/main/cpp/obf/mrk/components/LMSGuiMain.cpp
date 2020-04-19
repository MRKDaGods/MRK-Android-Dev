#include <jni.h>
#include <android/log.h>

#include "../MRKTouchEvent.h"
#include "../gui/MRKDisplay.h"
#include "../LMSExports.h"
#include "../utils/MRKUtils.h"
#include "../MRKApplication.h"
#include "../logger/MRKLogcatLogger.hpp"
#include "../MRKLog.h"

int mx97ZsnvWVG6W46LQAt0uiWrdvRta6kny43cBHmnn;
int mpr6hBex0BUy5r4oGB938y0vapA7mRiKbk738KWnQ;
int mGQWPn83WIy36Pl2iQATDxBgoNSLvqlirWzz59FR0;
int mzzLT9puhliYNIVLM9ruv8jsdcMvIbUsG8vPk91Ak;

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_LMSInitJNI(JNIEnv *env, jobject instance, jint w, jint h, jfloat dpr)
{
    if (MRK::mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::mHbNIdBsM46EIbgHCySSJ1DYjF8VCnKopzQD3hjK8())
        return;
    MRK::LMSRegisterLogCallback(MRK::Logger::m8dmpdonxRWd3YvlzRhbIO85SOKYoSsQ8sHeKcNBo::mh5BfA7xdQMSPyZuQaBwdBH5xdKu42gay6oHNKoIC);
    _UTILITY miP3KeKvoVScIVeve6CKg8uDWbAttakSwZs0HYK37(w, h);
    _GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn(); //init GLES2
    _GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu *display = new _GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu(_GUI LMS_ANCHOR_TOP_LEFT, _MATH m3wVKJDHmbyiIpyquT8B2tlNDdRFyPYKwOkTCGPMR(w, h), 2.f);
    MRK::mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::m4q0Eg79jSE80cIcPuyiMhGIpGtRXE1EXgDnA6FZn(60, display);
    MRK::LMSLog(MRK::LMS_LOGTYPE_INFO, LMS_SENDER_NATIVE, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483648,"|czBEPCETU", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str());
    //display->mVP9HmjX5zEkltUyWP9CN3JrH2JdCcqEfj6FtFHyg(MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483647,"|cz|cz", new unsigned char [1] { (unsigned char)0 }).c_str());
    mx97ZsnvWVG6W46LQAt0uiWrdvRta6kny43cBHmnn = nvgCreateImageMem(_GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::lms_base_pic, MRK::lms_base_pic_length);
    mpr6hBex0BUy5r4oGB938y0vapA7mRiKbk738KWnQ = nvgCreateImageMem(_GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::mrkpic, MRK::mrkpic_length);
    mGQWPn83WIy36Pl2iQATDxBgoNSLvqlirWzz59FR0 = nvgCreateImageMem(_GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::shangopic, MRK::shangopic_length);
    mzzLT9puhliYNIVLM9ruv8jsdcMvIbUsG8vPk91Ak = nvgCreateImageMem(_GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::Context(), NVG_IMAGE_GENERATE_MIPMAPS, MRK::dt2mspic, MRK::dt2mspic_length);
    MRK::mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::mKw8dABLa8xcZsb9hZoQlZxg5jLou7yhg5ks2XrPM();
}

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_LMSGLJobs(JNIEnv *env, jobject instance)
{
    MRK::mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::mpIGOCQwtwaiSIPBInvljB8qfGv3ojPgOL3yDGLZi();
    /*NVGcontext *vg = _GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::Context();
    nvgBeginFrame(vg, wx, hx, 1);
    nvgBeginPath(vg);
    nvgRect(vg, 0, 200, 100 + 100, 100);
    nvgFillColor(vg, nvgRGBA(123, 192, 0, 255));
    nvgFill(vg);
    // nvgText(vg, 120, 120, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483646,"|czpctytct", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483645,"ETBE", new unsigned char [1] { (unsigned char)0 }).c_str());
    nvgEndFrame(vg);*/
}

JNIEXPORT void JNICALL Java_io_github_LMS_LMSView_OnTouchEvent(JNIEnv *env, jobject instance, jint m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, jint y,
                                                               jint mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P)
{
    if (mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P > 2 || mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P < 0)
        return;
    MRK::mYJIpIJflgU0wmUiBglo5Jw2pgMsgxHinINndYT8C ev = MRK::mYJIpIJflgU0wmUiBglo5Jw2pgMsgxHinINndYT8C(m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp, y, (MRK::LMSTouchEventType)mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P);
    _GUI mLLC1G9g9RusnmNty9KZX82ZwmkBm2e0NqMib4lnu::mHsnQ6GZQHqov8NoAyWSYQMFA1h3JOcX3K7eoOcPQ(ev);
}

JNIEXPORT void mG1cbtEcsNVgofpg769ft6utKcNTH266pn9grvRUj(char *log)
{
    //__android_log_print(ANDROID_LOG_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483644,"|cz", new unsigned char [1] { (unsigned char)0 }).c_str(), MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483643,"|cz|P_PVTUB", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), log);
}