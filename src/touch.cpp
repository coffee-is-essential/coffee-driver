#include "coffee_drv/touch.hpp"

namespace coffee_drv {
    /**
     * @brief GT911을 통해 터치를 감지하면 마지막으로 터치된 위치를 last_x와 last_y에 저장합니다
     * 
     *        if touch is detected via the GT911, stores the last touched position into last_x and last_y
     * 
     * @return 터치 감지 여부
     * 
     *         whether touch was detected
     */
    static bool is_touched(void);

    /**
     * @brief lv_hal_indev에서 입력 기기를 읽을 때 콜백됩니다
     * 
     *        called by lv_hal_indev to read input from the touch device
     */
    static void read_touch(lv_indev_drv_t* indev_driver, lv_indev_data_t* indev_data);
    
    int last_x = 0;

    int last_y = 0;
    
    // 터치 제어를 위한 GT911 드라이버
    // GT911 driver for touch control
    static TAMC_GT911 touch = TAMC_GT911(COFFEE_DRV_GT911_SDA, COFFEE_DRV_GT911_SCL, COFFEE_DRV_GT911_INT, COFFEE_DRV_GT911_RST, max(COFFEE_DRV_MAP_X1, COFFEE_DRV_MAP_X2), max(COFFEE_DRV_MAP_Y1, COFFEE_DRV_MAP_Y2));

    bool init_touch(void)
    {
        // lvgl 터치 드라이버
        // lvgl touch driver
        static lv_indev_drv_t indev_drv;
        
        if(!Wire.begin(COFFEE_DRV_GT911_SDA, COFFEE_DRV_GT911_SCL)) {
            Serial.println("[coffee_drv/touch][error] failed to initialize touch driver...");
            
            return false;
        }

        touch.begin();
        
        touch.setRotation(COFFEE_DRV_GT911_ROTATION);

        lv_indev_drv_init(&indev_drv);
        
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = read_touch;

        lv_indev_drv_register(&indev_drv);

        Serial.println("[coffee_drv/touch][info] touch initialization success!");

        return true;
    }

    static bool is_touched(void)
    {
        touch.read();

        if(touch.isTouched) {
            last_x = map(touch.points[0].x, COFFEE_DRV_MAP_X1, COFFEE_DRV_MAP_X2, 0, COFFEE_DRV_WIDTH - 1);
            last_y = map(touch.points[0].y, COFFEE_DRV_MAP_Y1, COFFEE_DRV_MAP_Y2, 0, COFFEE_DRV_HEIGHT - 1);

            return true;
        } else
            return false;
    }

    static void read_touch(lv_indev_drv_t* indev_driver, lv_indev_data_t* indev_data)
    {
        if(is_touched()) {
            indev_data->state = LV_INDEV_STATE_PR;

            indev_data->point.x = last_x;
            indev_data->point.y = last_y;

#if COFFEE_DRV_PRINT_TOUCH
            Serial.print("touch X: ");
            Serial.print(indev_data->point.x);

            Serial.print(", touch Y: ");
            Serial.println(indev_data->point.y);
#endif
        } else
            indev_data->state = LV_INDEV_STATE_REL;
        
        delay(15);
    }
}
