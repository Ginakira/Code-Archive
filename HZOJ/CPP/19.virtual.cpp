/************************************************************
    File Name : 19.virtual.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 16:40:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    int x;
};

class B {
   public:
    int x;
    void run() {}
};

class C {
   public:
    int x;
    virtual void run() {}
    virtual void run1() {}
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    return 0;
}