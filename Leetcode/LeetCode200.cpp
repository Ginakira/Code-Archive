// 岛屿数量
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    struct UnionSet {
        int *fa, *cnt;
        UnionSet(int n) {
            fa = new int[n + 1];
            cnt = new int[n + 1];
            for (int i = 0; i <= n; ++i) {
                fa[i] = i, cnt[i] = 1;
            }
            return;
        }
        bool is_root(int x) { return fa[x] == x; }
        int get(int x) { return (fa[x] = (x == fa[x] ? x : get(fa[x]))); }
        void merge(int a, int b) {
            int aa = get(a), bb = get(b);
            if (aa == bb) return;
            fa[aa] = bb;
            cnt[bb] += cnt[aa];
            return;
        }
        ~UnionSet() {
            delete[] fa;
            delete[] cnt;
        }
    };
    int n, m;
    int ind(int i, int j) { return (i * m) + j + 1; }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        n = grid.size();
        m = grid[0].size();
        UnionSet u(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                if (i && grid[i - 1][j] == '1')
                    u.merge(ind(i, j), ind(i - 1, j));
                if (j && grid[i][j - 1] == '1')
                    u.merge(ind(i, j), ind(i, j - 1));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                if (!u.is_root(ind(i, j))) continue;
                ans++;
            }
        }
        return ans;
    }
};

// DFS
class Solution2 {
   private:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int rows, cols;
    vector<vector<bool>> visited;

   public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols, false));
        int ans = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (visited[i][j]) return;
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dir[k][0], ny = j + dir[k][1];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols ||
                grid[nx][ny] == '0') {
                continue;
            }
            dfs(nx, ny, grid);
        }
        return;
    }
};