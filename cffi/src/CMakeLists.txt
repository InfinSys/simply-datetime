
#=====================================
#     /cffi/src Directory Script
#=====================================

set(CFFI_BINARY_NAME "${MAIN_BINARY_NAME}_c")

# Simply Datetime C Library Target
add_library("${CFFI_BINARY_NAME}" SHARED)

target_include_directories(
    ${CFFI_BINARY_NAME}

    PUBLIC
    ${PRJ_INCLUDE_DIRS}
    ${PRJ_CFFI_INCLUDE_DIRS}
)

target_link_libraries(
    ${CFFI_BINARY_NAME}

    PUBLIC
    ${MAIN_BINARY_NAME}
)

# Sources
add_subdirectory(common)

target_link_libraries(
    ${CFFI_BINARY_NAME}

    PUBLIC
    GLOBAL_CXX_OPTIONS
)
