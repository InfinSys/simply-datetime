
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
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(const YearInt_t year, const uint8_t month) noexcept
    {
        if (!isValidYear(year) || !isValidMonth(month))
            return 0; // Unsupported or invalid

        switch (month) {
        case FEBRUARY:
            switch (isLeapYear(year)) {
            case true:
                return 29;
            default:
                return 28;
            }

        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;

        // January, March, May, July, August, October, December
        default:
            return 31;
        }
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const YearInt_t year) noexcept
    {
        if (!isValidYear(year))
            return 0; // Unsupported year

        uint16_t totalDays = 0;

        for (uint8_t month = 1; month <= 12; month++)
            totalDays += getDaysInMonth(year, month);

        return totalDays;
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
        const uint8_t monthTotalDays = getDaysInMonth(date.year(), date.month());
        return date.day() <= monthTotalDays;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(const Date date) noexcept
    {
        if (!isValidDate(date))
            return INVALID_DATE_DOW; // TODO: bruh...
        
        // Tomohiko Sakamoto's Algorithm
        const uint8_t monthKey[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        const YearInt_t year = date.year() - (date.month() < 3); // Extra days from leap year
                                                                 // only affect March and later
        const int index = (year + year / 4 - year / 100 + year / 400 + monthKey[date.month() - 1] + date.day()) % 7;

        return 0; // TODO: INCOMPLETE!!!
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(const YearInt_t year, const uint8_t month) noexcept
    {
        // TODO: INCOMPLETE!!!
        return 0;
    }

  private:
    GregorianCalendar()  = delete;
    ~GregorianCalendar() = delete;
};

SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
