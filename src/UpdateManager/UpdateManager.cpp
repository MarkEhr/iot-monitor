#include "UpdateManager.h"
#include "ESP8266httpUpdate.h"
#include "version.h"

UpdateManager::UpdateManager( Configuration* config ){
    updateIP = config -> getUpdateServerIP();
    updatePort = config -> getUpdateServerPort();
    updatePath = config -> getUpdateServerPath();
    pollInterval = config -> getUpdatePollInterval();

    ESPhttpUpdate.setAuthorization(config -> getServerAPIKey());
}

void UpdateManager::loop() {
    unsigned long now = millis();
    if( now - lastPollTime > pollInterval * 1000) { // seconds to millis
        pollUpdate();
        lastPollTime = now;
    }
}

void UpdateManager::update(String binaryName) {
    WiFiClient client;
    Serial.println("[UpdateManager] Attempting update to fimware: " + binaryName);
    ESPhttpUpdate.update(client, updateIP, updatePort, updatePath + "/" + binaryName);
}

void UpdateManager::pollUpdate() {
    WiFiClient client;
    t_httpUpdate_return ret = ESPhttpUpdate.update(client, updateIP, updatePort, updatePath, VERSION);
    switch(ret) {
        case HTTP_UPDATE_FAILED:
            Serial.println("[UpdateManager] Update failed: " + String(ESPhttpUpdate.getLastError()) + " " + ESPhttpUpdate.getLastErrorString());
            break;
        case HTTP_UPDATE_NO_UPDATES:
            Serial.println("[UpdateManager] No update available.");
            break;
        case HTTP_UPDATE_OK:
            Serial.println("[UpdateManager] Update ok."); // may not be called since we reboot the ESP
            break;
    }
}