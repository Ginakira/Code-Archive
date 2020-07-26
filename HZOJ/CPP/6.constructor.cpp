/************************************************************
    File Name : 6.constructor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/26 18:16:42
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class People {
   public:
    People() {}

    People(string name) {
        cout << "Parameter constructor" << endl;
        this->name = name;
    }

    People(int x) {
        cout << "Int parameter constructor" << endl;
        this->x = x;
    }

    ~People() { cout << "Destructor" << endl; }
    string name;
    int x;
};

int main() {
    People a("sakata");
    People b = string("hug");
    People c(543);
    People d = 678;
    cout << a.name << endl;
    cout << b.name << endl;
    cout << c.x << endl;
    cout << d.x << endl;
    c = 987;
    cout << c.x << endl;
    d = string("gintoki");
    cout << d.name << endl;
    return 0;
}