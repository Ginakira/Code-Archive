/************************************************************
    File Name : #558-采药.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/22 21:10:53
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, M, v[105], w[105], ans[1005];

// 01-Knapsack
int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = T; j; --j) {
            if (j < w[i]) {
                break;
            } else {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[T] << endl;
    return 0;
}