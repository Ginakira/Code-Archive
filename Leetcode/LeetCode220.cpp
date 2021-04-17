// LeetCode 220 存在重复元素III
#include <set>
#include <vector>
using namespace std;

// set
class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> records;
        for (int i = 0; i < n; ++i) {
            auto iter = records.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != records.end() &&
                *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            records.insert(nums[i]);
            if (i >= k) {
                records.erase(nums[i - k]);
            }
        }
        return false;
    }
};