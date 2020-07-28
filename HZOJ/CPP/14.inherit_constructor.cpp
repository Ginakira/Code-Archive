/************************************************************
    File Name : 14.inherit_constructor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/28 19:55:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class D {
   public:
    D() { cout << "D constructor" << endl; }
    ~D() { cout << "D destrouctor" << endl; }
};

class A {
   public:
    A() = delete;
    A(int x, int y) { cout << "A constructor" << endl; }
    ~A() { cout << "A destructor" << endl; }
};

class B {
   public:
    B() { cout << "B constructor" << endl; }
    ~B() { cout << "B destructor" << endl; }
};

class C : public D {
   public:
    // 隐式 默认行为 不写时采用默认初始化
    // C() : a(), b() { cout << "C constructor" << endl; }
    // C() : b(), a() { cout << "C constructor" << endl; }
    // 输出顺序不变化，初始化列表只规定了怎么初始化而并没有规定初始化顺序
    // 初始化列表中的初始化顺序只与成员属性的声明顺序有关
    C() : a(3, 4) { cout << "C constructor" << endl; }

    ~C() { cout << "C destrouctor" << endl; }

   private:
    B b;
    A a;
};

int main() {
    C c;
    return 0;
}