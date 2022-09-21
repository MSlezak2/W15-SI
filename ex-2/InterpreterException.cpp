#include "InterpreterException.h"

InterpreterException::InterpreterException(std::string interpreterName, std::string errorMessage, std::string faultyExpression) {
    
    exceptionMessage .append(interpreterName);
    exceptionMessage .append(" error: ");
    exceptionMessage .append(errorMessage);
    exceptionMessage .append(" : ");
    exceptionMessage .append(faultyExpression);
}

const char* InterpreterException::what() const noexcept {
    return exceptionMessage.c_str();
}
