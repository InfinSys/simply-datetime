
#ifndef SIMPLYDTLIB_GREGORIAN_CALENDAR_UTIL_H_
#define SIMPLYDTLIB_GREGORIAN_CALENDAR_UTIL_H_



#include<array>
#include<string>
#include"simplydt/common/julian_date_system/jdn_util.hpp"


/* Standard civil calendar system */
namespace GregorianCalendar {

	/* Julian Day Number (JDN) */
	using JDN = JulianDateSystem::JDN;

	/* Gregorian calendar date */
	typedef struct _GREGORIAN_DATE_STRUCT {
		const uint16_t year;
		const uint8_t month;
		const uint8_t day;
	} GregorianDate;

	/* Gregorian date formats */
	enum DateFormat {
		RECORD,// Record format (01-01-1970)
		STANDARD,// Standard format (01/01/1970)
	};

	/* Gregorian date string layouts */
	enum DateLayout {
		M_D_YYYY,// (mm/dd/YYYY) [ Example: 01-13-2024 ]
		M_D_YY,// (mm/dd/YY) [ Example: 01-13-24 ]
		M_YYYY,// (mm/YYYY) [ Example: 01-2024 ]
		M_YY,// (mm/YY) [ Example: 01-24 ]
		M_D,// (mm/dd) [ Example: 01-13 ]
		YYYY_M_D,// (YYYY/mm/dd) [ Example: 2024-01-13 ]
		YY_M_D,// (YY/mm/dd) [ Example: 24-01-13 ]
		YYYY_D_M,// (YYYY/dd/mm) [ Example: 2024-13-01 ]
		YY_D_M,// (YY/dd/mm) [ Example: 24-13-01 ]
		YYYY_M,// (YYYY/mm) [ Example: 2024-01 ]
		YY_M,// (YY/mm) [ Example: 24-01 ]
		D_M,// (dd/mm) [ Example: 13-01 ]
	};


	/* Month labels */
	const std::array<const char*, 12> Months{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	/* Day of week labels */
	const std::array<const char*, 7> DaysOfWeek{
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};


	/* Returns integer as a double digit string */
	std::string toDoubleDigitStr(const uint16_t& integer) noexcept;

	/* Returns true if provided year is a leap year */
	bool isLeapYear(const uint16_t& year) noexcept;

	/* Returns total number of days in provided year-month combination */
	uint8_t getTotalDaysInMonth(const uint16_t& year, const uint8_t& month) noexcept;

	/* Returns total number of days in provided year-month combination */
	uint8_t getTotalDaysInMonth(const GregorianDate& date) noexcept;

	/* Returns total number of days in provided year */
	uint16_t getTotalDaysInYear(const uint16_t& year) noexcept;

	/* Returns day of week index of provided date */
	uint8_t getDayOfWeekIndex(uint16_t year, uint8_t month, uint8_t day) noexcept;

	/* Returns day of week index of provided date */
	uint8_t getDayOfWeekIndex(const GregorianDate& date) noexcept;

	/* Returns day of week literal from provided date */
	const char* getDayOfWeek(const uint16_t& year, const uint8_t& month, const uint8_t& day) noexcept;

	/* Returns day of week literal from provided date */
	const char* getDayOfWeek(const GregorianDate& date) noexcept;

	/* Returns month index of provided month */
	uint8_t getMonthIndex(const uint8_t& month) noexcept;

	/* Returns month literal from provided month */
	const char* getMonthTitle(const uint8_t& month) noexcept;

	/* Evaluate Gregorian date from JDN */
	GregorianDate interpretJDNDate(const JDN& jdn) noexcept;

	/* Evaluate Gregorian year from JDN */
	uint16_t interpretJDNYear(const JDN& jdn) noexcept;

	/* Evaluate Gregorian month from JDN */
	uint8_t interpretJDNMonth(const JDN& jdn) noexcept;

	/* Evaluate Gregorian day from JDN */
	uint8_t interpretJDNDay(const JDN& jdn) noexcept;

	/* Returnsd gregorian date string in provided format */
	std::string toDateStr(const GregorianDate& date, DateFormat format, DateLayout layout) noexcept;

	/* Returns true if provided d2 date occurs before d1 date */
	bool isBefore(const GregorianDate& d1, const GregorianDate& d2) noexcept;

	/* Returns true if provided d2 date occurs after d1 date */
	bool isAfter(const GregorianDate& d1, const GregorianDate& d2) noexcept;

	/* Returns true if provided dates reference same time point */
	bool isEqual(const GregorianDate& d1, const GregorianDate& d2) noexcept;

}



#endif // SIMPLYDTLIB_GREGORIAN_CALENDAR_UTIL_H_
