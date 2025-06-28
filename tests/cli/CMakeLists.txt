
#======================================
#     /tests/cli Directory Script
#======================================

add_executable(
    dev_cli_debug
    "${CMAKE_CURRENT_SOURCE_DIR}/dev_exe.cpp"
)

target_compile_features(
    dev_cli_debug

    PUBLIC
    cxx_std_20
)

set(SIMPLYDT_TARGET_NAME "${${PRJ_SCOPE}_MAIN_BINARY_NAME}")

target_link_libraries(
    dev_cli_debug

    PUBLIC
    ${SIMPLYDT_TARGET_NAME}
)
