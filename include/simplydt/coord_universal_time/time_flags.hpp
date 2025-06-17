
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file time_flags.hpp
 *
 * @brief
 * Coordinated Universal Time flags.
 *
 * @details
 * Coordinated Universal Time characteristic flags.
 */

#ifndef SIMPLYDT_LIB_UTC_TIME_FLAGS_H_
#define SIMPLYDT_LIB_UTC_TIME_FLAGS_H_

#include <cstdint>

namespace simplydt::utc
{

    /*!
     * @brief
     * Coordinated Universal Time flags.
     *
     * @details
     * These flags describe structural characteristics
     * of a Coordinated Universal Time point that can
     * be derived from the Coordinated Universal Time
     * system independently.
     */
    enum class TimeFlag : uint32_t {
        NONE          = 0,       ///< No time flags
        INVALID       = 1 << 1,  ///< Invalid time

        DAY_Q1        = 1 << 21, ///< First quarter of day (00:00:00 - 05:59:59)
        DAY_Q2        = 1 << 22, ///< Second quarter of day (06:00:00 - 11:59:59)
        DAY_Q3        = 1 << 23, ///< Third quarter of day (12:00:00 - 17:59:59)
        DAY_Q4        = 1 << 24, ///< Fourth quarter of day (18:00:00 - 23:59:59)

        START_OF_DAY  = 1 << 25, ///< First hour of day (00:00:00 - 00:59:59)
        MIDDLE_OF_DAY = 1 << 26, ///< Mid hour of day (12:00:00 - 12:59:59)
        END_OF_DAY    = 1 << 27, ///< Final hour of day (23:00:00 - 23:59:59)

        EARLY_HOUR    = 1 << 28, ///< First 25 minutes of the hour (XX:00:00 - XX:24:59)
        MID_HOUR      = 1 << 29, ///< Median 10 minutes of the hour (XX:25:00 - XX:34:59)
        LATE_HOUR     = 1 << 30  ///< Final 25 minutes of the hour (XX:35:00 - XX:59:59)
    };

    /*!
     * @brief
     * Combine time flag values using bitwise OR.
     *
     * @details
     * Returns a `TimeFlag` with bits set where either
     * input flag has a bit set.
     *
     * @return
     * Bit combined time flag
     */
    [[nodiscard]] inline TimeFlag operator|(const TimeFlag lhs, const TimeFlag rhs) noexcept
    {
        return static_cast<TimeFlag>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
    }

    /*!
     * @brief
     * Computes bitwise AND of time flags.
     *
     * @details
     * Returns a `TimeFlag` with bits set only where both
     * input flags have bits set.
     *
     * @return
     * Bit filtered time flag
     */
    [[nodiscard]] inline TimeFlag operator&(const TimeFlag lhs, const TimeFlag rhs) noexcept
    {
        return static_cast<TimeFlag>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
    }

    /*!
     * @brief
     * Computes bitwise complement of time flag.
     *
     * @details
     * Returns a `TimeFlag` with all bits flipped relative
     * to the input.
     *
     * @return
     * Bit negated time flag
     */
    [[nodiscard]] inline TimeFlag operator~(TimeFlag flag) noexcept
    {
        return static_cast<TimeFlag>(~static_cast<uint32_t>(flag));
    }

    /*!
     * @brief
     * Combine time flag values in-place using bitwise OR.
     *
     * @return
     * Reference to left-hand side time flag
     */
    [[nodiscard]] inline TimeFlag& operator|=(TimeFlag& lhs, const TimeFlag rhs) noexcept
    {
        lhs = lhs | rhs;
        return lhs;
    }

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_UTC_TIME_FLAGS_H_