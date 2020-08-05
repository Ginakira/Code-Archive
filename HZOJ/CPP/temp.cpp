/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/05 22:15:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A() { cout << "constructor" << endl; }
    A(const A &obj) { cout << "copy constructor" << endl; }
};

A func() {
    A temp;
    return temp;
}
int main() {
    A a(func()); 
    return 0;
}