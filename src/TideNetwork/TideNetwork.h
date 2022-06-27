#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WiFiMulti.h>

#ifndef TideNetwork_H
#define TideNetwork_H

class TideNetwork {

    private: WiFiClient wifiClient;

    private: PubSubClient mqttClient;

    public: void setup();

    public: void loop( int value );

    public: void connectToBroker();

};

#endif