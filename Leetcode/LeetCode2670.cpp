// LeetCode 2670 找出不同元素数目差数组

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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp_pre, mp_suf;
        vector<int> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            mp_suf.emplace(nums[i]);
            suf[i] = mp_suf.size();
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            mp_pre.emplace(nums[i]);
            ans[i] = mp_pre.size() - suf[i + 1];
        }
        return ans;
    }
};