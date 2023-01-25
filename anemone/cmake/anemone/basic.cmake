source_group(basic REGULAR_EXPRESSION "anemone/basic/*")

target_sources(anemone_static PRIVATE
    # NOTE: basic
    ${ANEMONE_SRC_DIR}/basic/ConditionalCompilation.h
)