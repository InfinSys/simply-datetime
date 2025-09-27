
#======================================================
#     /tests/unit/gregorian_date Directory Script
#======================================================

add_executable(
    gregorian_date_tests

    "${CMAKE_CURRENT_SOURCE_DIR}/date_tests.cpp"
)

target_link_libraries(
    gregorian_date_tests

    PRIVATE
    googletest_external
)

target_include_directories(
    gregorian_date_tests

    PUBLIC
    ${PRJ_INCLUDE_DIRS}
)
