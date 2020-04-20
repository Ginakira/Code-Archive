/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/20 14:48:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a = 10, b = 32;
    int const* c = &a;
    // *c = 66;
    c = &b;
    cout << *c << endl;
    return 0;
}