
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file calendar_defs.hpp
 *
 * @brief
 * General calendar-agnostic definitions.
 */


#ifndef SIMPLYDT_LIB_GENERAL_CALENDAR_DEFINITIONS_H_
#define SIMPLYDT_LIB_GENERAL_CALENDAR_DEFINITIONS_H_

#include "simplydt/common/simplydt_defs.hpp"
#include <cstdint>
#include <tuple>

namespace simplydt
{

/*!
 * @brief
 * Enumeration of available calendar systems.
 */
enum CalendarSystem : uint8_t {
    JULIAN,    ///< Proleptic solar calendar
    GREGORIAN, ///< Civil solar calendar
};

/*!
 * @brief
 * Enumeration of individual calendar components.
 */
enum class CalendarComponent : uint8_t {
    DAY   = DatetimeComponent::DAY,   ///< Calendar day component
    MONTH = DatetimeComponent::MONTH, ///< Calendar month component
    YEAR  = DatetimeComponent::YEAR   ///< Calendar year component
};

/*!
 * @brief
 * Calendar year, month, and day value tuple.
 *
 * @details
 * This alias defines a generic date container
 * independent of any specific calendar system.
 * It is primarily used as a lightweight value
 * type for passing or storing complete date
 * information without additional calendar logic.
 */
template <typename Year_T>
using CalendarDateTuple = std::tuple<Year_T, uint8_t, uint8_t>;

} // namespace simplydt

#endif // SIMPLYDT_LIB_GENERAL_CALENDAR_DEFINITIONS_H_
