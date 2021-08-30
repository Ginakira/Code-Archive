#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int up = 0, down = m - 1, left = 0, right = n - 1;

    while (true) {
        for (int l = left; l <= right; ++l) cout << matrix[up][l] << ' ';
        if (++up > down) break;
        for (int u = up; u <= down; ++u) cout << matrix[u][right] << ' ';
        if (--right < left) break;
        for (int r = right; r >= left; --r) cout << matrix[down][r] << ' ';
        if (--down < up) break;
        for (int d = down; d >= up; --d) cout << matrix[left][d] << ' ';
        if (++left > right) break;
    }
    cout << endl;
    return 0;
}