// LeetCode 2044 统计按位或能得到最大值的子集数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 状态压缩
class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), max_ans = 0, cnt = 0, state = 1 << n;
        for (int i = 0; i < state; ++i) {
            int result = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    result |= nums[j];
                }
            }
            if (result == max_ans) {
                ++cnt;
            } else if (result > max_ans) {
                max_ans = result;
                cnt = 1;
            }
        }
        return cnt;
    }
};