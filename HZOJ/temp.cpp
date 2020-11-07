/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/28 21:55:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int num = 3, cnt = 0;
    while (num) {
        if (num & 1) {
            cnt++;
        }
        num >>= 1;
        cout << "\033[32mCount one digit\033[0m" << endl;
    }
    cout << cnt << endl;
    return 0;
}
