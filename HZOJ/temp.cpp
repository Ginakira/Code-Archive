/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/01/31 22:19:18
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define F(obj, name) (char *)(&(obj.name)) - (char *)(&(obj))

struct Foo {
    char a;
    int b;
    char c;
    struct {
        char d[20];
        long long e;
        char f;
    };
};

int main() {
    Foo foo;
    cout << sizeof(foo) << endl;
    cout << F(foo, a) << endl;
    cout << F(foo, b) << endl;
    cout << F(foo, c) << endl;
    cout << F(foo, d) << endl;
    cout << F(foo, e) << endl;
    cout << F(foo, f) << endl;

    return 0;
}