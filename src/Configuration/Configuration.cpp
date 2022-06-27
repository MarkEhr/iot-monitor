#include "Configuration.h"


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