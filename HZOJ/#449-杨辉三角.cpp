#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int tri[25][25] = {{0}};

int main() {
    tri[1][1] = 1;
    int n;
    cin >> n;
    cout << 1 << endl;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
            if (j != 1) cout << ' ';
            cout << tri[i][j];
        }
        cout << endl;
    }
    return 0;
}