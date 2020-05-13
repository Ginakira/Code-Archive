/************************************************************
    File Name : #593-魔法项链.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/13 20:16:11
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 30000
int n, m, ans[MAX_N + 5], mem[MAX_N + 5];  // 每种长度最后的状态
char str[MAX_N + 5];

int main() {
    cin >> n >> m >> &str[1];
    for (int i = 1; i <= n / 2; ++i) {
        int same = 0;
        for (int j = 1, k = i + 1; j <= i; ++j, ++k) {
            if (str[j] == str[k]) same++;
        }
        ans[same]++;
        for (int j = 2; j + 2 * i - 1 <= n; ++j) {
            if (str[j - 1] == str[j - 1 + i]) same--;
            if (str[j + i - 1] == str[j + 2 * i - 1]) same++;
            ans[same]++;
        }
        mem[i] = same;
    }
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 2) {
            cin >> t;
            cout << ans[t] << endl;
            continue;
        }
        char l;
        cin >> l;
        str[++n] = l;
        if (n % 2 == 0) {
            int same = 0, mid = n >> 1;
            for (int j = 1, k = 1 + mid; j <= mid; ++j, ++k) {
                if (str[j] == str[k]) same++;
            }
            ans[same]++;
            mem[mid] = same;
        }
        for (int j = 1; j <= (n - 1) / 2; ++j) {
            if (str[n - j - j] == str[n - j]) mem[j]--;
            if (str[n] == str[n - j]) mem[j]++;
            ans[mem[j]]++;
        }
    }
    return 0;
}