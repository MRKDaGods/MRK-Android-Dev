#include <map>
#include <string>

#include "MRKCommon.h"

namespace MRK
{
    _STD map<long, _STD string> ms_RealTable;

    _STD string MRKGetString(long id, _STD string z, unsigned char* g)
    {
        auto x = ms_RealTable.find(id);
        if (x != ms_RealTable.end())
            return x->second;

        int index = 0;
        int byte = 0;

        for (int i = 0; i < z.size(); i++)
        {

            unsigned char b = g[byte];

            int a = (b & (1 << index));

            char y = a ? 'd' : '1';
            z[i] ^= y;

            index++;

            if (index >= 8)
            {
                byte++;
                index = 0;
            }
        }

        ms_RealTable.insert(_STD make_pair(id, z));

        return z;
    }
}