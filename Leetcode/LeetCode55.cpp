// LeetCode 55 跳跃游戏

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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= farthest) {
                farthest = max(farthest, i + nums[i]);
                if (farthest >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};