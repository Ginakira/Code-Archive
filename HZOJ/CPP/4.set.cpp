/************************************************************
    File Name : 4.set.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/23 18:15:37
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    set<int> s;
    s.insert(235);
    s.insert(43);
    s.insert(99);
    s.insert(90);
    cout << s.size() << endl;
    s.insert(90);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *(s.begin()) << endl;
    return 0;
}