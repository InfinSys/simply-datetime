
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file simplydt_defs.hpp
 *
 * @brief
 * General Simply Datetime library definitions and
 * macros.
 */


#ifndef SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_
#define SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_

#include <cstdint>

namespace simplydt
{

#if defined(_WIN32) || defined(_WIN64)
/*! @brief Simply Datetime on Windows platform. */
#    define SIMPLYDT_WIN32
#elif defined(__unix__) || defined(__unix) || defined(__APPLE__)
/*! @brief Simply Datetime on POSIX compliant platform. */
#    define SIMPLYDT_POSIX
#    if defined(__APPLE__)
/*! @brief Simply Datetime on Apple platform. */
#        define SIMPLYDT_APPLE
#    elif defined(__unix__) || defined(__unix)
/*! @brief Simply Datetime on Linux platform. */
#        define SIMPLYDT_LINUX
#    endif
#endif

/*!
 * @brief
 * Enumeration of individual datetime components.
 */
enum DatetimeComponent : uint8_t {
    NANOSECOND  = 1 << 0, ///< Time nanosecond component
    MILLISECOND = 1 << 1, ///< Time millisecond component
    SECOND      = 1 << 2, ///< Time second component
    MINUTE      = 1 << 3, ///< Time minute component
    HOUR        = 1 << 4, ///< Time hour component
    DAY         = 1 << 5, ///< Date day component
    MONTH       = 1 << 6, ///< Date month component
    YEAR        = 1 << 7  ///< Date year component
};

/*!
 * @brief
 * Invalid literal.
 */
inline const char* INVALID_LITERAL = "invalid";

} // namespace simplydt

#endif // SIMPLYDT_LIB_GENERAL_DEFINITIONS_H_
