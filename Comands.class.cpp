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

bool isNumeric(const std::string &input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (isdigit(input[i]))
            continue;
        else if (input[i] == '.')
            continue;
        else if (input[i] == '-')
            continue;
        else
            return false;
    }
    return true;
}

bool isFloat(const std::string &input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (input[i] == '.')
            return true;
    }
    return false;
}

void Comands::exec_add() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it1;
    std::vector<const IOperand *>::iterator it2;

    it1 = this->container.begin();
    it2 = it1;
    it2++;

    IOperand const *e = **it1 + **it2;
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
    this->container.insert(this->container.begin(), e);
}

void Comands::exec_sub() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it1;
    std::vector<const IOperand *>::iterator it2;

    it1 = this->container.begin();
    it2 = it1;
    it2++;

    IOperand const *e = **it1 - **it2;
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
    this->container.insert(this->container.begin(), e);
}

void Comands::exec_mul() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it1;
    std::vector<const IOperand *>::iterator it2;

    it1 = this->container.begin();
    it2 = it1;
    it2++;

    IOperand const *e = **it1 * **it2;
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
    this->container.insert(this->container.begin(), e);
}

void Comands::exec_div() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }
    std::vector<const IOperand *>::iterator it2;
    std::vector<const IOperand *>::iterator it1;

    it1 = this->container.begin();
    it2 = it1;
    it2++;

    if(atof(this->container[1]->toString().data()) == 0)
    {
        throw CustomError::DivisionByZero();
    }

    IOperand const *e = **it1 / **it2;
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
    this->container.insert(this->container.begin(), e);
}

void Comands::exec_mod() {

    int size = this->container.size();

    if (size < 2) {
        throw CustomError::NotEnoughOperand();
    }

    std::vector<const IOperand *>::iterator it1;
    std::vector<const IOperand *>::iterator it2;

    it1 = this->container.begin();
    it2 = it1;
    it2++;

    if(atof(this->container[1]->toString().data()) == 0)
    {
        throw CustomError::DivisionByZero();
    }
    IOperand const *e = **it1 % **it2;
    this->container.erase(this->container.begin());
    this->container.erase(this->container.begin());
    this->container.insert(this->container.begin(), e);
}


IOperand const *Comands::createFloat(const std::string &value) const {
    const OpFloat *ret = new OpFloat(value);
    return ret;
}

IOperand const *Comands::createDouble(const std::string &value) const {
    const OpDouble *ret = new OpDouble(value);
    return ret;
}

IOperand const *Comands::createInt8(const std::string &value) const {
    if (atof(value.data()) > 127) {
        throw CustomError::OverFlow();
    }
    else if (atof(value.data()) < -128) {
        throw CustomError::UnderFlow();
    }
    else {
        const OpInt8 *ret = new OpInt8(value);
        return ret;
    }
}

IOperand const *Comands::createInt16(const std::string &value) const {
    if (atof(value.data()) > 32767) {
        throw CustomError::OverFlow();
    }
    if (atof(value.data()) < -32768) {
        throw CustomError::UnderFlow();
    }
    const OpInt16 *ret = new OpInt16(value);
    return ret;
}

IOperand const *Comands::createInt32(const std::string &value) const {
    if (atof(value.data()) >= 2147483647) {
        throw CustomError::OverFlow();
    }
    if (atof(value.data()) <= -2147483648) {
        throw CustomError::UnderFlow();
    }
    const OpInt32 *ret = new OpInt32(value);
    return ret;
}


void Comands::exec_dump() const {
    std::vector<const IOperand *> tmp = this->container;

    std::vector<const IOperand *>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); ++it) {
        std::cout << (*it)->toString() << std::endl;
    }
}

IOperand const *Comands::createOperand(eOperandType type, std::string const &value) const {

    if (isNumeric(value)) {

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
        }
        throw CustomError::UnknowOperand();
    }
    else {
        throw CustomError::NotNum();
    }
}

void Comands::exec_push(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, "(");

    std::string nb = split(sp[1], ")")[0].data();

    std::string type = sp[0];
    const IOperand *to_add;

    if (type == "int8") {
        if(!isFloat(nb))
        {
            to_add = this->createOperand(Int8, nb);
        }
        else
            throw CustomError::FloatingInt();
    }
    else if (type == "int16") {
        if(!isFloat(nb))
        {
            to_add = this->createOperand(Int16, nb);
        }
        else
            throw CustomError::FloatingInt();
    }
    else if (type == "int32") {
        if(!isFloat(nb))
        {
            to_add = this->createOperand(Int32, nb);
        }
        else
            throw CustomError::FloatingInt();
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
    this->container.insert(this->container.begin(), to_add);

}

void Comands::exec_print() const {
    if (this->container[0]->getPrecision() != Int8) {
        throw CustomError::NonPrintable();
    }
    else {
        char c = atoi(this->container[0]->toString().data());
        std::cout << c << std::endl;
    }
}

void Comands::exec_pop() {
    if (this->container.size())
        this->container.erase(this->container.begin());
    else
        throw CustomError::EmptyStack();
}

void Comands::exec_assert(std::string input) {
    if (!this->container.empty()) {
        std::vector <std::string> sp;

        sp = split(input, "(");

        std::string nb = split(sp[1], ")")[0].data();

        std::string type = sp[0];

        std::vector<const IOperand *>::iterator ite;
        ite = this->container.begin();

        if (type == "int8" && (*ite)->getType() == Int8) {
            if (!(nb == (*ite)->toString()))
                throw CustomError::WrongAssert();
        }
        else if (type == "int16" && (*ite)->getType() == Int16) {
            if (!(nb == (*ite)->toString()))
                throw CustomError::WrongAssert();
        }
        else if (type == "int32" && (*ite)->getType() == Int32) {
            if (!(nb == (*ite)->toString()))
                throw CustomError::WrongAssert();
        }
        else if (type == "float" && (*ite)->getType() == Float) {
            if (!(nb == (*ite)->toString()))
                throw CustomError::WrongAssert();
        }
        else if (type == "double" && (*ite)->getType() == Double) {
            if (!(nb == (*ite)->toString()))
                throw CustomError::WrongAssert();
        }
        else {
            throw CustomError::WrongAssertInstruction();
        }
    } else
        throw CustomError::EmptyStack();
}

IOperand const *Comands::createInt8Bis(std::string input) {
    return this->createInt8(input);
}

IOperand const *Comands::createInt16Bis(std::string input) {
    return this->createInt16(input);
}

IOperand const *Comands::createInt32Bis(std::string input) {
    return this->createInt32(input);
}

IOperand const* Comands::createFloatBis(std::string input) {
    return this->createFloat(input);
}
IOperand const *Comands::createDoubleBis(std::string input) {
    return this->createDouble(input);
}

void Comands::parse(std::string input) {
    std::vector <std::string> sp;

    sp = split(input, " ");

    if (!sp.empty()) {
        if (sp[0][0] != ';') {
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
                exec_mod();
            }
            else if (input == "print") {
                exec_print();
            }
            else if (sp[0] == "push") {
                if (sp.size() == 2)
                    exec_push(sp[1]);
                else
                    throw CustomError::WrongPush();
            }
            else if (input == "dump")
                exec_dump();
            else if (input == "pop")
                exec_pop();
            else if (sp[0] == "assert") {
                if (sp.size() == 2)
                    exec_assert(sp[1]);
                else
                    throw CustomError::WrongAssertInstruction();
            }
            else
                std::cout << "unknown cmd" << std::endl;
        }
    }
    else {
        throw CustomError::EmptyInput();
    }


}