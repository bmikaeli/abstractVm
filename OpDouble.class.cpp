#include "OpDouble.class.hpp"

OpDouble::OpDouble(std::string value) {
    this->value = value;
    this->type = Double;
}

OpDouble::~OpDouble() {
}

int OpDouble::getPrecision() const {
    return Double;
}

eOperandType OpDouble::getType() const {
    return this->type;
}

std::string const &OpDouble::toString() const {
    return this->value;
}

IOperand const *OpDouble::operator+(IOperand const &rhs) const {
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

IOperand const *OpDouble::operator%(IOperand const &rhs) const {
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

IOperand const *OpDouble::operator*(IOperand const &rhs) const {
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

IOperand const *OpDouble::operator-(IOperand const &rhs) const {
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

IOperand const *OpDouble::operator/(IOperand const &rhs) const {
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
