// 剑指 Offer 15. 二进制中1的个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};

class Solution2 {
   public:
    int hammingWeight(uint32_t n) { return __builtin_popcount(n); }
};