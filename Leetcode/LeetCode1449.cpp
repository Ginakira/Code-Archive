// LeetCode 1449 数位成本和为目标值的最大数字
#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 动态规划
// 首先求正好花费target成本时能组成的数字最长的长度，此为完全背包问题，求出答案的最长长度后，再根据dp结果进行反推，从数字9开始，即可求出答案。
class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= 9; ++i) {
            int c = cost[i - 1];
            for (int j = c; j <= target; ++j) {
                dp[j] = max(dp[j], dp[j - c] + 1);
            }
        }
        string ans = "";
        if (dp[target] <= 0) return "0";
        for (int i = 9, remain = target; i >= 1; --i) {
            int c = cost[i - 1];
            while (remain >= c && dp[remain] == dp[remain - c] + 1) {
                ans.push_back(i + '0');
                remain -= c;
            }
        }
        return ans;
    }
};