
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_date.hpp
 *
 * @brief
 * Gregorian calendar date declaration.
 */


#ifndef SIMPLYDT_LIB_SERIAL_GREGORIAN_CALENDAR_DATE_H_
#define SIMPLYDT_LIB_SERIAL_GREGORIAN_CALENDAR_DATE_H_

#include "simplydt/calendar/concepts/date_api_contract.hpp"
#include "simplydt/calendar/date/abstract_date.hpp"
#include "simplydt/calendar/gregorian/date_validation.hpp"
#include "simplydt/calendar/gregorian/gregorian_defs.hpp"
#include "simplydt/calendar/gregorian/helper_algorithms.hpp"
#include "simplydt/common/string_utils.hpp"

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar date.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
struct GregorianDate :
    public SerialCalendarDate<GregorianDate, DateValidationPolicy, int32_t, Year_Type> {
    /*! @brief Epoch date in serial days. */
    static constexpr Repr_Type SERIAL_EPOCH = 0;

    /*!
     * @brief
     * Intercepts invalid date constructor values.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Provided date in serial days if valid, epoch
     * otherwise
     */
    static constexpr Repr_Type useDefaultIfInvalid(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if (!ValidationPolicy::isValidDate(year, month, day))
            return SERIAL_EPOCH;

        return hinnant::toDaysSinceEpoch(year, month, day);
    }

    /*!
     * @brief
     * Construct Gregorian calendar date using year,
     * month, and day values.
     */
    constexpr GregorianDate(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
        : SerialCalendarDate<GregorianDate, DateValidationPolicy, int32_t, Year_Type>{
              useDefaultIfInvalid(year, month, day)
          }
    { }

    /*!
     * @brief
     * Construct default Gregorian calendar date
     * (epoch date).
     */
    constexpr GregorianDate() noexcept
        : SerialCalendarDate<GregorianDate, DateValidationPolicy, int32_t, Year_Type>{
              SERIAL_EPOCH
          }
    { }

    ~GregorianDate() = default;

    /*!
     * @brief
     * Date year component.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Year of Gregorian calendar date
     */
    [[nodiscard]] constexpr YearInt_t year() const noexcept
    {
        const int era = hinnant::eraFromSerialDays(this->serialDays);
        const unsigned yoe = hinnant::yearOfEraFromSerialDays(this->serialDays);
        const unsigned doy = (
            hinnant::dayOfEraFromSerialDays(this->serialDays)
            - (DAYS_IN_YEAR * yoe + yoe / 4 - yoe / 100)
        );
        const unsigned mp = hinnant::monthPrime(doy);
        return static_cast<YearInt_t>(era * YEARS_IN_ERA + yoe + (mp >= 10));
    }

    /*!
     * @brief
     * Date month component.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Month of Gregorian calendar date
     */
    [[nodiscard]] constexpr uint8_t month() const noexcept
    {
        const unsigned doy = hinnant::dayOfYearFromSerialDays(this->serialDays);
        const unsigned mp  = hinnant::monthPrime(doy);
        return static_cast<uint8_t>(mp + (mp < 10 ? 3 : -9));
    }

    /*!
     * @brief
     * Date day component.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Day of Gregorian calendar date
     */
    [[nodiscard]] constexpr uint8_t day() const noexcept
    {
        const unsigned doy = hinnant::dayOfYearFromSerialDays(this->serialDays);
        const unsigned mp  = hinnant::monthPrime(doy);
        return static_cast<uint8_t>(doy - (153 * mp + 2) / 5 + 1);
    }

    /*!
     * @brief
     * Compose string representation of Gregorian
     * calendar date.
     *
     * @return
     * Gregorian calendar date as string
     */
    [[nodiscard]] std::string toStr() const noexcept
    {
        const char delimiter = '-';
        std::string dateStr;
        dateStr.reserve(12);
        const DateTuple dateValues = hinnant::fromDaysSinceEpoch(this->serialDays);
        dateStr += (std::to_string(std::get<0>(dateValues)) + delimiter);
        dateStr += (toDoubleDigitStr(std::get<1>(dateValues)) + delimiter);
        dateStr += toDoubleDigitStr(std::get<2>(dateValues));
        return dateStr;
    }
};

SIMPLYDT_ENFORCE_DATE_CONTRACT(GregorianDate);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_SERIAL_GREGORIAN_CALENDAR_DATE_H_
