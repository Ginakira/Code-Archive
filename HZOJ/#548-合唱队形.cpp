/************************************************************
    File Name : #548-合唱队形.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/05 23:33:04
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000
#define INF 0x3f3f3f3f
int a[MAX_N + 5];
int dp_desc[MAX_N + 5];  // 最长下降
int dp_asc[MAX_N + 5];   // 最长上升

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp_desc[i] = 1;
        dp_asc[i] = 1;
    }

    int ans = INF;
    for (int mid = 1; mid <= n; ++mid) {
        fill(dp_asc, dp_asc + n + 1, 1);
        fill(dp_desc, dp_desc + n + 1, 1);
        int ans_desc = 0, ans_asc = 0;
        for (int i = 1; i <= mid; ++i) {
            for (int j = 1; j < i; ++j) {
                if (a[j] < a[i]) {
                    dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
                }
            }
            ans_asc = max(ans_asc, dp_asc[i]);
        }
        for (int i = mid; i <= n; ++i) {
            for (int j = mid; j < i; ++j) {
                if (a[j] > a[i]) {
                    dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1);
                }
            }
            ans_desc = max(ans_desc, dp_desc[i]);
        }
        ans = min(ans, n - (ans_asc + ans_desc - 1));
    }
    cout << ans << endl;

    return 0;
}