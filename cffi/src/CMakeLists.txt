
#=====================================
#     /cffi/src Directory Script
#=====================================

set(ORIGINAL_BINARY_NAME "${${PRJ_SCOPE}_MAIN_BINARY_NAME}")

set(STATIC_CFFI_BINARY_NAME "${ORIGINAL_BINARY_NAME}_c")
set(SHARED_CFFI_BINARY_NAME "${ORIGINAL_BINARY_NAME}_c_s")

# Simply Datetime C Library Target Interface
add_library(CFFI_LIBRARY_INTERFACE INTERFACE)

target_include_directories(
    CFFI_LIBRARY_INTERFACE

    INTERFACE
    ${PRJ_INCLUDE_DIRS}
    ${PRJ_CFFI_INCLUDE_DIRS}
)

target_link_libraries(
    CFFI_LIBRARY_INTERFACE

    INTERFACE
    ${ORIGINAL_BINARY_NAME}
)

target_link_libraries(
    CFFI_LIBRARY_INTERFACE

    INTERFACE
    GLOBAL_CXX_OPTIONS
)

# Sources
add_subdirectory(common)

# Static Simply Datetime C Interface Target
add_library("${STATIC_CFFI_BINARY_NAME}" STATIC)

# Shared Simply Datetime C Interface Target
add_library("${SHARED_CFFI_BINARY_NAME}" SHARED)

target_link_libraries(
    ${STATIC_CFFI_BINARY_NAME}

    PUBLIC
    CFFI_LIBRARY_INTERFACE
)

target_link_libraries(
    ${SHARED_CFFI_BINARY_NAME}

    PUBLIC
    CFFI_LIBRARY_INTERFACE
)
