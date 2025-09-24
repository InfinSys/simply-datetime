
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file helper_algorithms.hpp
 *
 * @brief
 * Gregorian calendar helper algorithms.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_HELPER_ALGORITHMS_H_
#define SIMPLYDT_LIB_GREGORIAN_HELPER_ALGORITHMS_H_

#include "simplydt/calendar/gregorian/gregorian_defs.hpp"
#include "simplydt/common/stl_chrono_defs.hpp"

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 */
namespace simplydt::gregorian::hinnant
{

/*!
 * @brief
 * Converts a calendar date to serial number
 * of days since Unix epoch.
 *
 * @details
 * Uses Howard Hinnant’s civil date algorithm
 * to convert a year, month, day combination
 * into a signed day count relative to the
 * Unix epoch (1970-01-01 = day 0). The result
 * can be negative for dates before the epoch.
 *
 * @return
 * Days since January 1, 1970
 */
[[nodiscard]] constexpr int32_t toDaysSinceEpoch(
    Year_Type year, uint8_t month, uint8_t day
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
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @return
 * Year era index
 */
[[nodiscard]] constexpr int eraFromSerialDays(int32_t serial_days) noexcept
{
    serial_days += 719'468;
    return (serial_days >= 0 ? serial_days : serial_days - 146'096) / 146'097;
}

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @return
 * Day offset from start of era
 */
[[nodiscard]] constexpr unsigned dayOfEraFromSerialDays(int32_t serial_days) noexcept
{
    const int era = eraFromSerialDays(serial_days);
    serial_days += 719'468;
    return static_cast<unsigned>(serial_days - era * 146'097);
}

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @return
 * Year offset in current era
 */
[[nodiscard]] constexpr unsigned yearOfEraFromSerialDays(int32_t serial_days) noexcept
{
    const unsigned doe = dayOfEraFromSerialDays(serial_days);
    return (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) / DAYS_IN_YEAR;
}

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @return
 * Day offset in current year
 */
[[nodiscard]] constexpr unsigned dayOfYearFromSerialDays(int32_t serial_days) noexcept
{
    const unsigned yoe = yearOfEraFromSerialDays(serial_days);
    return dayOfEraFromSerialDays(serial_days) - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
}

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 * 
 * @return
 * March-based month index
 */
[[nodiscard]] inline constexpr unsigned monthPrime(const unsigned dayOfYear) noexcept
{
    return (5 * dayOfYear + 2) / 153;
}

/*!
 * @brief
 * Converts a serial count of days since Unix
 * epoch to calendar date values.
 *
 * @details
 * Uses Howard Hinnant’s civil date algorithm
 * to convert a signed day count relative to
 * the Unix epoch (1970-01-01 = day 0) into a
 * year, month, day combination. Returns a
 * `DateTuple` representing the calculated
 * civil date in y-m-d order.
 *
 * @return
 * Calendar date values tuple
 */
[[nodiscard]] constexpr DateTuple fromDaysSinceEpoch(int32_t serial_days) noexcept
{
    // CREDITS: Howard Hinnant [Mr. Chrono] - (Ripple Labs)
    // Convert a serial count of days into a {year, month, day} triple.
    serial_days += 719'468;
    const int era      = (serial_days >= 0 ? serial_days : serial_days - 146'096) / 146'097;
    const unsigned doe = static_cast<unsigned>(serial_days - era * 146'097);
    const unsigned yoe = (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) / DAYS_IN_YEAR;
    const Year_Type y  = static_cast<Year_Type>(yoe) + era * YEARS_IN_ERA;
    const unsigned doy = doe - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
    const unsigned mp  = (5 * doy + 2) / 153;
    const uint8_t d    = static_cast<uint8_t>(doy - (153 * mp + 2) / 5 + 1);
    const uint8_t m    = static_cast<uint8_t>(mp + (mp < 10 ? 3 : -9));
    return DateTuple{y + (m <= February), m, d};
}

}

#endif // SIMPLYDT_LIB_GREGORIAN_HELPER_ALGORITHMS_H_
