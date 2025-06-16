
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file stl_chrono_defs.hpp
 *
 * @brief
 * STL chrono type aliases.
 *
 * @details
 * Type aliases of Standard Template Library chronological
 * header symbols.
 */


#ifndef SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_
#define SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_

#include <chrono>

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
     * System clock wrapper.
     */
    using SystemClock = std::chrono::system_clock;

    /*!
     * @brief
     * System clock time point.
     */
    using TimePoint = std::chrono::time_point<SystemClock>;

    /*!
     * @brief
     * System clock duration.
     */
    using TimeDuration = SystemClock::duration;

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
    using UnixTimestamp = std::time_t;

    /*!
     * @brief
     * Broken-down calendar components.
     */
    using CalendarDateTime = std::tm;

} // namespace simplydt::stl

#endif // SIMPLYDT_LIB_STL_CHRONO_ALIASES_H_
