
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
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

#include "simplydt/coord_universal_time/utc_time.hpp"
#include "simplydt/gregorian_calendar/gregorian_date.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    utc::Time::Underlying_T demo = 0;

    utc::Time::encodeUTCTimeIntoInteger(&demo, 10, 30, 2);

    std::cout << demo << std::endl;

    utc::Time test{ 2, 53, 34 };
    std::cout << test << std::endl;
    //

    return 0;
}
