#include <string>
#include <algorithm>
#include <numeric>

int calc(const std::string& x) {
	int difference{ 0 };
	// string of letters to string of numbers (ASCII equivalents of those letters)
	std::string total1{ "" };
	auto lambda1 = [&total1](char c) {
		int n = c;
		total1.append(std::to_string(n));
	};
	std::for_each(x.begin(), x.end(), lambda1);

	// new string of numbers, but '7's are replaced with '1's
	std::string total2(total1.length(), ' ');
	std::replace_copy(total1.begin(), total1.end(), total2.begin(),
		'7', '1');

	// calculate difference of sums of numbers in those strings
	int sumTotal1{ 0 };
	int sumTotal2{ 0 };
	auto lambda2 = [](int sumSoFar, char currentElement) { return sumSoFar + currentElement - '0'; };
	sumTotal1 = std::accumulate(total1.begin(), total1.end(), 0,
		lambda2);
	sumTotal2 = std::accumulate(total2.begin(), total2.end(), 0,
		lambda2);
	difference = sumTotal1 - sumTotal2;

	return difference;
}