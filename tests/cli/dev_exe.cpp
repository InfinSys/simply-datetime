
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
* -> [] :: Common Time Definitions ::
* -> [] using ExTime_t = uint64_t;
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

// Includes...
#include "simplydt/calendar/gregorian/gregorian_date.hpp"
#include "simplydt/time/utc/utc_time.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using Date    = simplydt::gregorian::GregorianDate;
    using Time    = simplydt::utc::UTCTime;
    using Days    = simplydt::Days;
    using Seconds = simplydt::Seconds;

    constexpr Date todayDate{2'025, 9, 3};
    constexpr Date pastDate{2'025, 8, 1};

    constexpr Time rightNow{1, 54, 19};
    constexpr Time secondsAgo{1, 53, 48};

    // GregorianDate constexpr tests:
    {
        constexpr Date::YearInt_t today_yr = todayDate.year();
        constexpr uint8_t today_mn         = todayDate.month();
        constexpr uint8_t today_dy         = todayDate.day();

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
        constexpr Days unit   = todayDate.units();
        constexpr int32_t rep = todayDate.underlying();
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

    // UTCTime constexpr tests:
    {
        constexpr uint8_t now_hr  = rightNow.hour12();
        constexpr uint8_t now_min = rightNow.minute();
        constexpr uint8_t now_sec = rightNow.second();

        constexpr bool eq  = rightNow == secondsAgo;
        constexpr bool lt  = rightNow < secondsAgo;
        constexpr bool gt  = rightNow > secondsAgo;
        constexpr bool lte = rightNow <= secondsAgo;
        constexpr bool gte = rightNow >= secondsAgo;

        constexpr Time ps       = rightNow + Seconds{15};
        constexpr Time ms       = rightNow - Seconds{15};
        constexpr Seconds diff1 = rightNow - secondsAgo;
        constexpr Seconds diff2 = secondsAgo - rightNow;
        constexpr Time arith    = secondsAgo + (rightNow - secondsAgo);

        constexpr bool zro     = rightNow.isZero();
        constexpr bool ftr     = rightNow.isAfter(secondsAgo);
        constexpr bool pst     = rightNow.isBefore(secondsAgo);
        constexpr bool btw     = rightNow.isBetween(secondsAgo, rightNow);
        constexpr Seconds unit = rightNow.units();
        constexpr uint32_t rep = rightNow.underlying();
    }

    // UTCTime increment/decrement tests:
    {
        Time now  = rightNow;
        Time next = ++now;
        next      = now++;

        next = rightNow - Seconds{30};
        next = --now;
        next = now--;

        next += Seconds{15};
        next -= Seconds{10};
    }

    // SerialCalendarDate and SerialTimeStandard stream out tests:
    {
        std::cout << "\nToday date: " << todayDate << "\nTime: " << rightNow << '\n';
        std::cout << "\nToday + 19 days = " << (todayDate + Days{19}) << '\n';
    }

    // Gregorian calendar tests:
    {
        //...
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
    // GregorianCalendar::getDayOfWeekAbbrev(demo); _SUSPEND_// constexpr bool isLeap =
    // GregorianCalendar::isLeapYear(demo); _SUSPEND_// constexpr uint16_t daysInYr         =
    // GregorianCalendar::getDaysInYear(demo); _SUSPEND_// constexpr
    // simplydt::gregorian::DayOfWeek dowRepr = _SUSPEND_//
    // GregorianCalendar::getDayOfWeekEnumRepr(demo); _SUSPEND_// constexpr UnixTimestamp
    // serialDays = GregorianCalendar::toDaysSinceEpoch(demo); _SUSPEND_// constexpr
    // GregorianDate fromSerial = GregorianCalendar::fromDaysSinceEpoch(0); _SUSPEND_//
    // constexpr UnixTimestamp tzz = _SUSPEND_//
    // GregorianCalendar::toUnixTimestamp(GregorianDate{2'004, 9, 17}); _SUSPEND_// constexpr
    // GregorianDate zzt = _SUSPEND_//     GregorianCalendar::fromUnixTimestamp(1'095'379'200);
    //// 2004-09-17T00:00:00.00 _SUSPEND_// const GregorianDate bzr = _SUSPEND_//
    // GregorianCalendar::fromTimePoint(std::chrono::system_clock::now(), false); _SUSPEND_//
    // std::cout << bzr << '\n';

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
