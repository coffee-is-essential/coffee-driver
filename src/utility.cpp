#include "coffee_drv/utility.hpp"

namespace coffee_drv {
    /**
     * @brief 현재 사용 가능한 메모리 양을 시리얼 통신으로 출력합니다
     * 
     *        prints the amount of currently available memory via serial communication
     */
    static void mem_monitor_task(void* task_param);

    void set_mem_monitor(unsigned int print_term) {
        xTaskCreatePinnedToCore(mem_monitor_task, "mem_monitor", 8192, reinterpret_cast<void*>(print_term), 5, NULL, 0);
    }

    static void mem_monitor_task(void* task_param) {
        unsigned int print_term = reinterpret_cast<unsigned int>(task_param);

        while (true) {
            unsigned int sram_total = heap_caps_get_total_size(MALLOC_CAP_INTERNAL) / 1024;
            unsigned int sram_free = heap_caps_get_free_size(MALLOC_CAP_INTERNAL) / 1024;

            unsigned int psram_total = heap_caps_get_total_size(MALLOC_CAP_SPIRAM) / 1024;
            unsigned int psram_free = heap_caps_get_free_size(MALLOC_CAP_SPIRAM) / 1024;

            Serial.printf("SRAM: total = %uKB, free = %uKB | PSRAM: total = %uKB, free = %uKB\n",
                    sram_total, sram_free, psram_total, psram_free);

            delay(print_term);
        }

        vTaskDelete(NULL);
    }
}
