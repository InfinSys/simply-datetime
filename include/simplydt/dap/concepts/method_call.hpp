
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file method_call.hpp
 *
 * @brief
 * Method overload entity concepts.
 */

#ifndef SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_CONCEPTS_H_
#define SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_CONCEPTS_H_

#include "simplydt/dap/type_traits/method_args.hpp"
#include "simplydt/dap/type_traits/method_call.hpp"
#include <concepts>

namespace simplydt::concepts
{

    /*!
     * @brief
     * Concept of a properly structured method overload
     * struct.
     * 
     * @details
     * This concepts details a contract-abiding overload
     * struct that can be invoked by DAP template methods.
     * To be "contract-abiding" in this context means that
     * type T Inherits from `dap::Overload`, defines a
     * static method `T::call(...)`, defines the nested
     * types `ReturnType` and `MethodArgs`, and have the
     * mentioned `MethodArgs` type be an instantiation of
     * the `dap::Arguments<...>` template. This concept
     * imposes no constraints on the overload return and
     * argument types.
     */
    template <typename T>
    concept valid_template_overload = requires {
        // Require 'T::MethodArgs' alias be defined
        // AND Require 'T::MethodArgs' be of type dap::Arguments
        requires type_traits::is_method_args_struct_v<typename T::MethodArgs>;

        // Require T inherit from dap::Overload
        requires type_traits::is_overload_derived_v<T, typename T::MethodArgs::Types>;

        // Require 'T::ReturnType' alias be defined
        // AND Require static 'T::call(...)' method be defined
        requires type_traits::has_static_call_signature_v<
            T,
            typename T::ReturnType,
            typename T::MethodArgs::Types>;
    };

} // namespace simplydt::concepts

#endif // SIMPLYDT_LIB_DAP_METHOD_CALL_STRUCT_CONCEPTS_H_
