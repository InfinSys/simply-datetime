
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
 * Algorithms from Howard Hinnant.
 *
 * @note
 * https://howardhinnant.github.io/date_algorithms.html
 * for more details.
 */
namespace simplydt::gregorian::hinnant
{

/*!
 * @brief
 * Days from 1970-01-01 to 0000-03-01.
 *
 * @details
 * This value shifts the epoch from 1970-01-01
 * to 0000-03-01 (March 1 of year 0) when
 * converting to civil date components or
 * vice-versa when calculating a serial count
 * of days since the Unix epoch. This is crucial
 * because it aligns the algorithm with all known
 * implementations of `std::chrono::system_clock`,
 * which count seconds from 1970-01-01, neglecting
 * leap seconds. This value is what makes the
 * serial date 0 equivalent to 1970-01-01 instead
 * of 0000-03-01.
 */
constexpr int32_t EPOCH_SHIFT = 719'468;

/*!
 * @brief
 * Total number of days in one Gregorian era.
 *
 * @details
 * Represents the number of days in a 400-year
 * Gregorian cycle. The patterns of the Gregorian
 * calendar repeat themselves over an era,
 * consequently the number of days in a single era
 * are the same for all others. This value is
 * calculated by multiplying the number of days in
 * a year by the number of years in one era, which
 * is then increased by an additional 97 days to
 * account for leap days within the era.
 */
constexpr uint32_t DAYS_IN_ERA = YEARS_IN_ERA * DAYS_IN_YEAR + 97;

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
    return static_cast<int32_t>(era * DAYS_IN_ERA + static_cast<long>(doe) - EPOCH_SHIFT);
}

/*!
 * @brief
 * Calculates 400-year era index from serial
 * number of days.
 *
 * @details
 * Adjusts the input day count by the epoch
 * shift to align with the March-based year
 * system used in the algorithm. Then
 * computes which 400-year Gregorian cycle
 * (era) the date falls within. The
 * calculation handles negative day counts
 * (dates before the algorithm's epoch) by
 * subtracting one less than a full era to
 * ensure proper era boundary crossing.
 *
 * @return
 * Year era index
 */
[[nodiscard]] constexpr int eraFromSerialDays(int32_t serial_days) noexcept
{
    serial_days += EPOCH_SHIFT;
    return (serial_days >= 0 ? serial_days : serial_days - 146'096) / DAYS_IN_ERA;
}

/*!
 * @brief
 * Calculates index of day within current
 * 400-year era.
 *
 * @details
 * First determines which 400-year era contains
 * the specified date using `eraFromSerialDays()`,
 * then calculates the relative day position
 * within that era. The result represents the
 * number of days elapsed since the start of the
 * era (March 1st of the era's first year) to
 * the specified date. The result can range from
 * [0 - 146,096] inclusive.
 *
 * @return
 * Day offset within current era [0 - 146,096]
 */
[[nodiscard]] constexpr unsigned dayOfEraFromSerialDays(int32_t serial_days) noexcept
{
    const int era = eraFromSerialDays(serial_days);
    serial_days += EPOCH_SHIFT;
    return static_cast<unsigned>(serial_days - era * DAYS_IN_ERA);
}

/*!
 * @brief
 * Calculates year index within current 400-year
 * era.
 *
 * @details
 * Uses the day-of-era value to compute the year
 * index within the 400-year Gregorian cycle. The
 * calculation accounts for leap year patterns by
 * subtracting/excluding partial periods. These
 * complex adjustment handles the irregular leap
 * year distribution across centuries. The result
 * can range from [0 - 399] inclusive.
 *
 * @return
 * Year offset within current era [0 - 399]
 */
[[nodiscard]] constexpr unsigned yearOfEraFromSerialDays(int32_t serial_days) noexcept
{
    const unsigned doe = dayOfEraFromSerialDays(serial_days);
    return (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) / DAYS_IN_YEAR;
}

/*!
 * @brief
 * Calculates day index within current year.
 *
 * @details
 * Computes the number of days that have elapsed
 * since the start of the current year. First
 * determines the year offset within the era,
 * then subtracts the cumulative days from the
 * beginning of the era up to the start of the
 * current year. The calculation accounts for
 * leap years by including the appropriate
 * number of leap days accumulated up to the
 * current year within the era. The result can
 * range from [0 - 365] inclusive.
 *
 * @return
 * Day offset within current year [0 - 365]
 */
[[nodiscard]] constexpr unsigned dayOfYearFromSerialDays(int32_t serial_days) noexcept
{
    const unsigned yoe = yearOfEraFromSerialDays(serial_days);
    return dayOfEraFromSerialDays(serial_days) - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
}

/*!
 * @brief
 * Calculates month index within a March-based
 * year system.
 *
 * @details
 * Uses integer arithmetic to convert a day of
 * year value into a month index where the year
 * starts in March. This March-based numbering
 * system simplifies leap day handling since
 * February becomes the last month of the year
 * (March = 0, April = 1, ..., February = 11).
 * The formula employs a linear approximation
 * that distributes days across months using
 * fixed-point mathematics for efficient
 * computation without branching.
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
    serial_days += EPOCH_SHIFT;
    const int era = (serial_days >= 0 ? serial_days : serial_days - 146'096) / DAYS_IN_ERA;
    const unsigned doe = static_cast<unsigned>(serial_days - era * DAYS_IN_ERA);
    const unsigned yoe = (doe - doe / 1'460 + doe / 36'524 - doe / 146'096) / DAYS_IN_YEAR;
    const Year_Type y  = static_cast<Year_Type>(yoe) + era * YEARS_IN_ERA;
    const unsigned doy = doe - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100);
    const unsigned mp  = (5 * doy + 2) / 153;
    const uint8_t d    = static_cast<uint8_t>(doy - (153 * mp + 2) / 5 + 1);
    const uint8_t m    = static_cast<uint8_t>(mp + (mp < 10 ? 3 : -9));
    return DateTuple{y + (m <= February), m, d};
}

} // namespace simplydt::gregorian::hinnant

#endif // SIMPLYDT_LIB_GREGORIAN_HELPER_ALGORITHMS_H_
