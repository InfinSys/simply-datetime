
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

#include "simplydt/gregorian_calendar/gregorian_date.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    simplydt::gregorian::Date sample{ 2'001, 2, 23 };

    std::cout << sample << std::endl;
    //

    return 0;
}
