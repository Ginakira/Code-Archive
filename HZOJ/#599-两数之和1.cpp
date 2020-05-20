/************************************************************
    File Name : #599-两数之和1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/20 20:21:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> mp;

int main() {
    int n, t, num;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (mp.find(t - num) == mp.end()) {
            mp[num] = i;
        } else {
            cout << mp[t - num] << ' ' << i << endl;
            break;
        }
    }
    return 0;
}