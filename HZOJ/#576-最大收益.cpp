/************************************************************
    File Name : #576-最大收益.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 20:40:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#define LL long long
using namespace std;

map<string, pair<LL, LL>> shop;

int main() {
    LL n, k, profit, stock, number;
    string product;
    cin >> n >> k;
    while (n--) {
        cin >> product >> profit >> stock;
        shop[product].first = profit;
        shop[product].second = stock;
    }
    LL earn = 0;
    for (LL i = 1; i <= k; ++i) {
        cin >> product >> number;
        if (shop[product].second < number) {
            cout << "-" << i << endl;
            return 0;
        } else {
            earn += number * shop[product].first;
            shop[product].second -= number;
        }
    }
    cout << earn << endl;
    return 0;
}