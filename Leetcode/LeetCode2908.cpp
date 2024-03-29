// LeetCode 2908 元素和最小的山形三元组

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
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        constexpr int INF = std::numeric_limits<int>::max();
        int ans = INF;
        vector<int> left(n);
        int min_num = INF;
        for (int i = 1; i < n; ++i) {
            left[i] = min_num = min(nums[i - 1], min_num);
        }
        int right = nums[n - 1];
        for (int i = n - 2; i > 0; --i) {
            if (left[i] < nums[i] && right < nums[i]) {
                ans = min(ans, left[i] + nums[i] + right);
            }
            right = min(right, nums[i]);
        }
        return ans == INF ? -1 : ans;
    }
};