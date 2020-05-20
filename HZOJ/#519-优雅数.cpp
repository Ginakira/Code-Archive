/************************************************************
    File Name : #519-优雅数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/20 08:48:54
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;
using namespace std;

int main() {
    LL a, b, ans = 0;
    cin >> a >> b;
    for (int i = 0; i <= 9; ++i) {      // 0-9 其他相同的位
        for (int j = 0; j <= 9; ++j) {  // 0-9 不一样的那位
            if (i == j) continue;
            for (int k = 3; k <= 17; ++k) {     // 优雅数位数
                for (int l = 1; l <= k; ++l) {  // 逐位生成 当前位数
                    if (l == 1 && j == 0) continue;  // 忽略前导0
                    if (l != 1 && i == 0) break;
                    LL t = 0;
                    for (int m = 1; m <= k; ++m) {  // 生成一个优雅数
                        if (m == l) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if (t >= a && t <= b) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}