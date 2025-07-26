
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_calendar.hpp
 *
 * @brief
 * Base CRTP calendar declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CRTP_CALENDAR_H_
#define SIMPLYDT_LIB_BASE_CRTP_CALENDAR_H_

#include "simplydt/calendar/concepts/calendar_contract.hpp"

namespace simplydt
{

/*!
* @brief
* Base contract-enforcing calendar.
*/
template <concepts::contract_abiding_calendar Calendar_Impl>
struct CalendricalSystem {
    // TODO: INCOMPLETE!!!

private:
    CalendricalSystem() = default;
    ~CalendricalSystem() = default;
    friend Calendar_Impl;
};

}

#endif // SIMPLYDT_LIB_BASE_CRTP_CALENDAR_H_
