/************************************************************
    File Name : 25.constexpr.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/02 18:56:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int f(int x) { return 3 * x * x + x; }

class A {
   public:
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};

int main() {
    int n;
    cin >> n;
    // constexpr int m = 2 * n;
    constexpr int m = f(12);
    cout << m << endl;
    constexpr A a(2, 3);
    cout << a.x << endl;
    return 0;
}