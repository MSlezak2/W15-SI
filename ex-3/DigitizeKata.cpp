#include <string>
#include <vector>
#include <algorithm>

std::vector<int> digitize(const int& n) {
	std::string number = std::to_string(n);
	int numberOfDigits = number.length();
	std::vector<int> digits(numberOfDigits);

	auto lambda = [](char c) {return c - '0'; };

	std::transform(number.begin(), number.end(), digits.begin(), lambda);

	return digits;
}