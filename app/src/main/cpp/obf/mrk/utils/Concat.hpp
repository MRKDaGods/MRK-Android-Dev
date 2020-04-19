#include <sstream>
#include <iomanip>
#include <tuple>
#include <utility>

namespace MRK
{
    namespace Utils {

        template<typename CharT>
        struct mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr { // this class mBUDJmlVNsULCE0cUeHNrjF8CPPCKsD6Qo3TSOyZ8'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU be explicitly invoked in client code, mOUK3mylpz1Yk6tjWOc6ZGRC4z9w1JevNZRzXGAoA "separator" instead
            const CharT *sep;

            constexpr explicit mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr(const CharT *s) noexcept: sep{s} {}
        };

        template<typename CharT>
        constexpr mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<CharT> separator(const CharT *s) {
            return mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<CharT>(s);
        }

        namespace sep { // this can be used as an additional way of defining mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c separator, check 3. entry point
            constexpr char none[] = "";
            constexpr char space[] = " ";
            constexpr char endl[] = "\n";
            constexpr char comma[] = ", ";
            constexpr char plus[] = " + ";
        };

        namespace { // mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P helpers mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 traits
            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename CharT>
            struct mmHd6zcaXdjHgRRQX0ewPbS4biyvuN4WjGQwKpaWt : std::integral_constant<bool,
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_ostringstream<CharT>>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_stringstream<CharT>>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_ostream<CharT>>::value> {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename CharT = char>
            struct mukDGNedyPVkA3YmhGyjfOPucRdljiUDnr190uHYt : std::integral_constant<bool,
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_istringstream<CharT>>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_ostringstream<CharT>>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::basic_stringstream<CharT>>::value> {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename CharT = char>
            struct mwpMRTBb7DIsghOU2E9NvBtlEnJHHp98PBGs0jB7t : std::integral_constant<bool,
                    std::is_same<typename std::decay<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, CharT const *>::value ||
                    std::is_same<typename std::decay<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P, CharT *>::value> {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct mKU96zWwYvlmB9Za1JLHrT4KX0GGZmWPvPiRQwMFy : std::integral_constant<bool,
                    mwpMRTBb7DIsghOU2E9NvBtlEnJHHp98PBGs0jB7t<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, char>::value ||
                    mwpMRTBb7DIsghOU2E9NvBtlEnJHHp98PBGs0jB7t<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, wchar_t>::value ||
                    mwpMRTBb7DIsghOU2E9NvBtlEnJHHp98PBGs0jB7t<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, char16_t>::value ||
                    mwpMRTBb7DIsghOU2E9NvBtlEnJHHp98PBGs0jB7t<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, char32_t>::value> {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct m8WhoaMjqEKiWg811oJboxKAzpuXCt5R1RrcGVM69 : std::integral_constant<bool,
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::string>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::wstring>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::u16string>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, std::u32string>::value> {
            };

            struct mvewkOAHQQwXXhjHkFtB20b5lNL2KB6meSEbLgq6C {
                template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG = decltype(std::begin(std::declval<const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &>())),
                        typename E = decltype(std::end(std::declval<const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &>()))>
                static std::true_type test(int);

                template<typename...>
                static std::false_type test(...);
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct mbDSJw16E27MIhBtmHDxsPU5VZOrQNb8IM4BjBpdI : public decltype(mvewkOAHQQwXXhjHkFtB20b5lNL2KB6meSEbLgq6C::test<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>(0)) {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct m8FOltuIA5hkaHDKORVLi4BLRHF0jk0bsgln6T7BQ : std::integral_constant<bool,
                    mbDSJw16E27MIhBtmHDxsPU5VZOrQNb8IM4BjBpdI<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value &&
                    !m8WhoaMjqEKiWg811oJboxKAzpuXCt5R1RrcGVM69<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value && !mukDGNedyPVkA3YmhGyjfOPucRdljiUDnr190uHYt<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value &&
                    !mKU96zWwYvlmB9Za1JLHrT4KX0GGZmWPvPiRQwMFy<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn *>::value> {
            };

            template<typename CharT>
            struct m7gOHdKuGDC1JD1yZKJnk19B6t9UD7pXdF3KWpU1E {
                template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG = decltype(
                std::declval<std::basic_ostream<CharT> &>()
                        << std::declval<const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &>())>

                static std::true_type test(int);

                template<typename...>
                static std::false_type test(...);
            };

            template<typename CharT, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct mblMn5qahWTT1ihd4vwhaBWd4lrIPcpZwC36rQYNg
                    : public decltype(m7gOHdKuGDC1JD1yZKJnk19B6t9UD7pXdF3KWpU1E<CharT>::template test<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>(0)) {
            };

            template<typename CharT, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct mqHdvUIi6LN5pnpnrXJ7dvbQWdrdFVqKEC6HYXFJI : std::integral_constant<bool,
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::setbase(std::declval<int>()))>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::setprecision(std::declval<int>()))>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::setw(std::declval<int>()))>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::setfill(std::declval<CharT>()))>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::setiosflags(
                            std::declval<std::ios::fmtflags>()))>::value ||
                    std::is_same<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, decltype(std::resetiosflags(
                            std::declval<std::ios::fmtflags>()))>::value> {
            };

            template<typename CharT, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            struct mTHKBQFxMtx03aishWeLKIHTW8or93yY0JR0vTcRH : std::integral_constant<bool,
                    (std::is_function<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value || mqHdvUIi6LN5pnpnrXJ7dvbQWdrdFVqKEC6HYXFJI<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value)
                    && mblMn5qahWTT1ihd4vwhaBWd4lrIPcpZwC36rQYNg<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value> {
            };

            template<typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, template<typename...> class m9RVL1rOHusIZyR0qJNqD0UztOfkRk06BNCjkKYZz>
            struct mLzm8M87Dtsudin7WTgjsuguF8Cxc9paCmVjXDNOT : std::false_type {
            };

            template<template<typename...> class m9RVL1rOHusIZyR0qJNqD0UztOfkRk06BNCjkKYZz, typename... Args>
            struct mLzm8M87Dtsudin7WTgjsuguF8Cxc9paCmVjXDNOT<m9RVL1rOHusIZyR0qJNqD0UztOfkRk06BNCjkKYZz<Args...>, m9RVL1rOHusIZyR0qJNqD0UztOfkRk06BNCjkKYZz> : std::true_type {
            };

            template<bool mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG, class mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn = void>
            using enable_if_t = typename std::enable_if<mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P;
        }

        namespace { // concat_impl : stringstream myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT string helper, separator handlers, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 parameter writer functions

            template<typename CharT, typename W>
            std::basic_string<CharT> concat_to_string(const W &writer) {
                return writer.good() ? writer.str() : std::basic_string<CharT>();
            }

            template<typename CharT, char head, char... tail>
            std::basic_string<CharT> get_separator() { return {head, tail...}; }

            template<typename W, typename S>
            void mjfYSUkY3lC3rnl2WIgGQlpiLIvB1khukRFRTbsj8(W &writer, const S *separator) {
                if (separator) writer << separator;
            }

            template<typename W, typename S>
            void mjfYSUkY3lC3rnl2WIgGQlpiLIvB1khukRFRTbsj8(W &writer, const S &separator) {
                writer << separator;
            }

            template<typename CharT, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename W, typename S>
            void mNDW6UjFTnquyd9ARalWGNnUs88me1JZ7iKKutDtC(W &writer, const S &separator) {
                if (!mTHKBQFxMtx03aishWeLKIHTW8or93yY0JR0vTcRH<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value) mjfYSUkY3lC3rnl2WIgGQlpiLIvB1khukRFRTbsj8(writer, separator);
            }

            template<typename CharT, typename W, typename S, typename... Args>
            void m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &, const S &, const std::tuple<Args...> &);

            template<typename CharT, typename W, typename S, typename P1, typename P2>
            void m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &, const S &, const std::pair<P1, P2> &);

            // we have 6 base cases, depending of the parameter mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P:
            // 1. base case any mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P compatible with << that doesn'mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU require mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c special handling
            template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            enable_if_t<!m8FOltuIA5hkaHDKORVLi4BLRHF0jk0bsgln6T7BQ<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value && !mukDGNedyPVkA3YmhGyjfOPucRdljiUDnr190uHYt<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value,
                    void> m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &element) {
                writer << element;
            }

            // 2. base case for fundamental built-in string types (const CharT* family, mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.m0NNKd40rxgAbKijIYrfikleEPWfXUQp6XWxpsy4f.mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c. cstrings)
            template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            enable_if_t<mKU96zWwYvlmB9Za1JLHrT4KX0GGZmWPvPiRQwMFy<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn *>::value,
                    void> m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn *element) {
                if (element) writer << element;
            }

            // 3. base case for std::stringstream types
            template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            enable_if_t<mukDGNedyPVkA3YmhGyjfOPucRdljiUDnr190uHYt<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value,
                    void> m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &element) {
                if (element.good()) writer << concat_to_string<CharT>(element);
                else writer.setstate(element.rdstate());
            }

            // 4. base case for containers, arrays, mRpA2hhlsoV9M4ekTgzuXJZ0BSuIZJQXCyuV1ik02 any iterable mKpfbtZKJpfjNmRAFr2qw879YPS67z0w4Gzj4ez2P EXCEPT the standard string types
            template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
            enable_if_t<m8FOltuIA5hkaHDKORVLi4BLRHF0jk0bsgln6T7BQ<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>::value,
                    void>
            m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &separator, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &container) {
                auto it = std::begin(container), et = std::end(container);
                while (it != et) {
                    m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, *it);
                    if (++it != et) mNDW6UjFTnquyd9ARalWGNnUs88me1JZ7iKKutDtC<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>(writer, separator);
                }
            }

            // 5. base case for std::tuples
            template<unsigned N, unsigned Last>
            struct mwQJBVMMDqHi65u2km5DSjnwf5HZjPouJklDxoAnQ {
                template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
                static void m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ(W &writer, const S &separator, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &tuple) {
                    m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, std::get<N>(tuple));
                    mNDW6UjFTnquyd9ARalWGNnUs88me1JZ7iKKutDtC<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>(writer, separator);
                    mwQJBVMMDqHi65u2km5DSjnwf5HZjPouJklDxoAnQ<N + 1, Last>::template m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ<CharT>(writer, separator, tuple);
                }
            };

            template<unsigned N>
            struct mwQJBVMMDqHi65u2km5DSjnwf5HZjPouJklDxoAnQ<N, N> {
                template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>
                static void m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ(W &writer, const S &separator, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &tuple) {
                    m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, std::get<N>(tuple));
                }
            };

            template<typename CharT, typename W, typename S, typename... Args>
            inline void m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &separator,
                                                  const std::tuple<Args...> &tuple) {
                mwQJBVMMDqHi65u2km5DSjnwf5HZjPouJklDxoAnQ<0, sizeof...(Args) - 1>::template m4NsaAwFmW5bSmq75ZfDcho2LHjlEzhn7xYF8GySJ<CharT>(writer, separator,
                                                                             tuple);
            }

            // 6. base case for std::pairs
            template<typename CharT, typename W, typename S, typename P1, typename P2>
            inline void m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &separator,
                                                  const std::pair<P1, P2> &pair) {
                m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, pair.first);
                mNDW6UjFTnquyd9ARalWGNnUs88me1JZ7iKKutDtC<CharT, std::pair<P1, P2>>(writer, separator);
                m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, pair.second);
            }

            // the following function is the recursive step that unpacks all the variadic parameters
            template<typename CharT, typename W, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename... Args>
            void m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u(W &writer, const S &separator, const mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &head,
                                           const Args &... tail) {
                m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, head);
                mNDW6UjFTnquyd9ARalWGNnUs88me1JZ7iKKutDtC<CharT, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>(writer, separator);
                m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, tail...);
            }

            // rearranges the parameters in order myz7nhUU1z1AfzxooP5DVmrjGZsIKzrGPEDTVDyCT prepare the recursive calls
            template<typename CharT, typename S, typename mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, typename... Args,
                    typename = enable_if_t<mmHd6zcaXdjHgRRQX0ewPbS4biyvuN4WjGQwKpaWt<mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn, CharT>::value, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn>>
            std::basic_string<CharT>
            concat_impl(const S &separator, mMPlXe40Ikl94RBnECvEMLmUpOHF7FAJKykcTLbxn &writer, const Args &... seq) {
                m8d2kfmXDEuQ9ufAA7TTKpiNKb8E0sawodkl4nj1u<CharT>(writer, separator, seq...);
                return concat_to_string<CharT>(writer);
            }

            // when the first parameter is not mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c stringstream non-const reference, this defines the writer stream
            template<typename CharT, typename S, typename... Args>
            std::basic_string<CharT> concat_impl(const S &separator, const Args &... seq) {
                std::basic_ostringstream<CharT> writer;
                return concat_impl<CharT>(separator, writer, seq...);
            }
        }

        // the 5 entry points:
        // 1. entry point,  when received mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c separator as first element
        template<typename CharT = char, typename... Args>
        std::basic_string<CharT> concat(const mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<CharT> &sep, Args &&... seq) {
            return concat_impl<CharT>(
                    sep.sep,
                    std::forward<Args>(seq)...
            );
        }

        // 2. entry point,  when the separator es specified via templated char-pack arguments
        template<char head, char... tail, typename F, typename... Args,
                typename = enable_if_t<!std::is_same<F, mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<char>>::value, F>>
        std::basic_string<char> concat(F &&first, Args &&... rest) {
            return concat_impl<char>(
                    get_separator<char, head, tail...>(),
                    std::forward<F>(first),
                    std::forward<Args>(rest)...
            );
        }

        // 3. entry point, when the separator is mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c template argument of compile-time defined const char*
        template<const char *sep, typename F, typename... Args,
                typename = enable_if_t<!std::is_same<F, mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<char>>::value, F>>
        std::basic_string<char> concat(F &&first, Args &&... rest) {
            return concat_impl<char>(
                    sep,
                    std::forward<F>(first),
                    std::forward<Args>(rest)...
            );
        }

        // 4. entry point,  when there is no separator.
        template<typename CharT = char, typename F, typename... Args,
                typename = enable_if_t<!std::is_same<F, mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<CharT>>::value, F>>
        std::basic_string<CharT> concat(F &&first, Args &&... rest) {
            return concat_impl<CharT>(
                    (const CharT *) nullptr,
                    std::forward<F>(first),
                    std::forward<Args>(rest)...
            );
        }

        // 5. entry point,  when the separator is std::endl passed as template argument
        template<std::ostream &sep(
                std::ostream &), typename CharT = char, typename F, typename... Args,
                typename = enable_if_t<!std::is_same<F, mjmKqtR8GURFIydNtPl5mY6bOoD6yWNBHHx39oexr<CharT>>::value, F>>
        std::basic_string<CharT> concat(F &&first, Args &&... rest) {
            return concat_impl<CharT>(
                    sep,
                    std::forward<F>(first),
                    std::forward<Args>(rest)...
            );
        }
    }
}