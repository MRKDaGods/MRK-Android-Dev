#pragma once

#include <android/log.h>

#include "../MRKLog.h"
#include "../utils/MRKUtils.h"

namespace MRK
{
    namespace Logger
    {
        class MRKLogcatLogger
        {
        private:
            static const char *LookUpMsg(MRKLogType logType)
            {
                switch (logType)
                {
                    case MRK_LOGTYPE_INFO:
                        return "INFO";
                    case MRK_LOGTYPE_WARNING:
                        return "WARNING";
                    case MRK_LOGTYPE_ERROR:
                        return "ERROR";
                }
                return "UNKNOWN-LOG-TYPE";
            }

        public:
            static void Log(MRKLogType logType, _STD string sender, _STD string msg)
            {
                __android_log_print(ANDROID_LOG_INFO, "MRK", "[%s] [%s] %s", LookUpMsg(logType),
                                    sender.c_str(), msg.c_str());
            }
        };
    }
}