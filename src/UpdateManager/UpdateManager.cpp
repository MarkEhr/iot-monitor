#include "UpdateManager.h"
#include "ESP8266httpUpdate.h"
#include "version.h"

UpdateManager::UpdateManager( Configuration* config ){
    updateIP = config -> getUpdateServerIP();
    updatePort = config -> getUpdateServerPort();
    updatePath = config -> getUpdateServerPath();
    pollInterval = config -> getUpdatePollInterval();
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
    ESPhttpUpdate.update(client, updateIP, updatePort, updatePath + "/" + binaryName);
}

void UpdateManager::pollUpdate() {
    WiFiClient client;
    Serial.println("Update port: " + String(updatePort));
    t_httpUpdate_return ret = ESPhttpUpdate.update(client, updateIP, updatePort, updatePath + "/poll", VERSION);
    switch(ret) {
        case HTTP_UPDATE_FAILED:
            Serial.println("[update] Update failed: ESPhttpUpdate.getLastErrorString()");
            break;
        case HTTP_UPDATE_NO_UPDATES:
            Serial.println("[update] Update no Update.");
            break;
        case HTTP_UPDATE_OK:
            Serial.println("[update] Update ok."); // may not be called since we reboot the ESP
            break;
    }
}