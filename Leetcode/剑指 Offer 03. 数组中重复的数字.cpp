// 剑指 Offer 03. 数组中重复的数字
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 交换 32ms
class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] == i) {
                continue;
            } else if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            swap(nums[nums[i]], nums[i]);
        }
        return -1;
    }
};

// set 83ms
class Solution2 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (int& num : nums) {
            if (nums_set.count(num)) {
                return num;
            }
            nums_set.insert(num);
        }
        return -1;
    }
};

// 排序 64ms
class Solution3 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

// map 64ms
class Solution4 {
   public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int& num : nums) {
            if (mp[num] == true) {
                return num;
            }
            mp[num] = true;
        }
        return -1;
    }
};
