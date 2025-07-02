
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file repr_types.hpp
 *
 * @brief
 * Datetime Abstraction Protocol underlying
 * representation type concepts.
 */

#ifndef SIMPLYDT_LIB_DAP_UNDERLYING_TYPES_CONCEPTS_H_
#define SIMPLYDT_LIB_DAP_UNDERLYING_TYPES_CONCEPTS_H_

#include <concepts>
#include <type_traits>

namespace simplydt::concepts
{

    /*!
     * @brief
     * Concept of a type that can be relatively
     * compared to other objects of same type.
     */
    template <typename T>
    concept comparable_type = requires (T instance) {
        { instance == instance } -> std::same_as<bool>;
        { instance < instance } -> std::same_as<bool>;
        { instance <= instance } -> std::same_as<bool>;
        { instance > instance } -> std::same_as<bool>;
        { instance >= instance } -> std::same_as<bool>;
    };

    /*!
     * @brief
     * Concept of a useable underlying type for
     * a DAP driver.
     */
    template <typename T>
    concept useable_underlying_type = requires {
        // T must not be a pointer
        requires !std::is_pointer_v<T>;

        // T must not have const qualification
        requires !std::is_const_v<T>;
        
        requires std::is_copy_constructible_v<T>;
        requires std::is_move_constructible_v<T>;
        requires std::is_assignable_v<T&, T>;

        // Require T have relative comparison operators
        requires comparable_type<T>;
    };

}

#endif // SIMPLYDT_LIB_DAP_UNDERLYING_TYPES_CONCEPTS_H_
