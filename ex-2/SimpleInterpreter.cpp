#include "SimpleInterpreter.h"
#include <sstream>

double SimpleInterpreter::interpret(const std::string& in, const OperatorManager& om) {
    double result{ 0 }, leftTerm{ 0 }, rightTerm{ 0 };
    std::string operatorName{ "" }, currentToken{ "" };
    std::stringstream ss(in);

    // look for left term
    ss >> currentToken; //TODO: what if there's no tokens left?
    try {
        leftTerm = std::stod(currentToken);
    } catch (const std::exception&) {

    }

    // look for operator
    ss >> operatorName; //TODO: what if there's no tokens left?
    om.findOperator(operatorName);

    // look for right term

    return result;
}
