/************************************************************
    File Name : #577-讲话模式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 19:30:02
************************************************************/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

map<string, int> saying;
vector<pair<string, int>> ans;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    stringstream ss;
    string basic, s, tmp;
    getline(cin, basic);
    for (int i = 0; i < basic.length(); ++i) {
        if (isalpha(basic[i]) || basic[i] == ' ') {
            if (basic[i] >= 'A' && basic[i] <= 'Z') {
                s.push_back(basic[i] + 32);
            } else {
                s.push_back(basic[i]);
            }
        }
    }
    ss << s;
    while (ss >> tmp) {
        saying[tmp]++;
    }
    for (map<string, int>::iterator it = saying.begin(); it != saying.end();
         ++it) {
        pair<string, int> tmp_pair;
        tmp_pair = make_pair(it->first, it->second);
        ans.push_back(tmp_pair);
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].first << ' ' << ans[0].second;
    return 0;
}