#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "Sensor.h"

class MotionSensor : public Sensor {
using Sensor::Sensor;

private:
    float start;
    float end;

public:
    MotionSensor(std::string, std::string, float, float);
    MotionSensor(std::string ven, std::string loc);

    time_t getStart() const;
    void setStart(time_t st);

    time_t getEnd() const;
    void setEnd(time_t en);

	void triggerActivity();
};

#endif
