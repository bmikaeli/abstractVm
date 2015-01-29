#include "IOperand.class.hpp"
#include "Comands.class.hpp"
#include <fstream>
#include <sstream>
#include <string>

int main(int ac, char **av) {
    Comands cmd;
    int i = 1;

    if (ac == 1) {
        for (std::string line; std::getline(std::cin, line); i++) {
            try {
                cmd.parse(line);
            }
            catch (std::exception &e) {
                std::cout << "Line " << i << " : Error : " << e.what() << std::endl;
                exit(1);
            }
        }
    }
    else if (ac == 2) {
        std::ifstream infile(av[1]);
        for (std::string line; std::getline(infile, line); i++) {
            try {
                cmd.parse(line);
            }
            catch (std::exception &e) {
                std::cout << "Line " << i << " : Error : " << e.what() << std::endl;
                exit(1);
            }
        }
        if(i == 0)
        {
            std::cout << "The file is invalid or empty" << std::endl;
        }
    }
    else
        std::cout << "Too many parameters" << std::endl;

    return (0);
}