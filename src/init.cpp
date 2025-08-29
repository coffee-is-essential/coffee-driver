#include "coffee_drv/init.hpp"

namespace coffee_drv {
    bool init_drivers(void)
    {
        if(!init_IO()) {
            Serial.println("[coffee_drv/init][error] initialization complete");

            return false;
        }

        if(!init_lcd()) {
            Serial.println("[coffee_drv/init][error] initialization complete");

            return false;
        }

        if(!init_touch()) {
            Serial.println("[coffee_drv/init][error] initialization complete");

            return false;
        }

#if COFFEE_DRV_SD_USE
        if(!init_sd(COFFEE_DRV_FS_LETTER)) {
            Serial.println("[coffee_drv/init][error] initialization complete");

            return false;
        }
#endif

        Serial.println("[coffee_drv/init][info] initialization complete");

        return true;
    }
}
