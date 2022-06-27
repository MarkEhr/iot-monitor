#include <Arduino.h>
#include "../Configuration/Configuration.h"

#ifndef WaterReader_H
#define WaterReader_H

// Minimum time since las watering to water again in millis
#define WATERING_WAIT_TIME 21600000 // 6 hours
// Time to keep the pump running during a watering in millis
#define WATER_TIME 20000

#define FILTER_READS 10

class WaterReader{

    //Properties
    private: int sensorPin;

    private: int pumpPin;

    private: int humidityValue;//Actual humidity sensed

    private: int minHumidity;//Sensor value when completely dry
    private: int maxHumidity;//Sensor value when completely wet
    private: int humidityThreshold;//Sensor value at which to water the plant

    private: int sensorReads[FILTER_READS];

    private: int readIndex = 0;

    private: unsigned long lastWater = - WATERING_WAIT_TIME -1;
    
    //Constructors
    public:WaterReader( Configuration* config );

    //Methods
    void loop();

    int read();

    public: int getHumidity();

    public: int getLastRead();

    public: void waterPlant( int waterMillis );

};
#endif