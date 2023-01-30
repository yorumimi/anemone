cmake_minimum_required(VERSION 3.20)
project(anemone CXX)

set(ANEMONE_DIR "../..")
set(ANEMONE_SRC_DIR "${ANEMONE_DIR}/anemone")
set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(ANEMONE_TARGET_PLATFORM "Win32" CACHE STRING "Choose platform")
set(ANEMONE_USE_DIRECT3D12  true    CACHE BOOL   "Use Direct3D12")

set(ANEMONE_USE_EXPERIMENTAL true CACHE BOOL "Use Experimental")

# NOTE: static library
add_library(anemone_static STATIC)
include(application.cmake)
include(basic.cmake)
include(platform.cmake)

set_target_properties(anemone_static PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(anemone_static PRIVATE
    ${ANEMONE_DIR}
    ${ANEMONE_DIR}/dependencies
)

