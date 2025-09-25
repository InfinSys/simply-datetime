
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file time_api_contract.hpp
 *
 * @brief
 * Conceptual temporaal time implementation contract.
 */


#ifndef SIMPLYDT_LIB_TEMPORAL_TIME_CONTRACT_CONCEPT_H_
#define SIMPLYDT_LIB_TEMPORAL_TIME_CONTRACT_CONCEPT_H_

#include "simplydt/time/concepts/time_concepts.hpp"

namespace simplydt::concepts
{

/*!
 * @brief
 * Concept of a type that meets the criteria to be
 * considered a useable time standard implementation.
 *
 * @details
 * A valid time standard type must provide contextual
 * nested types (for library internal-use), time
 * component accessors, and support for logical and
 * arithmetic operators. It must include basic state
 * management and sequential evaluation methods, as
 * well as stream output and string conversion
 * capabilities. Additionally, it must satisfy
 * fundamental C++ type requirements including default
 * initialization, copyability, and destructibility.
 */
template <typename Time_Impl>
concept contract_abiding_time = requires {
    requires time::has_contextual_nested_types<Time_Impl>;
    requires time::has_standard_time_component_methods<Time_Impl>;
    requires time::has_logical_operators<Time_Impl>;
    requires time::has_arithmetic_operators<Time_Impl>;
    requires time::has_basic_state_methods<Time_Impl>;
    requires time::has_sequential_evaluation_methods<Time_Impl>;
    requires time::is_stream_out_compatible<Time_Impl>;
    requires time::has_time_string_methods<Time_Impl>;
    requires std::default_initializable<Time_Impl>;
    requires std::copyable<Time_Impl>;
    requires std::destructible<Time_Impl>;
};

} // namespace simplydt::concepts

#ifndef SIMPLYDT_ENFORCE_TIME_CONTRACT
/*! @brief Macro for asserting time implementation interface contract. */
#    define SIMPLYDT_ENFORCE_TIME_CONTRACT(Class)                                             \
        static_assert(                                                                        \
            simplydt::concepts::contract_abiding_time<Class>,                                 \
            #Class " implementation does not fulfill the public API contract."                \
        )
#endif

#endif // SIMPLYDT_LIB_TEMPORAL_TIME_CONTRACT_CONCEPT_H_
