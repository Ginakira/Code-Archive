/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/08 23:34:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string rand_name(int n) {
    string name = "";
    for (int i = 0; i < n; ++i) {
        name += (char)(rand() % 26 + 'A');
    }
    return name;
}

class Animal {
   public:
    Animal(string name) : __name(name) {}
    string tell_me_your_name() { return this->__name; }
    virtual void run() { cout << "I don't know how to run" << endl; }
    virtual void say() = 0;
    virtual ~Animal() { cout << "Animal destructor" << endl; }

   private:
    string __name;
};

class Cat : public Animal {
   public:
    Cat() : Animal(rand_name(5) + "Cat") {}
    void run() override {
        cout << "I can run with four legs" << endl;
        return;
    }
    void say() override {
        cout << "Meow meow meow" << endl;
        return;
    }
    ~Cat() { cout << "Cat destructor" << endl; }

   private:
};

class Bat : public Animal {
   public:
    Bat() : Animal(rand_name(5) + "Bat") {}
    void run() override {
        cout << "I can fly" << endl;
        return;
    }
    void say() override {
        cout << "zzz zzz zzz" << endl;
        return;
    }
    ~Bat() { cout << "Bat destructor" << endl; }

   private:
};

int main() {
    Cat a;
    Bat b;
    cout << a.tell_me_your_name() << endl;
    a.run();
    cout << b.tell_me_your_name() << endl;
    b.run();
    Animal **arr = new Animal *[10];
    for (int i = 0; i < 10; ++i) {
        if (rand() % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << arr[i]->tell_me_your_name() << endl;
        arr[i]->run();
        arr[i]->say();
    }

    for (int i = 0; i < 10; ++i) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}