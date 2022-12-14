#pragma once
#include "InterpreterInterface.h"

class SimpleInterpreter :
    public InterpreterInterface {
public:
    SimpleInterpreter() = default;
    ~SimpleInterpreter() noexcept = default;

    virtual double interpret(const std::string& in, const OperatorManager& om) override;

private:
    const std::string interpreterName{"basic interpreter"};
    double parseNumberTerm(std::string in, std::stringstream& ss);
    ArithmeticOperator parseOperator(std::string in, std::stringstream& ss, const OperatorManager& om);
};

