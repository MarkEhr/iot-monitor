#include <Arduino.h>

#ifndef WifiCredentials_H
#define WifiCredentials_H

class WifiCredentials {

    public: WifiCredentials();
    
    public: WifiCredentials(String SSID, String key){
        this->SSID = SSID;
        this->key = key;
    }

    public: String SSID;

    public: String key;

};

#endif