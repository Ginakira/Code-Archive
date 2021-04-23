// LeetCode 368 最大整除子集
#include <algorithm>
#include <vector>
using namespace std;

// 先使用动态规划求出最大的子集元素数量，然后反推结果即可
// 因为整除具有传递性，即a<b<c时，如果b%a==0且c%b==0那么c%a==0
// 所以先进行排序，使用dp计算出最长的答案个数
// dp[i]初始值为1，处理每一位时枚举这一位之前的答案，选择一个最大的且能被nums[j]整除的来更新dp[i]
// 如果nums[i]%nums[j]==0,dp[i] = max(dp[i], dp[j] + 1);
// 然后得到最大的元素和子集元素数量，进行反推即可，注意反推时条件的限制
class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_val = 0, max_size = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > max_size) {
                max_size = dp[i];
                max_val = nums[i];
            }
        }

        vector<int> result;
        for (int i = n - 1; i >= 0 && max_size; --i) {
            if (dp[i] == max_size && max_val % nums[i] == 0) {
                result.emplace_back(nums[i]);
                --max_size;
                max_val = nums[i];
            }
        }
        return result;
    }
};