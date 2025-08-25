idf_component_register(SRCS "src/display.cpp"
        "src/init.cpp"
        "src/sd.cpp"
        "src/touch.cpp"
        "src/utility.cpp"
        "src/wifi.cpp"
    INCLUDE_DIRS "include"
    REQUIRES arduino-esp32
        gt911-arduino
        LovyanGFX
        lvgl
        PCA9557
)
