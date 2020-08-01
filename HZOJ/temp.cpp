/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/01 00:19:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct A {
    int x, y;
    int echo() {
        cout << "Hello world" << endl;
        return 0;
    }
};

class B {
   public:
    int echo() {
        cout << "Hello world" << endl;
        cout << x << ' ' << y << endl;
        return 0;
    }

   private:
    int x, y;
};

int main() {
    A a;
    B b;
    a.x = 3, a.y = 2;
    cout << a.x << ' ' << a.y << endl;
    b.echo();
    return 0;
}