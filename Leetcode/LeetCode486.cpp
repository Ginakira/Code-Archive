// leetCode 486 预测赢家
#include <numeric>
#include <vector>
using namespace std;

// 博弈 / 范围 dp
// dp[i][j]代表玩家1在i-j范围内能拿到的最大得分
class Solution {
   public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始状态
        for (int i = 0; i < n; ++i) {  // 长度为1的情况
            dp[i][i] = nums[i];
        }
        for (int i = 0; i < n - 1; ++i) {  // 长度为2的情况
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                // 当1拿左边的一个，后面用min因为玩家2也会用最佳取法，所以玩家1只能取到玩家2从剩下的中拿左边和拿右边两种情况的最小值
                int left = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                // 玩1拿右边，同上
                int right = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(left, right);
            }
        }
        // 如果玩家1拿到的分数超过总分一半，则可获胜
        return 2 * dp[0][n - 1] >= sum;
    }
};