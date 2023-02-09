#ifndef MAIL_H
#define MAIL_H
#include "Strategy.h"
#include <iostream>
#include <string>
#include <vector>

class Mail : public Strategy {
    using Strategy::Strategy;


private:
    std::string message;

public:
    Mail(std::string, std::string);

    void execute() override;

    //void setMessage(std::string, std::string) override;

};
#endif

