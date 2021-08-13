// LeetCode 233 数字1的个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countDigitOne(int n) {
        long long base = 1;
        int ans = 0;
        while (n >= base) {
            ans += (n / (base * 10)) * base +
                   min(max(n % (base * 10) - base + 1, 0LL), base);
            base *= 10;
        }
        return ans;
    }
};