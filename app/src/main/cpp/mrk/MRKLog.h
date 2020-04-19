#pragma once

#include <vector>
#include <string>

#include "MRKCommon.h"

namespace MRK
{
#define MRK_SENDER_NATIVE "MRK-Native"
#define MRK_SENDER_MANAGED "MRK-Managed"

    enum MRKLogType
    {
        MRK_LOGTYPE_INFO,
        MRK_LOGTYPE_WARNING,
        MRK_LOGTYPE_ERROR
    };

    struct MRKLogEntry
    {
        MRKLogType Type;
        _STD string Sender;
        _STD string Msg;
        float Time;
    };

    _STD vector<MRKLogEntry> *GetRecentLogs();
    void MRKRegisterLogCallback(void(*lf)(MRKLogType, _STD string, _STD string));
    void MRKLog(MRKLogType type, _STD string sender, _STD string msg);
}