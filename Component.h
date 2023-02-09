#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <memory>

class Sensor;
class Location;

class Component {


public:

    //virtual void addChild(std::shared_ptr<Component> componentchild)=0;
    virtual void trigger()=0;
    //virtual void activate(bool activation)=0;

    virtual void operator++()=0;
    virtual void operator--()=0;

    virtual std::vector<std::shared_ptr<Sensor>> getSensors()=0;
    virtual std::vector<std::shared_ptr<Location>> getLocations()=0;
};

#endif
