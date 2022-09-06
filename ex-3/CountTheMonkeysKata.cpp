#include <vector>
#include <algorithm>

std::vector<int> MonkeyCount(int n) {
    std::vector<int> result(n);
    int monkeyCount{ 0 };

    auto lambda = [&monkeyCount]() {
        return ++monkeyCount;
    };

    generate_n(result.begin(), n, lambda);

    return result;
}