#include "OpInt32.class.hpp"

OpInt32::OpInt32(std::string value) {
    this->value = value;
    this->type = Int32;
}

OpInt32::~OpInt32() {
}

int OpInt32::getPrecision() const {
    return Int32;
}

eOperandType OpInt32::getType() const {
    return this->type;
}

std::string const &OpInt32::toString() const {
    return this->value;
}

IOperand const *OpInt32::operator+(IOperand const &rhs) const {
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

IOperand const *OpInt32::operator%(IOperand const &rhs) const {
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

IOperand const *OpInt32::operator*(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atoi(this->toString().data()) * atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt32::operator-(IOperand const &rhs) const {
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

IOperand const *OpInt32::operator/(IOperand const &rhs) const {
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
