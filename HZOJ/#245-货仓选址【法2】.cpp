/************************************************************
    File Name : #245-货仓选址【法2】.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/21 21:04:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    nth_element(arr, arr + (n >> 1), arr + n);
    int ans = 0, pos = arr[n >> 1];
    for (int i = 0; i < n; ++i) {
        ans += abs(arr[i] - pos);
    }
    cout << ans << endl;
    return 0;
}