/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/21 15:54:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct A {
    int data;
    A(int data) : data{data} {}
};

struct B : virtual A {
    B() : A{1} { cout << data << endl; }
};

struct C : A {
    C() : A{2} { cout << data << endl; }
};

struct D : B, C {
    D() : A{3} {}
};

int main() {
    D d;
    cout << d.data << endl;
    return 0;
}