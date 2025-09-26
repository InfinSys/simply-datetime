
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_calendar.hpp
 *
 * @brief
 * Gregorian calendar declaration.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_CALENDAR_H_
#define SIMPLYDT_LIB_GREGORIAN_CALENDAR_H_

#include "simplydt/calendar/abstract_calendar.hpp"
#include "simplydt/calendar/concepts/calendar_api_contract.hpp"
#include "simplydt/calendar/gregorian/gregorian_date.hpp"

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar system.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
struct GregorianCalendar :
    public CalendricalSystem<GregorianCalendar, GregorianDate, Month, DayOfWeek> {
    /*! @brief Array of dates in one calendar week. */
    using WeekDates = std::array<Date, DAYS_IN_WEEK>;

    /*!
     * @brief
     * Identifies calendar system represented by
     * this implementation.
     */
    static constexpr CalendarSystem calendar = CalendarSystem::GREGORIAN;

    /*!
     * @brief
     * Indicates whether calendar system is
     * solar-based.
     *
     * @details
     * This constant specifies that the Gregorian
     * calendar system follows a solar model, where
     * date progression is based on the Earth's
     * orbit around the Sun.
     */
    static constexpr bool isSolarCalendar = true;

    /*!
     * @brief
     * Indicates whether calendar system is
     * lunar-based.
     *
     * @details
     * This constant specifies that the Gregorian
     * calendar system does not follow a lunar
     * model, which bases months on the phases of
     * the Moon.
     */
    static constexpr bool isLunarCalendar = false;

    /*!
     * @brief
     * Indicates whether calendar system is
     * lunisolar-based.
     *
     * @details
     * This constant specifies that the Gregorian
     * calendar system does not follow a lunisolar
     * model, which combines solar and lunar cycles
     * to structure months and years.
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
     * Abbreviated names of Gregorian calendar
     * months.
     */
    static constexpr inline const std::array<std::string_view, MONTHS_IN_YEAR>& MONTH_ABBREVS =
        MonthAbbrevs;

    /*!
     * @brief
     * Full names of Gregorian calendar
     * days-of-week.
     */
    static constexpr inline const std::array<const char*, DAYS_IN_WEEK>& DAY_OF_WEEK_NAMES =
        DaysOfWeek;

    /*!
     * @brief
     * Abbreviated names of Gregorian calendar
     * days-of-week.
     */
    static constexpr inline const std::array<std::string_view, DAYS_IN_WEEK>&
        DAY_OF_WEEK_ABBREVS = DayOfWeekAbbrevs;

    /*!
     * @brief
     * Evaluate support of year value.
     *
     * @details
     * This function returns true if the given year
     * falls within the inclusive bounds defined by
     * `YEAR_MINIMUM` and `YEAR_MAXIMUM` for the
     * Gregorian calendar system.
     *
     * @return
     * True if supported year value
     */
    [[nodiscard]] static constexpr bool isValidYear(const YearInt_t year) noexcept
    {
        return DatePolicy::isValidYear(year);
    }

    /*!
     * @brief
     * Determines whether a given year is a leap year.
     *
     * @details
     * This function checks if the specified year
     * qualifies as a leap year under Gregorian
     * calendar rules. A year is considered a leap
     * year if it is divisible by 4, except for
     * years divisible by 100 unless it is also
     * divisible by 400.
     *
     * @return
     * True if leap year
     */
    [[nodiscard]] static constexpr bool isLeapYear(const YearInt_t year) noexcept
    {
        return DatePolicy::isLeapYear(year);
    }

    /*!
     * @brief
     * Determines whether a date is within a leap
     * year.
     *
     * @return
     * True if leap year
     */
    [[nodiscard]] static constexpr bool isLeapYear(const Date date) noexcept
    {
        return DatePolicy::isLeapYear(date.year());
    }

    /*!
     * @brief
     * Returns total number of days in a given
     * calendar year.
     *
     * @details
     * Determines whether the specified year is a
     * leap year and returns `DAYS_IN_LEAP_YEAR` or
     * `DAYS_IN_YEAR` accordingly. If the year is
     * unsupported the function returns 0.
     *
     * @return
     * Total days in year
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const YearInt_t year) noexcept
    {
        if (!DatePolicy::isValidYear(year))
            return 0; // Unsupported year

        return DatePolicy::isLeapYear(year) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
    }

    /*!
     * @brief
     * Returns total number of days in a given
     * calendar year.
     *
     * @details
     * Extracts the year from the provided `Date`
     * to determine the total number of days in
     * the year.
     *
     * @return
     * Total days in year
     */
    [[nodiscard]] static constexpr uint16_t getDaysInYear(const Date date) noexcept
    {
        return DatePolicy::isLeapYear(date.year()) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
    }

    /*!
     * @brief
     * Checks if numerical month value is within
     * valid range.
     *
     * @details
     * This function returns true if the given
     * month falls within the inclusive bounds
     * defined by `MIN_MONTH_OF_YEAR` and
     * `MAX_MONTH_OF_YEAR` for the Gregorian
     * calendar system.
     *
     * @return
     * True if valid numerical month
     */
    [[nodiscard]] static constexpr bool isValidMonth(const uint8_t month) noexcept
    {
        return DatePolicy::isValidMonth(month);
    }

    /*!
     * @brief
     * Returns total number of days in a given
     * month of a specified year.
     *
     * @details
     * This function handles the varying lengths of
     * months in the Gregorian calendar, including
     * the special case of February during a leap
     * year. The function first validates the year
     * and month; if either is invalid, it returns 0
     * to indicate an unsupported or invalid date
     * component.
     *
     * @return
     * Total days in month
     */
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        return DatePolicy::getDaysInMonth(year, month);
    }

    /*!
     * @brief
     * Returns total number of days within month of
     * a given date.
     *
     * @details
     * Extracts the year and month from the provided
     * `Date` to determine the total number of days
     * in the dates month.
     *
     * @return
     * Total days in month
     */
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return DatePolicy::getDaysInMonth(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents)  // Month
        );
    }

    /*!
     * @brief
     * Checks if day value is within valid range.
     *
     * @details
     * This function returns true if the given day
     * falls within the inclusive bounds defined by
     * `MIN_DAY_OF_MONTH` and `MAX_DAY_OF_MONTH` for
     * the Gregorian calendar system.
     *
     * @return
     * True if valid day value
     */
    [[nodiscard]] inline static constexpr bool isValidDay(const uint8_t day) noexcept
    {
        return day >= MIN_DAY_OF_MONTH && day <= MAX_DAY_OF_MONTH;
    }

    /*!
     * @brief
     * Checks if week index is within valid range.
     *
     * @details
     * Checks whether the given week index represents
     * a valid calendar week, accounting for the fact
     * that weeks are aligned to calendar boundaries
     * rather than strictly contained within a single
     * year. A week index is considered valid if it
     * falls within the complete set of weeks that
     * contain days from the current year, which may
     * include partial weeks from adjacent years.
     * This accommodates cases where the first week
     * contains days from the previous December or
     * the last week contains days from the following
     * January.
     *
     * @return
     * True if valid calendar week index
     */
    [[nodiscard]] inline static constexpr bool isValidWeekIndex(const uint8_t week_index
    ) noexcept
    {
        return week_index <= WEEKS_IN_YEAR;
    }

    /*!
     * @brief
     * Checks if day-of-week index is within valid
     * range.
     *
     * @details
     * Accepts a zero-based day-of-week index
     * (0 = Sunday ... 6 = Saturday). Returns true
     * only if the index is less than `DAYS_IN_WEEK`.
     *
     * @return
     * True if valid day-of-week index
     */
    [[nodiscard]] inline static constexpr bool isValidDOWIndex(const uint8_t dow_index
    ) noexcept
    {
        return dow_index < DAYS_IN_WEEK;
    }

    /*!
     * @brief
     * Checks if given year, month, and day
     * combination form a valid calendar date.
     *
     * @details
     * This function returns true when the provided
     * date parameters describe a real date on the
     * Gregorian calendar. This is achieved by
     * comparing the dates day to the total number
     * of days in the month. If the provided year
     * is not supported, the function returns false.
     *
     * @return
     * True if date exists on calendar
     */
    [[nodiscard]] static constexpr bool isValidDate(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        return DatePolicy::isValidDate(year, month, day);
    }

    /*!
     * @brief
     * Calculates day-of-week index of provided
     * calendar date.
     *
     * @details
     * Implements Tomohiko Sakamoto's algorithm to
     * determine the day of the week for the
     * specified year, month, and day combination.
     * Returns a zero-based day-of-week index
     * (0 = Sunday ... 6 = Saturday), or
     * `INVALID_DOW_INDEX` if the provided date
     * does not exist on the calendar.
     *
     * @return
     * Day-of-week index
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        if (!DatePolicy::isValidDate(year, month, day))
            return INVALID_DOW_INDEX; // NOTE: This has to go...

        // CREDITS: Tomohiko Sakamoto
        // Day-of-week index algorithm
        year -= (month < March); // Extra days from leap year
                                 // only affect March and later
        const uint8_t monthIndex = month - 1;
        const int index =
            ((year + year / 4 - year / 100 + year / YEARS_IN_ERA +
              sakamoto::MONTH_KEY[monthIndex] + day) %
             DAYS_IN_WEEK);

        return static_cast<uint8_t>(index);
    }

    /*!
     * @brief
     * Calculates day-of-week index for a given
     * calendar date.
     *
     * @details
     * Extracts the year, month, and day from the
     * given `Date` instance to compute the
     * zero-based day-of-week index.
     *
     * @return
     * Day-of-week index
     */
    [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return getDayOfWeekIndex(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents), // Month
            std::get<2>(dateComponents)  // Day
        );
    }

    /*!
     * @brief
     * Number of full 7-day weeks contained in
     * specified month.
     *
     * @details
     * Calculates how many full seven-day calendar
     * weeks are in the provided month. Fractional
     * week information is truncated (*floor*) and
     * results are not dependent on current day of
     * the week. Returns 0 if the month is invalid
     * or if the provided year is unsupported.
     *
     * @return
     * Number of full 7-day weeks in month
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        const uint8_t monthTotalDays = DatePolicy::getDaysInMonth(year, month);

        if (monthTotalDays == 0)
            return 0; // Unsupported or invalid

        return static_cast<uint8_t>(monthTotalDays / DAYS_IN_WEEK);
        // NOTE: This is useless, instead make it number of whole weeks?
    }

    /*!
     * @brief
     * Number of full 7-day weeks contained in
     * specified month.
     *
     * @details
     * Extracts the year and month components from
     * the provided `Date` instance to calculate
     * how many full seven-day calendar weeks are
     * in the provided month. Fractional week
     * information is truncated.
     *
     * @return
     * Number of full 7-day weeks in month
     */
    [[nodiscard]] static constexpr uint8_t getWeeksInMonth(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return getWeeksInMonth(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents)  // Month
        );
    }

    /*!
     * @brief
     * Determines number of weeks a specified month
     * spans over the calendar.
     *
     * @details
     * Calculates how many full or partial weeks are
     * needed to contain all days of the specified
     * month in a standard calendar grid. The result
     * depends on the day of the week the month starts
     * on and the total number of days in the month.
     * Returns 0 if the month is invalid or if the
     * provided year is unsupported.
     *
     * @return
     * Number of weeks month spans
     */
    [[nodiscard]] static constexpr uint8_t getWeeksMonthSpans(
        const YearInt_t year, const uint8_t month
    ) noexcept
    {
        const uint8_t monthTotalDays = DatePolicy::getDaysInMonth(year, month);

        if (monthTotalDays == 0)
            return 0; // Unsupported or invalid

        const uint8_t firstOfMonthDowIndex = getDayOfWeekIndex(year, month, 1);
        const uint8_t monthCells           = firstOfMonthDowIndex + monthTotalDays;
        return (monthCells + 6) / DAYS_IN_WEEK;
    }

    /*!
     * @brief
     * Determines number of weeks a specified month
     * spans over the calendar.
     *
     * @details
     * Extracts year and month components from the
     * provided `Date` instance to calculates how
     * many full or partial weeks are needed to
     * contain all days of the specified month in
     * a standard calendar grid.
     *
     * @return
     * Number of weeks month spans
     */
    [[nodiscard]] static constexpr uint8_t getWeeksMonthSpans(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return getWeeksMonthSpans(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents)  // Month
        );
    }

    /*!
     * @brief
     * Determines zero-based index of week for a
     * specified date within its year.
     *
     * @details
     * This function calculates which week of the year
     * [0–52] the given Gregorian calendar date falls
     * into. Weeks are defined relative to Sundays,
     * with week 0 beginning on the first Sunday before
     * or on January 1 of the given year. The weeks are
     * calendar aligned. Consequently, the week index
     * can range from [0-52] (inclusive) because the
     * potential partial week(s) at the beginning and
     * end of the year are taken into account. The index
     * is obtained by computing the difference in days
     * between the target date and that first Sunday,
     * then dividing by the number of days in a week. If
     * the provided year, month, or day values do not
     * form a valid Gregorian date, the function returns
     * index 0 as a fallback.
     *
     * @return
     * Index of week within year [0 - 52]
     */
    [[nodiscard]] static constexpr uint8_t getWeekIndex(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        if (!DatePolicy::isValidDate(year, month, day))
            return 0; // NOTE: Unexpected behavior?

        const int8_t sundayDiff = SUNDAY - getDayOfWeekIndex(year, January, 1);
        const Days firstSunday{toDaysSinceEpoch(year, January, 1) + Days{sundayDiff}};
        const Days serialDate{toDaysSinceEpoch(year, month, day)};
        return static_cast<uint8_t>((serialDate - firstSunday).count() / DAYS_IN_WEEK);
    }

    /*!
     * @brief
     * Determines zero-based index of week for a
     * specified date within its year.
     *
     * @details
     * Extracts year, month, and day components from
     * the provided `Date` instance to calculate which
     * week of the year [0–52] the given Gregorian
     * calendar date falls into.
     *
     * @return
     * Index of week within year [0 - 52]
     */
    [[nodiscard]] static constexpr uint8_t getWeekIndex(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return getWeekIndex(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents), // Month
            std::get<2>(dateComponents)  // Day
        );
    }

    /*!
     * @brief
     * Converts a calendar date to serial number of
     * days since Unix epoch.
     *
     * @details
     * Uses Howard Hinnant’s civil date algorithm to
     * convert a year, month, day combination into a
     * signed day count relative to the Unix epoch
     * (1970-01-01 = day 0). The result can be
     * negative for dates before the epoch.
     *
     * @return
     * Days since January 1, 1970
     */
    [[nodiscard]] static constexpr Days toDaysSinceEpoch(
        YearInt_t year, uint8_t month, uint8_t day
    ) noexcept
    {
        if (!DatePolicy::isValidDate(year, month, day))
            return Days{0}; // Epoch date

        return Days{static_cast<Days::rep>(hinnant::toDaysSinceEpoch(year, month, day))};
    }

    /*!
     * @brief
     * Converts a calendar date to serial number of
     * days since Unix epoch.
     *
     * @details
     * Returns serial date count in explicit units of
     * precision (days) using the provided `Date`
     * instances `units()` function.
     *
     * @return
     * Days since January 1, 1970
     */
    [[nodiscard]] inline static constexpr Days toDaysSinceEpoch(const Date date) noexcept
    {
        return date.units();
    }

    /*!
     * @brief
     * Converts a serial count of days since Unix
     * epoch to a calendar date.
     *
     * @details
     * Uses Howard Hinnant’s civil date algorithm
     * to convert a signed day count relative to
     * the Unix epoch (1970-01-01 = day 0) into a
     * year, month, day combination. Returns a
     * `GregorianDate` representing the calculated
     * civil date.
     *
     * @return
     * Gregorian calendar date
     */
    [[nodiscard]] static constexpr Date fromDaysSinceEpoch(const Days serial_days) noexcept
    {
        DateTuple dateComponents = hinnant::fromDaysSinceEpoch(serial_days.count());

        return Date{
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents), // Month
            std::get<2>(dateComponents)  // Day
        };
    }

    /*!
     * @brief
     * Converts a calendar date to a Unix timestamp
     * (seconds since epoch).
     *
     * @details
     * Uses `toDaysSinceEpoch()` to calculate the
     * number of days since the Unix epoch
     * (1970-01-01) and multiplies by the number
     * of seconds in a day to obtain the equivalent
     * timestamp in seconds. The returned value is
     * stored in `stl::UnixTimestamp` and may be
     * negative for dates before the epoch.
     *
     * @return
     * Unix timestamp
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        return static_cast<stl::UnixTimestamp>(
            Seconds{toDaysSinceEpoch(year, month, day)}.count()
        );
    }

    /*!
     * @brief
     * Converts a calendar date to a Unix timestamp
     * (seconds since epoch).
     *
     * @details
     * Extracts year, month, and day components from
     * the provided `Date` instance to calculate the
     * number of days since the Unix epoch (1970-01-01).
     *
     * @return
     * Unix timestamp
     */
    [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(const Date date) noexcept
    {
        const DateTuple dateComponents = hinnant::fromDaysSinceEpoch(date.underlying());

        return toUnixTimestamp(
            std::get<0>(dateComponents), // Year
            std::get<1>(dateComponents), // Month
            std::get<2>(dateComponents)  // Day
        );
    }

    /*!
     * @brief
     * Converts a Unix timestamp (seconds since
     * epoch) to a calendar date.
     *
     * @details
     * Divides the given `stl::UnixTimestamp` by the
     * number of seconds in a day to convert seconds
     * to whole days since the Unix epoch (1970-01-01),
     * then calls `fromDaysSinceEpoch()` to obtain the
     * corresponding calendar date.
     *
     * @return
     * Gregorian calendar date
     */
    [[nodiscard]] static constexpr Date fromUnixTimestamp(const stl::UnixTimestamp& timestamp
    ) noexcept
    {
        return fromDaysSinceEpoch(Days{static_cast<Days::rep>(timestamp / SECONDS_IN_DAY)});
    }

    /*!
     * @brief
     * Converts a serial count of seconds to
     * a calendar date.
     *
     * @details
     * Converts the provided serial seconds count
     * timestamp to days, which is then interpreted
     * using Howard Hinnants algorithm.
     *
     * @return
     * Gregorian calendar date
     */
    [[nodiscard]] static constexpr Date fromUnixTimestamp(const Seconds serial_secs) noexcept
    {
        return fromDaysSinceEpoch(duration_cast<Days>(serial_secs));
    }

    /*!
     * @brief
     * Finds next weekday [Monday – Friday] after a
     * given date.
     *
     * @details
     * This function advances the provided `from_date`
     * to the next date that falls on a weekday
     * (Monday through Friday). If the current date is
     * Friday, the result is the following Monday
     * (skipping the weekend). If the current date is
     * Saturday or Sunday, the function advances to
     * the upcoming Monday. For all other weekdays
     * (Monday–Thursday), the result is simply the
     * next calendar day.
     *
     * @return
     * Next date between [Monday - Friday]
     */
    [[nodiscard]] static constexpr Date getNextWeekday(const Date from_date) noexcept
    {
        const DayOfWeek fromDow = static_cast<DayOfWeek>(getDayOfWeekIndex(from_date));

        switch (fromDow) {
        case FRIDAY:
            return from_date + Days{3};

        case SATURDAY:
            return from_date + Days{2};

        default: // SUNDAY - THURSDAY
            return from_date + Days{1};
        }
    }

    /*!
     * @brief
     * Finds most recent weekday [Monday – Friday]
     * before a given date.
     *
     * @details
     * This function rolls the provided `from_date`
     * back to the last date that falls on a weekday
     * (Monday through Friday). If the current date is
     * Monday, the result is the previous Friday. If
     * the current date is Sunday, the result is the
     * previous Friday as well. For all other days
     * (Tuesday through Saturday), the result is simply
     * the preceding calendar day, provided it falls
     * within the weekday range.
     *
     * @return
     * Last date between [Monday - Friday]
     */
    [[nodiscard]] static constexpr Date getLastWeekday(const Date from_date) noexcept
    {
        const DayOfWeek fromDow = static_cast<DayOfWeek>(getDayOfWeekIndex(from_date));

        switch (fromDow) {
        case SUNDAY:
            return from_date - Days{2};

        case MONDAY:
            return from_date - Days{3};

        default: // TUESDAY - SATURDAY
            return from_date - Days{1};
        }
    }

    /*!
     * @brief
     * Finds next Saturday following a provided date.
     *
     * @details
     * This function advances the provided `from_date`
     * to the next occurrence of Saturday in the
     * Gregorian calendar. If the given date already
     * falls on a Saturday, the function returns the
     * Saturday of the following week. For all other
     * days, the function computes the offset to the
     * upcoming Saturday and advances accordingly.
     *
     * @return
     * Next Saturday date
     */
    [[nodiscard]] static constexpr Date getNextWeekend(const Date from_date) noexcept
    {
        const uint8_t dowDiff = SATURDAY - getDayOfWeekIndex(from_date);

        if (dowDiff == 0)
            return from_date + Days{DAYS_IN_WEEK};

        return from_date + Days{dowDiff};
    }

    /*!
     * @brief
     * Finds last Saturday before provided date.
     *
     * @details
     * This function decreases the provided `from_date`
     * to the last occurrence of Saturday in the
     * Gregorian calendar. If the given date already
     * falls on a Saturday, the function returns the
     * Saturday of the prior week. For all other
     * days, the function computes the offset to the
     * previous Saturday and decreases accordingly.
     *
     * @return
     * Last Saturday date
     */
    [[nodiscard]] static constexpr Date getLastWeekend(const Date from_date) noexcept
    {
        const uint8_t dowDiff = SATURDAY - getDayOfWeekIndex(from_date);

        if (dowDiff == 0)
            return from_date - Days{DAYS_IN_WEEK};

        return from_date - Days{DAYS_IN_WEEK - dowDiff};
    }

    /*!
     * @brief
     * Finds all dates associated with provided week
     * within a year.
     *
     * @details
     * Gathers all 7 dates of a specified week within a
     * year into an array and returns the results.
     * Weeks are defined relative to Sundays, with week
     * 0 beginning on the first Sunday before or on
     * January 1 of the given year. The weeks are
     * calendar aligned. Consequently, a request for the
     * first and last week of a given year may result in
     * dates from the previous or next year. If the
     * provided year value is not supported or an invalid
     * week index is provided, the function returns an
     * array of epoch dates.
     *
     * @return
     * Array of calendar week dates
     */
    [[nodiscard]] static constexpr WeekDates getWeek(
        const YearInt_t year, const uint8_t week_index
    ) noexcept
    {
        WeekDates week{};

        if (!isValidWeekIndex(week_index) || !DatePolicy::isValidYear(year))
            return week; // Invalid week index or unsupported year

        const Days serialStart{
            toDaysSinceEpoch(year, January, 1) + Days{week_index * DAYS_IN_WEEK}
        };
        const DayOfWeek fromDow = static_cast<DayOfWeek>(getDayOfWeekIndex(year, January, 1));

        for (uint8_t dowIndex = SUNDAY; dowIndex < DAYS_IN_WEEK; dowIndex++) {
            const int8_t dowDiff = dowIndex - fromDow;
            week[dowIndex]       = fromDaysSinceEpoch(Days{serialStart + Days{dowDiff}});
        }

        return week;
    }

    /*!
     * @brief
     * Finds all dates associated with week containing
     * provided date.
     *
     * @details
     * Determines the full calendar week (Sunday through
     * Saturday) that the provided date falls within by
     * aligning to the date’s weekday and filling in
     * surrounding dates.
     *
     * @return
     * Array of calendar week dates
     */
    [[nodiscard]] static constexpr WeekDates getWeek(const Date date) noexcept
    {
        const Days serialStart{toDaysSinceEpoch(date)};
        const DayOfWeek fromDow = static_cast<DayOfWeek>(getDayOfWeekIndex(date));
        WeekDates week{};

        for (uint8_t dowIndex = SUNDAY; dowIndex < DAYS_IN_WEEK; dowIndex++) {
            const int8_t dowDiff = dowIndex - fromDow;
            week[dowIndex]       = fromDaysSinceEpoch(Days{serialStart + Days{dowDiff}});
        }

        return week;
    }

  private:
    GregorianCalendar()  = delete;
    ~GregorianCalendar() = delete;
};

SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_H_
