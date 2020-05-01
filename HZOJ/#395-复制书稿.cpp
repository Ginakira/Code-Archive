/************************************************************
    File Name : #395-复制书稿.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/01 16:35:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500
int m, k;
int page[MAX_N + 5], ans[MAX_N + 5][2];

int calc(int mid) {
    int cnt = 0, now_sum = 0;
    for (int i = 0; i < m; ++i) {
        if (now_sum + page[i] == mid) {
            now_sum = 0;
            cnt++;
        } else if (now_sum + page[i] > mid) {
            now_sum = page[i];
            cnt++;
        } else {
            now_sum += page[i];
        }
    }
    if (now_sum) cnt++;
    return cnt;
}

int main() {
    cin >> m >> k;
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> page[i];
        sum += page[i];
    }
    int l = 0, r = sum;
    while (l != r) {
        int mid = (l + r) >> 1;
        int cnt = calc(mid);
        if (cnt > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ans[k][1] = m;
    int now = page[m - 1], j = k;
    for (int i = m - 2; i >= 0; --i) {
        if (now + page[i] > l) {
            ans[j][0] = i + 2;
            j--;
            now = page[i];
            ans[j][1] = i + 1;
        } else if (now + page[i] == l) {
            ans[j][0] = i + 1;
            j--, i--;
            now = page[i]
            ans[j][1] = i + 1;
        } else {
            now += page[i];
        }
    }
    ans[1][0] = 1;
    for (int i = 1; i <= k; ++i) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }

    return 0;
}