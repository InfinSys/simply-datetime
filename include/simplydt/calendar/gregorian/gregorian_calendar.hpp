
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
#include "simplydt/common/stl_chrono_utils.hpp"

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
        return (year % 4) == 0 && (year % 100 != 0 || year % YEARS_IN_ERA == 0);
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

        // CREDITS: Tomohiko Sakamoto
        // Day-of-week index algorithm
        const YearInt_t modYear = year - (month < 3); // Extra days from leap year
                                                      // only affect March and later
        const uint8_t monthIndex = month - 1;
        const int index =
            ((modYear + modYear / 4 - modYear / 100 + modYear / YEARS_IN_ERA +
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
    [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
        // Convert {year, month, day} triple into a serial count of days.
        year -= month <= 2;
        const int era      = year / YEARS_IN_ERA;
        const unsigned yoe = static_cast<unsigned>(year - era * YEARS_IN_ERA);
        const unsigned doy = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;
        const unsigned doe = yoe * DAYS_IN_YEAR + yoe / 4 - yoe / 100 + doy;
        return static_cast<int32_t>(era * 146'097 + static_cast<long>(doe) - 719'468);
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(const Date date) noexcept
    {
        return toDaysSinceEpoch(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr Date fromDaysSinceEpoch(int32_t serial_days) noexcept
    {
        // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
        // Convert a serial count of days into a {year, month, day} triple.
        serial_days += 719'468;
        const int era = (serial_days >= 0 ? serial_days : serial_days - 146'096) / 146'097;
        const unsigned doe = static_cast<unsigned>(serial_days - era * 146'097);
        const unsigned yoe = (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) / DAYS_IN_YEAR;
        const YearInt_t y  = static_cast<YearInt_t>(yoe) + era * YEARS_IN_ERA;
        const unsigned doy = doe - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
        const unsigned mp  = (5 * doy + 2) / 153;
        const uint8_t d    = static_cast<uint8_t>(doy - (153 * mp + 2) / 5 + 1);
        const uint8_t m    = static_cast<uint8_t>(mp + (mp < 10 ? 3 : -9));
        return Date{static_cast<YearInt_t>(y + (m <= 2)), m, d};
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        return static_cast<stl::UnixTimestamp>(toDaysSinceEpoch(year, month, day) * 86'400);
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(const Date date) noexcept
    {
        return toUnixTimestamp(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr Date fromUnixTimestamp(const stl::UnixTimestamp& timestamp
    ) noexcept
    {
        return fromDaysSinceEpoch(static_cast<int32_t>(timestamp / 86'400));
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static Date fromTimePoint(const stl::SystemTimePoint& time_point) noexcept
    {
        const stl::UnixTimestamp secsSinceEpoch = stl::SystemClock::to_time_t(time_point);
        stl::CalendarDateTime dateBuffer{};

        if (!stl::deriveLocalDateTimeFromTimestamp(&secsSinceEpoch, &dateBuffer))
            return Date{}; // Failed to interpret local date

        return Date{
            static_cast<YearInt_t>(
                dateBuffer.tm_year + 1'900
            ), // tm_year measures years since 1900
            static_cast<uint8_t>(
                dateBuffer.tm_mon + 1
            ), // tm_mon measures months since January
            static_cast<uint8_t>(dateBuffer.tm_mday)
        };
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static Date fromTimePoint(
        const stl::SystemTimePoint& time_point, const bool local
    ) noexcept
    {
        if (local)
            return fromTimePoint(time_point);

        const stl::UnixTimestamp secsSinceEpoch = stl::SystemClock::to_time_t(time_point);
        return fromUnixTimestamp(secsSinceEpoch);
    }

  private:
    GregorianCalendar()  = delete;
    ~GregorianCalendar() = delete;
};

SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
