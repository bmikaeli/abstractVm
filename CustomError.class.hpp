#ifndef CUSTOM_ERROR_HPP
#define CUSTOM_ERROR_HPP

#include <iostream>

class CustomError {
public:
    class NotEnoughOperand : public std::exception {
        virtual const char *what() const throw() {
            return "There is not enought operands to execute the operation.";
        }
    };

    class UnknowOperand : public std::exception {
        virtual const char *what() const throw() {
            return "Unknown type of input.";
        }
    };

    class EmptyStack : public std::exception {
        virtual const char *what() const throw() {
            return "The Stack is empty. Cannot execute";
        }
    };

    class WrongAssert : public std::exception {
        virtual const char *what() const throw() {
            return "The Assert instruction has failed.";
        }
    };

    class WrongPush : public std::exception {
        virtual const char *what() const throw() {
            return "Wrong push instruction";
        }
    };

    class WrongAssertInstruction : public std::exception {
        virtual const char *what() const throw() {
            return "Wrong assert instruction";
        }
    };

    class EmptyInput : public std::exception {
        virtual const char *what() const throw() {
            return "Empty Input";
        }
    };

    class OverFlow : public std::exception {
        virtual const char *what() const throw() {
            return "OverFlow";
        }
    };

    class UnderFlow : public std::exception {
        virtual const char *what() const throw() {
            return "UnderFlow";
        }
    };

    class NotNum : public std::exception {
        virtual const char *what() const throw() {
            return "the input doesn't only contain digits";
        }
    };

    class DivisionByZero : public std::exception {
        virtual const char *what() const throw() {
            return "Divider is equal to 0.";
        }
    };

    class NonPrintable : public std::exception {
        virtual const char *what() const throw() {
            return "The element at the top of the stack isn't a 8-Bits integer.";
        }
    };
};

#endif