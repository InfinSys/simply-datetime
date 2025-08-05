
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_date.hpp
 *
 * @brief
 * Base CRTP calendar date declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CRTP_CALENDAR_DATE_H_
#define SIMPLYDT_LIB_BASE_CRTP_CALENDAR_DATE_H_

#include "simplydt/calendar/concepts/date_contract.hpp"

namespace simplydt
{

/*!
* @brief
* Base contract-enforcing agnostic calendar date.
* 
* @details
* This is Simply Datetime's generic representation
* of a calendar date. It is not associated with any
* specific calendar and is not a self-constructable
* type. It's responsibility is to enforce a set of
* API requirements on the derived calendar date
* implementations to ensure compatibility with
* library internals and consistenecy.
*/
template <typename Date_Impl, typename Year_T>
    requires concepts::contract_abiding_date<Date_Impl, Year_T>
struct CalendarDate {
    /*! @brief Calendar date implementation. */
    using Date = Date_Impl;
    /*! @brief Calendar date year type. */
    using YearInt_t = Year_T;

    // TODO: INCOMPLETE!!!

private:
    CalendarDate() = default;
    ~CalendarDate() = default;
    friend Date_Impl;
};

}

#endif // SIMPLYDT_LIB_BASE_CRTP_CALENDAR_DATE_H_
