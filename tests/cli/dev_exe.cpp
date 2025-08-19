
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] :: Datetime Output Styles ::
* -> [] StandardStyle ----> 2004-09-17:00:00:00.000
* -> [] UnixStyle --------> 2004-09-17T00:00:00.000
* -> [] CivilStyle -------> 2004-09-17 00:00:00
* -> [] ...
*
*
* -> [] :: GregorianCalendar Static Methods ::
* -> [] static constexpr uint8_t getWeeksInMonth()  <------(Returns whole weeks in month)
* -> [] static constexpr uint8_t getWeeksMonthSpans()  <---(Returns weeks spanned by month)
*
*
* -> [] :: Common Time Definitions ::
* -> [] using ExTime_t = uint64_t;
* -> [] constexpr ExTime_t EX_TIME_MAX = NANOSECS_IN_DAY - 1;
*
*
* -> [] :: Library Compile-Time Utilities ::
* -> [] template struct ArgParams<...>;  <---(Holds argument parameter types)
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

// Includes...
#include "simplydt/calendar/gregorian/gregorian_calendar.hpp"
#include "simplydt/time/utc/utc_time.hpp"
#include "simplydt/common/time_defs.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using GregorianDate     = simplydt::gregorian::GregorianDate;
    using GregorianCalendar = simplydt::gregorian::GregorianCalendar;
    using Month             = simplydt::gregorian::Month;
    using UnixTimestamp     = simplydt::stl::UnixTimestamp;
    using UTCTime           = simplydt::utc::UTCTime;

    constexpr GregorianDate demo{2'025, 8, 15};
    std::cout << "\nDemo date: " << demo << '\n';

    constexpr bool isValid                         = GregorianCalendar::isValidDate(demo);
    constexpr uint8_t noWeeks                      = GregorianCalendar::getWeeksInMonth(demo);
    constexpr const char* month                    = GregorianCalendar::getMonthName(demo);
    constexpr simplydt::gregorian::Month monthRepr = GregorianCalendar::getMonthEnumRepr(demo);
    constexpr const char* dowName                  = GregorianCalendar::getDayOfWeekName(demo);
    constexpr bool isLeap                          = GregorianCalendar::isLeapYear(demo);
    constexpr uint16_t daysInYr                    = GregorianCalendar::getDaysInYear(demo);
    constexpr simplydt::gregorian::DayOfWeek dowRepr =
        GregorianCalendar::getDayOfWeekEnumRepr(demo);
    constexpr UnixTimestamp serialDays = GregorianCalendar::toDaysSinceEpoch(demo);
    constexpr GregorianDate fromSerial = GregorianCalendar::fromDaysSinceEpoch(0);
    constexpr UnixTimestamp tzz =
        GregorianCalendar::toUnixTimestamp(GregorianDate{2'004, 9, 17});
    constexpr GregorianDate zzt =
        GregorianCalendar::fromUnixTimestamp(1'095'379'200); // 2004-09-17T00:00:00.00
    const GregorianDate bzr =
        GregorianCalendar::fromTimePoint(std::chrono::system_clock::now(), false);
    std::cout << bzr << '\n';

    constexpr UTCTime dvq = UTCTime{14, 37, 48};
    constexpr UTCTime gbx = UTCTime{simplydt::Hours{23} + simplydt::Minutes{15}};
    // constexpr bool eqlTst = dvq == dvq;
    constexpr uint8_t hr                  = dvq.hour12();
    constexpr uint8_t min                 = dvq.minute();
    constexpr uint8_t sec                 = dvq.second();
    constexpr simplydt::MeridiemPhase mdx = dvq.hourPhaseEnumRepr();
    constexpr const char* mmq             = dvq.hourPhaseStr();
    std::cout << "UTC Time: " << dvq << '\n';

    constexpr simplydt::Seconds evv = simplydt::Minutes{1} + simplydt::Seconds{14};
    //

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
