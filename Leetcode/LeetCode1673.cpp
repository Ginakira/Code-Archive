// LeetCode 1673 找出最具竞争力的子序列

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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (!res.empty() && n - i + res.size() > k &&
                   res.back() > nums[i]) {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};