#include "Alarm.h"

Alarm::Alarm(std::string mes)
    {
    message = "The alarm is sounded in " + mes;
    }

void Alarm::execute(){
    std::cout << message << std::endl;
}




