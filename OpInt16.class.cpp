#include "OpInt16.class.hpp"

OpInt16::OpInt16(std::string value) {
    this->value = value;
    this->type = Int16;
}

OpInt16::~OpInt16() {
}

int OpInt16::getPrecision() const {
    return Int16;
}

eOperandType OpInt16::getType() const {
    return this->type;
}

std::string const &OpInt16::toString() const {
    return this->value;
}

IOperand const *OpInt16::operator+(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atoi(this->toString().data()) + atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt16::operator%(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = fmod(atoi(this->toString().data()), atoi(rhs.toString().data()));


    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt16::operator*(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    int result;
    result = atoi(this->toString().data()) * atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt16::operator-(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atoi(this->toString().data()) - atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt16::operator/(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atoi(this->toString().data()) / atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}
