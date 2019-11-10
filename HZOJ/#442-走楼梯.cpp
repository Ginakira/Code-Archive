#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int f[33] = {0, 1, 2};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if(i > 2) f[i] = f[i - 1] + f[i - 2];
        if (i != 1) cout << ' ';
        cout << f[i];
    }
    return 0;
}