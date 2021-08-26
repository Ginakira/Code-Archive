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
    const int dirs[2][2]{{0, 1}, {1, 0}};

    int can_enter(int x, int y, int k) {
        int sum = 0;
        while (x) sum += x % 10, x /= 10;
        while (y) sum += y % 10, y /= 10;
        return sum <= k;
    }

   public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> seen(m, vector<int>(n, false));
        queue<tuple<int, int>> q;
        q.emplace(0, 0);
        seen[0][0] = true;
        int count = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            ++count;
            seen[x][y] = true;
            for (auto &dir : dirs) {
                int tx = x + dir[0], ty = y + dir[1];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || seen[tx][ty] ||
                    !can_enter(tx, ty, k))
                    continue;
                seen[tx][ty] = true;
                q.emplace(tx, ty);
            }
        }
        return count;
    }
};