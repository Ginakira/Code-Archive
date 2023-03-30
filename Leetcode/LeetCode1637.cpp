// LeetCOde 1637 两点之间不包含任何点的最宽垂直区域

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end());
        for (int i = 1; i < points.size(); ++i) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};