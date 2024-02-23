#include "TideNetwork.h"
#include "Utils.h"

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
WiFiServer server(80);

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

TideNetwork::TideNetwork( Configuration* config ){
  this->config = config;
}

void TideNetwork::setup() {
  
  delay(10);
  Serial.println('\n');

  int wifiCount = this->config->getWifiNetworksCount();
  for( int i=0; i < wifiCount; i++ ){
    WifiCredentials credentials = this->config->getWifiNetworks()[i];
    wifiMulti.addAP( credentials.SSID.c_str(), credentials.key.c_str());
  }

  Serial.println("[TideNetwork] Connecting ...");
  
  // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
  wl_status_t result = wifiMulti.run( 5000 );
  if ( result != WL_CONNECTED) {
    Serial.println("[TideNetwork] Failed to connected to wifi");
    return;

  }
  Serial.println('\n');
  Serial.print("[TideNetwork] Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer

  server.begin();

}

void TideNetwork::loop( int value ){

  WiFiClient client = server.available();
  this->wifiClient = client;

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    String header;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          if (currentLine.length() == 0) {
            Serial.println("Printing page");
            client.print(WEB_PAGE);
            client.print("<h1>Humedad: ");
            client.print(value);
            client.println("</h1>");
            client.print("</body></html>");

          }
          else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } 
        else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");

  }



}



void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    String message;
    for (int i = 0; i < length; i++) {
        message = message + (char) payload[i];  // convert *byte to string
    }
    Serial.print(message);
  
    Serial.println();
    Serial.println("-----------------------");
}

