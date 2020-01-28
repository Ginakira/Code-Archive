/************************************************************
    File Name : #82-伐木.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 11:20:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000000
int n, m, tree[MAXN + 5];

bool is_valid(int num) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (tree[i] > num ? tree[i] - num : 0);
        if (sum >= m) return true;
    }
    return false;
}

int binarySearch(int start) {
    int left = 0, right = start, mid;
    while (left < right) {
        mid = (left + right + 1) >> 1;
        if (is_valid(mid))
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    cin >> n >> m;
    int max_h = -1;
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
        max_h = max(max_h, tree[i]);
    }
    cout << binarySearch(max_h);
    return 0;
}