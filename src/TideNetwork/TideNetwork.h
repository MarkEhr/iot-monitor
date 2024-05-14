#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include "Configuration/Configuration.h"
#include "TideNetwork/WifiCredentials.h"

#ifndef TideNetwork_H
#define TideNetwork_H

class TideNetwork {

    public: TideNetwork( Configuration* config );

    private: Configuration* config;

    private: WiFiClient wifiClient;

    public: void setup();

    public: void loop();

};

#endif