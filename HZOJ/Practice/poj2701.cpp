/************************************************************
    File Name : poj2701.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/30 11:20:32
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool has_seven_digit(int num) {
    while (num) {
        if (num % 10 == 7) {  
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 7 != 0 && !has_seven_digit(i)) {
            sum += i * i;
        }
    }
    cout << sum << endl;
    return 0;
}