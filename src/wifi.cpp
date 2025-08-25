#include "coffee_drv/wifi.hpp"

<<<<<<< HEAD
namespace coffee_drv {
=======
namespace coffee {
>>>>>>> 960e2b8f931559bcf00d9f9962fef2e45777ae34
    bool init_wifi_sta(const char* ssid, const char* password) {
        uint32_t interval_ms = 500;

        uint32_t start = millis();

        WiFi.mode(WIFI_STA);

        WiFi.begin(ssid, password);

        Serial.print("wifi: connecting...");
        while (WiFi.status() != WL_CONNECTED) {
            delay(interval_ms);
            Serial.print(".");

<<<<<<< HEAD
            if (millis() - start > COFFEE_DRV_WIFI_TIMEOUT_MS) {
=======
            if (millis() - start > COFFEE_WIFI_TIMEOUT_MS) {
>>>>>>> 960e2b8f931559bcf00d9f9962fef2e45777ae34
                Serial.println("\nwifi: connection failed(timeout)");
                WiFi.disconnect(true, true);

                return false;
            }
        }

        Serial.println("\nwifi: connected");
        
        Serial.print("wifi: IP address=");
        Serial.println(WiFi.localIP());
        
        return true;
    }
}
