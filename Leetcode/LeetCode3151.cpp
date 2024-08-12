// LeetCode 3151 特殊数组 I

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
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (!((nums[i - 1] & 1) ^ (nums[i] & 1))) {
                return false;
            }
        }
        return true;
    }
};