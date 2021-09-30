#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL calculate(int x, int y, const vector<vector<int>> &matrix, int n) {
    LL sum = 0;
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
        sum += matrix[i][j];
    }
    for (int i = x + 1, j = y + 1; i < n && j < n; ++i, ++j) {
        sum += matrix[i][j];
    }
    for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j) {
        sum += matrix[i][j];
    }
    for (int i = x + 1, j = y - 1; i < n && j >= 0; ++i, --j) {
        sum += matrix[i][j];
    }
    sum += matrix[x][y];
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    LL max_sum = 0;
    for (int ai = 0; ai < n; ++ai) {
        for (int aj = 0; aj < n; ++aj) {
            for (int bi = 0; bi < n; ++bi) {
                for (int bj = 0; bj < n; ++bj) {
                    if (abs(ai - bi) == abs(aj - bj)) {
                        continue;
                    }
                    LL sum = calculate(ai, aj, matrix, n);
                    sum += calculate(bi, bj, matrix, n);
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}