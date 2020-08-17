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

int mul(int a, int b) { return a * b; }

int add(int a, int b) { return a + b; }

int main() {
    int n = 10000;
    auto a = [&](int a, int b) { return a + b + n; };
    n = 10000000;
    auto b = [&n](int a, int b) { return a + b + n; };
    auto c = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x) { return a(x, x) + b(x, x); };
    };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;
    auto d = c(a, b);
    cout << d(12) << endl;
    auto e = c(add, mul);
    cout << e(12) << endl;
    return 0;
}