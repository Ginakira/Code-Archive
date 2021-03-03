// LeetCode 338 比特位计数
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (int i = 1, high_bit = 1; i <= num; ++i) {
            if ((i & (i - 1)) == 0) {  // 为二的整数次幂
                high_bit = i;
            }
            dp[i] = dp[i - high_bit] + 1;
        }
        return dp;
    }
};