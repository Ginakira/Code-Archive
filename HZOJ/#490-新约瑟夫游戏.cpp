/************************************************************
    File Name : #490-新约瑟夫游戏.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/28 19:10:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 32767

int f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;
        // f[n] = (f[n - 1] + k - 1) % n + 1; k 每数k个人踢一个
    }
    int x = n;
    while (f[x] - x) x = f[x];
    cout << n + x << endl;
    return 0;
}