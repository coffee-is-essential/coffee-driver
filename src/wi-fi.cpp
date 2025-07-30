#include "wi-fi.hpp"

namespace coffee {
    extern "C" {
        bool init_wifi_sta(const char* ssid, const char* password) {
            uint32_t interval_ms = 500;

            uint32_t start = millis();

            WiFi.mode(WIFI_STA);

            WiFi.begin(ssid, password);

            Serial.print("wi-fi: connecting...");
            while (WiFi.status() != WL_CONNECTED) {
                delay(interval_ms);
                Serial.print(".");

                if (millis() - start > COFFEE_WIFI_TIMEOUT_MS) {
                    Serial.println("\nwi-fi: connection failed(timeout)");
                    WiFi.disconnect();

                    return false;
                }
            }

            Serial.println("\nwi-fi: connected");
            
            Serial.print("wi-fi: IP address=");
            Serial.println(WiFi.localIP());
            
            return true;
        }
    }
}
