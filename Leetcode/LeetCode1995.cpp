// LeetCode 1995 统计特殊四元组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int m = k + 1; m < n; ++m) {
                        if (nums[i] + nums[j] + nums[k] == nums[m]) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};