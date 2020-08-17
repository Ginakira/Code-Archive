/************************************************************
    File Name : 36.lambda.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/17 09:57:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    auto a = [](int a, int b) -> double {
        double c = 12.3;
        if (rand() % 2) {
            return c;
        } else {
            return a + b;
        }
    };
    auto b = [](int a, int b) { return a + b; };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(123, 456) << endl;
    cout << b(234, 435) << endl;
    return 0;
}