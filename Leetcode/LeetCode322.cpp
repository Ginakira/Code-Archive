// 每日一题计划 零钱兑换
#include <vector>
using namespace std;

// DFS + 贪心
// 普通的贪心方法无法得到最优解，比如[1,7,10]-14，所以我们需要借助DFS来获得所有的解法找出最优解
// 也就是贪心的基础上 枚举这枚使用了0～k次的情况，加上剪枝，运行时间12ms
class Solution {
   public:
    void dfs(vector<int> &coins, int amount, int c_index, int count, int &ans) {
        if (!amount) {
            ans = min(ans, count);
            return;
        }
        if (c_index >= coins.size()) return;
        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; --k) {
            dfs(coins, amount - k * coins[c_index], c_index + 1, count + k,
                ans);
        }
        return;
    }

    int coinChange(vector<int> &coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        dfs(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};

// 动态规划 dp[i]为总金额为i时的方案数，计算每个状态时遍历所有硬币为末尾的情况取最小值
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n ; ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};