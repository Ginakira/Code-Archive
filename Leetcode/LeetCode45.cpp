// LeetCode 45 跳跃游戏 II

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
    int jump(vector<int>& nums) {
        int steps = 0;
        int cur_end = 0;
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == cur_end) {
                cur_end = farthest;
                ++steps;
            }
        }
        return steps;
    }
};