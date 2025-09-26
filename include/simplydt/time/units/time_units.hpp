
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file time_units.hpp
 *
 * @brief
 * Aliases of individual units of time.
 */


#ifndef SIMPLYDT_LIB_TIME_UNITS_H_
#define SIMPLYDT_LIB_TIME_UNITS_H_

#include "simplydt/common/time_defs.hpp"
#include <chrono>

namespace simplydt
{

/*! @brief Seconds time unit. */
using Seconds = std::chrono::duration<int32_t, std::ratio<1>>;

/*! @brief Minutes time unit. */
using Minutes = std::chrono::duration<int32_t, std::ratio<SECONDS_IN_MINUTE>>;

/*! @brief Hours time unit. */
using Hours = std::chrono::duration<int32_t, std::ratio<SECONDS_IN_HOUR>>;

/*! @brief Days time unit. */
using Days = std::chrono::duration<int32_t, std::ratio<SECONDS_IN_DAY>>;

} // namespace simplydt

#endif // SIMPLYDT_LIB_TIME_UNITS_H_
