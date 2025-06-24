
#================================
#     /src Directory Script
#================================

include(utility/project_tools)

set(MAIN_BINARY_NAME "${${PRJ_SCOPE}_MAIN_BINARY_NAME}")

# Simply Datetime Library Target
add_library("${MAIN_BINARY_NAME}" STATIC)

target_include_directories(
    ${MAIN_BINARY_NAME}

    PUBLIC
    ${PRJ_INCLUDE_DIRS}
)

# Set library-wide C++ standard
use_project_cxx_standard(GLOBAL_CXX_OPTIONS INTERFACE)

target_link_options(
    GLOBAL_CXX_OPTIONS

    INTERFACE
    ${GLOBAL_LINK_FLAGS}
)

# NOTE: Subdirs go here; remove call below...
target_sources(
    ${MAIN_BINARY_NAME}

    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

target_link_libraries(
    ${MAIN_BINARY_NAME}

    PUBLIC
    GLOBAL_CXX_OPTIONS
)
