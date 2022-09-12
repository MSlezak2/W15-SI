#include "InterpreterException.h"

const char* InterpreterException::what() const noexcept {
    std::string message = interpreterName + " error: " + errorMessage + " : "
        + faultyExpression;
    return message.c_str();
}
