// LeetCode 930 和相同的二元子数组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int& num : nums) {
            sum += num;
            int target = sum - goal;
            if (mp.count(target)) {
                ans += mp[target];
            }
            ++mp[sum];
        }

        return ans;
    }
};