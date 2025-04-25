add_library(fh101rf_driver "")
set_target_properties(fh101rf_driver PROPERTIES LINKER_LANGUAGE C)

target_sources(fh101rf_driver
    PRIVATE
        fh101rf.c
    PUBLIC
        fh101rf.h
        fh101rf_reg.h
)

target_include_directories(fh101rf_driver PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_options(fh101rf_driver
    PUBLIC
    -Wno-unused-parameter
)
