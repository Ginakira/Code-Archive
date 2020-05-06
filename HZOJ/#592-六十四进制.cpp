/************************************************************
    File Name : #592-六十四进制.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 20:48:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007

int num[64];  // i转成二进制后有几个1
int num2[10] = {1, 2, 4, 8, 16, 32};
long long ans = 1;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < 64; ++i) {
        int t = i;
        for (int j = 5; j >= 0; --j) {
            if (t >= num2[j]) {
                num[i]++;
                t -= num2[j];
            }
        }
    }
    for (char c : str) {
        int t;
        if (c >= '0' && c <= '9') {
            t = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            t = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            t = c - 'a' + 36;
        } else if (c == '-') {
            t = 62;
        } else {
            t = 63;
        }
        t = 6 - num[t];  // 0的个数
        // 每一个0有3种方案 所以在这一位上有多少个0答案就乘以多少次3
        for (int i = 0; i < t; ++i) {
            ans = ans * 3 % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}