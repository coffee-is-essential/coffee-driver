#include "coffee_drv/init.hpp"

namespace coffee_drv {
    bool init_drivers(void)
    {
        if(!init_IO())
            return false;

        if(!init_lcd())
            return false;

        if(!init_touch())
            return false;

#if COFFEE_DRV_SD_USE
        if(!init_sd(COFFEE_DRV_FS_LETTER))
            return false;
#endif

        Serial.println("init: driver initialization complete");

        return true;
    }
}
