#ifndef INT16_CLASS_HPP
#define INT16_CLASS_HPP

#include "IOperand.class.hpp"

class OpInt16 : public IOperand {
public:
    OpInt16(std::string value);

    ~OpInt16();

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