#pragma once
#include "InterpreterInterface.h"

class SimpleInterpreter :
    public InterpreterInterface {
public:
    SimpleInterpreter() = default;
    ~SimpleInterpreter() = default;

    virtual double interpret(const std::string& in, const OperatorManager& om) override;

private:
};

