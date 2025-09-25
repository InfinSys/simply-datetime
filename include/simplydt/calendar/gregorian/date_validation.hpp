
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file date_validation.hpp
 *
 * @brief
 * Gregorian calendar date validation policy declaration.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_DATE_VALIDATION_POLICY_H_
#define SIMPLYDT_LIB_GREGORIAN_DATE_VALIDATION_POLICY_H_

#include "simplydt/calendar/gregorian/gregorian_defs.hpp"
#include <cstdint>

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar date validation policy.
 *
 * @details
 * This is the Gregorian calendar date validator, which is
 * responsible for determining if a given set of date params
 * describe a real date on the Gregorian calendar. This
 * structure serves no purpose beyond validating potential
 * Gregorian calendar dates and only maintains functions
 * necessarry for validation.
 */
struct DateValidationPolicy {
    /*!
     * @brief
     * Determines if provided year is a leap year.
     *
     * @details
     * This function checks if the specified year qualifies
     * as a leap year under Gregorian calendar rules. A year
     * is considered a leap year if it is divisible by 4,
     * except for years divisible by 100 unless it is also
     * divisible by 400.
     *
     * @return
     * True if leap year
     */
    [[nodiscard]] static constexpr bool isLeapYear(const Year_Type year) noexcept
    {
        return (year % 4) == 0 && (year % 100 != 0 || year % YEARS_IN_ERA == 0);
    }

    /*!
     * @brief
     * Evaluates support of year value.
     *
     * @details
     * This function returns true if the given year falls
     * within the inclusive bounds defined by `YEAR_MINIMUM`
     * and `YEAR_MAXIMUM` for the Gregorian calendar system.
     *
     * @return
     * True if supported year
     */
    [[nodiscard]] static constexpr bool isValidYear(const Year_Type year) noexcept
    {
        return year >= YEAR_MINIMUM && year <= YEAR_MAXIMUM;
    }

    /*!
     * @brief
     * Checks if a month value is within valid range.
     *
     * @details
     * This function returns true if the given month falls
     * within the inclusive bounds defined by
     * `MIN_MONTH_OF_YEAR` and `MAX_MONTH_OF_YEAR` for the
     * Gregorian calendar system.
     *
     * @return
     * True if valid numerical month
     */
    [[nodiscard]] static constexpr bool isValidMonth(const uint8_t month) noexcept
    {
        return month >= MIN_MONTH_OF_YEAR && month <= MAX_MONTH_OF_YEAR;
    }

    /*!
     * @brief
     * Calculates total number of days in a given month of
     * a specified year.
     *
     * @details
     * This function handles the varying lengths of months
     * in the Gregorian calendar, including the special
     * case of February during a leap year. The function
     * first validates the year and month; if either is
     * invalid, it returns 0 to indicate an unsupported or
     * invalid date value.
     *
     * @return
     * Total days in month
     */
    [[nodiscard]] static constexpr uint8_t getDaysInMonth(
        const Year_Type year, const uint8_t month
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
     * Checks if given date values form a valid Gregorian
     * date.
     *
     * @details
     * This function returns true when the provided date
     * parameters describe a real date on the Gregorian
     * calendar. This is achieved by comparing the dates
     * day to the total number of days in the month. If
     * the provided year is not supported, the function
     * returns false.
     *
     * @return
     * True if date exists on calendar
     */
    [[nodiscard]] static constexpr bool isValidDate(
        const Year_Type year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if (!isValidYear(year))
            return false;

        const uint8_t monthTotalDays = getDaysInMonth(year, month);
        return day <= monthTotalDays;
    }
};

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_DATE_VALIDATION_POLICY_H_
