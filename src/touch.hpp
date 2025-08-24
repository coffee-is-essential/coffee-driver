#ifndef COFFEE_TOUCH_HPP
#define COFFEE_TOUCH_HPP

#include <Arduino.h>
#include <Wire.h>

#include <TAMC_GT911.h>

#include <lvgl.h>

#include "config.hpp"

#define COFFEE_GT911
#define COFFEE_GT911_SCL 20
#define COFFEE_GT911_SDA 19
#define COFFEE_GT911_INT 3
#define COFFEE_GT911_RST 4
#define COFFEE_GT911_ROTATION ROTATION_NORMAL
#define COFFEE_MAP_X1 800
#define COFFEE_MAP_X2 0
#define COFFEE_MAP_Y1 480
#define COFFEE_MAP_Y2 0

namespace coffee
{
    /**
     * @brief 마지막으로 터치된 위치의 X 좌표
     * 
     *        X coordinate of the last touched location
     */
    extern int last_x;
    
    /**
     * @brief 마지막으로 터치된 위치의 Y 좌표
     * 
     *        Y coordinate of the last touched location
     */
    extern int last_y;

    /**
     * @brief 터치 스크린을 초기화합니다
     * 
     *        initializes the touch screen
     * 
     * @return 터치 스크린 초기화 성공 여부
     * 
     *         touch screen initialization success
     */
    bool init_touch(void);
}
#endif
