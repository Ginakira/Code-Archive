/************************************************************
    File Name : #49-练习题6：多重背包.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 19:41:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

// 按二进制位权拆成普通01 可以组成所有的可能

int all, n, ind, w[MAX_N + 5], v[MAX_N + 5], ans[MAX_N + 5];
int t[20];

int main() {
    int tt = 1;
    for (int i = 0; i < 20; ++i) {
        t[i] = tt;
        tt *= 2;
    }

    cin >> all >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z, temp = 0;
        cin >> x >> y >> z;
        while (z > 0) {
            ind++;
            if (z >= t[temp]) {
                w[ind] = x * t[temp];
                v[ind] = y * t[temp];
                z -= t[temp];
            } else {
                w[ind] = x * z;
                v[ind] = y * z;
                z = 0;
            }
            temp++;
        }
    }
    for (int i = 1; i <= ind; ++i) {
        for (int j = all; j >= w[i]; --j) {
            ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}