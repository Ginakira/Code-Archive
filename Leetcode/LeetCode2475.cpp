// LeetCode 2475 数组中不等三元组的数目

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
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] != nums[j] && nums[j] != nums[k] &&
                        nums[i] != nums[k]) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto& num : nums) {
            ++count[num];
        }
        int ans = 0, n = nums.size(), cur_cnt_sum = 0;
        for (auto [_, cnt] : count) {
            ans += cur_cnt_sum * cnt * (n - cnt - cur_cnt_sum);
            cur_cnt_sum += cnt;
        }
        return ans;
    }
};