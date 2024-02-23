#include <WebSocketsClient.h>
#include "WebSocketClient.h"


WebSocketsClient webSocket;

void hexdump(const void *mem, uint32_t len, uint8_t cols) {
	const uint8_t* src = (const uint8_t*) mem;
	Serial.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
	for(uint32_t i = 0; i < len; i++) {
		if(i % cols == 0) {
			Serial.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
		}
		Serial.printf("%02X ", *src);
		src++;
	}
	Serial.printf("\n");
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

	switch(type) {
		case WStype_DISCONNECTED:
			Serial.printf("[WSc] Disconnected!\n");
			break;
		case WStype_CONNECTED:
			Serial.printf("[WSc] Connected to url: %s\n", payload);

			// send message to server when Connected
			webSocket.sendTXT("Connected");
			break;
		case WStype_TEXT:
			Serial.printf("[WSc] get text: %s\n", payload);

			// send message to server
			// webSocket.sendTXT("message here");
			break;
		case WStype_BIN:
			Serial.printf("[WSc] get binary length: %u\n", length);
			hexdump(payload, length, 16);

			// send data to server
			// webSocket.sendBIN(payload, length);
			break;
        case WStype_PING:
        case WStype_PONG:
		case WStype_ERROR:			
		case WStype_FRAGMENT_TEXT_START:
		case WStype_FRAGMENT_BIN_START:
		case WStype_FRAGMENT:
		case WStype_FRAGMENT_FIN:
			break;
	}

}

void WebSocketClient::setup() {

	// server address, port and URL
	webSocket.begin("192.168.100.133", 4000, "/ws?sup=!");

	// event handler
	webSocket.onEvent(webSocketEvent);

	webSocket.setReconnectInterval(30000);

}

void WebSocketClient::loop() {
	webSocket.loop();
}

void WebSocketClient::send(  ){
    webSocket.sendTXT( "sup" );
}