#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Component.h"
#include <memory>
#include <stdexcept>
#include "Strategy.h"
#include "mail.h"

class Sensor : public Component, public std::enable_shared_from_this<Sensor>
{
private:

	int sensorID;
    std::string vendorName;
    std::string location;
    std::string type;
    bool isTriggered{false};
    bool isActive{false};
    std::vector<std::shared_ptr<Strategy>> strategies;
    static int countIDSensor;

public:

    Sensor(std::string, std::string);

    std::vector<std::shared_ptr<Strategy>> getStrategies() const;

    void addStrategy(std::shared_ptr<Strategy> strategyToAdd);
    void setSensorType(std::string sensorType);

    int getSensorID() const;
    bool getIsTriggered() const;
    std::string getVendorName() const;
    bool getIsActive() const;
    bool getIsPowered() const;
    std::string getSensorType() const;
    std::string getSensorLocation() const;

    int getCountIDSensor() const; //getCountID is used to assign an ID to a sensor.
    void incrementCountIDSensor();    //incrementCountID increments countID after assigning an ID to a sensor.

    void operator++() override; //prefix
    void operator--() override; //prefix

    void trigger() override;

    std::vector<std::shared_ptr<Sensor>> getSensors() override;
    std::vector<std::shared_ptr<Location>> getLocations() override;
};

//operator overloading of << to display info of Sensor.
std::ostream &operator<<(std::ostream &os, const Sensor &s);


#endif
