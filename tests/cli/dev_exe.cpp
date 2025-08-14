
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] N/a
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

    constexpr GregorianDate demo{2'025, 8, 14};
    std::cout << "\nDemo date: " << demo << '\n';

    constexpr bool isValid                         = GregorianCalendar::isValidDate(demo);
    constexpr uint8_t noWeeks                      = GregorianCalendar::getWeeksInMonth(demo);
    constexpr const char* month                    = GregorianCalendar::getMonthName(demo);
    constexpr simplydt::gregorian::Month monthRepr = GregorianCalendar::getMonthEnumRepr(demo);
    constexpr const char* dowName                  = GregorianCalendar::getDayOfWeekName(demo);
    constexpr simplydt::gregorian::DayOfWeek dowRepr =
        GregorianCalendar::getDayOfWeekEnumRepr(demo);
    //

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
