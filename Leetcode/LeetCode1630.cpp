// LeetCode 1630 等差子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        vector<bool> ans;
        size_t n = l.size();
        ans.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            size_t left = l[i], right = r[i], seg_n = right - left + 1;
            int min_val = *min_element(next(nums.begin(), left),
                                       next(nums.begin(), right + 1));
            int max_val = *max_element(next(nums.begin(), left),
                                       next(nums.begin(), right + 1));
            if (min_val == max_val) {
                ans.emplace_back(true);
                continue;
            }
            int d = (max_val - min_val) / (seg_n - 1);
            if (d * (seg_n - 1) != (max_val - min_val)) {
                ans.emplace_back(false);
                continue;
            }
            unordered_set<int> mark;
            bool flag = true;
            for (size_t j = left; j <= right; ++j) {
                if ((nums[j] - min_val) % d) {
                    flag = false;
                    break;
                }
                mark.emplace(nums[j]);
            }
            ans.emplace_back(flag && mark.size() == seg_n);
        }
        return ans;
    }
};