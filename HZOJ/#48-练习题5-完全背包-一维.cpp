/************************************************************
    File Name : #48-练习题5-完全背包-一维.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/22 20:53:13
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int all, n, w[10005], v[10005], ans[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> all;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= all; ++j) {
            if (j >= w[i]) {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[all] << endl;
    return 0;
}