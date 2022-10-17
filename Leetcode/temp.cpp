#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

int solve(int n, int k, const std::vector<int> &nums) {
    std::priority_queue<int, std::vector<int>, std::less<int>> q;
    for (auto num : nums) {
        q.emplace(num);
    }
    for (int _ = 0; _ < k; ++_) {
        int num = q.top();
        q.pop();
        q.emplace(__builtin_popcount(num));
    }
    int sum = 0;
    while (!q.empty()) {
        sum += q.top();
        q.pop();
    }
    return sum;
}

int main() {
    int n, k;
    while (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        int result = solve(n, k, nums);
        std::cout << result << std::endl;
    }
    return 0;
}