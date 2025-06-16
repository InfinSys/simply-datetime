
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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
     * Enumeration of broken-down calendar components.
     */
    enum CalendarComponent : uint8_t {
        SECOND, ///< Datetime second component
        MINUTE, ///< Datetime minute component
        HOUR,   ///< Datetime hour component
        DAY,    ///< Datetime day component
        MONTH,  ///< Datetime month component
        YEAR    ///< Datetime year component
    };

    /*!
     * @brief
     * Gregorian year integer type.
     *
     * @note
     * The underlying type used to represent Gregorian
     * calendar years imposes a limit on the range of
     * representable dates.
     */
    using YearInt_T = uint16_t;

    /*!
     * @brief
     * Array of Gregorian calendar month name literals.
     */
    const std::array<const char*, 12> Months = {
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
     * Array of Gregorian calendar day-of-week literals.
     */
    const std::array<const char*, 7> DaysOfWeek = {
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

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_CALENDAR_DEFINITIONS_H_
