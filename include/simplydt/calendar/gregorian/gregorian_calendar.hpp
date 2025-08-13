
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_calendar.hpp
 *
 * @brief
 * Gregorian calendar system declaration.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
#define SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_

#include "simplydt/calendar/abstract_calendar.hpp"
#include "simplydt/calendar/concepts/calendar_contract.hpp"
#include "simplydt/calendar/gregorian/gregorian_date.hpp"

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar system.
 */
struct GregorianCalendar final :
    public CalendricalSystem<GregorianCalendar, GregorianDate, Month, DayOfWeek> {
    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr CalendarSystem calendar = CalendarSystem::GREGORIAN;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr bool isSolarCalendar = true;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr bool isLunarCalendar = false;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr bool isLunisolarCalendar = false;

    /*!
     * @brief
     * Evaluate support of year value.
     */
    [[nodiscard]] static constexpr bool isValidYear(const YearInt_t year) noexcept
    {
        return year >= YEAR_MINIMUM && year <= YEAR_MAXIMUM;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isLeapYear(const YearInt_t year) noexcept
    {
        return (year % 4) == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isValidMonth(const uint8_t month) noexcept
    {
        return month >= MIN_MONTH_OF_YEAR && month <= MAX_MONTH_OF_YEAR;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isValidDay(const uint8_t day) noexcept
    {
        return day >= MIN_DAY_OF_MONTH && day <= MAX_DAY_OF_MONTH;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isValidDate(const Date date) noexcept
    {
        // TODO: INCOMPLETE!!!
        return false;
    }

  private:
    GregorianCalendar()  = delete;
    ~GregorianCalendar() = delete;
};

SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
