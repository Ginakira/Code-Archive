// LeetCode 2576 求出最多标记下标

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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int m = n / 2;
        ranges::sort(nums);
        for (int i = 0, j = m; i < m && j < n; ++i) {
            while (j < n && 2 * nums[i] > nums[j]) {
                ++j;
            }
            if (j < n) {
                ans += 2;
                ++j;
            }
        }
        return ans;
    }
};