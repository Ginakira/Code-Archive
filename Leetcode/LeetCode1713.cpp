// LeetCode 1713 得到子序列的最少操作次数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// LCS, 超时
class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int target_n = target.size(), arr_n = arr.size();
        vector<vector<int>> dp(target_n + 1, vector<int>(arr_n + 1));
        for (int i = 1; i <= target_n; ++i) {
            for (int j = 1; j <= arr_n; ++j) {
                if (target[i - 1] == arr[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return target_n - dp[target_n][arr_n];
    }
};

// 转化为最长严格上升子序列（超时），并进行二分优化，同LC300-Solution2
class Solution2 {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> target_pos;
        for (int i = 0; i < n; ++i) {
            target_pos[target[i]] = i;
        }

        vector<int> dp;
        for (const int& num : arr) {
            if (!target_pos.count(num)) continue;
            int index = target_pos[num];
            auto it = lower_bound(dp.begin(), dp.end(), index);
            if (it == dp.end()) {
                dp.push_back(index);
            } else {
                *it = index;
            }
        }

        return n - dp.size();
    }
};