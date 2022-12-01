// LeetCode 1779 找到最近的有相同X或Y座标的点

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int best_dis = numeric_limits<int>::max();
        int best_id = -1;
        for (size_t i = 0; i < points.size(); ++i) {
            auto& point = points[i];
            if (point[0] != x && point[1] != y) {
                continue;
            }
            int dis = abs(point[0] - x) + abs(point[1] - y);
            if (dis < best_dis) {
                best_dis = dis;
                best_id = i;
            } else if (dis == best_dis && i < best_id) {
                best_id = i;
            }
        }
        return best_id;
    }
};