// LeetCode 3254 长度为K的子数组的能量值I

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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n - k + 1);
        for (int l = 0, r = 0; r < n; ++r) {
            if (r > 0 && nums[r] != nums[r - 1] + 1) {
                l = r;
            }
            if (r - l + 1 >= k) {
                ans.emplace_back(nums[r]);
            } else if (r >= k - 1) {
                ans.emplace_back(-1);
            }
        }
        return ans;
    }
};
