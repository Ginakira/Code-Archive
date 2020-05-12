/************************************************************
    File Name : #342-照相的排列数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/12 20:48:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

// 假设新安排进来的是身高最低的

LL solve(LL k) {
    LL a[5] = {0};
    LL full_size = 1;
    for (LL i = 0; i < k; ++i) {
        cin >> a[i];
        full_size *= a[i] + 1;
    }
    // VLA 可变长数组
    LL f[a[0] + 1][a[1] + 1][a[2] + 1][a[3] + 1][a[4] + 1];
    memset(f, 0, sizeof(long long) * full_size);
    f[0][0][0][0][0] = 1;
    for (LL i1 = 0; i1 <= a[0]; ++i1) {
        for (LL i2 = 0; i2 <= a[1]; ++i2) {
            for (LL i3 = 0; i3 <= a[2]; ++i3) {
                for (LL i4 = 0; i4 <= a[3]; ++i4) {
                    for (LL i5 = 0; i5 <= a[4]; ++i5) {
                        LL val = f[i1][i2][i3][i4][i5];
                        if (i1 < a[0] && i1 >= i2 && i1 >= i3 && i1 >= i4 &&
                            i1 >= i5)
                            f[i1 + 1][i2][i3][i4][i5] += val;
                        if (i2 < a[1] && i2 >= i3 && i2 >= i4 && i2 >= i5)
                            f[i1][i2 + 1][i3][i4][i5] += val;
                        if (i3 < a[2] && i3 >= i4 && i3 >= i5)
                            f[i1][i2][i3 + 1][i4][i5] += val;
                        if (i4 < a[3] && i4 >= i5)
                            f[i1][i2][i3][i4 + 1][i5] += val;
                        if (i5 < a[4]) f[i1][i2][i3][i4][i5 + 1] += val;
                    }
                }
            }
        }
    }
    cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
    return 0;
}

int main() {
    LL k;
    while (cin >> k) {
        if (k == 0) break;
        solve(k);
    }
    return 0;
}