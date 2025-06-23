
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file c_datetime_defs.h
 *
 * @brief
 * C Standard date and time library aliases.
 */


#ifndef SIMPLYDT_LIB_C_DATE_TIME_ALIASES_C_H_
#define SIMPLYDT_LIB_C_DATE_TIME_ALIASES_C_H_

#include <time.h>
#include <stdint.h>

/*!
* @brief
* Seconds since the Unix epoch.
*
* @note
* This type is the C representation of
* `simplydt::stl::UnixTimestamp` type.
*
* @details
* Measures seconds elapsed since the Unix
* epoch (January 1, 1970 00:00:00.000).
*/
typedef int64_t simplydt_UnixTimestamp;

/*!
* @brief
* Broken-down calendar component struct.
*
* @note
* This type is the C representation of
* `simplydt::stl::CalendarDateTime` type.
*/
typedef tm simplydt_CalendarDateTime;

#endif // SIMPLYDT_LIB_C_DATE_TIME_ALIASES_C_H_
