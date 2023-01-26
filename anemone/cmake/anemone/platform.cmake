source_group(platform/win32      REGULAR_EXPRESSION "anemone/platform/win32/*")

target_sources(anemone_static PRIVATE

    $<$<PLATFORM_ID:Windows>:
        # NOTE: platform/win32
        ${ANEMONE_SRC_DIR}/platform/win32/RunnerWin32.hpp
        ${ANEMONE_SRC_DIR}/platform/win32/RunnerWin32.cpp
        ${ANEMONE_SRC_DIR}/platform/win32/PrerequisiteWin32.h
    >
)