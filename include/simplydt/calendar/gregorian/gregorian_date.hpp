
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

#include "simplydt/calendar/date/abstract_date.hpp"
#include "simplydt/calendar/gregorian/date_validation.hpp"
#include "simplydt/calendar/gregorian/gregorian_defs.hpp"
#include "simplydt/calendar/gregorian/helper_algorithms.hpp"

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
            return 0; // Serial epoch
        
        return toDaysSinceEpoch(year, month, day);
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

    ~GregorianDate() = default;
};

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_SERIAL_GREGORIAN_CALENDAR_DATE_H_
