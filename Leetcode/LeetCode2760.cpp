// LeetCode 2760 最长奇偶子数组

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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_len = 0;
        for (int l = 0, r = 0; l < n; ++l) {
            if (nums[l] & 1 || nums[l] > threshold) {
                continue;
            }
            r = l + 1;
            while (r < n && nums[r] <= threshold && ((nums[r] & 1) != (nums[r - 1] & 1))) {
                ++r;
            }
            max_len = max(max_len, r - l);
            l = r - 1;
        }
        return max_len;
    }
};