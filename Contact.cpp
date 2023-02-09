#include "Contact.h"




Contact::Contact(std::string mes)
    {
    message = "A message is sent to " + mes;
    }


void Contact::execute(){
    std::cout << message << std::endl;
}

