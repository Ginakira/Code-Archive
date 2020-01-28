/************************************************************
    File Name : #503-独木舟.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 14:49:47
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 30000

int weight[MAXN + 5];
bool is_shipped[MAXN + 5];

int main() {
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    sort(weight, weight + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (is_shipped[i]) continue;
        ans++, is_shipped[i] = true;
        for (int j = n - 1; j > i; --j) {
            if (!is_shipped[j] && weight[j] + weight[i] <= w) {
                is_shipped[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}