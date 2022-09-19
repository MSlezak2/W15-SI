#include <iostream>
#include "SimpleInterpreter.h"

int main() {
	SimpleInterpreter simpleInterpreter;
	OperatorManager om;
	om.registerOperator("findHypotenuse", "c",
		[](double a, double b) { return sqrt(a * a + b * b); }, 1);

	try {
		std::cout << simpleInterpreter.interpret("3 findHypotenuse 4", om);
	} catch (const std::exception& e) {
		std::cout << e.what();
	}

	return 0;
}