/************************************************************
    File Name : #391-数列分段.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 21:06:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
typedef long long LL;

LL n, m, arr[MAX_N + 5], sum_max, num_max;

LL func(LL tar) {
    LL cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + arr[i] == tar) {
            cnt++, sum = 0;
        } else if (sum + arr[i] > tar) {
            cnt++, sum = arr[i];
        } else
            sum += arr[i];
    }
    if (sum > 0) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum_max += arr[i];
        num_max = max(num_max, arr[i]);
    }
    LL l = num_max, r = sum_max;
    while (l != r) {
        LL mid = (l + r) >> 1;
        LL s = func(mid);
        if (s > m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}