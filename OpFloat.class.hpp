#ifndef FOAT_CLASS_HPP
#define FLOAT_CLASS_HPP

#include "IOperand.class.hpp"

class OpFloat : public IOperand {
public :
    OpFloat(std::string value);

    ~OpFloat();

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