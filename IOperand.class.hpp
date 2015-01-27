#ifndef IOPERAND_H
#define IOPERAND_H

#include <iostream>

class IOperand {

public:
    enum eOperandType {
        Int8,
        Int16,
        Int32,
        Float,
        Double,
    };

    virtual int getPrecision(void) const = 0;

    virtual eOperandType getType(void) const = 0;

    virtual IOperand const *operator+(IOperand const &rhs) const = 0;

    virtual IOperand const *operator-(IOperand const &rhs) const = 0;

    virtual IOperand const *operator*(IOperand const &rhs) const = 0;

    virtual IOperand const *operator/(IOperand const &rhs) const = 0;

    virtual IOperand const *operator%(IOperand const &rhs) const = 0;

    virtual std::string const &toString(void) const = 0;

    virtual~IOperand(void) {
    }

private :
    IOperand const *createInt8(std::string const &value) const;

    IOperand const *createInt16(std::string const &value) const;

    IOperand const *createInt32(std::string const &value) const;

    IOperand const *createFloat(std::string const &value) const;

    IOperand const *createDouble(std::string const &value) const;
};

#endif