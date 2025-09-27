
#=======================================
#     /tests/unit Directory Script
#=======================================

add_library(googletest_external INTERFACE)

target_include_directories(
    googletest_external

    INTERFACE
    "${googletest_SOURCE_DIR}/googletest/include"
)

target_link_libraries(
    googletest_external

    INTERFACE
    gtest
    gtest_main
)

# Simply Datetime requires C++ 20+
target_compile_features(
    googletest_external

    INTERFACE
    cxx_std_20
)

# Unit-Tests Sources
add_subdirectory(gregorian_date)
