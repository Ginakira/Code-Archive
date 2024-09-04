// LeetCode 2860 让所有学生保持开心的分组方法数

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
    int countWays(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i + 1 > nums[i] && i + 1 < nums[i + 1]) {
                ++cnt;
            }
        }
        cnt += 0 < nums[0] ? 1 : 0;
        cnt += n > nums[n - 1] ? 1 : 0;
        return cnt;
    }
};