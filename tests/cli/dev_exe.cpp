
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] Remove CRTP from time setup?
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
#include "simplydt/calendar/gregorian/gregorian_date.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using Date = simplydt::gregorian::GregorianDate;
    using Days = simplydt::Days;

    constexpr Date todayDate{2'025, 9, 1}; ///<---(The focus)
    constexpr Date pastDate{2'025, 8, 1};

    // GregorianDate constexpr tests:
    {
        constexpr bool eq  = todayDate == pastDate;
        constexpr bool lt  = todayDate < pastDate;
        constexpr bool gt  = todayDate > pastDate;
        constexpr bool lte = todayDate <= pastDate;
        constexpr bool gte = todayDate >= pastDate;

        constexpr Date pd    = todayDate + Days{7};
        constexpr Date md    = todayDate - Days{7};
        constexpr Days diff1 = todayDate - pastDate;
        constexpr Days diff2 = pastDate - todayDate;
        constexpr Date arith = pastDate + (todayDate - pastDate);

        constexpr bool zro    = todayDate.isZero();
        constexpr bool ftr    = todayDate.isAfter(pastDate);
        constexpr bool pst    = todayDate.isBefore(pastDate);
        constexpr bool btw    = todayDate.isBetween(pastDate, todayDate);
        constexpr Days ntl    = pastDate.daysUntil(todayDate);
        constexpr int32_t tck = todayDate.underlying();
    }

    // GregorianDate increment/decrement tests:
    {
        Date today = todayDate;
        Date next  = ++today;
        next       = today++;

        Date yesterday = todayDate - Days{1};
        Date last      = --yesterday;
        last           = yesterday--;

        next += Days{15};
        last -= Days{10};
    }

    //_SUSPEND_// const GregorianDate blizz =
    // GregorianCalendar::getDate(simplydt::stl::SystemClock::now());
    //_SUSPEND_// constexpr GregorianDate demo =
    //_SUSPEND_//     GregorianCalendar::getDate(2'025, simplydt::gregorian::AUGUST, 29);
    //_SUSPEND_// std::cout << "\nDemo date: " << demo << '\n';

    //_SUSPEND_// constexpr bool isValid                         =
    // GregorianCalendar::isValidDate(demo);
    //_SUSPEND_// constexpr uint8_t noWeeks                      =
    // GregorianCalendar::getWeeksInMonth(demo);
    //_SUSPEND_// constexpr const char* month                    =
    // GregorianCalendar::getMonthName(demo);
    //_SUSPEND_// constexpr simplydt::gregorian::Month monthRepr =
    // GregorianCalendar::getMonthEnumRepr(demo);
    //_SUSPEND_// constexpr const char* dowName                  =
    // GregorianCalendar::getDayOfWeekName(demo);
    //_SUSPEND_// constexpr std::string_view dowShort =
    //GregorianCalendar::getDayOfWeekAbbrev(demo); _SUSPEND_// constexpr bool isLeap =
    //GregorianCalendar::isLeapYear(demo); _SUSPEND_// constexpr uint16_t daysInYr         =
    //GregorianCalendar::getDaysInYear(demo); _SUSPEND_// constexpr
    //simplydt::gregorian::DayOfWeek dowRepr = _SUSPEND_//
    //GregorianCalendar::getDayOfWeekEnumRepr(demo); _SUSPEND_// constexpr UnixTimestamp
    //serialDays = GregorianCalendar::toDaysSinceEpoch(demo); _SUSPEND_// constexpr
    //GregorianDate fromSerial = GregorianCalendar::fromDaysSinceEpoch(0); _SUSPEND_//
    //constexpr UnixTimestamp tzz = _SUSPEND_//
    //GregorianCalendar::toUnixTimestamp(GregorianDate{2'004, 9, 17}); _SUSPEND_// constexpr
    //GregorianDate zzt = _SUSPEND_//     GregorianCalendar::fromUnixTimestamp(1'095'379'200);
    //// 2004-09-17T00:00:00.00 _SUSPEND_// const GregorianDate bzr = _SUSPEND_//
    //GregorianCalendar::fromTimePoint(std::chrono::system_clock::now(), false); _SUSPEND_//
    //std::cout << bzr << '\n';

    //_SUSPEND_// constexpr UTCTime dvq = UTCTime{14, 37, 48};
    //_SUSPEND_// constexpr UTCTime gbx = UTCTime{simplydt::Hours{23} + simplydt::Minutes{15}};
    //_SUSPEND_// // constexpr bool eqlTst = dvq == dvq;
    //_SUSPEND_// constexpr uint8_t hr                  = dvq.hour12();
    //_SUSPEND_// constexpr uint8_t min                 = dvq.minute();
    //_SUSPEND_// constexpr uint8_t sec                 = dvq.second();
    //_SUSPEND_// constexpr simplydt::MeridiemPhase mdx = dvq.hourPhaseEnumRepr();
    //_SUSPEND_// constexpr const char* mmq             = dvq.hourPhaseStr();
    //_SUSPEND_// std::cout << "UTC Time: " << dvq << '\n';
    //_SUSPEND_// constexpr simplydt::Seconds evv = dvq.toSerialSeconds();
    // constexpr GregorianDate next = GregorianCalendar::getNextDate(demo,
    // simplydt::gregorian::FRIDAY);
    //

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
