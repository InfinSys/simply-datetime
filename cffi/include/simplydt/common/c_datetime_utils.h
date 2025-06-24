
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file c_datetime_utils.h
 *
 * @brief
 * C Standard date and time library utilities.
 */


#ifndef SIMPLYDT_LIB_C_DATE_TIME_UTILITIES_C_H_
#define SIMPLYDT_LIB_C_DATE_TIME_UTILITIES_C_H_

#include "c_datetime_defs.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
* @brief
* Get system wall-clock timestamp in seconds
* since epoch.
*
* @return
* Current system clock time point in seconds
*/
simplydt_UnixTimestamp simplydt_get_now_system_time_secs(void);

#ifdef __cplusplus
}
#endif

#endif // SIMPLYDT_LIB_C_DATE_TIME_UTILITIES_C_H_
