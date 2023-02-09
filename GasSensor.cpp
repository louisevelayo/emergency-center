#include "GasSensor.h"

GasSensor::GasSensor(std::string ven, std::string loc)
    :Sensor{ven, loc}
{
  setSensorType("Gas Sensor");

  std::cout << "Gas Sensor created" << std::endl;
}
