// 每日一题 机器人的运动范围

// 裸DFS + 方向数组
class Solution {
   private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool mark[105][105];
    int m, n, ans = 1, k;

   public:
    bool is_invalid_position(int x, int y) {
        if (x < 0 || y < 0 || x > m - 1 || y > n - 1) return false;
        int sum = 0;
        while (x) sum += x % 10, x /= 10;
        while (y) sum += y % 10, y /= 10;
        return sum <= k;
    }

    void dfs(int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (is_invalid_position(tx, ty) && !mark[tx][ty]) {
                mark[tx][ty] = true;
                ans++;
                dfs(tx, ty);
            }
        }
    }

    int movingCount(int _m, int _n, int _k) {
        m = _m, n = _n, k = _k;
        mark[0][0] = true;
        dfs(0, 0);
        return ans;
    }
};

// BFS
