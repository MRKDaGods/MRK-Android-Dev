#pragma once

#include <android/log.h>

#include "../MRKLog.h"
#include "../utils/MRKUtils.h"

namespace MRK
{
    namespace Logger
    {
        class m8dmpdonxRWd3YvlzRhbIO85SOKYoSsQ8sHeKcNBo
        {
        private:
            static const char *LookUpMsg(MRKLogType logType)
            {
                switch (logType)
                {
                    case MRK_LOGTYPE_INFO:
                        return MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483593,"xw~", new unsigned char [1] { (unsigned char)0 }).c_str();
                    case MRK_LOGTYPE_WARNING:
                        return MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483592,"fpcxv", new unsigned char [1] { (unsigned char)0 }).c_str();
                    case MRK_LOGTYPE_ERROR:
                        return MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483591,"tcc~c", new unsigned char [1] { (unsigned char)0 }).c_str();
                }
                return MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483590,"dz~f}~vehat", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str();
            }

        public:
            static void mh5BfA7xdQMSPyZuQaBwdBH5xdKu42gay6oHNKoIC(MRKLogType logType, _STD string sender, _STD string msg)
            {
                __android_log_print(ANDROID_LOG_INFO, MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483589,"|cz", new unsigned char [1] { (unsigned char)0 }).c_str(), MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483588,"jBljBlB", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str(), LookUpMsg(logType),
                                    sender.c_str(), msg.c_str());
            }
        };
    }
}