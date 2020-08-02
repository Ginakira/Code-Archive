/************************************************************
    File Name : 26.final.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/02 19:49:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class A : public map<int, int> {
   public:
    virtual void say() {
        cout << "Class A : hello world" << endl;
        return;
    }
};

class B final : public A {
   public:
    void say() final override {
        cout << "Class B : hello world" << endl;
        return;
    }
};

// class C : public B {
//    public:
//     // void say() override {
//     //     cout << "Class C : hello world" << endl;
//     //     return;
//     // }
// };


int main() {
    A a;
    a[12344] = 23425;
    a[2344] = 3245;
    for (auto x : a) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}