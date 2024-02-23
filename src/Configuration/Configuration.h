#include <Arduino.h>
#include "TideNetwork/WifiCredentials.h"

#ifndef Configuration_H
#define Configuration_H

class Configuration{

    //Connection configurations
    private: WifiCredentials* wifiNetworks;
    public: WifiCredentials* getWifiNetworks();
    public: Configuration* setWifiNetworks( WifiCredentials* wifiNetworks );
    
    private: unsigned short wifiNetworksCount;
    public: unsigned short getWifiNetworksCount();
    public: Configuration* setWifiNetworksCount( unsigned short wifiNetworksCount );

    private: int wifiRetryInterval;
    public: int getWifiRetryInterval();
    public: Configuration* setWifiRetryInterval( int wifiNetworksCount );

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

    private: unsigned int measureTime;
    public: unsigned int getMeasureTime();
    public: Configuration* setMeasureTime( unsigned int measureTime );


    private: unsigned int readTime;
    public: unsigned int getReadTime();
    public: Configuration* setReadTime( unsigned int readTime );

};
#endif