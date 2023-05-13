// LeetCode 2241 与对应负数同时存在的最大正整数

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
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> us;
        for (int num : nums) {
            if (us.count(-num)) {
                ans = max(ans, abs(num));
            }
            us.insert(num);
        }
        return ans;
    }
};

class Solution2 {
   public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        std::array<bool, 2001> mark{{false}};
        for (int num : nums) {
            if (mark[-num + 1000]) {
                ans = max(ans, abs(num));
            }
            mark[num + 1000] = true;
        }
        return ans;
    }
};

class Solution3 {
   public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            while (l < r && -nums[l] < nums[r]) {
                --r;
            }
            if (-nums[l] == nums[r]) {
                return nums[r];
            }
            ++l;
        }
        return -1;
    }
};