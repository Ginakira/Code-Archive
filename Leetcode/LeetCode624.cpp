// LeetCode 624 数组列表中的最大距离

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
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int ans = 0;
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();
        for (int i = 1; i < n; ++i) {
            ans = max({ans, abs(arrays[i].back() - min_val),
                       abs(max_val - arrays[i].front())});
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }
        return ans;
    }
};