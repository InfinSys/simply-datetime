
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file arguments.hpp
 *
 * @brief
 * Method arguments entity declaration.
 */

#ifndef SIMPLYDT_LIB_METHOD_ARGUMENTS_STRUCT_H_
#define SIMPLYDT_LIB_METHOD_ARGUMENTS_STRUCT_H_

#include <tuple>

namespace simplydt::dap
{

    /*!
     * @brief
     * Method call arguments.
     */
    template <typename... ArgTypes>
    struct Arguments {
        /*! @brief Method argument types tuple. */
        using Types = std::tuple<ArgTypes...>;
    };

} // namespace simplydt::dap

#endif // SIMPLYDT_LIB_METHOD_ARGUMENTS_STRUCT_H_
