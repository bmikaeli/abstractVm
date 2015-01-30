#include "OpInt8.class.hpp"

OpInt8::OpInt8(std::string value) {
    this->value = value;
    this->type = Int8;
}

OpInt8::~OpInt8() {
}

int OpInt8::getPrecision() const {
    return Int8;
}

eOperandType OpInt8::getType() const {
    return this->type;
}

std::string const &OpInt8::toString() const {
    return this->value;
}

IOperand const *OpInt8::operator+(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result = atoi(this->toString().data()) + atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);

}

IOperand const *OpInt8::operator%(IOperand const &rhs) const {

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

IOperand const *OpInt8::operator*(IOperand const &rhs) const {

    Comands *cmd = new Comands();

    double result = atoi(this->toString().data()) * atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt8::operator-(IOperand const &rhs) const {

    Comands *cmd = new Comands();

    double result = atoi(this->toString().data()) - atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpInt8::operator/(IOperand const &rhs) const {


    Comands *cmd = new Comands();

    double result = atoi(this->toString().data()) / atoi(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}
