/************************************************************
    File Name : #587-环.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 18:07:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, a, b, c, cnt = 0;
    cin >> n >> a >> b >> c;
    if (a > b) cnt++;
    if (b > c) cnt++;
    if (c > a) cnt++;
    cout << (cnt == 1 ? 1 : 0) << endl;
    return 0;
}