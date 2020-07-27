/************************************************************
    File Name : 12.operator3.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/27 20:06:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 内部实现
class A {
   public:
    int x, y;
};

class B {
   public:
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }

    B(A *obj) : B() { this->obj = obj; }

    int operator()(int a, int b) { return a + b; }

    int &operator[](int ind) { return arr[ind]; }

    void operator[](const char *msg) {
        cout << msg << endl;
        return;
    }

    // 重载间接引用运算符 单目运算符
    // 智能指针也是重载了间接引用运算符 使其外在表现与传统指针一致
    A *operator->() { return obj; }

    // 重载取值运算符
    A &operator*() { return *obj; }

    ~B() { delete arr; }

   private:
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << ", " << a.y << ")";
    return out;
}

// 外部表现
int main() {
    B add;
    // 函数对象 其表现与函数相似
    // 通过重载小括号运算符实现
    cout << add(3, 4) << endl;
    // 数组对象
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];
    // p是指针对象而并不是指针 只是表现得像指针
    A a;
    a.x = 67, a.y = 99;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;
    return 0;
}