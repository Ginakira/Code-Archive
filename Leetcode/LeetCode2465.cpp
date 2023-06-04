// LeetCode 2465 不同的平均值数目

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
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> avg;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int sm = nums[i], bg = nums[n - i - 1];
            avg.emplace(sm + bg);
        }
        return avg.size();
    }
};