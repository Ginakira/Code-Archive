// LeetCode 2580 统计将重叠区间合并成组的方案数

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
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        constexpr int MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 0; i < n;) {
            int j = i + 1;
            int cur_end = ranges[i][1];
            while (j < n && ranges[j][0] <= cur_end) {
                cur_end = max(cur_end, ranges[j][1]);
                ++j;
            }
            i = j;
            ans = ans * 2 % MOD;
        }
        return ans;
    }
};