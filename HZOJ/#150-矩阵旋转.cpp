#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    int mat[233][233];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        bool first = true;
        for (int j = n - 1; j >= 0; --j) {
            if (!first) {
                cout << ' ';
            } else {
                first = false;
            }
            cout << mat[j][i];
        }
        cout << endl;
    }
    return 0;
}