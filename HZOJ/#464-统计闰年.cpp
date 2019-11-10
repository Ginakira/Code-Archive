#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool is_leap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return true;
    else
        return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int i = x; i <= y; ++i) {
        cnt = is_leap(i) ? cnt + 1 : cnt;
    }
    cout << cnt;
    return 0;
}