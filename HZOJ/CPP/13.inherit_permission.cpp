/************************************************************
    File Name : 13.inherit_permission.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/28 18:53:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
   public:
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "My name is : " << __name << ", age: " << age << endl;
    }

   protected:
    string __name;

    // 是声明而不是定义 因为每定义一个对象就会定义一个age 所以只是声明
   private:
    int age;
};

class Cat : public Animal {
   public:
    Cat() = delete;
    // 显式调用父类构造函数
    // 为什么子类无法访问到private却还要继承父类全部的属性和方法？
    // 在子类中访问不到 不代表在子类对象的存储空间中没有存
    // 功能的有效性取决于数据的完整性
    Cat(string name, int age) : Animal(name, age) {}
};

class Bat : protected Animal {
   public:
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
        // cout << "class Bot : " << age << endl;
    }
};

int main() {
    // 先调用父类构造函数 再调用子类构造函数
    Cat a("kitty", 29);
    a.say();
    Bat b("hug", 16384);
    b.say();
    return 0;
}