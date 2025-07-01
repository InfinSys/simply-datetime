
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file method_args.hpp
 *
 * @brief
 * Method arguments entity type traits.
 */

#ifndef SIMPLYDT_LIB_METHOD_ARGUMENT_TRAITS_H_
#define SIMPLYDT_LIB_METHOD_ARGUMENT_TRAITS_H_

#include "simplydt/dap/overload/arguments.hpp"
#include <type_traits>

namespace simplydt::type_trait
{
    // TYPE TRAIT : is_method_args

    /*!
     * @brief
     * Determine if type T is a method arguments struct.
     */
    template <typename T>
    struct is_method_args_struct;

    template <typename UnknownType>
    struct is_method_args_struct : std::false_type {};

    template <typename... Args>
    struct is_method_args_struct<dap::Arguments<Args...>> : std::true_type {};

    /*!
     * @brief
     * Determine if type T is a method arguments struct.
     */
    template <typename T>
    inline constexpr bool is_method_args_struct_v = is_method_args_struct<T>::value;

} // namespace simplydt::type_trait

#endif // SIMPLYDT_LIB_METHOD_ARGUMENT_TRAITS_H_
