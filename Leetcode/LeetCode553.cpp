// LeetCode 553 最优除法

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string optimalDivision(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        } else if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string ans;
        ans += to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (size_t i = 2; i < n; ++i) {
            ans += "/" + to_string(nums[i]);
        }
        ans.push_back(')');
        fill_n(ans.begin(), 10, 1);
        return ans;
    }
};