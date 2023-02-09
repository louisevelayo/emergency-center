#include "mail.h"

Mail::Mail(std::string type, std::string rec)
    {
    message = "A " + type + " is sent to  " + rec;
    }

void Mail::execute(){
    std::cout << message << std::endl;
}
