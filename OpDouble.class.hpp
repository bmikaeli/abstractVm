#ifndef DOUBLE_CLASS_HPP
#define DOUBLE_CLASS_HPP

#include "IOperand.class.hpp"
#include "Comands.class.hpp"

class OpDouble : public IOperand {
public:
    OpDouble(std::string value);

    ~OpDouble();

    int getPrecision(void) const;

    eOperandType getType(void) const;

    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    IOperand const *operator%(IOperand const &rhs) const;

    std::string const &toString(void) const;

private :
    std::string value;
    eOperandType type;
};

#endif