/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/07/16 09:42:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
bool foo(T arg) {
    return true;
}

template <>
bool foo(float arg) {
    return false;
}

int main() {
    cout << foo(1) << endl;
    cout << foo(1.0f) << endl;
    return 0;
}