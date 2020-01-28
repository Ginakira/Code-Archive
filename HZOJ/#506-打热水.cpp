/************************************************************
    File Name : #506-打热水.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 14:25:57
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

pair<int, int> arr[35];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + n + 1, cmp);
    double sum = 0, total = 0;
    for (int i = 1; i <= n; ++i) {
        i > 1 && cout << " ";
        cout << arr[i].second;
        sum += arr[i - 1].first;
        total += sum;
    }
    printf("\n%.2f", total / n);
    return 0;
}