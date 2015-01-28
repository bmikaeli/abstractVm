#include "OpInt32.class.hpp"

OpInt32::OpInt32(std::string value) {
    this->value = value;
    this->type = Int32;
}
OpInt32::~OpInt32() {
}

int OpInt32::getPrecision() const {
    return 12;
}
eOperandType OpInt32::getType() const {
    return this->type;
}
std::string const & OpInt32::toString() const {
    return this->value;
}
IOperand const* OpInt32::operator+(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt32::operator%(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt32::operator*(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt32::operator-(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt32::operator/(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
