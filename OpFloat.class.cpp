#include "OpFloat.class.hpp"

OpFloat::OpFloat(std::string value) {
    this->value = value;
    this->type = Float;
}

OpFloat::~OpFloat() {
}

int OpFloat::getPrecision() const {
    return Float;
}

eOperandType OpFloat::getType() const {
    return this->type;
}

std::string const &OpFloat::toString() const {
    return this->value;
}

IOperand const *OpFloat::operator+(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atof(this->toString().data()) + atof(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpFloat::operator%(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = fmod(atof(this->toString().data()), atof(rhs.toString().data()));

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpFloat::operator*(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atof(this->toString().data()) * atof(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpFloat::operator-(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atof(this->toString().data()) - atof(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}

IOperand const *OpFloat::operator/(IOperand const &rhs) const {
    Comands *cmd = new Comands();

    double result;
    result = atof(this->toString().data()) / atof(rhs.toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    if (rhs.getPrecision() > this->getPrecision())
        return cmd->createOperand(rhs.getType(), s);
    else
        return cmd->createOperand(this->getType(), s);
}
