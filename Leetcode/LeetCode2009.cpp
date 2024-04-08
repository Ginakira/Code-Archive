// LeetCode 2009 使数组连续的最少操作数

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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        vector<int> sorted_unique_nums(unique_nums.begin(), unique_nums.end());
        ranges::sort(sorted_unique_nums);
        int ans = n, j = 0;
        int m = sorted_unique_nums.size();
        for (int i = 0; i < m; ++i) {
            int right = sorted_unique_nums[i] + n - 1;
            while (j < m && sorted_unique_nums[j] <= right) {
                ans = min(ans, n - (j - i + 1));
                ++j;
            }
        }
        return ans;
    }
};