
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file general_defs.hpp
 *
 * @note
 * This file really shouldn't exist given it's
 * very broad nature. However, at the moment I
 * am unsure where to situate some of the ideas
 * in this document. The definitions are likely
 * to later be moved to another translation unit.
 *
 * @brief
 * General common Simply Datetime library
 * definitions.
 */


#ifndef SIMPLYDT_LIB_COMMON_DEFINITIONS_H_
#define SIMPLYDT_LIB_COMMON_DEFINITIONS_H_

#include <cstdint>

namespace simplydt
{

    /*!
     * @brief
     * Enumeration of broken-down calendar components.
     */
    enum CalendarComponent : uint8_t {
        SECOND, ///< Datetime second component
        MINUTE, ///< Datetime minute component
        HOUR,   ///< Datetime hour component
        DAY,    ///< Datetime day component
        MONTH,  ///< Datetime month component
        YEAR    ///< Datetime year component
    };

}

#endif // SIMPLYDT_LIB_COMMON_DEFINITIONS_H_
