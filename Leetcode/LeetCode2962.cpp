// LeetCode 2962 统计最大元素出现至少K次的子数组

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
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = *ranges::max_element(nums);
        int n = nums.size();
        long long ans = 0;
        int cur_cnt = 0;
        for (int l = 0, r = 0; l < n; ++l) {
            while (r < n && cur_cnt < k) {
                if (nums[r++] == max_num) {
                    ++cur_cnt;
                }
            }
            if (cur_cnt >= k) {
                ans += n - r + 1;
            }
            if (nums[l] == max_num) {
                --cur_cnt;
            }
        }
        return ans;
    }
};