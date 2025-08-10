
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_date.hpp
 *
 * @brief
 * Gregorian calendar date declaration.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
#define SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_

#include "simplydt/calendar/date/abstract_date.hpp"
#include "simplydt/calendar/concepts/date_contract.hpp"
#include "simplydt/calendar/gregorian/gregorian_defs.hpp"

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar date.
 *
 * @details
 * This type serves as a broken-down form of
 * Gregorian calendar dates and has no calendar
 * knowledge. This type does not validate the
 * date values provided to the constructor beyond
 * disregarding nonsensical values. Such values
 * are the kind that could obviously never be a
 * date (i.e, 2023-04-32, 2023-15-11, etc).
 * Consequently, a well-constructed `GregorianDate`
 * does not automatically imply that date exists on
 * the real-world calendar. The calendar can verify
 * the validity of the date held by this type.
 */
struct GregorianDate : public CalendarDate<GregorianDate, Year_Type> {
	/*! @brief Underlying date representation type. */
	using Repr_Type = uint32_t;

	/*! @brief Factor used to store and retrieve year values. */
	static constexpr Repr_Type YEAR_FACTOR = 10'000;

	/*! @brief Factor used to store and retrieve month values. */
	static constexpr Repr_Type MONTH_FACTOR = 100;

	/*! @brief Default Gregorian calendar date. */
	static constexpr Repr_Type DEFAULT_DATE = ((1'970 * YEAR_FACTOR) + 101);

	/*!
	* @brief
	* Encoded Gregorian calendar date to integer.
	* 
	* @return
	* Gregorian calendar date as integer
	*/
	static constexpr Repr_Type encodeGregorianDateToInteger(
		const YearInt_t year, const uint8_t month, const uint8_t day
	) noexcept
	{
		if ((month < MIN_MONTH_OF_YEAR) || (month > MAX_MONTH_OF_YEAR) || (day < MIN_DAY_OF_MONTH) || (day > MAX_DAY_OF_MONTH))
			return 0; // Invalid date params

		return ((year * YEAR_FACTOR) + (month * MONTH_FACTOR) + day);
	}

	/*!
	* @brief
	* Retrieve year component from encoded Gregorian
	* date integer.
	* 
	* @return
	* Gregorian date year component
	*/
	static constexpr YearInt_t extractEncodedYear(const Repr_Type& encoded_date) noexcept;

	/*!
	* @brief
	* Retrieve month component from encoded Gregorian
	* date integer.
	* 
	* @return
	* Gregorian date month component
	*/
	static constexpr uint8_t extractEncodedMonth(const Repr_Type& encoded_date) noexcept;

	/*!
	* @brief
	* Retrieve day component from encoded Gregorian
	* date integer.
	* 
	* @return
	* Gregorian date day component
	*/
	static constexpr uint8_t extractEncodedDay(const Repr_Type& encoded_date) noexcept;

	GregorianDate() noexcept : CalendarDate<GregorianDate, Year_Type>{ },
		date{ DEFAULT_DATE }
	{
		//
	}

	~GregorianDate() = default;

private:
	Repr_Type date; ///< Calendar date
};

// SIMPLYDT_ASSERT_DATE_INTERFACE_CONTRACT(GregorianDate);

}

#endif // SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
