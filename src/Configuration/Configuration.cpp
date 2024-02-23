#include "Configuration.h"


WifiCredentials* Configuration::getWifiNetworks(){
    return this->wifiNetworks;
}

Configuration* Configuration::setWifiNetworks( WifiCredentials* wifiNetworks ){
    this->wifiNetworks = wifiNetworks;
    return this;
}
    
unsigned short Configuration::getWifiNetworksCount(){
    return this->wifiNetworksCount;
}

Configuration* Configuration::setWifiNetworksCount( unsigned short wifiNetworksCount ){
    this->wifiNetworksCount = wifiNetworksCount;
    return this;
}

int Configuration::getSensorPin(){
    return this->sensorPin;
}


Configuration* Configuration::setSensorPin( int sensorPin ){
    this->sensorPin = sensorPin;
    return this;
}


int Configuration::getPumpPin(){
    return this->pumpPin;
}


Configuration* Configuration::setPumpPin( int pumpPin ){
    this->pumpPin = pumpPin;
    return this;
}


int Configuration::getCompletelyWetMeasure(){
    return this->completelyWetMeasure;
}


Configuration* Configuration::setCompletelyWetMeasure( int completelyWetMeasure ){
    this->completelyWetMeasure = completelyWetMeasure;
    return this;
}


int Configuration::getCompletelyDryMeasure(){
    return this->completelyDryMeasure;
}


Configuration* Configuration::setCompletelyDryMeasure( int completelyDryMeasure ){
    this->completelyDryMeasure = completelyDryMeasure;
    return this;
}


int Configuration::getHumidityToWater(){
    return this->humidityToWater;
}


Configuration* Configuration::setHumidityToWater( int humidityToWater ){
    this->humidityToWater = humidityToWater;
    return this;
}


unsigned int Configuration::getMeasureTime(){
    return this->measureTime;
}


Configuration* Configuration::setMeasureTime( unsigned int measureTime ){
    this->measureTime = measureTime;
    return this;
}


unsigned int Configuration::getReadTime(){
    return this->readTime;
}


Configuration* Configuration::setReadTime( unsigned int readTime ){
    this->readTime = readTime;
    return this;
}