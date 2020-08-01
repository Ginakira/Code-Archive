/************************************************************
    File Name : 17.inherit_problem.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 15:13:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct A {
    int x;
};

// 添加virtual关键字 合并相同的父类 解决菱形继承
struct B : virtual public A {
    void set(int x) {
        this->x = x;
        cout << "set : " << &this->x << endl;
    }
};
struct C : virtual public A {
    int get() {
        cout << "get : " << &this->x << endl;
        return this->x;
    }
};
struct D : public B, public C {};

int main() {
    // 问题：指代不明
    D d;
    // 存储空间变大 因为需要存储虚继承相关的信息
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}