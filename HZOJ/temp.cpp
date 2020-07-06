/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/04 10:58:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    __int64_t mask = 0x8000000000000000;
    double a = 0.111, b = -4.200001;
    int sa = (__int64_t)a & mask;
    int sb = (__int64_t)b & mask;
    cout << sa << ' ' << sb;
    return 0;
}