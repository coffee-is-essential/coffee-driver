#include "driver.hpp"

namespace coffee
{
    bool init_drivers(void)
    {
        if(!init_IO())
            return false;

        if(!init_lcd())
            return false;

        if(!init_touch())
            return false;

#if COFFEE_SD_USE
        if(!init_sd(COFFEE_FS_LETTER))
            return false;
#endif

        return true;
    }
}
