#include "SimpleInterpreter.h"
#include <sstream>
#include "InterpreterException.h"

double SimpleInterpreter::interpret(const std::string& in, const OperatorManager& om) {
    double result{ 0 }, leftTerm{ 0 }, rightTerm{ 0 };
    ArithmeticOperator op;
    std::stringstream ss(in);

    // parse 
    leftTerm = parseNumberTerm(in, ss);
    op = parseOperator(ss, om);
    rightTerm = parseNumberTerm(in, ss);

    //do the calculation
    result = op(leftTerm, rightTerm);

    return result;
}

double SimpleInterpreter::parseNumberTerm(std::string in, std::stringstream& ss) {
    double term{HUGE_VAL};
    std::string currentToken{ "" };

    ss >> currentToken; //TODO: what if there's no tokens left?
    try {
        term = std::stod(currentToken);
    } catch (const std::exception&) {
        throw InterpreterException(interpreterName, "invalid format of the number",
            in);
    }

    return term;
}

ArithmeticOperator SimpleInterpreter::parseOperator(std::stringstream& ss, const OperatorManager& om) {
    std::string operatorName{ "" };

    ss >> operatorName; //TODO: what if there's no tokens left?
   
    return om.findOperator(operatorName); // TODO: Why does it work? Why don't it (ArithmeticOperator object)
    // disappear after leaving scope of that function?
}
