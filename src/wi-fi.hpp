#ifndef COFFEE_WIFI_HPP
#define COFFEE_WIFI_HPP

#include <Arduino.h>
#include <WiFi.h>

#define COFFEE_WIFI_TIMEOUT_MS 10000

namespace coffee {
    extern "C" {
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
        bool init_wifi_sta(const char* ssid, const char* password);
    }
}
#endif
