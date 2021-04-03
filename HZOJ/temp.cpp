/*************************************************************************
        > File Name: 2.cpp
        > Author: wangjianduo
        > Mail: 448000069@qq.com
        > Created Time: 2021年04月02日 星期五 12时33分54秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
string s;
long long cnt = 1, ans;

int main() {
    while (cin >> s) {
        if (s == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        if (s == "pop") {
            ans += q.front() * cnt;
            cnt++;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
