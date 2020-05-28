/************************************************************
    File Name : #573-桐桐的新闻系统.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 11:04:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct User {
    int id, stamp, period;

    bool operator<(const User &a) const {
        if (stamp == a.stamp) return id > a.id;
        return stamp > a.stamp;
    }
};

priority_queue<User> q;

int main() {
    string op;
    while (cin >> op && op != "#") {
        int id, period;
        cin >> id >> period;
        q.push({id, period, period});
    }
    int k;
    cin >> k;
    while (k) {
        User temp = q.top();
        q.pop();
        cout << temp.id << endl;
        q.push({temp.id, temp.stamp + temp.period, temp.period});
        k--;
    }
    return 0;
}