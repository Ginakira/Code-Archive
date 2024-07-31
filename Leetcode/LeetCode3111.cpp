// LeetCode 3111 覆盖所有点的最少矩形数目

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
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        vector<int> p(points.size(), 0);
        ranges::transform(points, p.begin(), [](auto &v) { return v[0]; });
        ranges::sort(p);
        int bound = -1, cnt = 0;
        for (auto &point : p) {
            if (point > bound) {
                bound = point + w;
                ++cnt;
            }
        }
        return cnt;
    }
};