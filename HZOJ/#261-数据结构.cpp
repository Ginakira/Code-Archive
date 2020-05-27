/************************************************************
    File Name : #261-数据结构.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/27 23:04:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 1000
LL sum[MAX_N + 5];
LL f[MAX_N + 5];

int main() {
    int n;
    f[0] = 0x8000000000000000;
    stack<LL> s1, s2;
    char op[10];
    cin >> n;
    while (n--) {
        cin >> op;
        switch (op[0]) {
            case 'I': {
                LL x;
                cin >> x;
                s1.push(x);
                int ind = s1.size();
                sum[ind] = sum[ind - 1] + x;
                f[ind] = max(f[ind - 1], sum[ind]);
            } break;
            case 'D': {
                if (!s1.empty()) s1.pop();
            } break;
            case 'L': {
                if (s1.empty()) break;
                s2.push(s1.top());
                s1.pop();
            } break;
            case 'R': {
                if (s2.empty()) break;
                s1.push(s2.top());
                int ind = s1.size();
                sum[ind] = sum[ind - 1] + s2.top();
                f[ind] = max(f[ind - 1], sum[ind]);
                s2.pop();
            } break;
            case 'Q': {
                int k;
                cin >> k;
                cout << f[k] << endl;
            } break;
        }
    }
    return 0;
}