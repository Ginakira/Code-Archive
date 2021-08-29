#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int cut(vector<vector<int>> &grid, int x, int y, int r, int n, int m) {
    int count = 0;
    int r2 = r * r;
    for (int i = x - r; i <= x + r; ++i) {
        if (i < 0 || i >= n) continue;
        for (int j = y - r; j <= y + r; ++j) {
            if (j < 0 || j >= m) continue;
            if ((i - x) * (i - x) + (j - y) * (j - y) > r2) continue;
            count += grid[i][j];
            grid[i][j] = 0;
        }
    }
    return count;
}

void generate(vector<vector<int>> &grid) {
    for (auto &row : grid) {
        for (auto &num : row) {
            ++num;
        }
    }
}

int sum(vector<vector<int>> &grid) {
    int sum = 0;
    for (auto &row : grid) {
        for (auto &num : row) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, 1));
    for (int i = 0; i < k; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        cut(grid, x - 1, y - 1, r, n, m);
        if (i != k - 1) generate(grid);
    }
    cout << sum(grid) << endl;
    return 0;
}