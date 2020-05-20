/************************************************************
    File Name : #520-等式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/09 19:14:29
************************************************************/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LL long long
#define MAX_N 15000000
LL a, num[MAX_N + 5];

int main() {
    cin >> a;
    for (int i = 1; i <= MAX_N; ++i) {
        num[i] = num[i - 1] + i;
    }
    for (int i = a; 1; ++i) {  // 枚举k
        int l = i + 1, r = MAX_N;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (num[mid] - num[i] == num[i - 1]) {
                cout << i << ' ' << mid << endl;
                return 0;
            }
            if (num[mid] - num[i] > num[i - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return 0;
}