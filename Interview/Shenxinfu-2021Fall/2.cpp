#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// AC
void dfs(vector<vector<int>> &grid, int x, int y, int n, int m, int &ans) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1 ||
        grid[x][y] == 1) {
        return;
    }
    if (x == n - 1 && y == m - 1) {
        ++ans;
        return;
    }
    grid[x][y] = -1;
    dfs(grid, x + 1, y, n, m, ans);
    dfs(grid, x, y + 1, n, m, ans);
    grid[x][y] = 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    dfs(grid, 0, 0, n, m, ans);
    cout << ans << endl;
    return 0;
}