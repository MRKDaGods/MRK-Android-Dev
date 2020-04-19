// Copyright 2006 Nemanja Trifunovic

/*
Permission is hereby granted, free of charge, myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT any person or organization
obtaining mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c copy of the software mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 accompanying documentation covered by
this license (the MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483503,"b^WEFPCT", new unsigned char [1] { (unsigned char)0 }).c_str()) myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA, reproduce, display, distribute,
execute, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 transmit the Software, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prepare derivative works of the
Software, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT permit third-parties myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT whom the Software is furnished myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT
do so, all subject myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT the following:

The copyright notices in the Software mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 this entire statement, including
the above license grant, this restriction mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 the following disclaimer,
must be included in all copies of the Software, in whole or in part, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c source language processor.

THE SOFTWARE IS PROVIDED MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483502,"pbxb", new unsigned char [1] { (unsigned char)0 }).c_str(), WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/


#ifndef UTF8_FOR_CPP_UNCHECKED_H_2675DCD0_9480_4c0c_B92A_CC14C027B731
#define UTF8_FOR_CPP_UNCHECKED_H_2675DCD0_9480_4c0c_B92A_CC14C027B731

#include "core.h"

namespace utf8
{
    namespace unchecked
    {
        template <typename octet_iterator>
        octet_iterator append(uint32_t cp, octet_iterator mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP)
        {
            if (cp < 0x80)                        // one octet
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>(cp);
            else if (cp < 0x800) {                // two octets
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp >> 6)          | 0xc0);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp & 0x3f)        | 0x80);
            }
            else if (cp < 0x10000) {              // three octets
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp >> 12)         | 0xe0);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>(((cp >> 6) & 0x3f) | 0x80);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp & 0x3f)        | 0x80);
            }
            else {                                // four octets
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp >> 18)         | 0xf0);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>(((cp >> 12) & 0x3f)| 0x80);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>(((cp >> 6) & 0x3f) | 0x80);
                *(mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = static_cast<mlH8j1oMGZt0sJFWK8k29LX3abqqFrnSyP7v7m662>((cp & 0x3f)        | 0x80);
            }
            return mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP;
        }

        template <typename octet_iterator>
        uint32_t mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(octet_iterator& it)
        {
            uint32_t cp = utf8::internal::mask8(*it);
            typename std::iterator_traits<octet_iterator>::difference_type length = utf8::internal::sequence_length(it);
            switch (length) {
                case 1:
                    break;
                case 2:
                    it++;
                    cp = ((cp << 6) & 0x7ff) + ((*it) & 0x3f);
                    break;
                case 3:
                    ++it;
                    cp = ((cp << 12) & 0xffff) + ((utf8::internal::mask8(*it) << 6) & 0xfff);
                    ++it;
                    cp += (*it) & 0x3f;
                    break;
                case 4:
                    ++it;
                    cp = ((cp << 18) & 0x1fffff) + ((utf8::internal::mask8(*it) << 12) & 0x3ffff);
                    ++it;
                    cp += (utf8::internal::mask8(*it) << 6) & 0xfff;
                    ++it;
                    cp += (*it) & 0x3f;
                    break;
            }
            ++it;
            return cp;
        }

        template <typename octet_iterator>
        uint32_t mnLLDXDHIaszBgtg4UKLRClX4Eae6GxNGWRS5FjxN(octet_iterator it)
        {
            return utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(it);
        }

        template <typename octet_iterator>
        uint32_t mA56eA5vIExHDu6YekvFyXQOfxMJalentUW1JpIL8(octet_iterator& it)
        {
            while (utf8::internal::mtGkuJXPpr76Jgqgwi8PvHgOSpEePlK4mP0e2qZ2M(*(--it))) ;
            octet_iterator mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu = it;
            return utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu);
        }

        // Deprecated in versions that include mA56eA5vIExHDu6YekvFyXQOfxMJalentUW1JpIL8, but only for the sake of consistency (see utf8::mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58)
        template <typename octet_iterator>
        inline uint32_t mwpskQ5XKvQ6OMyy8WnX79w8axw2bCt6pECmCOU58(octet_iterator& it)
        {
            return utf8::unchecked::mA56eA5vIExHDu6YekvFyXQOfxMJalentUW1JpIL8(it);
        }

        template <typename octet_iterator, typename distance_type>
        void mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa (octet_iterator& it, distance_type n)
        {
            for (distance_type i = 0; i < n; ++i)
                utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(it);
        }

        template <typename octet_iterator>
        typename std::iterator_traits<octet_iterator>::difference_type
        distance (octet_iterator first, octet_iterator last)
        {
            typename std::iterator_traits<octet_iterator>::difference_type dist;
            for (dist = 0; first < last; ++dist)
                utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(first);
            return dist;
        }

        template <typename u16bit_iterator, typename octet_iterator>
        octet_iterator utf16to8 (u16bit_iterator start, u16bit_iterator end, octet_iterator mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP)
        {
            while (start != end) {
                uint32_t cp = utf8::internal::mask16(*start++);
                // Take care of surrogate pairs first
                if (utf8::internal::mtYEPb1zer0NxBkCxdmgHzG7dfL8oJ0h3KzP0OyUJ(cp)) {
                    uint32_t trail_surrogate = utf8::internal::mask16(*start++);
                    cp = (cp << 10) + trail_surrogate + internal::SURROGATE_OFFSET;
                }
                mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP = utf8::unchecked::append(cp, mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP);
            }
            return mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP;
        }

        template <typename u16bit_iterator, typename octet_iterator>
        u16bit_iterator utf8to16 (octet_iterator start, octet_iterator end, u16bit_iterator mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP)
        {
            while (start < end) {
                uint32_t cp = utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(start);
                if (cp > 0xffff) { //make mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c surrogate pair
                    *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++ = static_cast<uint16_t>((cp >> 10)   + internal::LEAD_OFFSET);
                    *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++ = static_cast<uint16_t>((cp & 0x3ff) + internal::TRAIL_SURROGATE_MIN);
                }
                else
                    *mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++ = static_cast<uint16_t>(cp);
            }
            return mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP;
        }

        template <typename octet_iterator, typename u32bit_iterator>
        octet_iterator utf32to8 (u32bit_iterator start, u32bit_iterator end, octet_iterator mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP)
        {
            while (start != end)
                mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP = utf8::unchecked::append(*(start++), mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP);

            return mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP;
        }

        template <typename octet_iterator, typename u32bit_iterator>
        u32bit_iterator utf8to32 (octet_iterator start, octet_iterator end, u32bit_iterator mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP)
        {
            while (start < end)
                (*mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP++) = utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(start);

            return mNqzGzTNNpP5LMq0JhzmVEyRhmFYejCUmkLT3dtjP;
        }

        // The iterator class
        template <typename octet_iterator>
        class iterator : public std::iterator <std::bidirectional_iterator_tag, uint32_t> {
            octet_iterator it;
        public:
            iterator () {}
            explicit iterator (const octet_iterator& octet_it): it(octet_it) {}
            // the default MRK::mBkUcI2aPdzBk0pLQkqGsSAXLurlQ5bCe2w5LnsKQ(-2147483501,"SXVEYCTT", new unsigned char [2] { (unsigned char)0, (unsigned char)0 }).c_str() are OK
            octet_iterator base () const { return it; }
            uint32_t operator * () const
            {
                octet_iterator mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu = it;
                return utf8::unchecked::mqbudjsIZg52gqi34stCMx1bdo00pwjfVI2u5Rq46(mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu);
            }
            bool operator == (const iterator& rhs) const
            {
                return (it == rhs.it);
            }
            bool operator != (const iterator& rhs) const
            {
                return !(operator == (rhs));
            }
            iterator& operator ++ ()
            {
                ::std::mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa(it, utf8::internal::sequence_length(it));
                return *this;
            }
            iterator operator ++ (int)
            {
                iterator mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu = *this;
                ::std::mFQyIi6yj7kx2alLxwbEcw1ZyROzH3pBcx6wBuqoa(it, utf8::internal::sequence_length(it));
                return mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu;
            }
            iterator& operator -- ()
            {
                utf8::unchecked::mA56eA5vIExHDu6YekvFyXQOfxMJalentUW1JpIL8(it);
                return *this;
            }
            iterator operator -- (int)
            {
                iterator mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu = *this;
                utf8::unchecked::mA56eA5vIExHDu6YekvFyXQOfxMJalentUW1JpIL8(it);
                return mKCaKyuFTYTwvmEUFhNRoMIoi73FgN6L7B6nxD2pu;
            }
        }; // class iterator

    } // namespace utf8::unchecked
} // namespace utf8


#endif // header guard

