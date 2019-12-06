/************************************************************
    File Name : #513-楼层编号.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 17:19:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool find_num(string a, int num) {
    if(a.find(to_string(num)) == a.npos) return false;
    else return true;
}

int main() {
    int m, t, real = 1;
    cin >> m >> t;
    for(int i = 1; i != m; ++i) {
        if(find_num(to_string(i), t)) continue;
        real++;
    }
    cout << real;
    return 0;
}