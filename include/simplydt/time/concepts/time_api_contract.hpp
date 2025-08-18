
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
 * considered a useable calendar date implementation.
 */
template <typename Time_Impl>
concept contract_abiding_time = requires {
    // TODO: INCOMPLETE!!!
    requires std::is_same_v<Time_Impl, Time_Impl>;
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
