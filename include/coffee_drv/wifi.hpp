#ifndef COFFEE_DRV_WIFI_HPP
#define COFFEE_DRV_WIFI_HPP

#include <cstdint>
#include <string>

#include <Arduino.h>
#include <WiFi.h>

#include "coffee_drv/config.hpp"

namespace coffee_drv {
    /**
     * @brief STA 모드 Wi-Fi를 초기화합니다
     * 
     *        initializes Wi-Fi in STA mode
     *
     * @param ssid 연결할 Wi-Fi SSID
     * 
     *             SSID of the Wi-Fi to connect
     * 
     * @param password Wi-Fi 접속 비밀번호
     * 
     *                 password for Wi-Fi connection
     */
    bool init_wifi_sta(std::string ssid, std::string password);
}
#endif
