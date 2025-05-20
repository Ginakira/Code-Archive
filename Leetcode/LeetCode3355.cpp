// LeetCode 3355 零数组变换 I

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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (const auto& q : queries) {
            ++diff[q[0]];
            --diff[q[1] + 1];
        }

        int sum_d = 0;
        for (int i = 0; i < n; ++i) {
            sum_d += diff[i];
            if (nums[i] > sum_d) {
                return false;
            }
        }
        return true;
    }
};