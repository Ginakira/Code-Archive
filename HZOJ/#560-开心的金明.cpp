/************************************************************
    File Name : #560-开心的金明.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 18:45:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 30000
typedef long long LL;

int weight[MAX_N + 5], value[MAX_N + 5], ans[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j > 0; --j) {
            if (j < weight[i]) {
                break;
            } else {
                ans[j] =
                    max(ans[j], (ans[j - weight[i]] + (value[i] * weight[i])));
            }
        }
    }
    cout << ans[n] << endl;
    return 0;
}