// LeetCode 2874 有序三元组中的最大值II

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
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            max_suffix[i] = max(max_suffix[i + 1], nums[i]);
        }
        int max_prefix = nums[0];
        long long ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] >= max_prefix) {
                max_prefix = nums[i];
                continue;
            }
            ans = max(ans, 1LL * (max_prefix - nums[i]) * max_suffix[i + 1]);
        }
        return ans;
    }
};