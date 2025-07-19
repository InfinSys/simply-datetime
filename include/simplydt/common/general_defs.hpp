
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file general_defs.hpp
 *
 * @note
 * This file really shouldn't exist given it's
 * broad nature. However, I am unsure where to
 * situate some of the ideas in this document.
 * The definitions are likely to later be moved
 * to another translation unit.
 *
 * @brief
 * General Simply Datetime library definitions.
 */


#ifndef SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_
#define SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_

#include <cstdint>

namespace simplydt
{

/*!
 * @brief
 * Enumeration of broken-down calendar components.
 */
enum CalendarComponent : uint8_t {
    SECOND, ///< Time second component
    MINUTE, ///< Time minute component
    HOUR,   ///< Time hour component
    DAY,    ///< Date day component
    MONTH,  ///< Date month component
    YEAR    ///< Date year component
};

/*!
 * @brief
 * Invalid literal.
 */
inline const char* INVALID_LITERAL = "invalid";

} // namespace simplydt

#endif // SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_
