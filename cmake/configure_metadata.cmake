
#==================================
#     PROJECT METADATA MODULE
#==================================

include(utility/metadata_tools)

set(TEMP_CACHE_VARS "")

set_metadata(PUBLISHER "Infinity Systems, LLC." DESCRIPTION "Product publisher")
set_metadata(PRODUCT_TYPE "Library" DESCRIPTION "Software type")
set_metadata(INTERFACE_TYPE "API" DESCRIPTION "Product interface")
set_metadata(UUID "ISJTB-CXX-XL20230401-000001" DESCRIPTION "Product unique identifier")
set_metadata(LICENSE_TYPE "AGPLv3" DESCRIPTION "Product license type")
set_metadata(FULL_NAME "Simply Datetime" DESCRIPTION "Product name")
set_metadata(SHORT_NAME "Simply Datetime" DESCRIPTION "Product short name")
set_metadata(MAIN_BINARY_NAME "simplydt" DESCRIPTION "Main binary")
set_metadata(META_PREFIX "${PRJ_SCOPE}" DESCRIPTION "Project metadata prefix")

# Temporarily cached variables for code generation
create_template_reference(SFTW_PUBLISHER    PUBLISHER)
create_template_reference(SFTW_TYPE         PRODUCT_TYPE)
create_template_reference(SFTW_INTERFACE    INTERFACE_TYPE)
create_template_reference(SFTW_UUID         UUID)
create_template_reference(SFTW_LICENSE_TYPE LICENSE_TYPE)
create_template_reference(SFTW_NAME         FULL_NAME)
create_template_reference(SFTW_SHORT_NAME   SHORT_NAME)
create_template_reference(SFTW_MAIN_BINARY  MAIN_BINARY_NAME)
create_template_reference(SFTW_META_PREFIX  META_PREFIX)

configure_template(
    "${CMAKE_SOURCE_DIR}/docs/templ/README.md.in"
    "${CMAKE_SOURCE_DIR}/README.md"
)

configure_template(
    "${CMAKE_SOURCE_DIR}/docs/templ/Doxyfile.in"
    "${CMAKE_SOURCE_DIR}/docs/Doxyfile"
)

configure_template(
    "${CMAKE_SOURCE_DIR}/docs/templ/index.html.in"
    "${CMAKE_SOURCE_DIR}/docs/ref/index.html"
)

configure_template(
    "${CMAKE_SOURCE_DIR}/docs/templ/inaug.md.in"
    "${CMAKE_SOURCE_DIR}/docs/prj/inaug.md"
)

configure_template(
    "${CMAKE_SOURCE_DIR}/lib/metadata/templ/info.h.in"
    "${CMAKE_SOURCE_DIR}/lib/metadata/info.h"
)

configure_template(
    "${CMAKE_SOURCE_DIR}/lib/metadata/templ/version.h.in"
    "${CMAKE_SOURCE_DIR}/lib/metadata/version.h"
)

clear_temporary_cache()
