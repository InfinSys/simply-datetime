
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file method.hpp
 *
 * @brief
 * Base DAP method overload entity definition.
 */

#ifndef SIMPLYDT_LIB_DAP_METHOD_OVERLOAD_STRUCT_H_
#define SIMPLYDT_LIB_DAP_METHOD_OVERLOAD_STRUCT_H_

#include "simplydt/dap/overload/arguments.hpp"

namespace simplydt::dap
{

    /*!
     * @brief
     * Base DAP method overload struct.
     */
    template <typename... ArgTypes>
    struct Overload {
        /*! @brief Overload method argument types. */
        using MethodArgs = Arguments<ArgTypes...>;

        /*! @brief Conceptual type identification. */
        static constexpr bool isOverload() noexcept { return true; }
    };

} // namespace simplydt::dap

#endif // SIMPLYDT_LIB_DAP_METHOD_OVERLOAD_STRUCT_H_
