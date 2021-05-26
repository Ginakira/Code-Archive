// 剑指 Offer 13. 机器人的运动范围
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// BFS
class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> seen;

    bool canEnter(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }

   public:
    int movingCount(int m, int n, int k) {
        int count = 0;
        seen.resize(m, vector<int>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x < 0 || x >= m || y < 0 || y >= n || seen[x][y] ||
                !canEnter(x, y, k)) {
                continue;
            }
            ++count;
            seen[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                q.push({nx, ny});
            }
        }
        return count;
    }
};