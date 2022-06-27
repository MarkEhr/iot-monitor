#include <Arduino.h>
#include "WaterReader/WaterReader.h"
#include "TideNetwork/TideNetwork.h"
#include "Configuration/Configuration.h"

Configuration* config;
WaterReader *waterReader;
TideNetwork *tideNetwork;

void setup() {

  Serial.begin(115200);

  //Set up device parameters
  config = new Configuration();
  config->setSensorPin(A0)
    ->setPumpPin(D8)
    ->setCompletelyWetMeasure(450)
    ->setCompletelyDryMeasure(1024);

  //Initialize controllers
  waterReader = new WaterReader( config );
  
  tideNetwork = new TideNetwork();
  tideNetwork->setup();
  //tideNetwork->connectToBroker();
  
}

void loop() {
  
  waterReader->loop();
  int humidity = waterReader->getHumidity();
  Serial.print("F-R ");
  Serial.print(humidity);
  Serial.print(" - ");
  Serial.println(waterReader->getLastRead());
  delay(5000);

  tideNetwork->loop( humidity );

}
