// LeetCode 18 四数之和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 解法同LC15 三数之和 多加一层循环 固定两个数 转化为两数之和问题
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }

                int third = second + 1, fourth = n - 1;
                int goal = target - nums[second] - nums[first];
                while (third < fourth) {
                    int sum = nums[third] + nums[fourth];
                    if (sum < goal) {
                        ++third;
                    } else if (sum > goal) {
                        --fourth;
                    } else {
                        ans.emplace_back(vector<int>{nums[first], nums[second],
                                                     nums[third],
                                                     nums[fourth]});
                        ++third, --fourth;
                        while (third < fourth && nums[third] == nums[third - 1])
                            ++third;
                        while (third < fourth &&
                               nums[fourth] == nums[fourth + 1])
                            --fourth;
                    }
                }
            }
        }

        return ans;
    }
};