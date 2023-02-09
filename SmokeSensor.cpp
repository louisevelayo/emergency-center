#include "SmokeSensor.h"

SmokeSensor::SmokeSensor(std::string ven, std::string loc)
    :Sensor{ven, loc}
{
  setSensorType("Smoke Sensor");

  std::cout << "Smoke Sensor created" << std::endl;
}
