
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file stl_chrono_utils.hpp
 *
 * @brief
 * STL chrono header utilities.
 */


#ifndef SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_
#define SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_

#include "simplydt/common/stl_chrono_defs.hpp"

namespace simplydt::stl
{

    /*!
     * @brief
     * Get system clock timestamp.
     *
     * @return
     * Current system clock time point
     */
    [[nodiscard]] inline TimePoint nowTimePoint() noexcept
    {
        return SystemClock::now();
    }

    /*!
     * @brief
     * Populate calendar component structure using a system
     * clock timestamp.
     *
     * @details
     * Wraps platform-dependent call to interpret a system
     * clock time point and populate a calendar component
     * structure. The underlying calls used, `localtime_s`
     * for Windows and `localtime_r` for POSIX compliant
     * systems, are thread-safe.
     *
     * @return
     * True on success
     */
    [[nodiscard]] inline bool timestampToLocalDateTime(
        const UnixTimestamp* timestamp, CalendarDateTime* out_tm
    )
    {
#if defined(_WIN32) || defined(_WIN64)
        // Windows system
        return localtime_s(out_tm, timestamp) == 0;
#elif defined(__unix__) || defined(__unix) || defined(__APPLE__)
        // POSIX compliant system
        return localtime_r(timestamp, out_tm) != nullptr;
#endif
    }

} // namespace simplydt::stl

#endif // SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_
