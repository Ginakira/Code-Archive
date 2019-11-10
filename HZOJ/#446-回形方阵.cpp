#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int n, a[10][10];

void write(int d) {
    for (int i = d - 1; i < n - d + 1; ++i) {
        for (int j = d - 1; j < n - d + 1; ++j) {
            if ((i == d - 1) || (i == n - d) || (j == d - 1) || (j == n - d)) {
                a[i][j] = d;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        write(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}