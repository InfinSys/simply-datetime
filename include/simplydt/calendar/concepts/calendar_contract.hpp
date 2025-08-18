
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file calendar_contract.hpp
 *
 * @brief
 * Conceptual calendar implementation contract.
 */


#ifndef SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_
#define SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_

#include "simplydt/calendar/concepts/calendar_concepts.hpp"
#include "simplydt/calendar/concepts/date_contract.hpp"

namespace simplydt::concepts
{

/*!
 * @brief
 * Concept of a type that meets the criteria to be
 * considered a useable calendar implementation.
 */
template <typename Calendar_Impl>
concept contract_abiding_calendar = requires {
    requires calendar::has_contextual_nested_types<Calendar_Impl>;
    requires contract_abiding_date<typename Calendar_Impl::Date>;
    requires calendar::has_characteristic_query_members<Calendar_Impl>;
    requires calendar::has_calendar_name_arrays<Calendar_Impl>;
    requires calendar::has_calendar_structure_methods<Calendar_Impl>;
    requires calendar::has_date_validation_methods<Calendar_Impl>;
    requires calendar::has_date_conversion_methods<Calendar_Impl>;
};

#ifndef SIMPLYDT_ENFORCE_CALENDAR_CONTRACT
/*! @brief Macro for asserting calendar implementation interface contract. */
#    define SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(Class)                                         \
        static_assert(                                                                        \
            simplydt::concepts::contract_abiding_calendar<Class>,                             \
            #Class " implementation does not fulfill the public API contract."                \
        )
#endif

} // namespace simplydt::concepts

#endif // SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_
