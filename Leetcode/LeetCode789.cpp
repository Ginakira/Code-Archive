// LeetCode 789 逃脱阻碍者

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 曼哈顿距离
class Solution {
   public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto manhattan_distance = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };
        int distance = manhattan_distance(0, 0, target[0], target[1]);
        for (auto& ghost : ghosts) {
            if (manhattan_distance(ghost[0], ghost[1], target[0], target[1]) <=
                distance) {
                return false;
            }
        }
        return true;
    }
};