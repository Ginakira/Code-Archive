/************************************************************
    File Name : 20.virtual.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 16:54:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A() = default;
    A(string s) { cout << "param constructor" << endl; }
    A(const A &a) { cout << "copy constructor" << endl; }
    int x;
    virtual void say(int xx) {
        cout << this << endl;
        cout << "Class A : I can say, xx = " << xx << ", this->x = " << this->x
             << endl;
        return;
    }
};

typedef void (*func)(int);
typedef void (*func2)(void *, int);

A retA() {
    // 因为构造函数也是成员函数 所以也存在this指针
    // 所以返回值优化还有另外一种实现方法 就是将this改变为外面的temp_c的地址
    A temp_a("Hello world");
    return temp_a;
}

int main() {
    cout << sizeof(A) << endl;
    A temp_a, temp_b;
    temp_a.x = 9973;
    temp_b.x = 10000;

    // 因为是成员方法 所以有一个特殊的指针变量this
    // 所以say方法的第一个参数根本就不是x，而是一个隐藏的this
    // ((func **)(&temp_a))[0][0](6);
    // 虽然调用的是a的方法，但是this指针传入的是b，所以方法中的this指向的是b
    ((func2 **)(&temp_a))[0][0](&temp_b, 6);

    // 没有返回值优化 会拷贝两次
    // 有返回值优化 不会调用拷贝
    A temp_c = retA();
    temp_c.say(2333);
    return 0;
}