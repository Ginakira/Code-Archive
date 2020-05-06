/************************************************************
    File Name : #591-游戏.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 20:31:49
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if ((m & 1) == 0) {
        int mid = n >> 1;
        if (m <= mid)
            cout << m + 1 << endl;
        else
            cout << m - 1 << endl;
    } else {
        int mid = (n + 1) >> 1;
        if (m < mid)
            cout << m + 1 << endl;
        else
            cout << m - 1 << endl;
    }
    return 0;
}