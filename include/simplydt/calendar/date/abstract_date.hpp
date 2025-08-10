
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
#include "simplydt/common/calendar_defs.hpp"
#include <optional>

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
// TODO: Above documentaion needs to updated...
template <typename Date_Impl, typename Year_T>
struct CalendarDate {
    /*! @brief Calendar date implementation. */
    using Date = Date_Impl;
    /*! @brief Calendar date year type. */
    using YearInt_t = Year_T;

    [[nodiscard]] std::optional<YearInt_t> getComponent(const CalendarComponent component) const
    {
        switch (component) {
        case CalendarComponent::YEAR:
            return thisImpl().year();
        case CalendarComponent::MONTH:
            return thisImpl().month();
        case CalendarComponent::DAY:
            return thisImpl().day();
        default:
            return std::nullopt; // Invalid component request
        };
    }

  private:
    CalendarDate()  = default;
    ~CalendarDate() = default;
    friend Date_Impl;

    [[nodiscard]] const Date& thisImpl() const noexcept
    {
        return static_cast<const Date&>(*this);
    }

    [[nodiscard]] Date& thisImpl() noexcept
    {
        return static_cast<Date&>(*this);
    }
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_CRTP_CALENDAR_DATE_H_
