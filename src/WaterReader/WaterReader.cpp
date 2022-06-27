
#include <Arduino.h>
#include "WaterReader.h"


#define PUMP_OFF LOW
#define PUMP_ON HIGH


WaterReader::WaterReader( Configuration* config ){

    for( int i=0; i<FILTER_READS; i++ ){
        sensorReads[i] = config->getCompletelyWetMeasure();
    }

    sensorPin = config->getSensorPin();
    pumpPin = config->getPumpPin();
    
    minHumidity = config->getCompletelyDryMeasure();
    maxHumidity = config->getCompletelyWetMeasure();
    humidityThreshold = config->getHumidityToWater();
    humidityValue = config->getCompletelyWetMeasure();



    pinMode(sensorPin, INPUT);
    pinMode(pumpPin, OUTPUT);

    digitalWrite( pumpPin, PUMP_OFF );
}

void WaterReader::loop(){
    
    read();

    // Test humidity threshold
    if( 
        ( minHumidity < maxHumidity && humidityValue < humidityThreshold ) ||
        ( minHumidity > maxHumidity && humidityValue > humidityThreshold ) 
    ){

        unsigned long timeSinceLastWater = millis() - lastWater;
        // Test minimum time between watering
        if( timeSinceLastWater > WATERING_WAIT_TIME ){
            waterPlant( WATER_TIME );
        }
    
    }

}

int WaterReader::read(){

    sensorReads[readIndex] = analogRead( sensorPin );
    readIndex++;

    if( readIndex >= FILTER_READS ){
        readIndex = 0;
    }

    // Low pass mean filter
    int total = 0;
    for( int i=0; i<FILTER_READS; i++ ){
        total += sensorReads[i];
    }

    humidityValue = total / FILTER_READS;

    return humidityValue;
}

int WaterReader::getHumidity(){
    return humidityValue;
}


int WaterReader::getLastRead(){
    return sensorReads[ (readIndex==0?FILTER_READS:readIndex)-1 ];
}

void WaterReader::waterPlant( int waterMillis ){

    Serial.print("Watering plant for ");
    Serial.print(waterMillis);
    Serial.println("ms");

    digitalWrite( pumpPin, PUMP_ON );
    delay( waterMillis );
    digitalWrite( pumpPin, PUMP_OFF );
    lastWater = millis();
}
