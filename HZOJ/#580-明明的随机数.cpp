/************************************************************
    File Name : #580-明明的随机数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 20:54:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<int> randnum;

int main() {
    int n, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        randnum.insert(tmp);
    }
    set<int>::iterator it;
    cout << randnum.size() << endl;
    for (it = randnum.begin(); it != randnum.end(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}