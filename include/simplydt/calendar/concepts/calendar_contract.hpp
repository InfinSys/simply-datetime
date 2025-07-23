
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file calendar_contract.hpp
 *
 * @brief
 * Calendar implementation conceptual contract.
 */


#ifndef SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_
#define SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_

#include <concepts>
#include <type_traits>

namespace simplydt::concepts
{

template <typename T>
concept contract_abiding_calendar = requires {
    requires std::is_same_v<T, T>;
};

}

#endif // SIMPLYDT_LIB_CALENDAR_CONTRACT_CONCEPT_H_
