// LeetCode3194 最小元素和最大元素的最小平均值

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
    double minimumAverage(vector<int>& nums) {
        double ans = numeric_limits<double>::max();
        ranges::sort(nums);
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            ans = min(ans, (nums[i] + nums[n - i - 1]) / 2.0);
        }
        return ans;
    }
};