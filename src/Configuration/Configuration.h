#include <Arduino.h>
#include "TideNetwork/WifiCredentials.h"

#ifndef Configuration_H
#define Configuration_H

class Configuration{

    //Connection configurations
    private: WifiCredentials* wifiNetworks;
    public: WifiCredentials* getWifiNetworks() const;
    public: Configuration* setWifiNetworks( WifiCredentials* wifiNetworks );
    
    private: unsigned short wifiNetworksCount;
    public: unsigned short getWifiNetworksCount() const;
    public: Configuration* setWifiNetworksCount( unsigned short wifiNetworksCount );

    private: int wifiRetryInterval;
    public: int getWifiRetryInterval() const;
    public: Configuration* setWifiRetryInterval( int wifiNetworksCount );

    //Server connection
    private: String webSocketServerIP;
    public: String getWebSocketServerIP() const;
    public: Configuration* setWebSocketServerIP( String webSocketServerIP );

    private: int webSocketServerPort;
    public: int getWebSocketServerPort() const;
    public: Configuration* setWebSocketServerPort( int webSocketServerPort );

    private: String serverAPIKey;
    public: String getServerAPIKey() const;
    public: Configuration* setServerAPIKey( String serverAPIKey );

    //WaterReader configuration
    private: int sensorPin;
    public: int getSensorPin() const;
    public: Configuration* setSensorPin( int sensorPin );

    private: int pumpPin;
    public: int getPumpPin() const;
    public: Configuration* setPumpPin( int pumpPin );

    private: int completelyWetMeasure = 540;
    public: int getCompletelyWetMeasure() const;
    public: Configuration* setCompletelyWetMeasure( int completelyWetMeasure );

    private: int completelyDryMeasure = 1024;
    public: int getCompletelyDryMeasure() const;
    public: Configuration* setCompletelyDryMeasure( int completelyDryMeasure );

    private: int humidityToWater = 800;
    public: int getHumidityToWater() const;
    public: Configuration* setHumidityToWater( int humidityToWater );

    private: unsigned int measureTime;
    public: unsigned int getMeasureTime() const;
    public: Configuration* setMeasureTime( unsigned int measureTime );


    private: unsigned int readTime;
    public: unsigned int getReadTime() const;
    public: Configuration* setReadTime( unsigned int readTime );

};
#endif