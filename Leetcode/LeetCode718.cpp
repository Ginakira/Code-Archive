// LeetCode 718 最长重复子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int max_len = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j] = (nums1[i] == nums2[j] ? dp[i + 1][j + 1] + 1 : 0);
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};