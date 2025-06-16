
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
        'YEAR_MIN/MAX', 'Invalid' string, etc.
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

#include "simplydt/coord_universal_time/utc_defs.hpp"
#include "simplydt/gregorian_calendar/gregorian_defs.hpp"
#include "simplydt/julian_calendar/julian_defs.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;
    //

    return 0;
}
