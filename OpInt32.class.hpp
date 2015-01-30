#ifndef INT32_CLASS_HPP
#define INT32_CLASS_HPP

#include "IOperand.class.hpp"
#include "Comands.class.hpp"

class OpInt32 : public IOperand {
public:
    OpInt32(std::string value);

    ~OpInt32();

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