
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file julian_defs.hpp
 *
 * @brief
 * Julian calendar system definitions.
 */

#ifndef SIMPLYDT_LIB_JULIAN_CALENDAR_DEFINITIONS_H_
#define SIMPLYDT_LIB_JULIAN_CALENDAR_DEFINITIONS_H_

/*!
 * @namespace simplydt::julian
 *
 * @brief
 * Proleptic Julian calendar system.
 */
namespace simplydt::julian
{

    /*!
     * @brief
     * Julian day number value type.
     *
     * @note
     * The underlying type used to represent Julian
     * day numbers imposes a limit on the level of
     * time precision.
     */
    using Jdn_T = double;

}

#endif // SIMPLYDT_LIB_JULIAN_CALENDAR_DEFINITIONS_H_
