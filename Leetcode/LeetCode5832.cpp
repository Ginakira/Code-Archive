// LeetCode 5832 构造元素不等于两相邻元素平均值的数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        int cur = 0;
        for (int i = 0; i < n; i += 2) {
            ans[i] = nums[cur++];
        }
        for (int i = 1; i < n; i += 2) {
            ans[i] = nums[cur++];
        }
        return ans;
    }
};