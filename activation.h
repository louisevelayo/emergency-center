#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "Strategy.h"
#include <iostream>
#include <string>
#include <vector>

#include "Strategy.h"

class Activation : public Strategy
{
private:
    std::string message;

public:
    Activation(std::string);

    void execute() override;
};

#endif // ACTIVATION_H
