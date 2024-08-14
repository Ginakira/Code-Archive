// LeetCode 3152 特殊数组 II

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> res;
        res.reserve(queries.size());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            if ((nums[i - 1] ^ nums[i]) & 1) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        for (auto& query : queries) {
            int i = query[0], j = query[1];
            res.emplace_back((dp[j] >= j - i + 1));
        }
        return res;
    }
};