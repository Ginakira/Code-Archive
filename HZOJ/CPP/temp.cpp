/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/13 10:12:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A(int* a) : num(a) {}
    ~A() {
        cout << "destructor" << endl;
        delete num;
    }
    int* num;
};

int* num = new int(2333);

int main() {
    A* a = new A(num);
    cout << num << endl;
    cout << a->num << endl;
    delete a;
    cout << *num << endl;
    return 0;
}