#ifndef UpdateManager_H
#define UpdateManager_H

#include "../Configuration/Configuration.h"

class UpdateManager{
    // ------------ Properties
    private: 
        String updateHost;
        uint8 updatePort;
        String updatePath;
        uint8 pollInterval;

    // ------------ Constructors
    public:
        UpdateManager( Configuration* config );

    // ------------ Methods
    public:
        // Polls for updates in case of missed WS update events
        void loop();
        // Trigger update calling host:port/path/binaryName
        void update(String binaryName);
};

#endif