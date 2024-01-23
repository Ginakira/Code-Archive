// LeetCode 2765 最长交替子数组

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
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int len = 1, flag = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == nums[j - 1] + flag) {
                    ++len;
                    flag = -flag;
                } else {
                    break;
                }
            }
            if (len > 1) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int begin = 0;
        for (int i = 1; i < n; ++i) {
            int len = i - begin + 1;
            if (nums[i] - nums[begin] == !(len & 1)) {
                ans = max(ans, len);
                continue;
            }
            begin = (nums[i] - nums[i - 1] == 1) ? i - 1 : i;
        }
        return ans;
    }
};