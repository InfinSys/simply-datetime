
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
     * System wall-clock wrapper.
     */
    using SystemClock = std::chrono::system_clock;

    /*!
     * @brief
     * Point in time derived from system clock.
     */
    using SystemTimePoint = std::chrono::time_point<SystemClock>;

    /*!
     * @brief
     * Duration measured using system clock.
     */
    using SystemDuration = SystemClock::duration;

    /*!
     * @brief
     * Unambiguous numerical calendar timestamp.
     *
     * @details
     * The `std::time_t` type is implementation-defined.
     * The way this type is used in Simply Datetime
     * assumes it measures seconds elapsed since the Unix
     * epoch (January 1, 1970 00:00:00.000).
     */
    using UnixTimestamp = int64_t;

    /*!
     * @brief
     * Broken-down calendar components.
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
