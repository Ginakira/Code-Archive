/************************************************************
    File Name : 23.dynamic_cast.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 20:26:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    virtual ~A() = default;

   private:
};

class B : public A {
   public:
    void sayB() {
        cout << "this is class B, x = " << x << endl;
        return;
    }
    int x;
};
class C : public A {
   public:
    void sayC() {
        cout << "this is class C, x = " << x << endl;
        return;
    }
    double x;
};
class D : public A {
   public:
    void sayD() {
        cout << "this is class D, x = " << x << endl;
        return;
    }
    string x;
};

int my_dynamic_cast(A *ta) {
    char **pa = (char **)(ta);
    char **pb = (char **)new B();
    char **pc = (char **)new C();
    char **pd = (char **)new D();
    int ret = -1;
    if (pa[0] == pb[0]) {
        ret = 0;
    } else if (pa[0] == pc[0]) {
        ret = 1;
    } else if (pa[0] == pd[0]) {
        ret = 2;
    }
    return ret;
}

int main() {
    srand(time(0));
    A *pa;
    B *pb;
    C *pc;
    D *pd;
    switch (rand() % 3) {
        case 0:
            pb = new B();
            pa = pb;
            pb->x = 123;
            break;
        case 1:
            pc = new C();
            pa = pc;
            pc->x = 45.6;
            break;
        case 2:
            pd = new D();
            pa = pd;
            pd->x = "Hello haizei";
            break;
    }

    // 如果pa指向的不是一个B类的对象，返回的是一个空地址
    // 如果A类不是多态的（不是虚函数） 将编译报错
    // 为什么要必须是多态的？
    // 因为如果是多态的，那么其派生类的对象前八个字节会存储一个虚函数表
    // 而同一个派生类下面的所有对象虚函数表地址都是一致的
    // 所以dynamic_cast根据虚函数表地址的比较结果来判断是否是某个派生类对象的
    if ((pb = dynamic_cast<B *>(pa))) {
        cout << "Class B : ";
        pb->sayB();
    } else if ((pc = dynamic_cast<C *>(pa))) {
        cout << "Class C : ";
        pc->sayC();
    } else if ((pd = dynamic_cast<D *>(pa))) {
        cout << "Class D : ";
        pd->sayD();
    }

    // 仿照实现dynamic_cast
    switch (my_dynamic_cast(pa)) {
        case 0:
            ((B *)(pa))->sayB();
            break;
        case 1:
            ((C *)(pa))->sayC();
            break;
        case 2:
            ((D *)(pa))->sayD();
            break;
    }

    return 0;
}