/************************************************************
    File Name : #474-四级考试.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 20:45:17
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int prob[110][4], ans[200] = {1, 1};

void large_plus(int ans[], int num) {
    for (int i = 1; i <= ans[0]; ++i) {
        if (num == 0) {
            ans[0] = 0;
            return;
        }
        ans[i] *= num;
    }
    for (int i = 1; i <= ans[0]; ++i) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
    return;
}

int clear_zero(int ans[]) {
    for (int i = 1; i <= ans[0]; ++i) {
        if (ans[i]) return i;
    }
    return 0;
}

int main() {
    int n;
    char s[110];
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d%% %d%% %d%% %d%%", &a, &b, &c, &d);
        prob[i][0] = a, prob[i][1] = b;
        prob[i][2] = c, prob[i][3] = d;
    }
    for (int i = 0; i < n; ++i) {
        int tmp = prob[i][s[i] - 'A'];
        large_plus(ans, tmp);
    }
    int pos = clear_zero(ans);
    if (ans[0] > 2 * n) {
        cout << 1 << endl;
        return 0;
    }
    cout << "0";
    if (ans[0]) {
        cout << ".";
        for (int i = ans[0]; i < 2 * n; ++i) {
            cout << '0';
        }
        for (int i = ans[0]; i >= pos; --i) {
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}