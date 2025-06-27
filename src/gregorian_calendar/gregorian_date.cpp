
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

#include "simplydt/gregorian_calendar/gregorian_date.hpp"

//	simplydt::gregorian::Date : CONSTRUCTOR

simplydt::gregorian::Date::Date(
    const YearInt_T year, const uint8_t month, const uint8_t day
) noexcept
    : date{ DEFAULT_DATE }
{
    Date::encodeGregorianDateIntoInteger(&this->date, year, month, day);
}

simplydt::gregorian::Date::Date(const YearInt_T year, const uint8_t month) noexcept
    : date{ DEFAULT_DATE }
{
    Date::encodeGregorianDateIntoInteger(&this->date, year, month, 1);
}

simplydt::gregorian::Date::Date(const Date& date) noexcept : date{ DEFAULT_DATE }
{
    this->date = date.date;
}

simplydt::gregorian::Date::Date() noexcept : date{ DEFAULT_DATE }
{
    //
}

//	simplydt::gregorian::Date : CONSTRUCTOR END!


//	simplydt::gregorian::Date : STATIC

bool simplydt::gregorian::Date::encodeGregorianDateIntoInteger(
    Underlying_T* integer, const YearInt_T& year, const uint8_t& month, const uint8_t& day
) noexcept
{
    if (integer == nullptr)
        return false;

    if ((month < MIN_MONTH_OF_YEAR) || (month > MAX_MONTH_OF_YEAR))
        return false; // Invalid date params

    if ((day < MIN_DAY_OF_MONTH) || (day > MAX_DAY_OF_MONTH))
        return false; // Invalid date params

    *integer = ((year * YEAR_FACTOR) + (month * MONTH_FACTOR) + day);

    return true;
}

simplydt::gregorian::YearInt_T simplydt::gregorian::Date::extractEncodedYear(
    const Underlying_T* date
) noexcept
{
    return static_cast<YearInt_T>(*date / YEAR_FACTOR);
}

uint8_t simplydt::gregorian::Date::extractEncodedMonth(const Underlying_T* date) noexcept
{
    return static_cast<uint8_t>((*date % YEAR_FACTOR) / MONTH_FACTOR);
}

uint8_t simplydt::gregorian::Date::extractEncodedDay(const Underlying_T* date) noexcept
{
    return static_cast<uint8_t>((*date % YEAR_FACTOR) % MONTH_FACTOR);
}

//	simplydt::gregorian::Date : STATIC END!


//	simplydt::gregorian::Date : OPERATOR

bool simplydt::gregorian::Date::operator==(const Date date) const noexcept
{
    return this->date == date.date;
}

bool simplydt::gregorian::Date::operator<(const Date date) const noexcept
{
    return this->date < date.date;
}

bool simplydt::gregorian::Date::operator>(const Date date) const noexcept
{
    return this->date > date.date;
}

bool simplydt::gregorian::Date::operator<=(const Date date) const noexcept
{
    return this->date <= date.date;
}

bool simplydt::gregorian::Date::operator>=(const Date date) const noexcept
{
    return this->date >= date.date;
}

uint16_t simplydt::gregorian::Date::operator[](const CalendarComponent component
) const noexcept
{
    return this->getComponent(component);
}

//	simplydt::gregorian::Date : OPERATOR END!


//	simplydt::gregorian::Date : PUBLIC

simplydt::gregorian::YearInt_T simplydt::gregorian::Date::year() const noexcept
{
    return Date::extractEncodedYear(&this->date);
}

uint8_t simplydt::gregorian::Date::month() const noexcept
{
    return Date::extractEncodedMonth(&this->date);
}

std::string simplydt::gregorian::Date::monthLiteral() const noexcept
{
    const uint8_t monthIndex = this->month() - 1;

    return Months[monthIndex];
}

std::string simplydt::gregorian::Date::monthAbbreviation() const noexcept
{
    const uint8_t monthIndex = this->month() - 1;

    return std::string{ MonthAbbrevs[monthIndex] };
}

uint8_t simplydt::gregorian::Date::day() const noexcept
{
    return Date::extractEncodedDay(&this->date);
}

uint16_t simplydt::gregorian::Date::getComponent(const CalendarComponent component
) const noexcept
{
    switch (component) {
    case CalendarComponent::YEAR:
        return Date::extractEncodedYear(&this->date);

    case CalendarComponent::MONTH:
        return Date::extractEncodedMonth(&this->date);

    case CalendarComponent::DAY:
        return Date::extractEncodedDay(&this->date);

    default:
        return 0; // Invalid component
    }
}

std::string simplydt::gregorian::Date::toStr() const noexcept
{
    const char delimiter = '-';

    std::string dateStr;
    dateStr.reserve(12);

    dateStr += (std::to_string(this->year()) + delimiter);
    dateStr += (toDoubleDigitStr(this->month()) + delimiter);
    dateStr += toDoubleDigitStr(this->day());

    return dateStr;
}

//	simplydt::gregorian::Date : PUBLIC END!


//	simplydt::gregorian::Date : PROTECTED
//	simplydt::gregorian::Date : PROTECTED END!


//	simplydt::gregorian::Date : PRIVATE
//	simplydt::gregorian::Date : PRIVATE END!
