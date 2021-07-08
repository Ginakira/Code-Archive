// 面试题 17.10. 主要元素
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力解法 不符合题目的空间复杂度要求
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            ++mp[num];
        }
        int target = nums.size() / 2;
        for (auto& [num, count] : mp) {
            if (count > target) {
                return num;
            }
        }
        return -1;
    }
};

// Boyer-Mooer投票法
class Solution2 {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                ans = num;
                ++cnt;
            } else if (num == ans) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return count(nums.begin(), nums.end(), ans) > n / 2 ? ans : -1;
    }
};