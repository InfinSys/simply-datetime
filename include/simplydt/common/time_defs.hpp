
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file time_defs.hpp
 *
 * @brief
 * General time definitions.
 */


#ifndef SIMPLYDT_LIB_GENERAL_TIME_DEFINITIONS_H_
#define SIMPLYDT_LIB_GENERAL_TIME_DEFINITIONS_H_

#include "simplydt/common/simplydt_defs.hpp"
#include <cstdint>

namespace simplydt
{

/*!
 * @brief
 * Time representation type.
 *
 * @details
 * The underlying type used to represent temporal
 * time. Optimal for second precision.
 */
using Time_t = uint32_t;

/*! @brief Total number of seconds in one day. */
constexpr uint32_t SECONDS_IN_DAY = 86'400;

/*! @brief Total number of seconds in one hour. */
constexpr uint16_t SECONDS_IN_HOUR = 3'600;

/*! @brief Total number of seconds in one minute. */
constexpr uint8_t SECONDS_IN_MINUTE = 60;

/*! @brief Total number of minutes in one day. */
constexpr uint16_t MINUTES_IN_DAY = 1'440;

/*! @brief Total number of minutes in one hour. */
constexpr uint8_t MINUTES_IN_HOUR = 60;

/*! @brief Total number of hours in one day. */
constexpr uint8_t HOURS_IN_DAY = 24;

/*! @brief Midnight in serial seconds (00:00:00 AM). */
constexpr Time_t MIDNIGHT = 0;

/*! @brief Noon in serial seconds (12:00:00 PM). */
constexpr Time_t NOON = SECONDS_IN_DAY / 2;

/*! @brief End of day in serial seconds (23:59:59 PM) */
constexpr Time_t TIME_MAX = SECONDS_IN_DAY - 1;

} // namespace simplydt

#endif // SIMPLYDT_LIB_GENERAL_TIME_DEFINITIONS_H_
