/************************************************************
    File Name : poj3237.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/28 11:15:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int foot;
        cin >> foot;
        if (foot % 2 != 0) {
            cout << "0 0" << endl;
            continue;
        }
        int least_ans = foot / 4 + (foot % 4 / 2);
        int most_ans = foot / 2;
        cout << least_ans << ' ' << most_ans << endl;
    }
    return 0;
}