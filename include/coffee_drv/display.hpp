#ifndef COFFEE_DRV_DISPLAY_HPP
#define COFFEE_DRV_DISPLAY_HPP

#include <driver/i2c.h>
#include <esp_heap_caps.h>

#include <Arduino.h>
#include <Wire.h>

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>

#include <lvgl.h>

#include <PCA9557.h>

#include "coffee_drv/config.hpp"

#define COFFEE_DRV_BACKLIGHT 2
#define COFFEE_DRV_BACKLIGHT_CH 1

namespace coffee_drv
{
    /**
     * @brief 화면 제어를 위한 클래스
     * 
     *        class for controlling the LCD screen
     */
    class LCD: public lgfx::LGFX_Device {
    public:
        lgfx::Panel_RGB _panel;

        lgfx::Bus_RGB _bus;

        LCD(void);
    };

    /**
     * @brief 디스플레이 출력과 관련된 객체
     * 
     *        object related to display output
     */
    extern LCD lcd;

    /**
     * @brief 디스플레이 운용에 필요한 각종 IO 핀들을 초기화합니다
     * 
     *        initializes the various IO pins required for display operation
     * 
     * @return IO 핀 초기화 성공 여부
     * 
     *         IO pin initialization success
     */
    bool init_IO(void);

    /**
     * @brief LCD를 초기화합니다
     * 
     *        initializes the LCD
     * 
     * @return LCD 초기화 성공 여부
     * 
     *         LCD initialization success
     */
    bool init_lcd(void);

    /**
     * @brief 화면을 끕니다
     * 
     *        turns off the LCD screen
     */
    void turn_off_lcd(void);

    /**
     * @brief 화면을 켭니다
     * 
     *        turns on the LCD screen
     */
    void turn_on_lcd(void);
}
#endif
