/************************************************************
    File Name : #606-最大子段和.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/23 21:13:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000
#define INF 0x3f3f3f3f

int main() {
    int n;
    cin >> n;
    int arr[MAX_N + 5];
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int ans = -INF;
    arr[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        arr[i] = max(arr[i], arr[i - 1] + arr[i]);
        ans = max(ans, arr[i]);
    }
    cout << ans << endl;
    return 0;
}