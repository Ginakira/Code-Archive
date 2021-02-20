/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/02/19 20:43:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base {
   public:
    void foo(int a) { cout << "Base Functin: int" << endl; }
    void foo(int a, double b) { cout << "Base Function: int, double" << endl; }
};

class Sub : public Base {
   public:
    void foo(int a) { cout << "Sub Function: int" << endl; }
};

int main() {
    Sub obj;
    obj.foo(2);
    return 0;
}