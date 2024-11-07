add_library(segger_rtt "")
set_target_properties(segger_rtt PROPERTIES LINKER_LANGUAGE C)

target_sources(segger_rtt
    PRIVATE
        SEGGER_RTT.c
        SEGGER_RTT_printf.c
    PUBLIC
        SEGGER_RTT.h
        SEGGER_RTT_Conf.h
)

target_include_directories(segger_rtt PUBLIC ${CMAKE_CURRENT_LIST_DIR})
