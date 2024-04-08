
#include <Arduino.h>
#include "WaterReader.h"
#include "WebSocketClient/WebSocketClient.h"

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
    measureInterval = config->getMeasureTime();
    readInterval = config->getReadTime();



    pinMode(sensorPin, INPUT);
    pinMode(pumpPin, OUTPUT);

    digitalWrite( pumpPin, PUMP_OFF );
}

void WaterReader::loop(WebSocketClient* webSocketClient){
    
    unsigned long now = millis();

    //Execute readings only every readInterval
    if( now - lastReadTime > readInterval ){
        read();
        webSocketClient->send( "{\"humidity\":\"" + String(humidityValue) + "\"}" );
        lastReadTime = now;
    }

    //Execute measure events only every measureInterval
    if( now - lastMeasureEvent > measureInterval ){
        measureEvent( now );
        lastMeasureEvent = now;
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

void WaterReader::measureEvent( unsigned long actualMillis ){

    bool shouldWater = ( minHumidity < maxHumidity && humidityValue < humidityThreshold ) ||
        ( minHumidity > maxHumidity && humidityValue > humidityThreshold );

    //Print values
    Serial.print("F-R ");
    Serial.print( this->getHumidity() );
    Serial.print(" - ");
    Serial.println( this->getLastRead() );
    Serial.print("Watering - ");
    Serial.println( shouldWater? "Yes":"No" );

    // Test humidity threshold to activate watering system
    if( shouldWater ){

        unsigned long timeSinceLastWater = actualMillis - lastWater;
        // Test minimum time between watering
        if( timeSinceLastWater > WATERING_WAIT_TIME ){
            waterPlant( WATER_TIME );
        }
    
    }

}

/**
 * @brief Activate the watering system
 * This is a blocking process to prevent other functions from extending the watering too much
 * 
 * @param waterMillis 
 */
void WaterReader::waterPlant( int waterMillis ){

    Serial.print("Watering plant for ");
    Serial.print(waterMillis);
    Serial.println("ms");

    digitalWrite( pumpPin, PUMP_ON );
    delay( waterMillis );
    digitalWrite( pumpPin, PUMP_OFF );
    lastWater = millis();
}
