/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/03/09 12:52:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int x = 1, a = 0, b = 0;
    switch (x) {
        case 0:
            b++;
        case 1:
            a++;
            break;
        case 2:
            a++, b++;
    }
    cout << a << ' ' << b << endl;
    return 0;
}