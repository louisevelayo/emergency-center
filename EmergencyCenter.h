#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H
#include "Component.h"
#include "Location.h"
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "Sensor.h"
#include "MotionSensor.h"
#include "GasSensor.h"
#include "SmokeSensor.h"
#include "Sensor.h"
#include "Component.h"
#include "Location.h"
#include "activation.h"
#include "Alarm.h"
#include "Contact.h"
#include "mail.h"

//class Sensor{};

class EmergencyCenter {

protected:
    EmergencyCenter();
    static EmergencyCenter* ecInstance;

private:
    std::vector<std::unique_ptr<Sensor>> sensorList;
    EmergencyCenter* instance;
    std::vector<std::shared_ptr<Component>> components;

public:  



	void setSensorList(Sensor sensorList[]);

    void addSensor(Sensor sensor_to_add);

    void removeSensor(int index, std::vector<std::shared_ptr<Sensor>> listOfSensors);

    void addChildToParent(std::shared_ptr<Location> l, std::shared_ptr<Component> c);
    void add(std::shared_ptr<Location> location);

    static EmergencyCenter* getInstance();

    std::vector<std::shared_ptr<Location>> getAllLocations();
    std::vector<std::shared_ptr<Sensor>> getSensorList();
    std::vector<std::shared_ptr<Sensor>> getAllByVendor(std::string vendor, std::vector<std::shared_ptr<Sensor>>);
    std::vector<std::shared_ptr<Sensor>> getAllByType(std::string type, std::vector<std::shared_ptr<Sensor>>);
    std::vector<std::shared_ptr<Sensor>> getAllByLocation(std::string location, std::vector<std::shared_ptr<Sensor>>);
    std::vector<std::shared_ptr<Location>> getLocationsByLocations(std::string location, std::vector<std::shared_ptr<Location>> locations);
    std::vector<std::shared_ptr<Sensor>> getAllByLocationPointer(std::shared_ptr<Location> locationPointer);

    std::vector<std::shared_ptr<Sensor>> orderById(std::vector<std::shared_ptr<Sensor>> vectorToSort);
    std::vector<std::shared_ptr<Sensor>> orderByVendor(std::vector<std::shared_ptr<Sensor>> vectorToSort);
    std::vector<std::shared_ptr<Sensor>> orderByLocation(std::vector<std::shared_ptr<Sensor>> vectorToSort);

    void overviewSensorsInVector(std::vector<std::shared_ptr<Sensor>>);
    void overviewLocationsInVector(std::vector<std::shared_ptr<Location>> vector);
    void overviewSensors();
    void overviewByVendor(std::string vendor);
    void overviewByType(std::string type);
    void overviewByLocation(std::string location);
    void overviewLocations();
    void overviewLocationsByLocation(std::string location);
    void overviewByLocationPointer(std::shared_ptr<Location> locationPointer);

    void activateAllInVector(std::vector<std::shared_ptr<Sensor>> sensorsToActivate);
    void activateAllComponents();
    void activateAllByVendor(std::string vendor);
    void activateAllByType(std::string type);
    void activateAllByLocation(std::string location);
    void activateAllByLocationPointer(std::shared_ptr<Location> locationPointer);
    void activateSpecificSensor(int sensorID);

    void deActivateAllInVector(std::vector<std::shared_ptr<Sensor>>);
    void deActivateAllComponents();
    void deActivateAllByVendor(std::string vendor);
    void deActivateAllByType(std::string type);
    void deActivateAllByLocation(std::string location);
    void deActivateAllByLocationPointer(std::shared_ptr<Location> locationPointer);
    void deActivateSpecificSensor(int sensorID);

    void testAllComponentsInVector(std::vector<std::shared_ptr<Sensor>> sensorsToTest);
    void testAllComponents();
    void testAllByVendor(std::string vendor);
    void testAllByType(std::string type);
    void testAllByLocation(std::string location);
    void testAllByLocationPointer(std::shared_ptr<Location> locationPointer);
    void testSpecificSensor(int sensorID);

};

#endif
