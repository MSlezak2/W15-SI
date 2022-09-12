#include "ArithmeticOperator.h"

double ArithmeticOperator::operator()(const double leftTerm, const double rightTerm) {
    actualFunction(leftTerm, rightTerm);
}

std::string ArithmeticOperator::getName() noexcept {
    return name;
}
