
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file stl_chrono_defs.hpp
 *
 * @brief
 * Type aliases for standard C++ date and time constructs.
 *
 * @details
 * This header defines convenient type aliases for
 * commonly used C++ Standard Library date and time
 * types, such as clocks, time points, durations,
 * and calendar representations. These aliases simplify
 * usage and ensure consistency throughout the Simply
 * Datetime library.
 */


#ifndef SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_
#define SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_

#include <chrono>
#include <cstdint>

/*!
 * @namespace simplydt::stl
 *
 * @brief
 * C++ Standard Template Library support.
 */
namespace simplydt::stl
{

/*!
 * @brief
 * System-wide real time wall-clock wrapper.
 */
using SystemClock = std::chrono::system_clock;

/*!
 * @brief
 * Point in time derived from system clock.
 */
using SystemTimePoint = std::chrono::time_point<SystemClock>;

/*!
 * @brief
 * Interval of time.
 */
using SystemDuration = SystemClock::duration;

/*!
 * @brief
 * Count of seconds since Unix epoch to some time
 * point.
 *
 * @details
 * The `std::time_t` type is implementation-defined.
 * Simply Datetime does not explicitly use this type
 * because it needs guarantee that the type used to
 * represent seconds since the Unix epoch (January 1,
 * 1970 00:00:00.000) is a 64-bit signed integer.
 * This is to mitigate the '2038' year overflow
 * internally. Simply Datetime provides a safe method
 * for converting this type to standard `std::tm`.
 */
using UnixTimestamp = int64_t;
// TODO: Need safe conversion method to std::time_t for compatibility

/*!
 * @brief
 * Broken-down calendar date and time structure.
 *
 * @details
 * This is a C-style struct that stores individual
 * components of a calendar time point and contains
 * two key fields to be mindful of: `tm_mon` which
 * measures the number of months ***since*** January,
 * and `tm_year` which measures the number of years
 * ***since*** 1900.
 */
using CalendarDateTime = std::tm;

} // namespace simplydt::stl

#endif // SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_
