// LeetCode 3143 正方形中的最多点数

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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        array<int, 26> min_d;
        min_d.fill(numeric_limits<int>::max());
        int min2 = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            int d = max(abs(points[i][0]), abs(points[i][1]));
            char c = s[i] - 'a';
            if (d < min_d[c]) {
                min2 = min(min2, min_d[c]);
                min_d[c] = d;
            } else {
                min2 = min(min2, d);
            }
        }
        return ranges::count_if(min_d, [min2](int num) { return num < min2; });
    }
};