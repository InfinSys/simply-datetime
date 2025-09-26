
# Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
# Released under the terms of the GNU Affero General Public License version 3.

#=======================================
#
#     Simply Datetime Library -
#     Build Generation Script
#
#     (Root CMakeLists.txt Script)
#
#=======================================

cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(PRJ_NAME "Simply_Datetime")
set(PRJ_SCOPE "SIMPLYDT")
set(PRJ_C_STANDARD 23)
set(PRJ_CXX_STANDARD 20)

project(
    ${PRJ_NAME}
    VERSION 0.1.0.0
    LANGUAGES C CXX ASM
)

set(CMAKE_C_STANDARD ${PRJ_C_STANDARD})
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD ${PROJECT_CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(PRJ_CMAKE_MODULE_DIR "${CMAKE_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${PRJ_CMAKE_MODULE_DIR}")

set(
    PRJ_INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/lib"
)

# Do not modify the variables below
set(CLI_DEBUGGING OFF)
set(UNIT_TESTING OFF)
set(BENCHMARKING OFF)

set(FORMATTING OFF)
set(CFFI_BUILD OFF)
# Do not modify the variables above

if(DEFINED CACHE{${PRJ_SCOPE}_CLI_DEBUG} AND ${PRJ_SCOPE}_CLI_DEBUG)
    message(STATUS "${PRJ_NAME} CLI debug build - enabled")
    set(CLI_DEBUGGING ON)
endif()

if(DEFINED CACHE{${PRJ_SCOPE}_UNIT_TEST} AND ${PRJ_SCOPE}_UNIT_TEST)
    message(STATUS "${PRJ_NAME} unit-test build - enabled")
    set(UNIT_TESTING ON)
    enable_testing()
    add_subdirectory(3rdparty/googletest)
endif()

if(DEFINED CACHE{${PRJ_SCOPE}_BENCHMARK} AND ${PRJ_SCOPE}_BENCHMARK)
    message(STATUS "${PRJ_NAME} benchmark build - enabled")
    set(BENCHMARKING ON)
    add_subdirectory(3rdparty/benchmark)
endif()

if(DEFINED CACHE{${PRJ_SCOPE}_C_LIB} AND ${PRJ_SCOPE}_C_LIB)
    message(STATUS "${PRJ_NAME} C interface build - enabled")
    set(CFFI_BUILD ON)
endif()

if(DEFINED CACHE{${PRJ_SCOPE}_FORMAT} AND ${PRJ_SCOPE}_FORMAT)
    find_program(CLANG_FORMAT_EXECUTABLE clang-format)

    if(NOT CLANG_FORMAT_EXECUTABLE)
        message(WARNING "clang-format not found: Cannot produce source code format target.")
    else()
        message(STATUS "${PRJ_NAME} source format target - enabled")
        set(FORMATTING ON)
        include(clang_format)
    endif()
endif()

# Includes
include_directories(${PRJ_INCLUDE_DIRS})

include(compiler/detector)
include(linker/config)

# Sources
add_subdirectory(lib)

include(utility/project_tools)

# Set library-wide C++ standard
use_project_cxx_standard(GLOBAL_CXX_OPTIONS INTERFACE)

target_link_options(
    GLOBAL_CXX_OPTIONS

    INTERFACE
    ${GLOBAL_LINK_FLAGS}
)

# C Interface Source
if(CFFI_BUILD)
    add_subdirectory(cffi)
endif()

# Testing
add_subdirectory(tests)
