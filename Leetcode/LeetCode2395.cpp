// LeetCOde 2395 和相等的子数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> mark;
        size_t n = nums.size();
        for (size_t i = 0; i < n - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (mark.count(sum)) {
                return true;
            }
            mark.emplace(sum);
        }
        return false;
    }
};