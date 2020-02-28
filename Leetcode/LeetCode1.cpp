// 两数之和
#include <map>
#include <vector>
using namespace std;

// 暴力解法 O(n^2) 320ms
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// 两遍哈希表 使用map O(n) 24ms
class Solution2 {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.count(complement) && mp[complement] != i) {
                return {i, mp[complement]};
            }
        }
        return {};
    }
};

// 一遍哈希 O(n) 8ms
class Solution3 {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.count(complement)) return {i, mp[complement]};
            mp[nums[i]] = i;
        }
        return {};
    }
};