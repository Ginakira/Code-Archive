#include <unordered_map>
#include <vector>
using namespace std;

// 使用unordered_map记录下标，其内部实现为哈希表，普通map内部实现为RB-Tree
// Use unordered_map to record the index of number. Its internal implementation
// is a hash table, and the normal map internal implementation is RB-Tree.
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mark;
        int n = nums.size();
        bool ret = false;
        for (int i = 0; i < n; ++i) {
            if (mark.count(nums[i]) && i - mark[nums[i]] <= k) {
                ret = true;
            } else {
                mark[nums[i]] = i;
            }
        }
        return ret;
    }
};