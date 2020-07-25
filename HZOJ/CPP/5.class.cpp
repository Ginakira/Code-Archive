/************************************************************
    File Name : 5.class.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/25 16:19:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class People {
    friend int main();
    int x, y;

   public:
    void set(int x);
    void say();
};

struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function : " << this << endl;
    this->x = x;
    return;
}

void People::say() {
    cout << x << ' ' << y << endl;
    return;
}

int main() {
    People a;
    People2 b;
    a.y = 18432;
    cout << "a object : " << &a << endl;
    a.set(3);
    a.say();
    b.x = 4;
    cout << b.x << endl;
    return 0;
}