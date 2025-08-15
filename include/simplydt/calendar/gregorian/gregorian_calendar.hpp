
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
     * Identifies the calendar system represented by this
     * implementation.
     */
    static constexpr CalendarSystem calendar = CalendarSystem::GREGORIAN;

    /*!
     * @brief
     * Indicates whether the calendar system is solar-based.
     *
     * @details
     * This constant specifies that the Gregorian calendar system
     * follows a solar model, where date progression is based on
     * the Earth's orbit around the Sun.
     */
    static constexpr bool isSolarCalendar = true;

    /*!
     * @brief
     * Indicates whether the calendar system is lunar-based.
     *
     * @details
     * This constant specifies that the Gregorian calendar system
     * does not follow a lunar model, which bases months on the
     * phases of the Moon.
     */
    static constexpr bool isLunarCalendar = false;

    /*!
     * @brief
     * Indicates whether the calendar system is lunisolar-based.
     *
     * @details
     * This constant specifies that the Gregorian calendar system
     * does not follow a lunisolar model, which combines solar
     * and lunar cycles to structure months and years.
     */
    static constexpr bool isLunisolarCalendar = false;

    /*!
     * @brief
     * Full names of Gregorian calendar months.
     */
    static constexpr inline const std::array<const char*, MONTHS_IN_YEAR>& MONTH_NAMES =
        Months;

    /*!
     * @brief
     * Abbreviated names of Gregorian calendar months.
     */
    static constexpr inline const std::array<std::string_view, MONTHS_IN_YEAR>& MONTH_ABBREVS =
        MonthAbbrevs;

    /*!
     * @brief
     * Full names of Gregorian calendar days-of-week.
     */
    static constexpr inline const std::array<const char*, DAYS_IN_WEEK>& DAY_OF_WEEK_NAMES =
        DaysOfWeek;

    /*!
     * @brief
     * Abbreviated names of Gregorian calendar days-of-week.
     */
    static constexpr inline const std::array<std::string_view, DAYS_IN_WEEK>&
        DAY_OF_WEEK_ABBREVS = DayOfWeekAbbrevs;

    /*!
     * @brief
     * Evaluate support of year value.
     *
     * @details
     * This function returns true if the given year falls within
     * the inclusive bounds defined by `YEAR_MINIMUM` and
     * `YEAR_MAXIMUM` for the Gregorian calendar system.
     *
     * @return
     * True if supported year value
     */
    [[nodiscard]] static constexpr bool isValidYear(const YearInt_t year) noexcept
    {
        return year >= YEAR_MINIMUM && year <= YEAR_MAXIMUM;
    }

    /*!
     * @brief
     * Determines whether a given year is a leap year.
     *
     * @details
     * This function checks if the specified year qualifies as a
     * leap year under Gregorian calendar rules. A year is
     * considered a leap year if it is divisible by 4, except for
     * years divisible by 100 unless it is also divisible by 400.
     *
     * @return
     * True if provided year is a leap year
     */
    [[nodiscard]] static constexpr bool isLeapYear(const YearInt_t year) noexcept
    {
        return (year % 4) == 0 && (year % 100 != 0 || year % YEARS_IN_ERA == 0);
    }

    /*!
     * @brief
     * Determines whether a given date is within a leap year.
     *
     * @return
     * True if provided date is within a leap year
     */
    [[nodiscard]] static constexpr bool isLeapYear(const Date& date) noexcept
    {
        return isLeapYear(date.year());
    }

    /*!
     * @brief
     * Returns total number of days in a given calendar year.
     *
     * @details
     * Determines whether the specified year is a leap year and
     * returns `DAYS_IN_LEAP_YEAR` or `DAYS_IN_YEAR` accordingly.
     * If the year is unsupported the function returns 0.
     *
     * @return
     * Total days in year
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const YearInt_t year) noexcept
    {
        if (!isValidYear(year))
            return 0; // Unsupported year

        return isLeapYear(year) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
    }

    /*!
     * @brief
     * Returns total number of days in the year of a given date.
     *
     * @details
     * Extracts the year from the provided `Date` to determine
     * the total number of days in the year.
     *
     * @return
     * Total days in year
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const Date date) noexcept
    {
        return getDaysInYear(date.year());
    }

    /*!
     * @brief
     * Checks if a month value is within valid range.
     *
     * @details
     * This function returns true if the given month falls within
     * the inclusive bounds defined by `MIN_MONTH_OF_YEAR` and
     * `MAX_MONTH_OF_YEAR` for the Gregorian calendar system.
     *
     * @return
     * True if valid numerical month value
     */
    [[nodiscard]] static constexpr bool isValidMonth(const uint8_t month) noexcept
    {
        return month >= MIN_MONTH_OF_YEAR && month <= MAX_MONTH_OF_YEAR;
    }

    /*!
     * @brief
     * Returns total number of days in a given month of a
     * specified year.
     *
     * @details
     * This function handles the varying lengths of months in
     * the Gregorian calendar, including the special case of
     * February during a leap year. The function first validates
     * the year and month; if either is invalid, it returns 0 to
     * indicate an unsupported or invalid date component.
     *
     * @return
     * Total days in month
     */
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        if (!isValidYear(year) || !isValidMonth(month))
            return 0; // Unsupported or invalid

        switch (month) {
        case February:
            switch (isLeapYear(year)) {
            case true:
                return 29;
            default:
                return 28;
            }

        case April:
        case June:
        case September:
        case November:
            return 30;

        // January, March, May, July, August, October, December
        default:
            return 31;
        }
    }

    /*!
     * @brief
     * Returns total number of days in the month of a specified
     * date.
     *
     * @details
     * Extracts the year and month from the provided `Date` to
     * determine the total number of days in the dates month.
     *
     * @return
     * Total days in month
     */
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(const Date date) noexcept
    {
        return getDaysInMonth(date.year(), date.month());
    }

    /*!
     * @brief
     * Checks if a day value is within valid range.
     *
     * @details
     * This function returns true if the given day falls within
     * the inclusive bounds defined by `MIN_DAY_OF_MONTH` and
     * `MAX_DAY_OF_MONTH` for the Gregorian calendar system.
     *
     * @return
     * True if valid day value
     */
    [[nodiscard]] static constexpr bool isValidDay(const uint8_t day) noexcept
    {
        return day >= MIN_DAY_OF_MONTH && day <= MAX_DAY_OF_MONTH;
    }

    /*!
     * @brief
     * Checks if a given year, month, and day combination form
     * a valid calendar date.
     *
     * @details
     * This function returns true when the provided date parameters
     * describe a real date on the Gregorian calendar. This is
     * achieved by comparing the dates day to the total number
     * of days in the month. If the provided year is not supported,
     * the function returns false.
     *
     * @return
     * True if date exists on calendar
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
     * Checks if a given date is a valid calendar date.
     *
     * @details
     * Extracts components from the provided `Date` to determine
     * validity of the date.
     *
     * @return
     * True if date exists on calendar
     */
    [[nodiscard]] static constexpr bool isValidDate(const Date date) noexcept
    {
        return isValidDate(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * Checks if a day-of-week index is within valid range.
     *
     * @details
     * Accepts a zero-based day-of-week index
     * (0 = Sunday ... 6 = Saturday). Returns true only if the
     * index is less than `DAYS_IN_WEEK`.
     *
     * @return
     * True if valid day-of-week index
     */
    [[nodiscard]] static constexpr bool isValidDOWIndex(const uint8_t dow) noexcept
    {
        return dow < DAYS_IN_WEEK;
    }

    /*!
     * @brief
     * Calculates day-of-week index for a given calendar date.
     *
     * @details
     * Implements Tomohiko Sakamoto's algorithm to determine
     * the day of the week for the specified year, month, and
     * day combination. Returns a zero-based day-of-week index
     * (0 = Sunday ... 6 = Saturday), or `INVALID_DOW_INDEX`
     * if the provided date does not exist on the calendar.
     *
     * @return
     * Day-of-week index
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        if (!isValidDate(year, month, day))
            return INVALID_DOW_INDEX;

        // CREDITS: Tomohiko Sakamoto
        // Day-of-week index algorithm
        year -= (month < March); // Extra days from leap year
                                 // only affect March and later
        const uint8_t monthIndex = month - 1;
        const int index =
            ((year + year / 4 - year / 100 + year / YEARS_IN_ERA +
              sakamoto::MONTH_KEY[monthIndex] + day) %
             DAYS_IN_WEEK);

        if (index >= DAYS_IN_WEEK)
            return INVALID_DOW_INDEX;

        return static_cast<uint8_t>(index);
    }

    /*!
     * @brief
     * Calculates day-of-week index for a given calendar date.
     *
     * @details
     * Extracts the year, month, and day from the given `Date`
     * instance to compute the zero-based day-of-week index.
     *
     * @return
     * Day-of-week index
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(const Date date) noexcept
    {
        return getDayOfWeekIndex(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * Determines number of weeks a specified month spans
     * over the calendar.
     *
     * @details
     * Calculates how many full or partial weeks are needed to
     * contain all days of the specified month in a standard
     * calendar grid. The result depends on the day of the week
     * the month starts on and the total number of days in the
     * month. Returns 0 if the month is invalid or if the
     * provided year is unsupported.
     *
     * @return
     * Number of weeks month spans
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
     * Determines number of weeks a calendar dates month
     * spans over the calendar.
     *
     * @details
     * Extracts the year and month from the provided `Date`
     * instance to calculate the number of weeks a month
     * spans over the calendar.
     *
     * @return
     * Number of weeks month spans
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(const Date date) noexcept
    {
        return getWeeksInMonth(date.year(), date.month());
    }

    /*!
     * @brief
     * Converts a calendar date to serial number of days since
     * Unix epoch.
     *
     * @details
     * Uses Howard Hinnant’s civil date algorithm to convert
     * a year, month, day combination into a signed day count
     * relative to the Unix epoch (1970-01-01 = day 0). The
     * result can be negative for dates before the epoch.
     *
     * @return
     * Days since January 1, 1970
     */
    [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
        // Convert {year, month, day} triple into a serial count of days.
        year -= month <= February;
        const int era      = year / YEARS_IN_ERA;
        const unsigned yoe = static_cast<unsigned>(year - era * YEARS_IN_ERA);
        const unsigned doy = (153 * (month + (month > February ? -3 : 9)) + 2) / 5 + day - 1;
        const unsigned doe = yoe * DAYS_IN_YEAR + yoe / 4 - yoe / 100 + doy;
        return static_cast<int32_t>(era * 146'097 + static_cast<long>(doe) - 719'468);
    }

    /*!
     * @brief
     * Converts a calendar date to serial number of days since
     * Unix epoch.
     *
     * @details
     * Extracts the date components from the provided `Date`
     * instance to calculate a signed day count relative to
     * the Unix epoch (1970-01-01 = day 0). The result can be
     * negative for dates before the epoch.
     *
     * @return
     * Days since January 1, 1970
     */
    [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(const Date date) noexcept
    {
        return toDaysSinceEpoch(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * Converts a serial count of days since Unix epoch to
     * a calendar date.
     *
     * @details
     * Uses Howard Hinnant’s civil date algorithm to convert
     * a signed day count relative to the Unix epoch
     * (1970-01-01 = day 0) into a year, month, day combination.
     * Returns a `GregorianDate` representing the calculated
     * civil date.
     *
     * @return
     * Gregorian calendar date
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
     * Converts a calendar date to a Unix timestamp (seconds
     * since epoch).
     *
     * @details
     * Uses `toDaysSinceEpoch()` to calculate the number of
     * days since the Unix epoch (1970-01-01) and multiplies
     * by the number of seconds in a day to obtain the
     * equivalent timestamp in seconds. The returned value
     * is stored in `stl::UnixTimestamp` and may be negative
     * for dates before the epoch.
     *
     * @return
     * Unix timestamp
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        return static_cast<stl::UnixTimestamp>(toDaysSinceEpoch(year, month, day) * 86'400);
    }

    /*!
     * @brief
     * Converts a calendar date to a Unix timestamp (seconds
     * since epoch).
     *
     * @details
     * Extracts the date components from the provided `Date`
     * instance to calculate the corresponding Unix timestamp.
     * The returned value is stored in `stl::UnixTimestamp`
     * and may be negative for dates before the epoch.
     *
     * @return
     * Unix timestamp
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(const Date date) noexcept
    {
        return toUnixTimestamp(date.year(), date.month(), date.day());
    }

    /*!
     * @brief
     * Converts a Unix timestamp (seconds since epoch) to a
     * calendar date.
     *
     * @details
     * Divides the given `stl::UnixTimestamp` by the number
     * of seconds in a day to convert seconds to whole days
     * since the Unix epoch (1970-01-01), then calls
     * `fromDaysSinceEpoch()` to obtain the corresponding
     * calendar date.
     *
     * @return
     * Gregorian calendar date
     */
    [[nodiscard]] static constexpr Date fromUnixTimestamp(const stl::UnixTimestamp& timestamp
    ) noexcept
    {
        return fromDaysSinceEpoch(static_cast<int32_t>(timestamp / 86'400));
    }

    /*!
     * @brief
     * Converts a system clock time point to a local calendar
     * date.
     *
     * @details
     * Interprets the given `stl::SystemTimePoint` as local
     * time by converting it to a Unix timestamp and then
     * populating a `std::tm` structure via
     * `stl::deriveLocalDateTimeFromTimestamp()`. The
     * resulting year, month, and day fields are used to
     * construct and return a `GregorianDate`. If the local
     * date conversion fails a default constructed Gregorian
     * date is returned.
     *
     * @return
     * Gregorian calendar date
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
     * Converts a system clock time point to a local calendar
     * date.
     *
     * @details
     * If `local` is true (time-zone), interprets the given
     * `stl::SystemTimePoint` as local time. If `local` is false
     * (no time-zone), interprets the time point as UTC. If the
     * local date conversion fails a default constructed Gregorian
     * date is returned.
     *
     * @return
     * Gregorian calendar date
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
