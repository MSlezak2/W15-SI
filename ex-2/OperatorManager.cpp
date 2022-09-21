#include "OperatorManager.h"
#include <iostream>

void OperatorManager::registerOperator(std::string name, std::string symbol, std::function<double(const double, const double)> function, unsigned short int priority) {
	//TODO: That's probably unnecessary - insert() returns information whether it could put a new one into the set
	// Check whether there already is an operator with such name
	std::unordered_set<ArithmeticOperator>::iterator operatorWithSuchName =
		std::find_if(operators.begin(), operators.end(), [name](ArithmeticOperator op) {
		return (op.getName().compare(name) == 0);
			});

	if (operatorWithSuchName == operators.end()) {
		ArithmeticOperator newOperator(name, symbol, function, priority);
		operators.insert(newOperator);
	} else {
		std::cout << "Add operation failed: there already is an operator with that name" << std::endl;
	}
}

void OperatorManager::unregisterOperator(std::string name) {
	//TODO: That's probably also unnecessary, erase() method returns relevant info (...)
	// Check whether there is an operator with such name
	std::unordered_set<ArithmeticOperator>::iterator theOperator = 
		std::find_if(operators.begin(), operators.end(), [name](ArithmeticOperator op) {
			return (op.getName().compare(name) == 0);
		});

	if (theOperator != operators.end()) {
		operators.erase(theOperator);
	} else {
		std::cout << "Remove operation failed: there's no such operator" << std::endl;
	}
}

ArithmeticOperator OperatorManager::findOperator(std::string symbol) const {
	//TODO: Figure out how to return the reference to the operator (or maybe const reference)
	//TODO: What to do if there's no such operator?
	std::unordered_set<ArithmeticOperator>::iterator theOperator =
		std::find_if(operators.begin(), operators.end(), [symbol](ArithmeticOperator op) {
		return (op.getSymbol().compare(symbol) == 0);
			});
	
	if (theOperator != operators.end()) { //TODO: How to do it my way (assign it to the variable and then return)?
		return (*theOperator);
	} else {
		return ArithmeticOperator(); // TODO: Should I throw an exception or what? If so - custom one or one of predefined?
	}

}

std::unordered_set<ArithmeticOperator, ArithmeticOperator::HashFunction>& OperatorManager::getOperators() {
	return operators;
}
