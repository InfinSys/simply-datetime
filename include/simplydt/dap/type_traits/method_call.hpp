
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file method_call.hpp
 *
 * @brief
 * Method overload entity type traits.
 */

#ifndef SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_TRAITS_H_
#define SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_TRAITS_H_

#include "simplydt/dap/overload/method.hpp"
#include <tuple>
#include <type_traits>
#include <utility>

namespace simplydt::type_trait
{

    /*!
     * @brief
     * Check that type T has a static method named 'call'
     * that respects return and argument types specified.
     *
     * @details
     * This helper trait does not invoke the `T::call()`
     * method for verification. Instead it uses
     * `std::declval` which simulates the call with the
     * provided parameter types in an unevaluated context
     * to determine the legality of the expression.
     */
    template <typename T, typename ReturnType, typename... ArgTypes>
        struct has_static_call_signature_impl : std::bool_constant < requires {
        {
            T::call(std::declval<ArgTypes>()...)
        } -> std::convertible_to<ReturnType>;
    } > {};

    /*!
     * @brief
     * Determine if type T has an appropriate static
     * 'call()' method.
     */
    template <typename T, typename ReturnType, typename ArgTypesTuple>
    struct has_static_call_signature;

    /*!
     * @brief
     * Determine if type T has an appropriate static
     * 'call()' method.
     */
    template <typename T, typename ReturnType, typename... Args>
    struct has_static_call_signature<T, ReturnType, std::tuple<Args...>> {
        /*! @brief Static analysis result. */
        static constexpr bool
            value = has_static_call_signature_impl<T, ReturnType, Args...>::value;
    };

    /*!
     * @brief
     * Determine if type T has an appropriate static
     * 'call()' method.
     */
    template <typename T, typename ReturnType, typename ArgTypesTuple>
    inline constexpr bool
        has_static_call_signature_v = has_static_call_signature<T, ReturnType, ArgTypesTuple>::
            value;

    /*!
     * @brief
     * Determine if type T inherits from DAP overload
     * struct.
     */
    template <typename T, typename ArgTypesTuple>
    struct is_dap_overload_derived;

    /*!
     * @brief
     * Determine if type T inherits from DAP overload
     * struct.
     */
    template <typename T, typename... Args>
    struct is_dap_overload_derived<T, std::tuple<Args...>> {
        /*! @brief Static analysis result. */
        static constexpr bool value = std::is_base_of_v<dap::Overload<Args...>, T>;
    };

    /*!
     * @brief
     * Determine if type T inherits from DAP overload
     * struct.
     */
    template <typename T, typename ArgTypesTuple>
    inline constexpr bool
        is_dap_overload_derived_v = is_dap_overload_derived<T, ArgTypesTuple>::value;

} // namespace simplydt::type_trait

#endif // SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_TRAITS_H_
