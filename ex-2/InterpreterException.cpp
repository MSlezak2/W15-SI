#include "InterpreterException.h"

InterpreterException::InterpreterException(std::string interpreterName, std::string errorMessage, std::string faultyExpression) {
    
    std::string tempExceptionMessage;
    tempExceptionMessage.append(interpreterName);
    tempExceptionMessage.append(" error: ");
    tempExceptionMessage.append(errorMessage);
    tempExceptionMessage.append(" : ");
    tempExceptionMessage.append(faultyExpression);

    strcpy_s(exceptionMessage, tempExceptionMessage.size(), tempExceptionMessage.c_str());
}

const char* InterpreterException::what() const noexcept {
    return exceptionMessage;
}
