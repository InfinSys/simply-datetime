
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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
#include "simplydt/calendar/type_traits/date_traits.hpp"

namespace simplydt::concepts
{

/*!
* @brief
* Concept of a type that meets the criteria to be
* considered a useable calendar date implementation.
*/
template <typename Date_Impl, typename Year_T>
concept contract_abiding_date = requires {
    // TODO: INCOMPLETE!!!
    requires std::is_integral_v<Year_T>;
    requires date::has_date_component_methods<Date_Impl, Year_T>;
    //requires date::has_basic_state_methods<Date_Impl>;
};

}

#endif // SIMPLYDT_LIB_CALENDAR_DATE_CONTRACT_CONCEPT_H_
