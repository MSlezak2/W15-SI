#include "OperatorManager.h"
#include <iostream>

void OperatorManager::registerOperator(std::string name, std::string symbol, std::function<double(const double, const double)> function, unsigned short int priority) {
	//TODO: That's probably unnecessary - insert() returns information whether it could put a new one into the set
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

ArithmeticOperator OperatorManager::findOperator(std::string name) const {
	//TODO: Figure out how to return the reference to the operator (or maybe const reference)
	std::unordered_set<ArithmeticOperator>::iterator theOperator =
		std::find_if(operators.begin(), operators.end(), [name](ArithmeticOperator op) {
		return (op.getName().compare(name) == 0);
			});

	return *theOperator;
}

std::unordered_set<ArithmeticOperator>& OperatorManager::getOperators() {
	return operators;
}
