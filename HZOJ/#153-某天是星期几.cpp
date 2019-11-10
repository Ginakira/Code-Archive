#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int day[7] = {6, 7, 1, 2, 3, 4, 5};
int main() {
    int y, m, d, ans;
    cin >> y >> m >> d;
    if (m == 1) m = 13, y--;
    if (m == 2) m = 14, y--;
    int k = y % 100, j = y / 100;
    ans = (d + (26 * (m + 1) / 10) + k + k / 4 + j / 4 + 5 * j) % 7;
    cout << day[ans];
    return 0;
}