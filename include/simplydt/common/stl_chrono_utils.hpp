
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file stl_chrono_utils.hpp
 *
 * @brief
 * Utilities for standard C++ date and time related
 * constructs.
 */


#ifndef SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_
#define SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_

#include "simplydt/common/simplydt_defs.hpp"
#include "simplydt/common/stl_chrono_defs.hpp"

namespace simplydt::stl
{

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
 * systems, are thread-safe and both apply the systems
 * local timezone to the populated calendar struct.
 *
 * @return
 * True on success
 */
[[nodiscard]] inline bool deriveLocalDateTimeFromTimestamp(
    const UnixTimestamp* timestamp, CalendarDateTime* out_tm
)
{
#if defined(SIMPLYDT_WIN32)
    return localtime_s(out_tm, timestamp) == 0;
#elif defined(SIMPLYDT_POSIX)
    return localtime_r(timestamp, out_tm) != nullptr;
#endif
}

} // namespace simplydt::stl

#endif // SIMPLYDT_LIB_STL_CHRONO_UTILITIES_H_
