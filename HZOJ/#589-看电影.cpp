/************************************************************
    File Name : #589-看电影.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 18:36:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, k, id;
    cin >> n >> k >> id;
    int gcd_num = gcd(n, k);
    cout << k / gcd_num << '/' << n / gcd_num << endl;
    return 0;
}