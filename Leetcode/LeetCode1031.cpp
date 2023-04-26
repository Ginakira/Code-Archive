// LeetCode 1031 两个非重叠子数组的最大和

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
   private:
    int helper(vector<int>& nums, int first_len, int second_len) {
        int ans = 0, n = nums.size();
        int sum_first =
            accumulate(nums.begin(), next(nums.begin(), first_len), 0);
        int max_sum_first = sum_first;
        int sum_second =
            accumulate(next(nums.begin(), first_len),
                       next(nums.begin(), first_len + second_len), 0);
        ans = max_sum_first + sum_second;
        for (int i = first_len, j = first_len + second_len; j < n; ++i, ++j) {
            sum_first += nums[i] - nums[i - first_len];
            max_sum_first = max(max_sum_first, sum_first);
            sum_second += nums[j] - nums[j - second_len];
            ans = max(ans, max_sum_first + sum_second);
        }
        return ans;
    }

   public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen),
                   helper(nums, secondLen, firstLen));
    }
};