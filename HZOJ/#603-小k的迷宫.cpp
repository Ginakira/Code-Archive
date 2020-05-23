/************************************************************
    File Name : #603-小k的迷宫.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/23 11:10:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1001

struct UnionSet {
    int *fa;
    UnionSet(int n) {
        fa = new int[n + 1];
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
        }
        return;
    }
    int find(int x) { return (fa[x] = (x == fa[x] ? x : find(fa[x]))); }
    void merge(int a, int b) {
        // cout << "MERGE" << a << " TO " << b << endl;
        int aa = find(a), bb = find(b);
        // cout << "A-FA " << aa << "  B-FA " << bb << endl;
        if (aa == bb) return;
        fa[aa] = bb;
        return;
    }
    ~UnionSet() { delete[] fa; }
};

struct Node {
    int x, y;
};

int n, m, q;
int ind(int i, int j) { return i * m + j + 1; }
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int grid[MAX_N + 5][MAX_N + 5];
bool vis[MAX_N + 5][MAX_N + 5];

void dfs(int x, int y, UnionSet &u) {
    if (grid[x][y] != 0 || vis[x][y]) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0], ty = y + dir[i][1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (grid[tx][ty] != 0 || vis[tx][ty]) continue;
        u.merge(ind(tx, ty), ind(x, y));
        dfs(tx, ty, u);
    }
    return;
}

void solve() {
    cin >> n >> m >> q;
    UnionSet u(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = 0, vis[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == 0) {
                dfs(i, j, u);
            }
        }
    }

    // Query
    int xi, yi, xj, yj;
    for (int i = 0; i < q; ++i) {
        cin >> xi >> yi >> xj >> yj;
        if (grid[xi][yi] != 0 || grid[xj][yj] != 0) {
            cout << 0 << endl;
            continue;
        }
        int fa_i = u.find(ind(xi, yi)), fa_j = u.find(ind(xj, yj));
        // cout << "FA-" << fa_i << ' ' << fa_j << endl;
        cout << (fa_i == fa_j ? 1 : 0) << endl;
    }

    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}