#include <map>
#include <string>

#include "MRKCommon.h"

namespace MRK
{
    _STD map<long, _STD string> mQm3sYkB7cGFEpw33Zj0K2qAZMpjAe6o48kra0nPb;

    _STD string mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(long ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl, _STD string m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D, unsigned char* g)
    {
        auto m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp = mQm3sYkB7cGFEpw33Zj0K2qAZMpjAe6o48kra0nPb.find(ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl);
        if (m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp != mQm3sYkB7cGFEpw33Zj0K2qAZMpjAe6o48kra0nPb.end())
            return m5lAKQu6QSiHcGPvIXvFEX9rHtD8fsq2PRJPRQeFp->second;

        int mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS = 0;
        int byte = 0;

        for (int i = 0; i < m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D.size(); i++)
        {

            unsigned char b = g[byte];

            int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c = (b & (1 << mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS));

            char y = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c ? 'd' : '1';
            m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D[i] ^= y;

            mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS++;

            if (mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS >= 8)
            {
                byte++;
                mj8EOrQaRlwYfpYZ7Xvjv3ZCBHZHidLm4lxy2sMMS = 0;
            }
        }

        //mQm3sYkB7cGFEpw33Zj0K2qAZMpjAe6o48kra0nPb.insert(_STD make_pair(ms2IuSvjcoOE7EDMbHXAuDhsxA4ojQVuKUFwVzrYl, m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D));

        return m1u3Zww5RCe36QqdsfPdY2wb3ExycTb9e6uRMiN7D;
    }
}