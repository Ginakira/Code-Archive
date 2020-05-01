/************************************************************
    File Name : #394-跳石头.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/01 13:09:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int l1, n, m, num[500005] = {0};
    cin >> l1 >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    num[n + 1] = l1;
    int l = 0, r = l1;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = 0, last = 0;
        for (int i = 1; i <= n + 1; ++i) {
            if (num[i] - last < mid) {
                cnt++;
            } else {
                last = num[i];
            }
        }
        if (cnt <= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;

    return 0;
}