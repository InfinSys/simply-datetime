
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] n/a
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

#include "simplydt/common/stl_chrono_utils.hpp"

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    stl::TimePoint test = stl::nowTimePoint();

    std::cout << test << std::endl;
    //

    return 0;
}
