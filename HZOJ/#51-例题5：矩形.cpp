/************************************************************
    File Name : #51-例题5：矩形.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/12 20:10:13
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000
#define MOD 100007
int f[MAX_N + 5];
// 可通过一个左上角坐标和右下角坐标确定一个矩形
int a[MAX_N + 5];
// a[i] 当前行第i列 向下数连续白色格子的数量 从最后一行开始往上算
int s[MAX_N + 5], top = -1;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    // 将矩阵倒过来也不影响结果 所以不用存
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, val; j <= m; ++j) {
            cin >> val;
            if (val == 1)
                a[j] += 1;
            else
                a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for (int j = m; j >= 1; j--) {
            while (a[s[top]] >= a[j]) top--;
            f[j] = (s[top] - j) * a[j] + f[s[top]];
            f[j] %= MOD;
            s[++top] = j;
            ans += f[j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}