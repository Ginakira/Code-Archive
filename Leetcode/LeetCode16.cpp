// LeetCode 16 最接近的三数之和
#include <vector>
using namespace std;

// 暴力穷举
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = 0x3f3f3f3f, ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};

// 双指针
class Solution2 {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int second = first + 1, third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target) {
                    return target;
                }
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if (sum < target) {
                    ++second;
                } else {
                    --third;
                }
            }
        }
        return ans;
    }
};