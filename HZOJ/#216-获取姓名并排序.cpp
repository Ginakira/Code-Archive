/************************************************************
    File Name : #216-获取姓名并排序.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/23 18:27:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    set<PSI> s;
    string name;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        name = name.substr(name.find(".") + 1, name.length());
        s.insert(PSI(name, i));
    }
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        cout << iter->first << endl;
    }
    return 0;
}