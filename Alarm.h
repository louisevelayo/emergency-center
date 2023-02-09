#ifndef ALARM_H
#define ALARM_H
#include "Strategy.h"
#include <iostream>
#include <string>
#include <vector>

class Alarm : public Strategy, public std::enable_shared_from_this<Alarm>{
    using Strategy::Strategy;

private:
    std::string message;

public:
    Alarm(std::string);

    void execute() override;

    //void setMessage(std::string) override;

};

#endif

