// LeetCode 2740 找出分区值

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
    int findValueOfPartition(vector<int>& nums) {
        ranges::sort(nums);
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < nums.size() - 1; ++i) {
            ans = min(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};