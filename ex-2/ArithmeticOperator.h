#pragma once
#include <functional>
#include <string>


class ArithmeticOperator {
public:
	ArithmeticOperator(std::string n, std::string s,
		std::function<double(const double, const double)> f, unsigned short int p)
		: name{ n }, symbol{ s }, actualFunction{ f }, priority{ p } {};
	~ArithmeticOperator() = default;

	double operator()(const double leftRerm, const double rightTerm);
	std::string getName() noexcept;

private:
	std::function<double(const double, const double)> actualFunction;
	std::string name;
	std::string symbol;
	unsigned short int priority;
};

