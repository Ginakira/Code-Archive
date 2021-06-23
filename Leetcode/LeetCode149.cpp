// LeetCode 149 直线上最多的点数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 枚举 判断斜率 + 哈希表
class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) {
            return n;
        }
        int max_count = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> count;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                double gradient = dx * 1.0 / dy;
                if (count.count(gradient)) {
                    ++count[gradient];
                } else {
                    count[gradient] = 2;
                }
                max_count = max(max_count, count[gradient]);
            }
        }
        return max_count;
    }
};