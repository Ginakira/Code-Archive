// 存在重复元素II
#include <unordered_map>
#include <vector>
using namespace std;

// 使用unordered_map记录下标，其内部实现为哈希表，普通map内部实现为RB-Tree
// Use unordered_map to record the index of number. Its internal implementation
// is a hash table, and the normal map internal implementation is RB-Tree.
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.count(nums[i])) {
                if (i - mp[nums[i]] <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};