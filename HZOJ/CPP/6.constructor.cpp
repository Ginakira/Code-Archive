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

    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }

    void operator=(const People &a) {
        cout << "Operator =" << endl;
        this->name = a.name;
        this->x = a.x;
    }

    ~People() { cout << "Destructor" << endl; }
    string name;
    int x;
};

void increase(int &a) {
    a++;
    return;
}

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    int num = 7;
    increase(num);
    cout << num << endl;
    cout << add(4, 5) << endl;
    
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
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
    c = a;
    cout << c.name << endl;
    cout << c.x << endl;
    return 0;
}