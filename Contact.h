#ifndef CONTACT_H
#define CONTACT_H
#include "Strategy.h"
#include <iostream>
#include <string>
#include <vector>
class Contact : public Strategy {
    using Strategy::Strategy;

private:
    std::string message;

public:
    Contact(std::string);

    void execute() override;

    //void setMessage(std::string) override;

};

#endif

