// LeetCode 2808 使循环数组所有元素相等的最少秒数

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
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), ans = n;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].emplace_back(i);
        }
        for (auto& [_, pos] : mp) {
            int max_dis = pos[0] + n - pos.back();
            for (int i = 1; i < pos.size(); ++i) {
                max_dis = max(max_dis, pos[i] - pos[i - 1]);
            }
            ans = min(ans, max_dis / 2);
        }
        return ans;
    }
};