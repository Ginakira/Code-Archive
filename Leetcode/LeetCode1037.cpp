// LeetCode 1037 有效的回旋镖

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isBoomerang(vector<vector<int>>& points) {
        int v1_0 = points[1][0] - points[0][0],
            v1_1 = points[1][1] - points[0][1];
        int v2_0 = points[2][0] - points[0][0],
            v2_1 = points[2][1] - points[0][1];
        return v1_0 * v2_1 - v1_1 * v2_0 != 0;
    }
};