/************************************************************
    File Name : #55-寻找666.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 20:37:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int zeller(int y, int m, int d) {
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 +
           1;
}

int main() {
    int sy, sm, sd, ey, em, ed, ans = 0;
    cin >> sy >> sm >> sd >> ey >> em >> ed;
    if (sm > 6 || (sm == 6 && sd > 6)) sy++;
    if (em < 6 || (em == 6 && em < 6)) ey--;
    for (int i = sy; i <= ey; ++i) {
        if (zeller(i, 6, 6) == 6) ans++;
    }
    cout << ans << endl;
    return 0;
}