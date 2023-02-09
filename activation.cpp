#include "activation.h"
#include <ostream>


Activation::Activation(std::string mes)
{
    message = "Activated " + mes;
}

void Activation::execute(){
    std::cout << message << std::endl;
}

