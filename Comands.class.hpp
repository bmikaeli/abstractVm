#ifndef COMAND_CLASS_HPP
#define COMAND_CLASS_HPP

#include "IOperand.class.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include "OpInt16.class.hpp"
#include "OpInt8.class.hpp"
#include "OpInt32.class.hpp"
#include "OpFloat.class.hpp"
#include "OpDouble.class.hpp"

#include "CustomError.class.hpp"

class Comands {

public:
    Comands();

    ~Comands();

    void parse(std::string input);

    void exec_add();

    void exec_sub();

    void exec_mod();

    void exec_div();

    void exec_mul();

    void exec_print() const;

    void exec_push(std::string input);

    void exec_assert(std::string input);

    void exec_dump() const;

    void exec_pop();

    IOperand const *createOperand(eOperandType type, std::string const &value) const;

private:

    IOperand const *createInt8(std::string const &value) const;

    IOperand const *createInt16(std::string const &value) const;

    IOperand const *createInt32(std::string const &value) const;

    IOperand const *createFloat(std::string const &value) const;

    IOperand const *createDouble(std::string const &value) const;

    std::vector<const IOperand *> container;
};

#endif