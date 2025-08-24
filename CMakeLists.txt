add_library(duino_led STATIC
    src/PicoLed.cpp
)

target_include_directories(duino_led PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(duino_led pico_stdlib)
