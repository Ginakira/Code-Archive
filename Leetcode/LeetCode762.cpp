// LeetCode 762 二进制表示中质数个计算置位

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        auto is_prime = [](int num) {
            return (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 ||
                    num == 13 || num == 17 || num == 19)
                       ? 1
                       : 0;
        };

        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += is_prime(__builtin_popcount(i));
        }
        return ans;
    }
};

class Solution2 {
   public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if ((1 << __builtin_popcount(i)) & 0b10100010100010101100) {
                ++ans;
            }
        }
        return ans;
    }
};