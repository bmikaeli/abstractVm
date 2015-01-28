#include "Comands.class.hpp"

std::vector <std::string> split(std::string input, const char *delimiter) {
    char *pch;
    char *line;

    line = const_cast<char *>(input.c_str());

    std::vector <std::string> array;

    pch = strtok(line, delimiter);
    while (pch != NULL) {
        array.push_back(pch);
        pch = strtok(NULL, delimiter);
    }
    return array;
}

Comands::Comands() {
}

Comands::~Comands() {
}

#include <string>
//#include <ostream>
#include <sstream>

void Comands::exec_add() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it0;
    std::vector<const IOperand *>::iterator it1;

    it1 = this->container.end();
    it1--;
    it0 = it1;
    it0--;

    double result;
    result = atof((*it0)->toString().data()) + atof((*it1)->toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    this->container.push_back(createDouble(s));
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
}

void Comands::exec_sub() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it0;
    std::vector<const IOperand *>::iterator it1;

    it1 = this->container.end();
    it1--;
    it0 = it1;
    it0--;

    double result;
    result = atof((*it0)->toString().data()) - atof((*it1)->toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    this->container.push_back(createDouble(s));
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
}

void Comands::exec_mul() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it0;
    std::vector<const IOperand *>::iterator it1;

    it1 = this->container.end();
    it1--;
    it0 = it1;
    it0--;

    double result;
    result = atof((*it0)->toString().data()) * atof((*it1)->toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    this->container.push_back(createDouble(s));
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
}
void Comands::exec_div() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it0;
    std::vector<const IOperand *>::iterator it1;

    it1 = this->container.end();
    it1--;
    it0 = it1;
    it0--;

    double result;
    result = atof((*it0)->toString().data()) / atof((*it1)->toString().data());

    std::ostringstream ss;
    ss << result;
    std::string s(ss.str());

    this->container.push_back(createDouble(s));
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
}

//void Comands::exec_mod() {
//
//    int size = this->container.size();
//
//    if (size < 2) {
//        throw CustomError::NotEnoughOperand();
//    }
//
//    std::vector<const IOperand *>::iterator it0;
//    std::vector<const IOperand *>::iterator it1;
//
//    it1 = this->container.end();
//    it1--;
//    it0 = it1;
//    it0--;
//
//    double result;
//    result = atof((*it0)->toString().data()) % atof((*it1)->toString().data());
//
//    std::ostringstream ss;
//    ss << result;
//    std::string s(ss.str());
//
//    this->container.push_back(createDouble(s));
//    this->container.erase(this->container.begin());
//    this->container.erase(this->container.begin());
//}


IOperand const *Comands::createFloat(const std::string &value) const {
    const OpFloat *ret = new OpFloat(value);
    return ret;
}

IOperand const *Comands::createDouble(const std::string &value) const {
    const OpDouble *ret = new OpDouble(value);
    return ret;
}

IOperand const *Comands::createInt8(const std::string &value) const {
    const OpInt8 *ret = new OpInt8(value);
    return ret;
}

IOperand const *Comands::createInt16(const std::string &value) const {
    const OpInt16 *ret = new OpInt16(value);
    return ret;
}

IOperand const *Comands::createInt32(const std::string &value) const {
    const OpInt32 *ret = new OpInt32(value);
    return ret;
}

void Comands::exec_dump() {
    std::vector<const IOperand *>::iterator it;
    for (it = this->container.begin(); it != this->container.end(); ++it) {
        std::cout << (*it)->toString() << std::endl;
    }
}

IOperand const *Comands::createOperand(eOperandType type, std::string const &value) const {
    if (type == Int8) {
        return this->createInt8(value);
    }
    if (type == Int16) {
        return this->createInt16(value);

    }
    if (type == Int32) {
        return this->createInt32(value);

    }
    if (type == Float) {
        return this->createFloat(value);

    }
    if (type == Double) {
        return this->createDouble(value);
    }
    throw CustomError::UnknowOperand();
    return this->createDouble(value);
}

void Comands::exec_push(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, "(");

    std::string nb = split(sp[1], ")")[0].data();

    std::string type = sp[0];
    const IOperand *to_add;
    if (type == "int8") {
        to_add = this->createOperand(Int32, nb);
    }
    else if (type == "int16") {
        to_add = this->createOperand(Int8, nb);
    }
    else if (type == "int32") {
        to_add = this->createOperand(Int16, nb);
    }
    else if (type == "double") {
        to_add = this->createOperand(Double, nb);
    }
    else if (type == "float") {
        to_add = this->createOperand(Float, nb);
    }
    else {
        throw CustomError::UnknowOperand();
    }
    this->container.push_back(to_add);

}

void Comands::exec_pop() {
    if (this->container.size())
        this->container.erase(this->container.begin());
    else
        throw CustomError::EmptyStack();
}

void Comands::exec_assert(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, "(");

    std::string nb = split(sp[1], ")")[0].data();

    std::string type = sp[0];

    std::vector<const IOperand *>::iterator ite;
    ite = this->container.end();
    ite--;

    if (type == "int8" && (*ite)->getType() == 0) {
    }
    else if (type == "int16" && (*ite)->getType() == 1) {
    }
    else if (type == "int32" && (*ite)->getType() == 2) {
    }
    else if (type == "float" && (*ite)->getType() == 3) {
    }
    else if (type == "double" && (*ite)->getType() == 4) {
    }
    else {
        throw CustomError::UnknowOperand();
    }

}

void Comands::parse(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, " ");

    if (input == "exit")
        exit(1);
    else if (input == "add") {
        exec_add();
    }
    else if (input == "sub") {
        exec_sub();
    }
    else if (input == "mul") {
        exec_mul();
    }
    else if (input == "div") {
        exec_div();
    }
    else if (input == "mod") {
        exec_add();
    }
    else if (sp[0] == "push") {
        exec_push(sp[1]);
    }
    else if (input == "dump")
        exec_dump();
    else if (input == "pop")
        exec_pop();
    else if (sp[0] == "assert")
        exec_assert(sp[1]);
    else
        std::cout << "unknown cmd" << std::endl;
}