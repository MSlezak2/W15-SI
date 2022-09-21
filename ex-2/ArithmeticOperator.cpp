#include "ArithmeticOperator.h"

bool operator==(const ArithmeticOperator& leftOne, const ArithmeticOperator& rightOne) {
    return leftOne.name == rightOne.name; // TODO: is it the right way to do it? Shouldn't I compare all the other attributes as well?
}

double ArithmeticOperator::operator()(const double leftTerm, const double rightTerm) {
    return actualFunction(leftTerm, rightTerm);
}

std::string ArithmeticOperator::getName() noexcept {
    return name;
}

std::string ArithmeticOperator::getSymbol() noexcept {
    return symbol;
}
