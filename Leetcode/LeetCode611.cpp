// LeetCode 611 有效三角形的个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序 + 二分
class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = nums[i], b = nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), a + b);
                ans += (it - nums.begin() - j - 1);
            }
        }
        return ans;
    }
};

// 排序 + 双指针
// 思路同上 因为有序 所以两边之和递增 移动即可
class Solution2 {
   public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};