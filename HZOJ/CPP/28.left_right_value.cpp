/************************************************************
    File Name : 28.left_right_value.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/02 20:24:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define TEST(a, f)           \
    {                        \
        cout << #a << " : "; \
        f(a);                \
    }

void f2(int &x) {
    cout << "left value" << endl;
    return;
}

void f2(int &&x) {
    cout << "right value" << endl;
    return;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
    return;
}

void f(int &&x) {
    cout << "right value" << endl;
    TEST(forward<int &&>(x), f2);
    TEST(move(x), f2);
    return;
}

int main() {
    int a, b = 1, c = 3;
    a = b;
    (++a) = b + c;
    cout << a << endl;
    // (a++) = b + c;
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 6;
    (a += 3);

    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    return 0;
}
