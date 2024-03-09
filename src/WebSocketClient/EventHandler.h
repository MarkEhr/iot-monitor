#ifndef EventHandler_H
#define EventHandler_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include"UpdateManager/UpdateManager.h"

class EventHandler {
    // ------------ Methods
    public: 
        void handleText(uint8_t * text);
};

#endif