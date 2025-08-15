
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_date.hpp
 *
 * @brief
 * Base CRTP calendar date declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CALENDAR_DATE_H_
#define SIMPLYDT_LIB_BASE_CALENDAR_DATE_H_

#include "simplydt/common/calendar_defs.hpp"
#include <optional>

namespace simplydt
{

/*!
 * @brief
 * Base calendar agnostic date.
 *
 * @details
 * This is a generic representation of a calendar date
 * that is not associated with any specific calendar.
 * This type is not self-constructable and must be
 * inherited by a concrete implementation that presents
 * a valid public API. Implementations should seek
 * confirmation their API is compliant by invoking the
 * date contract enforcement macro just after the body
 * of the implementation. Failing to be compliant can
 * result in substitution errors or undefined behavior.
 */
template <typename Date_Impl, typename Year_T>
struct CalendarDate {
    /*! @brief Calendar date implementation. */
    using Date = Date_Impl;
    /*! @brief Date year type. */
    using YearInt_t = Year_T;

    [[nodiscard]] std::optional<YearInt_t> getComponent(const CalendarComponent component
    ) const
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

#endif // SIMPLYDT_LIB_BASE_CALENDAR_DATE_H_
