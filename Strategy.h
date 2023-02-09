#ifndef STRATEGY_H
#define STRATEGY_H
#include <string>
#include <vector>
#include <memory>

class Sensor;
class Alarm;
class Contact;
class Mail;



//some change to test
class Strategy: public std::enable_shared_from_this<Strategy> {

private:


public:


    void virtual execute() = 0;

    //void virtual setMessage(std::string) = 0;

};

#endif
