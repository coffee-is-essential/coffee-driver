#ifndef COFFEE_DRV_INIT_HPP
#define COFFEE_DRV_INIT_HPP

#include <Arduino.h>

#include "coffee_drv/config.hpp"
#include "coffee_drv/display.hpp"
#include "coffee_drv/sd.hpp"
#include "coffee_drv/touch.hpp"

namespace coffee_drv
{
    /**
     * @brief 디스플레이 운용을 위한 각종 드라이버를 초기화합니다
     * 
     *        initializes various drivers for the display operation
     * 
     * @return 초기화 성공 여부
     * 
     *         initialization success
     */
    bool init_drivers(void);
}
#endif