#pragma once
#include <string>
#include "OperatorManager.h"

class InterpreterInterface {
public:
	virtual ~InterpreterInterface() noexcept = default;
	
	virtual double interpret(const std::string& in, const OperatorManager& om) = 0;

};

