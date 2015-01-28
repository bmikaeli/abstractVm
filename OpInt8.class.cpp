#include "OpInt8.class.hpp"

OpInt8::OpInt8(std::string value) {
    this->value = value;
    this->type = Int8;
}
OpInt8::~OpInt8() {
}

int OpInt8::getPrecision() const {
    return 12;
}
eOperandType OpInt8::getType() const {
    return this->type;
}
std::string const & OpInt8::toString() const {
    return this->value;
}
IOperand const* OpInt8::operator+(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt8::operator%(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt8::operator*(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt8::operator-(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpInt8::operator/(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
