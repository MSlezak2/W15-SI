#include <iostream>
#include "SimpleInterpreter.h"

int main() {
	SimpleInterpreter simpleInterpreter;
	OperatorManager om;
	om.registerOperator("hypotenuse", "c",
		[](double a, double b) { return sqrt((a * a) + (b * b)); }, 1);

	std::cout << "3 c 4 = " << simpleInterpreter.interpret("3 c 4", om) <<std::endl << std::endl;
	std::cout << "3 cc 4 = " << simpleInterpreter.interpret("3 cc 4", om) << std::endl << std::endl;
	std::cout << "3 cc A = " << simpleInterpreter.interpret("3 cc A", om) << std::endl << std::endl;
	
	return 0;
}