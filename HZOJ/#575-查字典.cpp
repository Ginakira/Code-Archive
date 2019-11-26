/************************************************************
    File Name : #575-查字典.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 20:34:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> dict;

int main() {
    int n, m, page;
    string word;
    cin >> n;
    while (n--) {
        cin >> word >> page;
        dict[word] = page;
    }
    cin >> m;
    while (m--) {
        cin >> word;
        cout << dict[word] << endl;
    }
    return 0;
}