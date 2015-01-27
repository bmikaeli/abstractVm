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

void Comands::exec_add() {
    int size = this->container.size();
    if (size < 2) {
        throw std::exception();
    }
//    const IOperand *tmp1 = this->container[size];
//    const IOperand *tmp2 = this->container[size - 1];

    this->container.pop_back();
    this->container.pop_back();
//    this->container.push_back(tmp1 + tmp2);
}

void Comands::exec_dump() {
    std::vector<const IOperand *>::iterator it;

    for (it = this->container.begin(); it != this->container.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

//IOperand const *Comands::createFloat(const std::string &value) const {
//    return new Float();
//}

//IOperand const *Comands::createInt8(const std::string &value) const {
//    Int8 * ret = NULL;
//    (void)value;
//  ret = new Int8(value);
//    return ret;
//}
//
//IOperand const *Comands::createInt16(const std::string &value) const {
//}
//
//IOperand const *Comands::createInt32(const std::string &value) const {
//}

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
    return this->createDouble(value);
}

void Comands::exec_push(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, "(");

    std::string nb = split(sp[1], ")")[0].data();

    std::string type = sp[0];
    const IOperand *to_add;
    if (type == "int32") {
        to_add = this->createOperand(Int32, nb);
    }
    else if (type == "int8") {
        to_add = this->createOperand(Int8, nb);
    }
    else if (type == "int16") {
        to_add = this->createOperand(Int16, nb);
    }
    else if (type == "Double") {
        to_add = this->createOperand(Double, nb);
    }
    else if (type == "Float") {
        to_add = this->createOperand(Float, nb);
    }
    else {
        throw std::exception();
    }
    this->container.push_back(to_add);

}

void Comands::exec_pop() {
    if (this->container.size())
        this->container.erase(this->container.begin());
    else
        throw std::exception();
}


void Comands::parse(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, " ");

    if (input == "exit")
        exit(1);
    else if (input == "add") {
        exec_add();
    }
    else if (sp[0] == "push") {
        exec_push(sp[1]);
    }
    else if (input == "dump")
        exec_dump();
    else if (input == "pop")
        exec_pop();
    else
        std::cout << "unknown cmd" << std::endl;
}