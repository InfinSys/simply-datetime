
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file date_flags.hpp
 *
 * @brief
 * Gregorian calendar date flags.
 *
 * @details
 * Gregorian calendar date characteristic flags.
 */

#ifndef SIMPLYDT_LIB_GREGORIAN_DATE_FLAGS_H_
#define SIMPLYDT_LIB_GREGORIAN_DATE_FLAGS_H_

#include <cstdint>

namespace simplydt::gregorian
{

    /*!
     * @brief
     * Gregorian calendar date flags.
     *
     * @details
     * These flags describe structural characteristics
     * of a Gregorian date that can be derived from the
     * Gregorian calendar system independently.
     */
    enum class DateFlag : uint32_t {
        NONE              = 0,       ///< No date flags
        INVALID           = 1 << 0,  ///< Invalid date

        CALENDAR_Q1       = 1 << 2,  ///< First quarter of calendar year (Jan-Mar)
        CALENDAR_Q2       = 1 << 3,  ///< Second quarter of calendar year (Apr-Jun)
        CALENDAR_Q3       = 1 << 4,  ///< Third quarter of calendar year (Jul-Sep)
        CALENDAR_Q4       = 1 << 5,  ///< Fourth quarter of calendar year (Oct-Dec)

        START_OF_YEAR     = 1 << 6,  ///< January
        MIDDLE_OF_YEAR    = 1 << 7,  ///< June
        END_OF_YEAR       = 1 << 8,  ///< December

        LEAP_YEAR         = 1 << 9,  ///< Leap year

        START_OF_MONTH    = 1 << 10, ///< First day of month
        MIDDLE_OF_MONTH   = 1 << 11, ///< Median day of month
        END_OF_MONTH      = 1 << 12, ///< Last day of month

        WEEKDAY           = 1 << 13, ///< Weekday date (Mon-Fri)
        WEEKEND           = 1 << 14, ///< Weekend date (Sat/Sun)

        START_OF_WEEK     = 1 << 15, ///< Beginning of week (Sun)
        START_OF_WEEKDAYS = 1 << 16, ///< Beginning of weekdays (Mon)
        MIDDLE_OF_WEEK    = 1 << 17, ///< Wednesday
        END_OF_WEEKDAYS   = 1 << 18, ///< End of weekdays (Fri)
        END_OF_WEEK       = 1 << 19, ///< End of week (Sat)

        LEAP_DAY          = 1 << 20  ///< February 29th
    };

    /*!
     * @brief
     * Combine date flag values using bitwise OR.
     *
     * @details
     * Returns a `DateFlag` with bits set where either
     * input flag has a bit set.
     *
     * @return
     * Bit combined date flag
     */
    [[nodiscard]] inline DateFlag operator|(const DateFlag lhs, const DateFlag rhs) noexcept
    {
        return static_cast<DateFlag>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
    }

    /*!
     * @brief
     * Computes bitwise AND of date flags.
     *
     * @details
     * Returns a `DateFlag` with bits set only where both
     * input flags have bits set.
     *
     * @return
     * Bit filtered date flag
     */
    [[nodiscard]] inline DateFlag operator&(const DateFlag lhs, const DateFlag rhs) noexcept
    {
        return static_cast<DateFlag>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
    }

    /*!
     * @brief
     * Computes bitwise complement of date flag.
     *
     * @details
     * Returns a `DateFlag` with all bits flipped relative
     * to the input.
     *
     * @return
     * Bit negated date flag
     */
    [[nodiscard]] inline DateFlag operator~(DateFlag flag) noexcept
    {
        return static_cast<DateFlag>(~static_cast<uint32_t>(flag));
    }

    /*!
     * @brief
     * Combine date flag values in-place using bitwise OR.
     *
     * @return
     * Reference to left-hand side date flag
     */
    [[nodiscard]] inline DateFlag& operator|=(DateFlag& lhs, const DateFlag rhs) noexcept
    {
        lhs = lhs | rhs;
        return lhs;
    }

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_DATE_FLAGS_H_
