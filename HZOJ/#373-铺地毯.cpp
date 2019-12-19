/************************************************************
    File Name : #373-铺地毯.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 20:38:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#define MAXN 10010
using namespace std;

int map[MAXN][4];

int main() {
    int n, g, k;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> map[i][0] >> map[i][1] >> g >> k;
        map[i][2] = map[i][0] + g;
        map[i][3] = map[i][1] + k;
    }
    int x, y, ans = -1;
    cin >> x >> y;
    for (int i = 1; i <= n; ++i) {
        if (x >= map[i][0] && x <= map[i][2] && y >= map[i][1] &&
            y <= map[i][3])
            ans = i;
    }
    cout << ans << endl;
    return 0;
}