/************************************************************
    File Name : 15.inherit_copy.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/28 20:44:54
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
        cout << "class A default constructor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) { cout << "class A copy constructor : " << this << endl; }
    void say() { cout << "Class A" << endl; }
    int x;
};

class B : public A {
   public:
    B() {
        this->y = 0x05060708;
        cout << "class B default constructor" << endl;
    }
    // 不完整的拷贝构造
    // B(const B &b) { cout << "class B copy constructor" << endl; }
    // 虽然A类的拷贝构造需要A&类型的参数 但是B& b可以转换成其父类的表现形式
    // 因为B类是从A类继承过来的 其对象拥有所有的A类的属性
    B(const B &b) : A(b) {
        cout << "class B copy constructor : " << this << endl;
    }
    // 可以看到输出的this地址一致，说明其头部存储的是父类对象的信息
    // 因为相关的对象从子类父类中 这样的设计可以使其实的位置无需改变
    // 在内存排布上 父类的信息在前面存储 子类的信息在后面存储
    void func() { A::say(); }
    void say() { cout << "Class B" << endl; }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for (int i = 0; i < sizeof(B); ++i) {
        printf("%X", msg[i]);
        // 为什么是倒过来存的？因为使用的是小端系统 数字低位存在低地址位
        // 输出的是从低地址到高地址 大小端都是对于变量的存储方式而言的
        // 而非整块内存
    }
    printf("\n");
    return 0;
}