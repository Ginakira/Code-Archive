/************************************************************
    File Name : 1.stl.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/21 19:52:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    // int op, val;
    // queue<int> q;
    // while (cin >> op >> val) {
    //     switch (op) {
    //         case 1:
    //             q.push(val);
    //             break;
    //         case 2:
    //             q.pop();
    //             break;
    //         case 3:
    //             cout << q.front() << endl;
    //             break;
    //     }
    //     cout << "Queue size:" << q.size()
    //          << ", empty: " << (q.empty() ? "true" : "false") << endl;
    // }

    string s1 = "hello", s2 = "world";
    s1 += " ";
    s1 += s2;
    cout << s1 << endl;

    for (int i = 0; i < s1.size(); ++i) {
        cout << s1[i] << endl;
    }
    return 0;
}