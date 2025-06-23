
#============================================
#     /cffi/src/common Directory Script
#============================================

target_sources(
    ${CFFI_BINARY_NAME}

    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/c_datetime_utils.cpp"
)
