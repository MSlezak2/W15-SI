#pragma once
#include <functional>
#include <string>


class ArithmeticOperator {
public:
	ArithmeticOperator() = default;
	ArithmeticOperator(std::string n, std::string s,
		std::function<double(const double, const double)> f, unsigned short int p)
		: name{ n }, symbol{ s }, actualFunction{ f }, priority{ p } {};
	~ArithmeticOperator() = default;

	double operator()(const double leftRerm, const double rightTerm);
	std::string getName() noexcept;

	// needed for storing in a set:
	friend bool operator==(const ArithmeticOperator& leftOne, const ArithmeticOperator& rightOne);
	class HashFunction {
	public:
		size_t operator()(const ArithmeticOperator& ao) const {
			size_t nameHash{ std::hash<std::string>()(ao.name)};
			size_t symbolHash{ std::hash<std::string>()(ao.symbol) << 1 };
			size_t priorityHash{ std::hash<int>()(ao.priority) << 2 };
			//TODO: How to take into account actualFunction attribute while calculating hash?
			return nameHash ^ symbolHash ^ priorityHash;
		}
	};

private:
	std::function<double(const double, const double)> actualFunction;
	std::string name;
	std::string symbol;
	unsigned short int priority;
};

