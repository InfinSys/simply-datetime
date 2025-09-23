
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
#include "simplydt/calendar/gregorian/gregorian_calendar.hpp"
#include "simplydt/time/utc/utc_time.hpp"

struct ICanWat {
    bool testing = true;
};

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    bool ICanWat::* frtho = nullptr;
    bool* known = nullptr;

    //\\//
    using Calendar      = simplydt::gregorian::GregorianCalendar;
    using Date          = simplydt::gregorian::GregorianDate;
    using Time          = simplydt::utc::UTCTime;
    using Days          = simplydt::Days;
    using Seconds       = simplydt::Seconds;
    using UnixTimestamp = simplydt::stl::UnixTimestamp;

    constexpr Date todayDate{2'025, 9, 7};
    constexpr Date pastDate{2'025, 8, 23};

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
        constexpr const char* mnm          = Calendar::getMonthName(todayDate);
        constexpr std::string_view mabbr   = Calendar::getMonthAbbrev(todayDate);
        constexpr Calendar::Month mrepr    = Calendar::getMonthEnumRepr(todayDate);
        constexpr Days serial              = Calendar::toDaysSinceEpoch(2001, 2, 23);
        constexpr Date jtb                 = Calendar::fromDaysSinceEpoch(serial);
        constexpr UnixTimestamp ts         = Calendar::toUnixTimestamp(2001, 2, 23);
        constexpr Date rtc2                = Calendar::fromUnixTimestamp(ts);
        constexpr Date next                = Calendar::getNextWeekday(jtb);
        constexpr Date last                = Calendar::getLastWeekday(next);
        constexpr Date weekend             = Calendar::getLastWeekend(jtb);
        constexpr Calendar::WeekDates week = Calendar::getWeek(2025, 0);
        constexpr uint8_t wkIndex          = Calendar::getWeekIndex(2025, 9, 22);
    }

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
