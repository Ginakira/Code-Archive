/************************************************************
    File Name : #383-周末舞会.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 19:29:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> male, female;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 1; i <= x; ++i) male.push(i);
    for (int i = 1; i <= y; ++i) female.push(i);
    for (int i = 0; i < n; ++i) {
        cout << male.front() << ' ' << female.front() << endl;
        male.push(male.front());
        female.push(female.front());
        male.pop();
        female.pop();
    };
    return 0;
}