
#ifndef _DEV_EXECUTABLE_UTILITIES_H_
#define _DEV_EXECUTABLE_UTILITIES_H_

#include "metadata/info.h"
#include "metadata/version.h"
#include <iostream>

inline void ProjectInfoOut() noexcept
{
    std::cout << '\n'
              << "\n\tCopyright (C) " << SIMPLYDT_PUBLISHER << "\n"
              << "\n\t[ " << SIMPLYDT_FULL_NAME << " ]"
              << "\n\t-> (Dev CLI executable)\n"
              << "\n\tRelease: " << (int)SIMPLYDT_VERSION_MAJOR
              << ", Version: " << (int)SIMPLYDT_VERSION_MINOR
              << ", Patch: " << (int)SIMPLYDT_VERSION_PATCH
              << ", Tweak: " << (int)SIMPLYDT_VERSION_TWEAK
              << "\n\t > CLI Debug Executable"
              << "\n\t > C++ 20"
              << "\n\n"
              << std::endl;
}

#endif // _DEV_EXECUTABLE_UTILITIES_H_
