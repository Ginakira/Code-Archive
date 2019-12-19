/************************************************************
    File Name : #382-报数（解法2）.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 19:20:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool person[1010];

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    int cnt = 1;
    for (int i = 1; sum < n - 1; i = (i + 1) % n) {
        if (person[i]) continue;
        if (cnt == m) {
            person[i] = 1;
            cnt = 1;
            sum++;
        } else {
            cnt++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!person[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}