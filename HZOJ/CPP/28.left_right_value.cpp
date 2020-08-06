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

int test_func(const int &&x) {
    cout << x << endl;
    return 0;
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
    // 右值绑定到左值引用上
    test_func(123);
    // 左值无法绑定到右值引用上
    // 因为右值引用意味着这个值只是一个临时值 马上要被销毁了
    // test_func(a);
    return 0;
}
