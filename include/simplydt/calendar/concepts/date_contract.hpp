
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file date_contract.hpp
 *
 * @brief
 * Conceptual calendar date implementation contract.
 */


#ifndef SIMPLYDT_LIB_CALENDAR_DATE_CONTRACT_CONCEPT_H_
#define SIMPLYDT_LIB_CALENDAR_DATE_CONTRACT_CONCEPT_H_

#include "simplydt/calendar/concepts/date_concepts.hpp"

namespace simplydt::concepts
{

/*!
 * @brief
 * Concept of a type that meets the criteria to be
 * considered a useable calendar date implementation.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
template <typename Date_Impl>
concept contract_abiding_date = requires {
    requires date::has_contextual_nested_types<Date_Impl>;
    requires std::is_integral_v<typename Date_Impl::YearInt_t>;
    requires date::has_date_component_methods<Date_Impl>;
    requires date::has_logical_operators<Date_Impl>;
    requires date::has_arithmetic_operators<Date_Impl>;
    requires date::has_basic_state_methods<Date_Impl>;
    requires date::has_sequential_evaluation_methods<Date_Impl>;
    requires date::is_stream_out_compatible<Date_Impl>;
    requires date::has_date_string_methods<Date_Impl>;
    requires std::default_initializable<Date_Impl>;
    requires std::copyable<Date_Impl>;
    requires std::destructible<Date_Impl>;
};

} // namespace simplydt::concepts

#ifndef SIMPLYDT_ENFORCE_DATE_CONTRACT
/*! @brief Macro for asserting date interface implementation contract. */
#    define SIMPLYDT_ENFORCE_DATE_CONTRACT(Class)                                             \
        static_assert(                                                                        \
            simplydt::concepts::contract_abiding_date<Class>,                                 \
            #Class " implementation does not fulfill the public API contract."                \
        )
#endif

#endif // SIMPLYDT_LIB_CALENDAR_DATE_CONTRACT_CONCEPT_H_
