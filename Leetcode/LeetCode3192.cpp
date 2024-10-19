// LeetCode 3192 使二进制数组全部等于1的最少操作次数 II

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
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] ^= (ans & 1) == 0) {
                ++ans;
            }
        }
        return ans;
    }
};