
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] :: Simply Datetime Units ::
* -> [] using Days = int32_t
* -> [] using Hours = int32_t
* -> [] ...
*
* -> [] (Need a base class to compose int32_t)
* -> [] (Present common functionality amongst units)
* -> [] (Units interact with date/time types)
* -> [] (Units can automatically convert from one another)
*
*
* -> [] :: Month Vars ::
* -> [] constexpr uint8_t January = 1
* -> [] constexpr uint8_t February = 2
* -> [] constexpr uint8_t March = 3
* -> [] ...
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

// Includes...
#include "simplydt/calendar/gregorian/gregorian_calendar.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using GregorianDate     = simplydt::gregorian::GregorianDate;
    using GregorianCalendar = simplydt::gregorian::GregorianCalendar;
    using Month             = simplydt::gregorian::Month;
    using UnixTimestamp     = simplydt::stl::UnixTimestamp;

    constexpr GregorianDate demo{2'025, 8, 15};
    std::cout << "\nDemo date: " << demo << '\n';

    constexpr bool isValid                         = GregorianCalendar::isValidDate(demo);
    constexpr uint8_t noWeeks                      = GregorianCalendar::getWeeksInMonth(demo);
    constexpr const char* month                    = GregorianCalendar::getMonthName(demo);
    constexpr simplydt::gregorian::Month monthRepr = GregorianCalendar::getMonthEnumRepr(demo);
    constexpr const char* dowName                  = GregorianCalendar::getDayOfWeekName(demo);
    constexpr simplydt::gregorian::DayOfWeek dowRepr =
        GregorianCalendar::getDayOfWeekEnumRepr(demo);
    constexpr UnixTimestamp serialDays = GregorianCalendar::toDaysSinceEpoch(demo);
    constexpr GregorianDate fromSerial = GregorianCalendar::fromDaysSinceEpoch(0);
    constexpr UnixTimestamp tzz =
        GregorianCalendar::toUnixTimestamp(GregorianDate{2'004, 9, 17});
    constexpr GregorianDate zzt =
        GregorianCalendar::fromUnixTimestamp(1'095'379'200); // 2004-09-17T00:00:00.00
    const GregorianDate bzr = GregorianCalendar::fromTimePoint(std::chrono::system_clock::now(), false);
    std::cout << bzr << '\n';
    // int32_t toDaysSinceEpoch()
    // Date fromDaysSinceEpoch()
    //

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
