/************************************************************
    File Name : #379-仓库日志.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/16 10:42:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct goods {
    int data, max;
};

goods tmp_good{0, 0};

stack<goods> s;
int main() {
    int N, op;
    cin >> N;
    while (N--) {
        cin >> op;
        switch (op) {
            case 0: {
                cin >> tmp_good.data;
                tmp_good.max = max(tmp_good.data, tmp_good.max);
                s.push(tmp_good);
            } break;
            case 1: {
                if (!s.empty()) {
                    s.pop();
                    tmp_good.max = s.empty() ? 0 : s.top().max;
                }
            } break;
            case 2: {
                if (s.empty()) {
                    cout << 0 << endl;
                    break;
                }
                cout << s.top().max << endl;
            } break;
        }
    }
    return 0;
}