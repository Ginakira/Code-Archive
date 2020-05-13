/************************************************************
    File Name : #508-两人过河.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/13 19:14:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000
int n, num[MAX_N + 5], ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {
            ans += num[0];
            break;
        } else if (i == 1) {
            ans += num[1];
            break;
        } else if (i == 2) {
            ans += num[0] + num[1] + num[2];
            break;
        }
        // 1. 最快 + 次快。最快回，最慢 + 次慢，次快回。过河快
        // 2. 最慢 + 最快。最快回，最快 + 次慢，最快回。送手电筒快
        ans += min(num[1] + num[0] + num[i] + num[1],
                   num[i] + num[0] + num[i - 1] + num[0]);
    }
    cout << ans << endl;
    return 0;
}