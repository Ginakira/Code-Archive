#include <iostream>
#include <climits>
using namespace std;

int a[15][15];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i][1] = 1;
        a[1][i] = 1;
    }
    int maxs = INT_MIN;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            maxs = max(maxs, a[i][j]);
        }
    }
    cout << maxs << endl;
    return 0;
}