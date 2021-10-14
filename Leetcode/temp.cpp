/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/10/11 22:39:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A() { cout << "A constructor\n"; }
    virtual ~A() { cout << "A destructor\n"; }
};

class B : public A {
   public:
    B() { cout << "B constructor\n"; }
    ~B() override { cout << "B destructor\n"; }
};

int main() {
    A *b = new B;
    delete b;
    return 0;
}