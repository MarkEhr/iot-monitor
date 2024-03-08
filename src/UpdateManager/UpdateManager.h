#ifndef UpdateManager_H
#define UpdateManager_H

#include "../Configuration/Configuration.h"

class UpdateManager{
    // ------------ Properties
    private: 
        String updateIP;
        int updatePort;
        String updatePath;
        unsigned int pollInterval;
        unsigned long lastPollTime = 0;

    // ------------ Constructors
    public:
        UpdateManager( Configuration* config );

    // ------------ Methods
    public:
        // Polls for updates in case of missed WS update events
        void loop();
        // Trigger update calling host:port/path/binaryName
        void update(String binaryName);
        // Poll for updates, sends current version so server can validate if there is a new one
        // see https://arduino-esp8266.readthedocs.io/en/latest/ota_updates/readme.html#advanced-updater
        // for requirements of server implementation
        void pollUpdate();
};

#endif