/************************************************************
    File Name : 38.protected.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/20 09:35:32
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A() {
        x = rand() % 100;
        cout << this << " init x value : " << x << endl;
    }

   protected:
    int x;
};

class C : public A {
   public:
    int z;
};

/**
 * static_cast是在编译阶段的转换，dynamic_cast是运行期的转换
 * 在子类中转换为父类的引用后
 * 无法确定传进来的对象是否是B类的对象（是否继承自A类）
 * 只有转换的类型与外面的类型是一样的 才能访问受保护的成员
 */

class B : public A {
   public:
    void say(B &b) {
        // cout << &b << " x value : " << (static_cast<A &>(b)).x << endl;
        return;
    }

    void say(C &c) {
        // cout << &c << " x value : " << (static_cast<A &>(c)).x << endl;
    }
};

int main() {
    B b1, b2;
    b1.say(b2);
    return 0;
}