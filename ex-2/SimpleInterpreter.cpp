#include "SimpleInterpreter.h"
#include <sstream>
#include "InterpreterException.h"
#include <iostream>

double SimpleInterpreter::interpret(const std::string& in, const OperatorManager& om) {
    double result{ HUGE_VAL }, leftTerm{ 0 }, rightTerm{ 0 };
    ArithmeticOperator op;
    std::stringstream ss(in);
    bool parsingSuccesful = true;

    // parse 
    try {
        leftTerm = parseNumberTerm(in, ss);
    } catch (const InterpreterException& e) {
        std::cout << e.what() << std::endl; 
        parsingSuccesful = false;
    } 
    try {
        op = parseOperator(in, ss, om);
    } catch (const InterpreterException& e) {
        std::cout << e.what() << std::endl;
        parsingSuccesful = false;
    }
    try {
        rightTerm = parseNumberTerm(in, ss);
    } catch (const InterpreterException& e) {
        std::cout << e.what() << std::endl;
        parsingSuccesful = false;
    }

    //do the calculation
    if (parsingSuccesful) {
        result = op(leftTerm, rightTerm);
    }

    return result;
}

double SimpleInterpreter::parseNumberTerm(std::string in, std::stringstream& ss) {
    double term{HUGE_VAL};
    std::string currentToken{ "" };

    ss >> currentToken; //TODO: what if there's no tokens left?
    try {
        term = std::stod(currentToken);
    } catch (const std::invalid_argument&) {
        throw InterpreterException(interpreterName, "invalid format of the number", in);
    } catch (const std::out_of_range&) {
        throw InterpreterException(interpreterName, "number exceeds possible range", in);
    }

    return term;
}

ArithmeticOperator SimpleInterpreter::parseOperator(std::string in, std::stringstream& ss, const OperatorManager& om) {
    std::string operatorName{ "" };

    ss >> operatorName; //TODO: what if there's no tokens left?

    ArithmeticOperator a = om.findOperator(operatorName);

    if (a.getName().compare("") == 0) {
        throw InterpreterException(interpreterName, "incorrect operator", in);
    }
    return a;

    ; // TODO: Why does it work? Why don't it (ArithmeticOperator object)
    // disappear after leaving scope of that function?
}
