source_group(application        REGULAR_EXPRESSION "anemone/application/*")
source_group(application/win32  REGULAR_EXPRESSION "anemone/application/win32/*")

target_sources(anemone_static PRIVATE
    # NOTE: application
    ${ANEMONE_SRC_DIR}/application/Window.hpp
    ${ANEMONE_SRC_DIR}/application/Window.cpp

    $<$<PLATFORM_ID:Windows>:
        # NOTE: platform/win32
        ${ANEMONE_SRC_DIR}/application/win32/WindowWin32.hpp
        ${ANEMONE_SRC_DIR}/application/win32/WindowWin32.cpp
    >
)
