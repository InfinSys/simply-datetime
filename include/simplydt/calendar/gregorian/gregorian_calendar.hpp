
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
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr inline const std::array<const char*, MONTHS_IN_YEAR>& MONTH_NAMES =
        Months;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr inline const std::array<std::string_view, MONTHS_IN_YEAR>& MONTH_ABBREVS =
        MonthAbbrevs;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr inline const std::array<const char*, DAYS_IN_WEEK>& DAY_OF_WEEK_NAMES =
        DaysOfWeek;

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    static constexpr inline const std::array<std::string_view, DAYS_IN_WEEK>&
        DAY_OF_WEEK_ABBREVS = DayOfWeekAbbrevs;

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
    [[nodiscard]] static constexpr bool isLeapYear(const Date& date) noexcept
    {
        return isLeapYear(date.year());
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
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        if (!isValidYear(year) || !isValidMonth(month))
            return 0; // Unsupported or invalid

        switch (month) {
        // February
        case 2:
            switch (isLeapYear(year)) {
            case true:
                return 29;
            default:
                return 28;
            }

        // April, June, September, November
        case 4:
        case 6:
        case 9:
        case 11:
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
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(const Date date) noexcept
    {
        return getDaysInMonth(date.year(), date.month());
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

        for (uint8_t month = MIN_MONTH_OF_YEAR; month <= MAX_MONTH_OF_YEAR; month++)
            totalDays += getDaysInMonth(year, month);

        return totalDays;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const Date date) noexcept
    {
        return getDaysInYear(date.year());
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
    [[nodiscard]] static constexpr bool isValidDate(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if (!isValidYear(year))
            return false;

        const uint8_t monthTotalDays = getDaysInMonth(year, month);
        return day <= monthTotalDays;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isValidDate(const Date date) noexcept
    {
        return isValidDate(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if (!isValidDate(year, month, day))
            return INVALID_DOW_INDEX;

        // Tomohiko Sakamoto's Algorithm
        const YearInt_t modYear = year - (month < 3); // Extra days from leap year
                                                      // only affect March and later
        const uint8_t monthIndex = month - 1;
        const int index =
            ((modYear + modYear / 4 - modYear / 100 + modYear / 400 +
              sakamoto::MONTH_KEY[monthIndex] + day) %
             DAYS_IN_WEEK);

        if (index >= DAYS_IN_WEEK)
            return INVALID_DOW_INDEX;

        return static_cast<uint8_t>(index);
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(const Date date) noexcept
    {
        return getDayOfWeekIndex(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr bool isValidDOWIndex(const uint8_t dow) noexcept
    {
        return dow > 0 && dow < DAYS_IN_WEEK;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        const uint8_t monthTotalDays = getDaysInMonth(year, month);

        if (monthTotalDays == 0)
            return 0; // Unsupported or invalid

        const uint8_t firstOfMonthDowIndex = getDayOfWeekIndex(year, month, 1);
        const uint8_t monthCells           = firstOfMonthDowIndex + monthTotalDays;
        return (monthCells + 6) / DAYS_IN_WEEK;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(const Date date) noexcept
    {
        return getWeeksInMonth(date.year(), date.month());
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        // TODO: INCOMPLETE!!!
        return 0;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr Date fromUnixTimestamp(const stl::UnixTimestamp& timestamp
    ) noexcept
    {
        // TODO: INCOMPLETE!!!
        return Date{};
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static Date fromTimePoint(const stl::SystemTimePoint& time_point) noexcept
    {
        // TODO: INCOMPLETE!!!
        return Date{};
    }

  private:
    GregorianCalendar()  = delete;
    ~GregorianCalendar() = delete;
};

SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
