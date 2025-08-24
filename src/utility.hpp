#ifndef COFFEE_UTILITY_HPP
#define COFFEE_UTILITY_HPP

#include <esp_heap_caps.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <Arduino.h>

#include "config.hpp"

namespace coffee {
    /**
     * @brief 메모리 정보를 시리얼 모니터로 출력하는 FreeRTOS Task를 추가합니다
     * 
     *        adds a FreeRTOS task that prints memory information to the serial monitor
     * 
     * @param print_term 출력 주기(ms)
     * 
     *                   print interval in milliseconds
     */
    void set_mem_monitor(unsigned int print_term);
}
#endif
