
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file julian_defs.hpp
 *
 * @brief
 * Coordinated Universal Time system definitions.
 */

#ifndef SIMPLYDT_LIB_UTC_SYSTEM_DEFINITIONS_H_
#define SIMPLYDT_LIB_UTC_SYSTEM_DEFINITIONS_H_

#include <array>
#include <cstdint>

/*!
 * @namespace simplydt::utc
 *
 * @brief
 * Standard Coordinated Universal Time system.
 */
namespace simplydt::utc
{

    /*!
     * @brief
     * Binary meridiem indicator literals for 12-hour
     * clock.
     */
    const std::array<const char*, 2> MeridiemPhases = { "AM", "PM" };

    /*!
     * @brief
     * Binary 12-hour clock meridiem indicators.
     */
    enum MeridiemPhase : uint8_t {
        AM, ///< Anti meridiem (before midday)
        PM  ///< Post meridiem (after midday)
    };

    /*!
     * @brief
     * Maximum number of seconds in a minute.
     */
    constexpr uint8_t MAX_SECONDS_IN_MINUTE = 59;

    /*!
     * @brief
     * Maximum number of minutes in a hour.
     */
    constexpr uint8_t MAX_MINUTES_IN_HOUR = 59;

    /*!
     * @brief
     * Maximum number of hours in a day.
     */
    constexpr uint8_t MAX_HOURS_IN_DAY = 23;

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_UTC_SYSTEM_DEFINITIONS_H_
