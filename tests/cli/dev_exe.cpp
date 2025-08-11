
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] N/a
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

// Includes...
#include "simplydt/calendar/abstract_calendar.hpp"
#include "simplydt/calendar/gregorian/gregorian_date.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    simplydt::gregorian::GregorianDate demo{2'025, 8, 11};

    std::cout << demo << '\n';
    //

    std::cout << "\n\n\t[ Complete ]" << std::endl;
    return 0;
}
