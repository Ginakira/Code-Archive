/************************************************************
    File Name : #251-士兵.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/17 20:50:54
************************************************************/
// 移动距离 \sigma{i = 1, n} | Y_i - pos |
// 与货仓选址一样 所以pos应该是中位数
// X为要移动到的位置 第i个点最后的位置应该是X_i + i
// 所以某个点X方向的移动代价 |X_i - X - i|
// X的总代价为 将其累加 \sigma{i = 1, n} |X_i - X - i|
// 用w_i代替X_i - i 则为 \sigma{i = 1, n} |w_i - X|
// 又转化成了货仓选址问题 所以X要移动到的 也是中位数

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000
int x[MAX_N + 5];
int y[MAX_N + 5];
int w[MAX_N + 5];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    sort(y, y + n);
    sort(x, x + n);
    for (int i = 0; i < n; ++i) w[i] = x[i] - i;
    sort(w, w + n);
    int sum = 0, cy = y[n >> 1], cw = w[n >> 1];
    for (int i = 0; i < n; ++i) {
        sum += abs(y[i] - cy);
        sum += abs(w[i] - cw);
    }
    cout << sum << endl;
    return 0;
}