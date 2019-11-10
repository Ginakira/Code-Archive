#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool is_ugly(int x) {
    while(x % 5 == 0) {
        x /= 5;
    }
    while(x % 3 == 0) {
        x /= 3;
    }
    while(x % 2 == 0) {
        x /= 2;
    }
    return x == 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (is_ugly(i)) cout << i << endl;
    }
    return 0;
}