// LeetCode 2717 半有序排列

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
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        auto pos_a = ranges::find(nums, 1);
        auto pos_b = ranges::find(nums, n);
        int ans = (pos_a - nums.begin()) + (nums.end() - pos_b - 1);
        if (pos_a > pos_b) {
            --ans;
        }
        return ans;
    }
};