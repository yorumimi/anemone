cmake_minimum_required(VERSION 3.20)
project(anemone CXX)

set(ANEMONE_DIR "../..")
set(ANEMONE_SRC_DIR "${ANEMONE}/anemone")
set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(ANEMONE_TARGET_PLATFORM "Win32" CACHE STRING "Choose platform")
set(ANEMONE_USE_DIRECT3D12  true    CACHE BOOL   "Use Direct3D12")

set(ANEMONE_USE_EXPERIMENTAL true CACHE BOOL "Use Experimental")
