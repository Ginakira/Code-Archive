/************************************************************
    File Name : #566-上网统计.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-24 18:57:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string order[1010];
map<string, vector<string>> netlog;

int main() {
    int cnt = 0, n, m;
    string user, page;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> user >> page;
        if (netlog.count(user) == 0) {
            order[cnt++] = user;
        }
        netlog[user].push_back(page);
    }
    for (int i = 0; i < cnt; ++i) {
        cout << order[i];
        vector<string>::iterator it;
        for (it = netlog[order[i]].begin(); it != netlog[order[i]].end();
             ++it) {
            cout << ' ' << *it;
        }
        cout << endl;
    }
    return 0;
}