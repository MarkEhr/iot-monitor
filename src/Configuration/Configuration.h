#include <Arduino.h>

#ifndef Configuration_H
#define Configuration_H

class Configuration{

    //WaterReader configuration
    private: int sensorPin;
    public: int getSensorPin();
    public: Configuration* setSensorPin( int sensorPin );

    private: int pumpPin;
    public: int getPumpPin();
    public: Configuration* setPumpPin( int pumpPin );

    private: int completelyWetMeasure = 540;
    public: int getCompletelyWetMeasure();
    public: Configuration* setCompletelyWetMeasure( int completelyWetMeasure );

    private: int completelyDryMeasure = 1024;
    public: int getCompletelyDryMeasure();
    public: Configuration* setCompletelyDryMeasure( int completelyDryMeasure );

    private: int humidityToWater = 800;
    public: int getHumidityToWater();
    public: Configuration* setHumidityToWater( int humidityToWater );

};
#endif