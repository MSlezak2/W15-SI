#pragma once
#include <unordered_set>
#include "ArithmeticOperator.h"

class OperatorManager {
public:
	//TODO: Place noexcept keywords where it's appropriate
	OperatorManager() = default;
	~OperatorManager() = default;

	void registerOperator(std::string name, std::string symbol,
		std::function<double(const double, const double)> function, 
		unsigned short int priority);
	void unregisterOperator(std::string name);
	ArithmeticOperator findOperator(std::string name);
	std::unordered_set<ArithmeticOperator>& getOperators(); //TODO: Did they really meant returns "reference to ..."?

private:
	std::unordered_set<ArithmeticOperator> operators; //TODO: Is that the right container for the job?
};
