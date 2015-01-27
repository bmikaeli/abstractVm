#ifndef COMAND_CLASS_HPP
#define COMAND_CLASS_HPP

#include <iostream>
#include "IOperand.class.hpp"
#include <vector>

class Comands {

public:
    Comands();

    ~Comands();

private:
    std::vector<const IOperand *> container;
};

#endif