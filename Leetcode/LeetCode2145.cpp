// LeetCode 2145 统计隐藏数组数目

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
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ans = 0;
        long long min_diff = std::numeric_limits<int>::max(), max_diff = 0;
        for (long long cur = 0; int diff : differences) {
            cur += diff;
            min_diff = min(min_diff, cur);
            max_diff = max(max_diff, cur);
        }
        for (int i = lower; i <= upper; ++i) {
            if (i + min_diff >= lower && i + max_diff <= upper) {
                ++ans;
            }
        }
        return ans;
    }
};