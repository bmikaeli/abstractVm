#include "OpDouble.class.hpp"

OpDouble::OpDouble(std::string value) {
    this->value = value;
    this->type = Double;
}
OpDouble::~OpDouble() {
}

int OpDouble::getPrecision() const {
    return 12;
}
eOperandType OpDouble::getType() const {
    return this->type;
}
std::string const & OpDouble::toString() const {
    return this->value;
}
IOperand const* OpDouble::operator+(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpDouble::operator%(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpDouble::operator*(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpDouble::operator-(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
IOperand const* OpDouble::operator/(IOperand const &rhs) const {
    (void)rhs;
    return this;
}
