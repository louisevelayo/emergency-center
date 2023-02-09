#include "Sensor.h"
#include "Component.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>

int Sensor::countIDSensor = 0;

Sensor::Sensor(std::string ven, std::string loc)
    : vendorName(ven), location(loc)
{    
    this->sensorID =getCountIDSensor();
    incrementCountIDSensor();
    std::cout << "Sensor created with id: "<< this->sensorID << std::endl;
}

std::vector<std::shared_ptr<Strategy>> Sensor::getStrategies() const {
    return this->strategies;
}

void Sensor::addStrategy(std::shared_ptr<Strategy> strategyToAdd) {
    (this->strategies).push_back(strategyToAdd);
}

int Sensor::getSensorID() const {
	return this->sensorID;
}

void Sensor::setSensorType(std::string sensorType){
    this->type = sensorType;
}

bool Sensor::getIsTriggered() const {
	return this->isTriggered;
}

std::string Sensor::getVendorName() const {
    return this->vendorName;
}

std::string Sensor::getSensorLocation() const{
    return this->location;
}

std::string Sensor::getSensorType() const{
    return this->type;
}


bool Sensor::getIsActive() const{
	return this->isActive;
}

//getCountID is used to assign an ID to a sensor.
int Sensor::getCountIDSensor() const{
    return countIDSensor;
}

//incrementCountID increments countID after assigning an ID to a sensor.
void Sensor::incrementCountIDSensor(){
    this->countIDSensor++;
}

void Sensor::trigger(){
    auto strategyList =getStrategies();
    for(unsigned long long i =0; i<strategyList.size(); i++ ){
        strategyList.at(i)->execute();
    }
}

std::vector<std::shared_ptr<Sensor>> Sensor::getSensors(){
    std::vector<std::shared_ptr<Sensor>> mySensor;
    mySensor.push_back(shared_from_this());
    return mySensor;

}
std::vector<std::shared_ptr<Location>> Sensor::getLocations(){
    std::vector<std::shared_ptr<Location>> nothing;
    return nothing;
}


//operator overloading of ++ to activate Sensor.
void Sensor::operator++(){
    this->isActive = 1;
}

//operator overloading of -- to deactivate Sensor.
void Sensor::operator--(){
    this->isActive = 0;
}

//operator overloading of << to display info of Sensor.
std::ostream &operator<<(std::ostream &os, const Sensor &s){

    os << "Sensor ID: " << s.getSensorID();
    os << " - Vendor: " << s.getVendorName();
    os << " - Location " << s.getSensorLocation();
    os << " - Sensor type: " << s.getSensorType();
    os << " - Is activated: " << std::boolalpha << s.getIsActive();
    return os;
    }



