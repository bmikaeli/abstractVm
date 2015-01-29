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
    (void) rhs;
    return this;
}

IOperand const *OpFloat::operator%(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *OpFloat::operator*(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *OpFloat::operator-(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *OpFloat::operator/(IOperand const &rhs) const {
    (void) rhs;
    return this;
}
