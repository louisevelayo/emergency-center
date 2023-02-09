#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
#include <vector>
#include "Component.h"
#include "Sensor.h"
#include <memory>

class Location : public Component, public std::enable_shared_from_this<Location>
{

private:
    std::string name;
    std::vector<std::shared_ptr<Component>> components;

public:
    Location();
    Location(std::string name);
    Location(std::string nam, std::vector<std::shared_ptr<Component>> &components);
    std::string getName() const;
    void setName(std::string Name);
    void trigger() override;

    void add(std::shared_ptr<Component> componentchild);
    //void activate(bool activation) override;

    void operator++() override;
    void operator--() override;

    std::vector<std::shared_ptr<Location>> getLocations() override;
    std::vector<std::shared_ptr<Sensor>> getSensors() override;

    void printSensors();
    void printLocations();

};

#endif
