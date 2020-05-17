/************************************************************
    File Name : #250-糖果传递.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/17 20:11:13
************************************************************/
// 当首尾不产生交换的情况下 c为最终平均值
// 存储第i位发生的代价的前缀和数组Si = |Si - i * c| 累加即为总代价
// 如果成环 则最优的方案中 一定是有两个点没有发生过交换的
// 这样问题就变成了找一个位置从那断开（将其作为计算的第一个位置）
// Si = \sigma{k = 1, i} a_k
// gi = s_i - i * c 代表从1点开始的调整代价

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 1000000
LL a[MAX_N + 5];
LL s[MAX_N + 5];
LL g[MAX_N + 5];
LL n, sum = 0, c, ans = 0;

int main() {
    cin >> n;
    for (LL i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n;
    for (LL i = 1; i <= n; ++i) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    for (LL i = 1; i <= n; ++i) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
