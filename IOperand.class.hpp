#ifndef IOPERAND_H
#define IOPERAND_H

#include <iostream>
enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
};

class IOperand {

public:


    virtual int getPrecision(void) const = 0;

    virtual eOperandType getType(void) const = 0;

    IOperand const *createOperand(eOperandType type, std::string const &value) const;

    virtual IOperand const *operator+(IOperand const &rhs) const = 0;

    virtual IOperand const *operator-(IOperand const &rhs) const = 0;

    virtual IOperand const *operator*(IOperand const &rhs) const = 0;

    virtual IOperand const *operator/(IOperand const &rhs) const = 0;

    virtual IOperand const *operator%(IOperand const &rhs) const = 0;

    virtual std::string const &toString(void) const = 0;

    virtual~IOperand(void) {
    }
};

#endif