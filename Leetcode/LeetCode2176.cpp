// LeetCode 2176 统计数组中相等且可以被整除的数对

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
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                if (i * j % k != 0) {
                    continue;
                }
                ++ans;
            }
        }
        return ans;
    }
};