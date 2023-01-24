cmake_minimum_required(VERSION 3.20)
project(game CXX)

set(PRODUCT_NAME game)
set(ANEMONE_DIR "../..")
set(CMAKE_CONFIGURATION_TYPES Debug Release)

source_group(platform/win32 REGULAR_EXPRESSION "platform/win32/*")
add_executable(${PRODUCT_NAME} WIN32)

target_sources(${PRODUCT_NAME} PRIVATE

    # On Windows
    $<$<PLATFORM_ID:Windows>:
        platform/win32/Main.cpp
    >
)

set_target_properties(${PRODUCT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_compile_definitions(${PRODUCT_NAME} PRIVATE
    $<$<CONFIG:Debug>:_DEBUG;POMDOG_DEBUG_BUILD=1>
    $<$<CONFIG:Release>:NDEBUG>

    # On Windows
    $<$<PLATFORM_ID:Windows>:
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    >
)

if(NOT ANEMONE_BUILD_TARGET_ALL)
    add_subdirectory(${ANEMONE_DIR}/cmake/anemone ${CMAKE_CURRENT_BINARY_DIR}/anemone_build)
endif()