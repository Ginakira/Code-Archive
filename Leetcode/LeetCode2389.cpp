// LeetCode 2389 和有限的最长子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pre_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }
        for (auto& query : queries) {
            ans.emplace_back(
                distance(pre_sum.begin(),
                         upper_bound(pre_sum.begin(), pre_sum.end(), query)) -
                1);
        }
        return ans;
    }
};