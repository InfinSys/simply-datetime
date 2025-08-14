
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_calendar.hpp
 *
 * @brief
 * Base CRTP calendar declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CALENDAR_H_
#define SIMPLYDT_LIB_BASE_CALENDAR_H_

#include "simplydt/calendar/concepts/calendar_contract.hpp"

namespace simplydt
{

/*!
 * @brief
 * Base calendar agnostic system.
 */
template <typename Calendar_Impl, typename Date_T, typename Month_Enum, typename DOW_Enum>
struct CalendricalSystem {
    /*! @brief Calendar system implementation. */
    using Calendar = Calendar_Impl;
    /*! @brief Calendar implementation base class. */
    using Base = CalendricalSystem<Calendar_Impl, Date_T, Month_Enum, DOW_Enum>;
    /*! @brief Calendar date. */
    using Date = Date_T;
    /*! @brief Year integer type. */
    using YearInt_t = typename Date::YearInt_t;
    /*! @brief Enumeration of calendar months. */
    using Month = Month_Enum;
    /*! @brief Enumeration of calendar days of week. */
    using DayOfWeek = DOW_Enum;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr const char* getMonthLiteral(const uint8_t month) noexcept
    {
        if (!Calendar::isValidMonth(month))
            return INVALID_LITERAL;
        // TODO: INCOMPLETE!!!
        // Use template passed constexpr array somehow...
        return "temp";
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr const char* getMonthLiteral(const Month month) noexcept
    {
        // TODO: INCOMPLETE!!!
        // Use template passed constexpr array somehow...
        return "temp";
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr const char* getMonthLiteral(const Date date) noexcept
    {
        return date.monthLiteral();
    }

  private:
    CalendricalSystem()  = delete;
    ~CalendricalSystem() = delete;
    friend Calendar_Impl;
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_CALENDAR_H_
