#include "OpInt16.class.hpp"

OpInt16::OpInt16(std::string value) {
    this->value = value;
    this->type = Int16;
}
OpInt16::~OpInt16() {
}

int OpInt16::getPrecision() const {
    return 12;
}
eOperandType OpInt16::getType() const {
    return this->type;
}
std::string const & OpInt16::toString() const {
    return this->value;
}
IOperand const* OpInt16::operator+(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt16::operator%(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt16::operator*(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt16::operator-(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt16::operator/(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
