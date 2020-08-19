/************************************************************
    File Name : 39.visitor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/20 10:48:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
   public:
    virtual ~Animal() {};
};

class Cat : public Animal {};

class Dog : public Animal {};

class Mouse : public Animal {};

class Bat : public Animal {};

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; ++i) {
        switch (rand() % 3) {
            case 0:
                arr[i] = new Cat();
                break;
            case 1:
                arr[i] = new Dog();
                break;
            case 2:
                arr[i] = new Mouse();
                break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        // 
        if (dynamic_cast<Cat *>(arr[i])) {
            cout << "this is a cat" << endl;
        } else if (dynamic_cast<Dog *>(arr[i])) {
            cout << "this is a dog" << endl;
        } else if (dynamic_cast<Mouse *>(arr[i])) {
            cout << "this is a mouse" << endl;
        } else if (dynamic_cast<Bat *>(arr[i])) {
            cout << "this is a bat" << endl;
        }
    }
    return 0;
}