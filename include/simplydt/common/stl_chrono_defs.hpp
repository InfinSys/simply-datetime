
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file stl_chrono_defs.hpp
 *
 * @brief
 * STL date and time library aliases.
 *
 * @details
 * Type aliases for Standard Template Library date and time
 * symbols.
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
     * Time point in seconds since Unix epoch.
     *
     * @details
     * The `std::time_t` type is implementation-defined.
     * Simply Datetime does not use this type because it
     * needs guarantee that the type representing seconds
     * since the Unix epoch (January 1, 1970 00:00:00.000)
     * is a 64-bit signed integer. This is to mitigate the
     * '2038' year overflow.
     */
    using UnixTimestamp = int64_t;

    /*!
     * @brief
     * Broken-down calendar component struct.
     *
     * @details
     * This type is a C-style struct that stores individual
     * components of a calendar time point and contains two
     * key fields to be mindful of: `tm_mon` which measures
     * the number of months ***since*** January, and `tm_year`
     * which measures the number of years ***since*** 1900.
     */
    using CalendarDateTime = std::tm;

} // namespace simplydt::stl

#endif // SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_
