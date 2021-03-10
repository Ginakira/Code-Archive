/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/03/09 20:50:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a = 1, b = 1;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << ' ' << b << endl;
    return 0;
}