
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_defs.hpp
 *
 * @brief
 * Gregorian calendar system definitions.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_CALENDAR_DEFINITIONS_H_
#define SIMPLYDT_LIB_GREGORIAN_CALENDAR_DEFINITIONS_H_

#include <array>
#include <cstdint>
#include <string_view>

/*!
 * @namespace simplydt::gregorian
 *
 * @brief
 * Standard civil calendar system.
 */
namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian year integer type.
 *
 * @note
 * The underlying type used to represent Gregorian
 * calendar years imposes a limit on the range of
 * representable dates.
 */
using Year_Type = uint16_t;

/*!
 * @brief
 * Minimum supported year value.
 *
 * @details
 * This is the minimum supported year for the
 * Gregorian calendar in Simply Datetime.
 * This limit was choosen because it aligns with
 * Microsoft's FILETIME structure which measures
 * 100-nanosecond intervals since January 1, 1601.
 * This allows compatibility with Windows NT
 * systems and historical time point capabilities.
 */
constexpr Year_Type YEAR_MINIMUM = 1'601;

/*!
 * @brief
 * Maximum supported year value.
 *
 * @details
 * This is the maximum supported year value for the
 * Gregorian calendar in Simply Datetime.
 */
constexpr Year_Type YEAR_MAXIMUM = 2'038; // TODO: Find real limitation...

/*!
 * @brief
 * Abbreviation length for Gregorian calendar name
 * literals.
 *
 * @details
 * Details length of abbreviated Gregorian calendar
 * day-of-week and month names.
 */
constexpr int ABBREV_LENGTH = 3;

/*!
 * @brief
 * Minimum day of Gregorian month.
 */
constexpr uint8_t MIN_DAY_OF_MONTH = 1;

/*!
 * @brief
 * Maximum day of Gregorian month.
 */
constexpr uint8_t MAX_DAY_OF_MONTH = 31;

/*!
 * @brief
 * Minimum month of Gregorian year.
 */
constexpr uint8_t MIN_MONTH_OF_YEAR = 1;

/*!
 * @brief
 * Maximum month of Gregorian year.
 */
constexpr uint8_t MAX_MONTH_OF_YEAR = 12;

/*!
 * @brief
 * Total number of days in one calendar week.
 */
constexpr uint8_t DAYS_IN_WEEK = 7;

/*!
 * @brief
 * Total number of months in one calendar year.
 */
constexpr uint8_t MONTHS_IN_YEAR = 12;

/*!
 * @brief
 * Enumeration of Gregorian calendar months.
 */
enum Month : uint8_t {
    JANUARY,   ///< January (1)
    FEBRUARY,  ///< February (2)
    MARCH,     ///< March (3)
    APRIL,     ///< April (4)
    MAY,       ///< May (5)
    JUNE,      ///< June (6)
    JULY,      ///< July (7)
    AUGUST,    ///< August (8)
    SEPTEMBER, ///< September (9)
    OCTOBER,   ///< October (10)
    NOVEMBER,  ///< November (11)
    DECEMBER   ///< December (12)
};

/*!
 * @brief
 * Enumeration of Gregorian calendar days of week.
 */
enum DayOfWeek : uint8_t {
    SUNDAY,    ///< Sunday
    MONDAY,    ///< Monday
    TUESDAY,   ///< Tuesday
    WEDNESDAY, ///< Wednesday
    THURSDAY,  ///< Thursday
    FRIDAY,    ///< Friday
    SATURDAY   ///< Saturday
};

/*!
 * @brief
 * Array of Gregorian calendar month name literals.
 */
inline constexpr std::array<const char*, MONTHS_IN_YEAR> Months = {
    "January",   ///< Index 0
    "February",  ///< Index 1
    "March",     ///< Index 2
    "April",     ///< Index 3
    "May",       ///< Index 4
    "June",      ///< Index 5
    "July",      ///< Index 6
    "August",    ///< Index 7
    "September", ///< Index 8
    "October",   ///< Index 9
    "November",  ///< Index 10
    "December"   ///< Index 11
};

/*!
 * @brief
 * Array of abbreviated Gregorian calendar month
 * names.
 */
inline constexpr std::array<std::string_view, MONTHS_IN_YEAR> MonthAbbrevs = {
    std::string_view(Months[JANUARY], ABBREV_LENGTH),   ///< Jan
    std::string_view(Months[FEBRUARY], ABBREV_LENGTH),  ///< Feb
    std::string_view(Months[MARCH], ABBREV_LENGTH),     ///< Mar
    std::string_view(Months[APRIL], ABBREV_LENGTH),     ///< Apr
    std::string_view(Months[MAY], ABBREV_LENGTH),       ///< May
    std::string_view(Months[JUNE], ABBREV_LENGTH),      ///< Jun
    std::string_view(Months[JULY], ABBREV_LENGTH),      ///< Jul
    std::string_view(Months[AUGUST], ABBREV_LENGTH),    ///< Aug
    std::string_view(Months[SEPTEMBER], ABBREV_LENGTH), ///< Sep
    std::string_view(Months[OCTOBER], ABBREV_LENGTH),   ///< Oct
    std::string_view(Months[NOVEMBER], ABBREV_LENGTH),  ///< Nov
    std::string_view(Months[DECEMBER], ABBREV_LENGTH)   ///< Dec
};

/*!
 * @brief
 * Array of Gregorian calendar day-of-week literals.
 */
inline constexpr std::array<const char*, DAYS_IN_WEEK> DaysOfWeek = {
    "Sunday",    ///< Index 0
    "Monday",    ///< Index 1
    "Tuesday",   ///< Index 2
    "Wednesday", ///< Index 3
    "Thursday",  ///< Index 4
    "Friday",    ///< Index 5
    "Saturday"   ///< Index 6
};

/*!
 * @brief
 * Array of abbreviated Gregorian calendar day-of-week
 * literals.
 */
inline constexpr std::array<std::string_view, DAYS_IN_WEEK> DayOfWeekAbbrevs = {
    std::string_view(DaysOfWeek[SUNDAY], ABBREV_LENGTH),    ///< Sun
    std::string_view(DaysOfWeek[MONDAY], ABBREV_LENGTH),    ///< Mon
    std::string_view(DaysOfWeek[TUESDAY], ABBREV_LENGTH),   ///< Tue
    std::string_view(DaysOfWeek[WEDNESDAY], ABBREV_LENGTH), ///< Wed
    std::string_view(DaysOfWeek[THURSDAY], ABBREV_LENGTH),  ///< Thu
    std::string_view(DaysOfWeek[FRIDAY], ABBREV_LENGTH),    ///< Fri
    std::string_view(DaysOfWeek[SATURDAY], ABBREV_LENGTH)   ///< Sat
};

/*!
 * @brief
 * Invalid date day-of-week index.
 *
 * @details
 * Used to signal invalid dates that seek a day-of-week
 * index.
 */
constexpr uint8_t INVALID_DOW_INDEX = 255;

} // namespace simplydt::gregorian

/*!
 * @brief
 * Tomohiko Sakamoto's Algorithm.
 *
 * @details
 * Algorithm for computing day-of-week indecies of
 * Gregorian calendar dates by Tomohiko Sakamoto.
 */
namespace simplydt::sakamoto
{

/*!
 * @brief
 * Month key table for Tomohiko Sakamoto's algorithm.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
static constexpr uint8_t MONTH_KEY[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

} // namespace simplydt::sakamoto

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_DEFINITIONS_H_
