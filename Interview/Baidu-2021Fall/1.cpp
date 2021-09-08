// AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void fill_image(vector<vector<int>> &result, int _i, int _j, int k) {
    int x = _i * k, y = _j * k;
    for (int i = x; i < x + k; ++i) {
        for (int j = y; j < y + k; ++j) {
            result[i][j] = 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> origin(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> origin[i][j];
        }
    }
    int N = n * k;
    vector<vector<int>> result(N, vector<int>(N));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!origin[i][j]) continue;
            fill_image(result, i, j, k);
        }
    }

    for (auto &vec : result) {
        for (auto &num : vec) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}