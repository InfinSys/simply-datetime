
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] Advocating for strategy-based datetime
*       implementation so that it is easy to
*       swap the logic that drives the datetime
*       type.
* -> [] Need a general place for stuff like
*       'YEAR_MIN/MAX', 'Invalid' string, etc.
* -> [] Move 'CalendarComponent' enum out of
*       'gregorian' namespace to more general
*       location. (Split Standardized Strategies)
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

#include "simplydt/gregorian_calendar/gregorian_date.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    simplydt::gregorian::Date sample1{ 2'001, 2, 23 };
    simplydt::gregorian::Date sample2{ 2'024, 1, 9 };

    std::cout << (sample1 < sample2) << std::endl;
    //

    return 0;
}
