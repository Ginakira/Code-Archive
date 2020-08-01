/************************************************************
    File Name : 18.virtual.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 15:51:19
************************************************************/
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
   public:
    virtual void run() {
        cout << "I don't know how to run" << endl;
        return;
    }
};

class Cat : public Animal {
   public:
    void run() override {
        cout << "I can run with four legs" << endl;
        return;
    }
};

class Dog : public Animal {
   public:
    void run() override {
        cout << "I can run and wag tail." << endl;
        return;
    }
};

class Bat : public Animal {
   public:
    void run() override {
        cout << "I can fly." << endl;
        return;
    }
};

int main() {
    srand(time(0));
    Cat a;
    Animal &b = a;
    Animal *c[10];
    a.run();
    b.run();

    for (int i = 0; i < 10; ++i) {
        int op = rand() % 3;
        switch (op) {
            case 0:
                c[i] = new Cat();
                break;
            case 1:
                c[i] = new Dog();
                break;
            case 2:
                c[i] = new Bat();
                break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        c[i]->run();
    }
    return 0;
}