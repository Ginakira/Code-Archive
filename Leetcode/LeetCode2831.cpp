// LeetCode 2831 找出最长等值子数组

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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, vector<int>> mark;
        for (int i = 0; i < nums.size(); ++i) {
            mark[nums[i]].emplace_back(i);
        }
        for (auto& [_, idxs] : mark) {
            for (int i = 0, j = 0; i < idxs.size(); ++i) {
                while (idxs[i] - idxs[j] - (i - j) > k) {
                    ++j;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};