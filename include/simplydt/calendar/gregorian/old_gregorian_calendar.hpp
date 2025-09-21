
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

//_-_// namespace simplydt::gregorian
//_-_// {
//_-_//
//_-_// /*!
//_-_//  * @brief
//_-_//  * Gregorian calendar system.
//_-_//  */
//_-_// struct GregorianCalendar final :
//_-_//     public CalendricalSystem<GregorianCalendar, GregorianDate, Month, DayOfWeek> {
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Identifies the calendar system represented by this
//_-_//      * implementation.
//_-_//      */
//_-_//     static constexpr CalendarSystem calendar = CalendarSystem::GREGORIAN;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Indicates whether the calendar system is solar-based.
//_-_//      *
//_-_//      * @details
//_-_//      * This constant specifies that the Gregorian calendar system
//_-_//      * follows a solar model, where date progression is based on
//_-_//      * the Earth's orbit around the Sun.
//_-_//      */
//_-_//     static constexpr bool isSolarCalendar = true;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Indicates whether the calendar system is lunar-based.
//_-_//      *
//_-_//      * @details
//_-_//      * This constant specifies that the Gregorian calendar system
//_-_//      * does not follow a lunar model, which bases months on the
//_-_//      * phases of the Moon.
//_-_//      */
//_-_//     static constexpr bool isLunarCalendar = false;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Indicates whether the calendar system is lunisolar-based.
//_-_//      *
//_-_//      * @details
//_-_//      * This constant specifies that the Gregorian calendar system
//_-_//      * does not follow a lunisolar model, which combines solar
//_-_//      * and lunar cycles to structure months and years.
//_-_//      */
//_-_//     static constexpr bool isLunisolarCalendar = false;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Full names of Gregorian calendar months.
//_-_//      */
//_-_//     static constexpr inline const std::array<const char*, MONTHS_IN_YEAR>& MONTH_NAMES
//=
//_-_//         Months;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Abbreviated names of Gregorian calendar months.
//_-_//      */
//_-_//     static constexpr inline const std::array<std::string_view, MONTHS_IN_YEAR>&
// MONTH_ABBREVS =
//_-_//         MonthAbbrevs;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Full names of Gregorian calendar days-of-week.
//_-_//      */
//_-_//     static constexpr inline const std::array<const char*, DAYS_IN_WEEK>&
// DAY_OF_WEEK_NAMES =
//_-_//         DaysOfWeek;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Abbreviated names of Gregorian calendar days-of-week.
//_-_//      */
//_-_//     static constexpr inline const std::array<std::string_view, DAYS_IN_WEEK>&
//_-_//         DAY_OF_WEEK_ABBREVS = DayOfWeekAbbrevs;
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Evaluate support of year value.
//_-_//      *
//_-_//      * @details
//_-_//      * This function returns true if the given year falls within
//_-_//      * the inclusive bounds defined by `YEAR_MINIMUM` and
//_-_//      * `YEAR_MAXIMUM` for the Gregorian calendar system.
//_-_//      *
//_-_//      * @return
//_-_//      * True if supported year value
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidYear(const YearInt_t year) noexcept
//_-_//     {
//_-_//         return year >= YEAR_MINIMUM && year <= YEAR_MAXIMUM;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Determines whether a given year is a leap year.
//_-_//      *
//_-_//      * @details
//_-_//      * This function checks if the specified year qualifies as a
//_-_//      * leap year under Gregorian calendar rules. A year is
//_-_//      * considered a leap year if it is divisible by 4, except for
//_-_//      * years divisible by 100 unless it is also divisible by 400.
//_-_//      *
//_-_//      * @return
//_-_//      * True if provided year is a leap year
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isLeapYear(const YearInt_t year) noexcept
//_-_//     {
//_-_//         return (year % 4) == 0 && (year % 100 != 0 || year % YEARS_IN_ERA == 0);
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Determines whether a given date is within a leap year.
//_-_//      *
//_-_//      * @return
//_-_//      * True if provided date is within a leap year
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isLeapYear(const Date& date) noexcept
//_-_//     {
//_-_//         return isLeapYear(date.year());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Returns total number of days in a given calendar year.
//_-_//      *
//_-_//      * @details
//_-_//      * Determines whether the specified year is a leap year and
//_-_//      * returns `DAYS_IN_LEAP_YEAR` or `DAYS_IN_YEAR` accordingly.
//_-_//      * If the year is unsupported the function returns 0.
//_-_//      *
//_-_//      * @return
//_-_//      * Total days in year
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint16_t getDaysInYear(const YearInt_t year)
// noexcept
//_-_//     {
//_-_//         if (!isValidYear(year))
//_-_//             return 0; // Unsupported year
//_-_//
//_-_//         return isLeapYear(year) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Returns total number of days in the year of a given date.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the year from the provided `Date` to determine
//_-_//      * the total number of days in the year.
//_-_//      *
//_-_//      * @return
//_-_//      * Total days in year
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint16_t getDaysInYear(const Date date) noexcept
//_-_//     {
//_-_//         return getDaysInYear(date.year());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Checks if a month value is within valid range.
//_-_//      *
//_-_//      * @details
//_-_//      * This function returns true if the given month falls within
//_-_//      * the inclusive bounds defined by `MIN_MONTH_OF_YEAR` and
//_-_//      * `MAX_MONTH_OF_YEAR` for the Gregorian calendar system.
//_-_//      *
//_-_//      * @return
//_-_//      * True if valid numerical month value
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidMonth(const uint8_t month) noexcept
//_-_//     {
//_-_//         return month >= MIN_MONTH_OF_YEAR && month <= MAX_MONTH_OF_YEAR;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Returns total number of days in a given month of a
//_-_//      * specified year.
//_-_//      *
//_-_//      * @details
//_-_//      * This function handles the varying lengths of months in
//_-_//      * the Gregorian calendar, including the special case of
//_-_//      * February during a leap year. The function first validates
//_-_//      * the year and month; if either is invalid, it returns 0 to
//_-_//      * indicate an unsupported or invalid date component.
//_-_//      *
//_-_//      * @return
//_-_//      * Total days in month
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getDaysInMonth(
//_-_//         const YearInt_t year, const uint8_t month
//_-_//     ) noexcept
//_-_//     {
//_-_//         if (!isValidYear(year) || !isValidMonth(month))
//_-_//             return 0; // Unsupported or invalid
//_-_//
//_-_//         switch (month) {
//_-_//         case February:
//_-_//             switch (isLeapYear(year)) {
//_-_//             case true:
//_-_//                 return 29;
//_-_//             default:
//_-_//                 return 28;
//_-_//             }
//_-_//
//_-_//         case April:
//_-_//         case June:
//_-_//         case September:
//_-_//         case November:
//_-_//             return 30;
//_-_//
//_-_//         // January, March, May, July, August, October, December
//_-_//         default:
//_-_//             return 31;
//_-_//         }
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Returns total number of days in the month of a specified
//_-_//      * date.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the year and month from the provided `Date` to
//_-_//      * determine the total number of days in the dates month.
//_-_//      *
//_-_//      * @return
//_-_//      * Total days in month
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getDaysInMonth(const Date date) noexcept
//_-_//     {
//_-_//         return getDaysInMonth(date.year(), date.month());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Checks if a day value is within valid range.
//_-_//      *
//_-_//      * @details
//_-_//      * This function returns true if the given day falls within
//_-_//      * the inclusive bounds defined by `MIN_DAY_OF_MONTH` and
//_-_//      * `MAX_DAY_OF_MONTH` for the Gregorian calendar system.
//_-_//      *
//_-_//      * @return
//_-_//      * True if valid day value
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidDay(const uint8_t day) noexcept
//_-_//     {
//_-_//         return day >= MIN_DAY_OF_MONTH && day <= MAX_DAY_OF_MONTH;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Checks if a given year, month, and day combination form
//_-_//      * a valid calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * This function returns true when the provided date parameters
//_-_//      * describe a real date on the Gregorian calendar. This is
//_-_//      * achieved by comparing the dates day to the total number
//_-_//      * of days in the month. If the provided year is not supported,
//_-_//      * the function returns false.
//_-_//      *
//_-_//      * @return
//_-_//      * True if date exists on calendar
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidDate(
//_-_//         const YearInt_t year, const uint8_t month, const uint8_t day
//_-_//     ) noexcept
//_-_//     {
//_-_//         if (!isValidYear(year))
//_-_//             return false;
//_-_//
//_-_//         const uint8_t monthTotalDays = getDaysInMonth(year, month);
//_-_//         return day <= monthTotalDays;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Checks if a given date is a valid calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts components from the provided `Date` to determine
//_-_//      * validity of the date.
//_-_//      *
//_-_//      * @return
//_-_//      * True if date exists on calendar
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidDate(const Date date) noexcept
//_-_//     {
//_-_//         return isValidDate(date.year(), date.month(), date.day());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Checks if a day-of-week index is within valid range.
//_-_//      *
//_-_//      * @details
//_-_//      * Accepts a zero-based day-of-week index
//_-_//      * (0 = Sunday ... 6 = Saturday). Returns true only if the
//_-_//      * index is less than `DAYS_IN_WEEK`.
//_-_//      *
//_-_//      * @return
//_-_//      * True if valid day-of-week index
//_-_//      */
//_-_//     [[nodiscard]] static constexpr bool isValidDOWIndex(const uint8_t dow) noexcept
//_-_//     {
//_-_//         return dow < DAYS_IN_WEEK;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Calculates day-of-week index for a given calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * Implements Tomohiko Sakamoto's algorithm to determine
//_-_//      * the day of the week for the specified year, month, and
//_-_//      * day combination. Returns a zero-based day-of-week index
//_-_//      * (0 = Sunday ... 6 = Saturday), or `INVALID_DOW_INDEX`
//_-_//      * if the provided date does not exist on the calendar.
//_-_//      *
//_-_//      * @return
//_-_//      * Day-of-week index
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(
//_-_//         YearInt_t year, uint8_t month, uint8_t day
//_-_//     ) noexcept
//_-_//     {
//_-_//         if (!isValidDate(year, month, day))
//_-_//             return INVALID_DOW_INDEX;
//_-_//
//_-_//         // CREDITS: Tomohiko Sakamoto
//_-_//         // Day-of-week index algorithm
//_-_//         year -= (month < March); // Extra days from leap year
//_-_//                                  // only affect March and later
//_-_//         const uint8_t monthIndex = month - 1;
//_-_//         const int index =
//_-_//             ((year + year / 4 - year / 100 + year / YEARS_IN_ERA +
//_-_//               sakamoto::MONTH_KEY[monthIndex] + day) %
//_-_//              DAYS_IN_WEEK);
//_-_//
//_-_//         if (index >= DAYS_IN_WEEK)
//_-_//             return INVALID_DOW_INDEX;
//_-_//
//_-_//         return static_cast<uint8_t>(index);
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Calculates day-of-week index for a given calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the year, month, and day from the given `Date`
//_-_//      * instance to compute the zero-based day-of-week index.
//_-_//      *
//_-_//      * @return
//_-_//      * Day-of-week index
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getDayOfWeekIndex(const Date date) noexcept
//_-_//     {
//_-_//         return getDayOfWeekIndex(date.year(), date.month(), date.day());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Determines number of weeks a specified month spans
//_-_//      * over the calendar.
//_-_//      *
//_-_//      * @details
//_-_//      * Calculates how many full or partial weeks are needed to
//_-_//      * contain all days of the specified month in a standard
//_-_//      * calendar grid. The result depends on the day of the week
//_-_//      * the month starts on and the total number of days in the
//_-_//      * month. Returns 0 if the month is invalid or if the
//_-_//      * provided year is unsupported.
//_-_//      *
//_-_//      * @return
//_-_//      * Number of weeks month spans
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getWeeksInMonth(
//_-_//         const YearInt_t year, const uint8_t month
//_-_//     ) noexcept
//_-_//     {
//_-_//         const uint8_t monthTotalDays = getDaysInMonth(year, month);
//_-_//
//_-_//         if (monthTotalDays == 0)
//_-_//             return 0; // Unsupported or invalid
//_-_//
//_-_//         const uint8_t firstOfMonthDowIndex = getDayOfWeekIndex(year, month, 1);
//_-_//         const uint8_t monthCells           = firstOfMonthDowIndex + monthTotalDays;
//_-_//         return (monthCells + 6) / DAYS_IN_WEEK;
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Determines number of weeks a calendar dates month
//_-_//      * spans over the calendar.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the year and month from the provided `Date`
//_-_//      * instance to calculate the number of weeks a month
//_-_//      * spans over the calendar.
//_-_//      *
//_-_//      * @return
//_-_//      * Number of weeks month spans
//_-_//      */
//_-_//     [[nodiscard]] static constexpr uint8_t getWeeksInMonth(const Date date) noexcept
//_-_//     {
//_-_//         return getWeeksInMonth(date.year(), date.month());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a calendar date to serial number of days since
//_-_//      * Unix epoch.
//_-_//      *
//_-_//      * @details
//_-_//      * Uses Howard Hinnant’s civil date algorithm to convert
//_-_//      * a year, month, day combination into a signed day count
//_-_//      * relative to the Unix epoch (1970-01-01 = day 0). The
//_-_//      * result can be negative for dates before the epoch.
//_-_//      *
//_-_//      * @return
//_-_//      * Days since January 1, 1970
//_-_//      */
//_-_//     [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(
//_-_//         YearInt_t year, uint8_t month, uint8_t day
//_-_//     ) noexcept
//_-_//     {
//_-_//         // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
//_-_//         // Convert {year, month, day} triple into a serial count of days.
//_-_//         year -= month <= February;
//_-_//         const int era      = year / YEARS_IN_ERA;
//_-_//         const unsigned yoe = static_cast<unsigned>(year - era * YEARS_IN_ERA);
//_-_//         const unsigned doy = (153 * (month + (month > February ? -3 : 9)) + 2) / 5 +
// day - 1;
//_-_//         const unsigned doe = yoe * DAYS_IN_YEAR + yoe / 4 - yoe / 100 + doy;
//_-_//         return static_cast<int32_t>(era * 146'097 + static_cast<long>(doe) - 719'468);
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a calendar date to serial number of days since
//_-_//      * Unix epoch.
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the date components from the provided `Date`
//_-_//      * instance to calculate a signed day count relative to
//_-_//      * the Unix epoch (1970-01-01 = day 0). The result can be
//_-_//      * negative for dates before the epoch.
//_-_//      *
//_-_//      * @return
//_-_//      * Days since January 1, 1970
//_-_//      */
//_-_//     [[nodiscard]] static constexpr int32_t toDaysSinceEpoch(const Date date) noexcept
//_-_//     {
//_-_//         return toDaysSinceEpoch(date.year(), date.month(), date.day());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a serial count of days since Unix epoch to
//_-_//      * a calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * Uses Howard Hinnant’s civil date algorithm to convert
//_-_//      * a signed day count relative to the Unix epoch
//_-_//      * (1970-01-01 = day 0) into a year, month, day combination.
//_-_//      * Returns a `GregorianDate` representing the calculated
//_-_//      * civil date.
//_-_//      *
//_-_//      * @return
//_-_//      * Gregorian calendar date
//_-_//      */
//_-_//     [[nodiscard]] static constexpr Date fromDaysSinceEpoch(int32_t serial_days)
// noexcept
//_-_//     {
//_-_//         // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
//_-_//         // Convert a serial count of days into a {year, month, day} triple.
//_-_//         serial_days += 719'468;
//_-_//         const int era = (serial_days >= 0 ? serial_days : serial_days - 146'096) /
// 146'097;
//_-_//         const unsigned doe = static_cast<unsigned>(serial_days - era * 146'097);
//_-_//         const unsigned yoe = (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) /
// DAYS_IN_YEAR;
//_-_//         const YearInt_t y  = static_cast<YearInt_t>(yoe) + era * YEARS_IN_ERA;
//_-_//         const unsigned doy = doe - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
//_-_//         const unsigned mp  = (5 * doy + 2) / 153;
//_-_//         const uint8_t d    = static_cast<uint8_t>(doy - (153 * mp + 2) / 5 + 1);
//_-_//         const uint8_t m    = static_cast<uint8_t>(mp + (mp < 10 ? 3 : -9));
//_-_//         return Date{static_cast<YearInt_t>(y + (m <= 2)), m, d};
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a calendar date to a Unix timestamp (seconds
//_-_//      * since epoch).
//_-_//      *
//_-_//      * @details
//_-_//      * Uses `toDaysSinceEpoch()` to calculate the number of
//_-_//      * days since the Unix epoch (1970-01-01) and multiplies
//_-_//      * by the number of seconds in a day to obtain the
//_-_//      * equivalent timestamp in seconds. The returned value
//_-_//      * is stored in `stl::UnixTimestamp` and may be negative
//_-_//      * for dates before the epoch.
//_-_//      *
//_-_//      * @return
//_-_//      * Unix timestamp
//_-_//      */
//_-_//     [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(
//_-_//         const YearInt_t year, const uint8_t month, const uint8_t day
//_-_//     ) noexcept
//_-_//     {
//_-_//         return static_cast<stl::UnixTimestamp>(toDaysSinceEpoch(year, month, day) *
// 86'400);
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a calendar date to a Unix timestamp (seconds
//_-_//      * since epoch).
//_-_//      *
//_-_//      * @details
//_-_//      * Extracts the date components from the provided `Date`
//_-_//      * instance to calculate the corresponding Unix timestamp.
//_-_//      * The returned value is stored in `stl::UnixTimestamp`
//_-_//      * and may be negative for dates before the epoch.
//_-_//      *
//_-_//      * @return
//_-_//      * Unix timestamp
//_-_//      */
//_-_//     [[nodiscard]] static constexpr stl::UnixTimestamp toUnixTimestamp(const Date date)
// noexcept
//_-_//     {
//_-_//         return toUnixTimestamp(date.year(), date.month(), date.day());
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a Unix timestamp (seconds since epoch) to a
//_-_//      * calendar date.
//_-_//      *
//_-_//      * @details
//_-_//      * Divides the given `stl::UnixTimestamp` by the number
//_-_//      * of seconds in a day to convert seconds to whole days
//_-_//      * since the Unix epoch (1970-01-01), then calls
//_-_//      * `fromDaysSinceEpoch()` to obtain the corresponding
//_-_//      * calendar date.
//_-_//      *
//_-_//      * @return
//_-_//      * Gregorian calendar date
//_-_//      */
//_-_//     [[nodiscard]] static constexpr Date fromUnixTimestamp(const stl::UnixTimestamp&
// timestamp
//_-_//     ) noexcept
//_-_//     {
//_-_//         return fromDaysSinceEpoch(static_cast<int32_t>(timestamp / 86'400));
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a system clock time point to a local calendar
//_-_//      * date.
//_-_//      *
//_-_//      * @details
//_-_//      * Interprets the given `stl::SystemTimePoint` as local
//_-_//      * time by converting it to a Unix timestamp and then
//_-_//      * populating a `std::tm` structure via
//_-_//      * `stl::deriveLocalDateTimeFromTimestamp()`. The
//_-_//      * resulting year, month, and day fields are used to
//_-_//      * construct and return a `GregorianDate`. If the local
//_-_//      * date conversion fails a default constructed Gregorian
//_-_//      * date is returned.
//_-_//      *
//_-_//      * @return
//_-_//      * Gregorian calendar date
//_-_//      */
//_-_//     [[nodiscard]] static Date fromTimePoint(const stl::SystemTimePoint& time_point)
// noexcept
//_-_//     {
//_-_//         const stl::UnixTimestamp secsSinceEpoch =
// stl::SystemClock::to_time_t(time_point);
//_-_//         stl::CalendarDateTime dateBuffer{};
//_-_//
//_-_//         if (!stl::deriveLocalDateTimeFromTimestamp(&secsSinceEpoch, &dateBuffer))
//_-_//             return Date{}; // Failed to interpret local date
//_-_//
//_-_//         return Date{
//_-_//             static_cast<YearInt_t>(
//_-_//                 dateBuffer.tm_year + 1'900
//_-_//             ), // tm_year measures years since 1900
//_-_//             static_cast<uint8_t>(
//_-_//                 dateBuffer.tm_mon + 1
//_-_//             ), // tm_mon measures months since January
//_-_//             static_cast<uint8_t>(dateBuffer.tm_mday)
//_-_//         };
//_-_//     }
//_-_//
//_-_//     /*!
//_-_//      * @brief
//_-_//      * Converts a system clock time point to a local calendar
//_-_//      * date.
//_-_//      *
//_-_//      * @details
//_-_//      * If `local` is true (time-zone), interprets the given
//_-_//      * `stl::SystemTimePoint` as local time. If `local` is false
//_-_//      * (no time-zone), interprets the time point as UTC. If the
//_-_//      * local date conversion fails a default constructed Gregorian
//_-_//      * date is returned.
//_-_//      *
//_-_//      * @return
//_-_//      * Gregorian calendar date
//_-_//      */
//_-_//     [[nodiscard]] static Date fromTimePoint(
//_-_//         const stl::SystemTimePoint& time_point, const bool local
//_-_//     ) noexcept
//_-_//     {
//_-_//         if (local)
//_-_//             return fromTimePoint(time_point);
//_-_//
//_-_//         const stl::UnixTimestamp secsSinceEpoch =
// stl::SystemClock::to_time_t(time_point);
//_-_//         return fromUnixTimestamp(secsSinceEpoch);
//_-_//     }
//_-_//
//_-_//   private:
//_-_//     GregorianCalendar()  = delete;
//_-_//     ~GregorianCalendar() = delete;
//_-_// };
//_-_//
//_-_// SIMPLYDT_ENFORCE_CALENDAR_CONTRACT(GregorianCalendar);
//_-_//
//_-_// } // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_STRUCT_H_
