// LeetCode 1414 和为K的最少斐波那契数字数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        int fib_a = 0, fib_b = 1, fib_c = 1;
        vector<int> fibs{fib_a};
        while (fib_c <= k) {
            fibs.emplace_back(fib_c);
            fib_a = fib_b;
            fib_b = fib_c;
            fib_c = fib_a + fib_b;
        }

        for (size_t i = fibs.size() - 1; i >= 0 && k; --i) {
            while (k > 0 && fibs[i] <= k) {
                ++ans;
                k -= fibs[i];
            }
        }
        return ans;
    }
};