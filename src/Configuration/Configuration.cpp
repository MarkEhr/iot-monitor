#include "Configuration.h"


//Connection configurations

WifiCredentials* Configuration::getWifiNetworks() const{
    return this->wifiNetworks;
}

Configuration* Configuration::setWifiNetworks( WifiCredentials* wifiNetworks ){
    this->wifiNetworks = wifiNetworks;
    return this;
}
    
unsigned short Configuration::getWifiNetworksCount() const{
    return this->wifiNetworksCount;
}

Configuration* Configuration::setWifiNetworksCount( unsigned short wifiNetworksCount ){
    this->wifiNetworksCount = wifiNetworksCount;
    return this;
}

//Server connection
String Configuration::getWebSocketServerIP() const{
    return this->webSocketServerIP;
}

Configuration* Configuration::setWebSocketServerIP( String webSocketServerIP ){
    this->webSocketServerIP = webSocketServerIP;
    return this;
}

int Configuration::getWebSocketServerPort() const{
    return this->webSocketServerPort;
}

Configuration* Configuration::setWebSocketServerPort( int webSocketServerPort ){
    this->webSocketServerPort = webSocketServerPort;
    return this;
}

String Configuration::getServerAPIKey() const{
    return this->serverAPIKey;
}

Configuration* Configuration::setServerAPIKey( String serverAPIKey ){
    this->serverAPIKey = serverAPIKey;
    return this;
}

//UpdateManager confguration
String Configuration::getUpdateServerIP() const{
    return this->updateServerIP;
}

Configuration* Configuration::setUpdateServerIP( String updateServerIP ){
    this->updateServerIP = updateServerIP;
    return this;
}

int Configuration::getUpdateServerPort() const{
    return this->updateServerPort;
}

Configuration* Configuration::setUpdateServerPort( int updateServerPort ){
    this->updateServerPort = updateServerPort;
    return this;
}

String Configuration::getUpdateServerPath() const{
    return this->updateServerPath;
}

Configuration* Configuration::setUpdateServerPath( String updateServerPath ){
    this->updateServerPath = updateServerPath;
    return this;
}

unsigned int Configuration::getUpdatePollInterval() const{
    return this->updatePollInterval;
}

Configuration* Configuration::setUpdatePollInterval( unsigned int updatePollInterval ){
    this->updatePollInterval = updatePollInterval;
    return this;
}

//WaterReader configuration

int Configuration::getSensorPin() const{
    return this->sensorPin;
}


Configuration* Configuration::setSensorPin( int sensorPin ){
    this->sensorPin = sensorPin;
    return this;
}


int Configuration::getPumpPin() const{
    return this->pumpPin;
}


Configuration* Configuration::setPumpPin( int pumpPin ){
    this->pumpPin = pumpPin;
    return this;
}


int Configuration::getCompletelyWetMeasure() const{
    return this->completelyWetMeasure;
}


Configuration* Configuration::setCompletelyWetMeasure( int completelyWetMeasure ){
    this->completelyWetMeasure = completelyWetMeasure;
    return this;
}


int Configuration::getCompletelyDryMeasure() const{
    return this->completelyDryMeasure;
}


Configuration* Configuration::setCompletelyDryMeasure( int completelyDryMeasure ){
    this->completelyDryMeasure = completelyDryMeasure;
    return this;
}


int Configuration::getHumidityToWater() const{
    return this->humidityToWater;
}


Configuration* Configuration::setHumidityToWater( int humidityToWater ){
    this->humidityToWater = humidityToWater;
    return this;
}


unsigned int Configuration::getMeasureTime() const{
    return this->measureTime;
}


Configuration* Configuration::setMeasureTime( unsigned int measureTime ){
    this->measureTime = measureTime;
    return this;
}


unsigned int Configuration::getReadTime() const{
    return this->readTime;
}


Configuration* Configuration::setReadTime( unsigned int readTime ){
    this->readTime = readTime;
    return this;
}