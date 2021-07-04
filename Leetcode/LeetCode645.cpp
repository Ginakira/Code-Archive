// LeetCode 645 错误的集合
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 常规做法 标记
class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);

        int repeat = 0, lost = 0;
        for (int& num : nums) {
            if (seen[num]) {
                repeat = num;
            }
            seen[num] = true;
        }

        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                lost = i;
            }
        }
        return {repeat, lost};
    }
};