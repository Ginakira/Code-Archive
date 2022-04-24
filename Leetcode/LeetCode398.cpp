// LeetCode 398 随机数索引

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力
class Solution {
   private:
    unordered_map<int, vector<int>> mp;

   public:
    Solution(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            mp[nums[i]].emplace_back(i);
        }
        srand(time(0));
    }

    int pick(int target) {
        auto& indexes = mp[target];
        return indexes[rand() % indexes.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */