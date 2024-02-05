// LeetCode 1696 跳跃游戏VI
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
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> q;
        q.emplace_back(nums[0], 0);
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            while (i - q.front().second > k) {
                q.pop_front();
            }
            ans = q.front().first + nums[i];
            while (!q.empty() && ans >= q.back().first) {
                q.pop_back();
            }
            q.emplace_back(ans, i);
        }
        return ans;
    }
};