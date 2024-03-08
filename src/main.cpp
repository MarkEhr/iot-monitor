#include <Arduino.h>
#include "WaterReader/WaterReader.h"
#include "TideNetwork/TideNetwork.h"
#include "TideNetwork/WifiCredentials.h"
#include "Configuration/Configuration.h"
#include "WebSocketClient/WebSocketClient.h"
#include "UpdateManager/UpdateManager.h"

Configuration* config;
WaterReader *waterReader;
TideNetwork *tideNetwork;
WebSocketClient *webSocketClient;
UpdateManager *updateManager;

void setup() {

  Serial.begin(115200);

  Serial.write(WEBSOCKETS_NETWORK_TYPE);

  //Create wifi config
  int wifiCount = 3;
  WifiCredentials* credentials = (WifiCredentials*) malloc (  sizeof(WifiCredentials) * wifiCount );
  credentials[0] = *(new WifiCredentials("TIDE", "eltideano"));
  credentials[1] = *(new WifiCredentials("Seven Kingdoms 2.4", "Barbacoa#1"));
  credentials[2] = *(new WifiCredentials("Luke1, I am your WiFi", "Noooooooo1"));

  //Set up device parameters
  config = new Configuration();
  config->setSensorPin(A0)
    ->setPumpPin(D8)
    ->setReadTime(1000)
    ->setMeasureTime(5000)
    ->setCompletelyWetMeasure(450)
    ->setCompletelyDryMeasure(1024)

    ->setWifiNetworksCount( wifiCount )
    ->setWifiNetworks( credentials )

    ->setWebSocketServerIP("192.168.0.166")
    ->setWebSocketServerPort(4000)
    ->setServerAPIKey("+d!k~XB9yp-crxAn=cCGr$-o")

    ->setUpdateServerIP("192.168.0.166")
    ->setUpdateServerPort(4000)
    ->setUpdateServerPath("/update")
    ->setUpdatePollInterval(10);  //seconds, will probably change to minutes/hours in prod


  //Initialize controllers
  waterReader = new WaterReader( config );
  
  tideNetwork = new TideNetwork( config );
  tideNetwork->setup();

  webSocketClient = new WebSocketClient();
  webSocketClient->setup( *config );
  
  updateManager = new UpdateManager( config );
}

unsigned long lastMillis = 0;

void loop() {
  updateManager->loop();
  
  waterReader->loop();

  //tideNetwork->loop( waterReader->getHumidity() );
  
  webSocketClient->loop();
  //webSocketClient->send( );

}
