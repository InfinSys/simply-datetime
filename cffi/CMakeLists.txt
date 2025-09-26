
# Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
# Released under the terms of the GNU Affero General Public License version 3.

#====================================
#
#     Simply Datetime Library -
#     C Interface Build Script
#
#     /cffi Directory
#
#====================================

# TODO: Major changes needed here in due time...

set(
    PRJ_CFFI_INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
)

# Sources
add_subdirectory(src)
