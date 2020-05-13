/************************************************************
    File Name : #503-独木舟.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/13 18:02:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 30000
int a[MAX_N + 5];
bool is_shipped[MAX_N + 5];

int main() {
    int w, n, ans = 0;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (is_shipped[i]) continue;
        ans++, is_shipped[i] = true;
        for (int j = n - 1; j > i; --j) {
            if (!is_shipped[j] && w - a[i] >= a[j]) {
                is_shipped[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}