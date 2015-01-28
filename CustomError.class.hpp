#ifndef CUSTOM_ERROR_HPP
#define CUSTOM_ERROR_HPP

#include <iostream>

class CustomError {
public:
    class NotEnoughOperand : public std::exception{
        virtual const char *what() const throw()
        {
            return "There is not enought operands to execute the operation.";
        }
    };
    class UnknowOperand : public std::exception{
        virtual const char *what() const throw()
        {
            return "Unknown type of input.";
        }
    };
    class EmptyStack : public std::exception{
        virtual const char *what() const throw()
        {
            return "The Stack is empty. Cannot execute";
        }
    };
    class WrongAssert : public std::exception{
        virtual const char *what() const throw()
        {
            return "The Assert instruction has failed.";
        }
    };
};

#endif