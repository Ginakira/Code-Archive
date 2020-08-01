/************************************************************
    File Name : 22.virtual_destructor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 20:12:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base {
   public:
    Base() {
        cout << "Base constructor" << endl;
        this->x = new int;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
        delete this->x;
    }

   private:
    int *x;
};

class Base_A : public Base {
   public:
    Base_A() {
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }
    ~Base_A() {
        cout << "Base_A destructor" << endl;
        delete this->y;
    }

   private:
    int *y;
};

int main() {
    Base *ba = new Base_A;
    // 如果父类的析构方法不写成虚函数
    // 只调用了Base的析构函数 造成内存泄露
    // 因为析构函数也是属于普通的成员方法 因为标识符类型是ba
    // 所以只会调用Base的析构函数
    // 在拥有继承的关系中，父类的析构函数一定是虚函数。是为了保证正确地释放掉子类的空间
    delete ba;
    return 0;
}