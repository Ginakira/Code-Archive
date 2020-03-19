/************************************************************
    File Name : #540-生日购物.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/03/19 09:33:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, cost, price[45], record[2][3000005], cnt[2];

void dfs(int set_num, int start, int end, int sum) {
    if (sum > cost) return;
    for (int i = start; i < end; ++i) {
        sum += price[i];
        record[set_num][cnt[set_num]++] = sum;
        dfs(set_num, i + 1, end, sum);
        sum -= price[i];
    }
    return;
}

int main() {
    while (cin >> n >> cost) {
        cnt[0] = cnt[1] = 1;
        for (int i = 0; i < n; ++i) {
            cin >> price[i];
        }
        dfs(0, 0, n / 2, 0);
        dfs(1, n / 2, n, 0);
        sort(record[1], record[1] + cnt[1]);
        bool solved = false;
        for (int i = 0; i < cnt[0]; ++i) {
            int target = cost - record[0][i];
            int l = 0, r = cnt[1] - 1, mid;
            while (l <= r) {
                mid = (l + r) / 2;
                if (record[1][mid] == target) {
                    solved = true;
                    break;
                }
                if (record[1][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (solved) break;
        }
        cout << (solved ? "YES\n" : "NO\n");
    }
    return 0;
}