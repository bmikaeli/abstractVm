#ifndef INT8_CLASS_HPP
#define INT8_CLASS_HPP

#include "IOperand.class.hpp"

class OpInt8 : public IOperand {
public:
    OpInt8(std::string value);

    ~OpInt8();

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