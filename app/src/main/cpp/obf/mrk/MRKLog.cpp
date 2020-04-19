#include "MRKLog.h"
#include "MRKApplication.h"

namespace MRK
{
    static _STD vector<void(*)(MRKLogType, _STD string, _STD string)> GLogCallbacks;
    static _STD vector<ms14IpZopVTQ73kbkXO6TztmaNfed4EIvTmaHFv51> RecentLogs;

    void mdebl83aPrUuDuzqxu4vru1VFpnHLhvjYD2NVk2Sy(void(*lf)(MRKLogType, _STD string, _STD string))
    {
        if (lf)
            GLogCallbacks.push_back(lf);
    }

    void mZbpdVaJQ3YzNawKz2aRIjXqFcVRNdxcphQSLtrIW(MRKLogType mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, _STD string sender, _STD string msg)
    {
        //if (RecentLogs.size() >= 80)
        //    RecentLogs.erase(RecentLogs.begin());
        RecentLogs.push_back(ms14IpZopVTQ73kbkXO6TztmaNfed4EIvTmaHFv51{
                mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P,
                sender,
                msg,
                mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::mf0dTt17BL38kNiJjD4Hhoe6uCk6jWRHnBeYJXNTl()
        });
        for (auto func : GLogCallbacks)
            func(mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, sender, msg);
    }

    _STD vector<ms14IpZopVTQ73kbkXO6TztmaNfed4EIvTmaHFv51> *GetRecentLogs()
    {
        return &RecentLogs;
    }
}