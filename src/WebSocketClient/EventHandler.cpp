#include <Arduino.h>
#include "EventHandler.h"
#include <ArduinoJson.h>
#include "UpdateManager/UpdateManager.h"

extern UpdateManager *updateManager;

void EventHandler::handleText(uint8_t * text) {
    JsonDocument document;
    DeserializationError err = deserializeJson(document, text);

    if(err) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(err.f_str());
        return;
    }
    
    if(document.containsKey("update")) {
        updateManager->update(document["update"].as<String>());
    }
}