#pragma once
#include <stdexcept>

class InterpreterException : public std::exception {
public:
	InterpreterException(std::string interpreterName, std::string errorMessage,
		std::string faultyExpression);

	virtual const char* what() const noexcept override;

private:
	char exceptionMessage[1000];
};



