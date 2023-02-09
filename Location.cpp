#include "Location.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

Location::Location(){

}

Location::Location(std::string name)
    : name{name}
{
    std::cout <<"location created"<<std::endl;
}

Location::Location(std::string nam, std::vector<std::shared_ptr<Component>> &components)
    : name{nam}
{
    this->components = components;
}

std::string Location::getName() const{
    return this->name;
}

/*
 * Louise changes the method below to add a component instead of sensor.
 * Adding a component allows us to build a tree structure. Location shouldn't care if more
 * locations or sensors are added, thus we need to generalize to component
 */
void Location::add(std::shared_ptr<Component> component) {
    components.push_back(component);
}

void Location::trigger(){
    for(long unsigned int i=0; i<this->components.size(); i++){
        components.at(i)->trigger();
    }
}


std::vector<std::shared_ptr<Location>> Location::getLocations() {
    std::vector<std::shared_ptr<Location>> locations;
    for(long unsigned int i=0; i<this->components.size(); i++){
        std::vector<std::shared_ptr<Location>> Mylocation = components.at(i)->getLocations();
        locations.insert(locations.end(), Mylocation.begin(), Mylocation.end());
    }
    locations.push_back(shared_from_this());
    return locations;
}
/*
void Location::trigger(bool trigger_variable){
    for(long unsigned int i=0; i < components.size(); i++){
       (components[i])->trigger(trigger_variable);
    };
}
*/
std::vector<std::shared_ptr<Sensor>> Location::getSensors(){
    std::vector<std::shared_ptr<Sensor>> sensorList;
    for(long unsigned int i=0; i<this->components.size(); i++){
        std::vector<std::shared_ptr<Sensor>> Mysensor = components.at(i)->getSensors();
        sensorList.insert(sensorList.end(), Mysensor.begin(), Mysensor.end());
    }
    return sensorList;
}

void Location::printSensors(){
    std::vector<std::shared_ptr<Sensor>> sensorList = this->getSensors();
    for(auto & s : sensorList){
        std::cout << s << std::endl;
    }
}

void Location::printLocations(){
    std::vector<std::shared_ptr<Location>> locationList = this->getLocations();
    for(auto & s : locationList){
        std::cout << s << std::endl;
    }
}

void Location::operator++(){
    for(int i=0; i < (int)components.size(); i++){
        (components.at(i))->operator++();
    }
    return;
}

void Location::operator--(){
    for(int i=0; i < (int)components.size(); i++){
        (components.at(i))->operator--();
    }
    return;
}
