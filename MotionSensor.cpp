#include "MotionSensor.h"

MotionSensor::MotionSensor(std::string ven, std::string loc)
    :Sensor{ven, loc}
{
  setSensorType("Motion Sensor");

  std::cout << "Motion Sensor created" << std::endl;
}

MotionSensor::MotionSensor(std::string ven, std::string loc, float st, float en)
    :Sensor{ven, loc}, start{st}, end{en}
{
  setSensorType("Motion Sensor");

  std::cout << "Motion Sensor created" << std::endl;
}


time_t MotionSensor::getStart() const{
    return start;
}

void MotionSensor::setStart(time_t st) {
    this->start = st;
}

time_t MotionSensor::getEnd() const{
    return end;
}

void MotionSensor::setEnd(time_t en) {
    this->end = en;
}



void MotionSensor::triggerActivity() {
    // TODO - implement MotionSensor::triggerActivity
	throw "Not yet implemented";
}
