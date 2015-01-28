#include "IOperand.class.hpp"
#include "Comands.class.hpp"

int main() {
    Comands cmd;
    for (std::string line; std::getline(std::cin, line);) {
        try {
            cmd.parse(line);
        }
        catch (std::exception &e) {
            std::cout << "Error : " << e.what() << std::endl;
            exit(1);
        }
    }
    return (0);
}