#include <Arduino.h>
#include "../Configuration/Configuration.h"
#include "WebSocketClient/WebSocketClient.h"

#ifndef WaterReader_H
#define WaterReader_H

// Minimum time since las watering to water again in millis
#define WATERING_WAIT_TIME 21600000 // 6 hours
// Time to keep the pump running during a watering in millis
#define WATER_TIME 20000

#define FILTER_READS 10

class WaterReader{

    // ------------ Properties
    private: int sensorPin;

    private: int pumpPin;

    private: int humidityValue;//Actual humidity sensed

    private: int minHumidity;//Sensor value when completely dry
    private: int maxHumidity;//Sensor value when completely wet
    private: int humidityThreshold;//Sensor value at which to water the plant
    
    private: unsigned int readInterval;//Time between raw sensor readings

    private: unsigned int measureInterval;//Time between measure events

    private: int sensorReads[FILTER_READS];

    private: int readIndex = 0;

    private: unsigned long lastWater = - WATERING_WAIT_TIME -1;

    private: unsigned long lastMeasureEvent = 0;
    private: unsigned long lastReadTime = 0;
    

    // ------------ Constructors
    public:WaterReader( Configuration* config );


    // ------------ Methods
    
    //To run on the main loop
    void loop(WebSocketClient *webSocketClient);
    //Read the sensor values
    int read();
    //Get humidity saved value (after signal filter)
    public: int getHumidity();
    //Get last values read from sensor (raw)
    public: int getLastRead();
    //Activate plant watering system
    public: void waterPlant( int waterMillis );
    //Event ran every WaterReader::measureInterval
    private: void measureEvent( unsigned long actualMillis );

};
#endif