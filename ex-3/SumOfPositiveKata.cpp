#include <vector>
#include <numeric>

int positive_sum(const std::vector<int> arr) {
    int sum{ 0 };

    auto lambda = [](int a, int b) {
        int sumSoFar{ 0 };
        if (b > 0) {
            sumSoFar = a + b;
        } else {
            sumSoFar = a;
        }
        return sumSoFar;
    };

    sum = std::accumulate(arr.begin(), arr.end(), 0, lambda);

    return sum;
}