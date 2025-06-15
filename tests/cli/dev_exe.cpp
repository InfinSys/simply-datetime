
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] n/a
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

#include "simplydt/common/stl_chrono_defs.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    stl::SysTimePoint test = std::chrono::system_clock::now();

    std::cout << test << std::endl;
    //

    return 0;
}
