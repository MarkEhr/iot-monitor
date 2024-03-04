#ifndef WebSocketClient_H
#define WebSocketClient_H

#include <WebSocketsClient.h>
#include "Configuration/Configuration.h"

class WebSocketClient {

    public: 
        void setup(  const Configuration& configuration);
        void loop();
        void send( String message );

    private: 
        WebSocketsClient webSocket;
        void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

};

#endif