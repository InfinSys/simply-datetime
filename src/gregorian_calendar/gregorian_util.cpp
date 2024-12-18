
#include"simplydt/gregorian_calendar/gregorian_util.hpp"


//  SimplyDt::GregorianCalendar::Util : FREE

bool SimplyDt::GregorianCalendar::Util::isLeapYear(const uint16_t& year) noexcept
{
	return ((year % (uint16_t)4) == 0 && (year % (uint16_t)100 != 0 || year % (uint16_t)400 == 0));
}

uint8_t SimplyDt::GregorianCalendar::Util::getMonthTotalDays(const uint16_t& year, const uint8_t& month) noexcept
{

    /*****************************************************************************\
    *             vvv           AI GENERATED CODE BELOW           vvv             *
    \*****************************************************************************/

    if (month < (uint8_t)1 || month > (uint8_t)12)
        return 0;

    switch (month) {
    // February
    case (uint8_t)2:
        switch (isLeapYear(year)) {
        case true:
            return (uint8_t)29;    // Leap year

        default:
            return (uint8_t)28;    // Non-leap year
        }

    // April, June, September and November
    case (uint8_t)4:
    case (uint8_t)6:
    case (uint8_t)9:
    case (uint8_t)11:
        return (uint8_t)30;

    // January, March, May, July, August, October and December
    default:
        return (uint8_t)31;
    }

    /*****************************************************************************\
    *             ^^^           AI GENERATED CODE ABOVE           ^^^             *
    \*****************************************************************************/
    
}

uint16_t SimplyDt::GregorianCalendar::Util::getYearTotalDays(const uint16_t& year) noexcept
{
    uint16_t totalDays{ 0 };

    for (uint8_t month{ 1 }; month <= (uint8_t)12; ++month)
        totalDays += getMonthTotalDays(year, month);

    return totalDays;
}

uint8_t SimplyDt::GregorianCalendar::Util::getMonthIndex(const uint8_t& month) noexcept
{
    if (month >= (uint8_t)1 && month <= (uint8_t)12)
        return month - (uint8_t)1;
    
    return 0;
}

const char* SimplyDt::GregorianCalendar::Util::getMonth(const uint8_t& month) noexcept
{
    if (month == 0 || month > (uint8_t)12)
        return nullptr;

    return SimplyDt::GregorianCalendar::Months[getMonthIndex(month)];
}
