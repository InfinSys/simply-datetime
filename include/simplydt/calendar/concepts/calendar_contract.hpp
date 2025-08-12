
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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

namespace simplydt::concepts
{

/*!
 * @brief
 * Concept of a type that meets the criteria to be
 * considered a useable calendar implementation.
 */
template <typename T>
concept contract_abiding_calendar = requires {
    // TODO: INCOMPLETE!!!
    requires std::is_same_v<T, T>;
};

#ifndef SIMPLYDT_ENFORCE_CALENDAR_CONTRACT
/*! @brief Macro for asserting calendar implementation interface contract. */
#    define SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(Class)                                             \
        static_assert(                                                                        \
            simplydt::concepts::contract_abiding_calendar<Class>,                                 \
            #Class " implementation does not fulfill the public API contract."                \
        );
#endif

} // namespace simplydt::concepts

#endif // SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_
