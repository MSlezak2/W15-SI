#pragma once
#include <stdexcept>

class InterpreterException : public std::exception {
public:
	InterpreterException(std::string interpreterName, std::string errorMessage,
		std::string faultyExpression) : interpreterName{ interpreterName }, 
		errorMessage{ errorMessage }, faultyExpression{ faultyExpression } {};

	virtual const char* what() const noexcept override;

private:
	std::string interpreterName;
	std::string errorMessage;
	std::string faultyExpression;
};



