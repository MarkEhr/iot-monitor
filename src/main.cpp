#include <Arduino.h>
#include "WaterReader/WaterReader.h"
#include "TideNetwork/TideNetwork.h"
#include "TideNetwork/WifiCredentials.h"
#include "Configuration/Configuration.h"
#include "WebSocketClient/WebSocketClient.h"

Configuration* config;
WaterReader *waterReader;
TideNetwork *tideNetwork;
WebSocketClient *webSocketClient;

void setup() {

  Serial.begin(115200);

  //Create wifi config
  int wifiCount = 2;
  WifiCredentials* credentials = (WifiCredentials*) malloc (  sizeof(WifiCredentials) * wifiCount );
  credentials[0] = *(new WifiCredentials("TIDE1", "NoMeLaSe"));
  credentials[1] = *(new WifiCredentials("Luke1, I am your WiFi", "Noooooooo1"));

  //Set up device parameters
  config = new Configuration();
  config->setSensorPin(A0)
    ->setPumpPin(D8)
    ->setMeasureTime(5000)
    ->setCompletelyWetMeasure(450)
    ->setCompletelyDryMeasure(1024)
    ->setWifiNetworksCount( wifiCount )
    ->setWifiNetworks( credentials );


  //Initialize controllers
  waterReader = new WaterReader( config );
  
  tideNetwork = new TideNetwork( config );
  tideNetwork->setup();

  webSocketClient = new WebSocketClient();
  webSocketClient->setup();
  
}

unsigned long lastMillis = 0;

void loop() {
  
  waterReader->loop();

  tideNetwork->loop( waterReader->getHumidity() );
  
  webSocketClient->loop();
  //webSocketClient->send( );

}
