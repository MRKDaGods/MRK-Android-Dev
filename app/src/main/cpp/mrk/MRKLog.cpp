#include "MRKLog.h"
#include "MRKApplication.h"

namespace MRK
{
    static _STD vector<void(*)(MRKLogType, _STD string, _STD string)> GLogCallbacks;
    static _STD vector<MRKLogEntry> RecentLogs;

    void MRKRegisterLogCallback(void(*lf)(MRKLogType, _STD string, _STD string))
    {
        if (lf)
            GLogCallbacks.push_back(lf);
    }

    void MRKLog(MRKLogType type, _STD string sender, _STD string msg)
    {
        //if (RecentLogs.size() >= 80)
        //    RecentLogs.erase(RecentLogs.begin());
        RecentLogs.push_back(MRKLogEntry{
                type,
                sender,
                msg,
                MRKApplication::GetTimeSinceLaunch()
        });
        for (auto func : GLogCallbacks)
            func(type, sender, msg);
    }

    _STD vector<MRKLogEntry> *GetRecentLogs()
    {
        return &RecentLogs;
    }
}