#include "coffee_drv/wifi.hpp"

namespace coffee_drv {
    bool init_wifi_sta(std::string ssid, std::string password) {
        WiFi.mode(WIFI_STA);

        WiFi.begin(ssid.c_str(), password.c_str());

        Serial.print("[coffee_drv/wifi][info] attempting to connect");

        uint32_t start = millis();
        uint32_t interval_ms = 1000;
        while (WiFi.status() != WL_CONNECTED) {
            delay(interval_ms);
            Serial.print(".");

            if (millis() - start > COFFEE_DRV_WIFI_TIMEOUT_MS) {
                Serial.println();

                WiFi.disconnect(true, true);
                
                Serial.println("[coffee_drv/wifi][error] connection failed(timeout)");

                return false;
            }
        }

        Serial.println();
        Serial.println("[coffee_drv/wifi][info] successfully connected!");
        
        Serial.print("[coffee_drv/wifi][info] local IP=");
        Serial.println(WiFi.localIP());
        
        return true;
    }
}
