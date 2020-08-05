/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/05 16:05:58
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class A {
   public:
    A() { this->arr = new int[100]; }
    A(const A &obj) : x(obj.x), y(obj.y) {
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }
    int *arr;
    int x, y;
};

int main() {
    A a;
    A b = a;
    a.arr[0] = 123;
    b.arr[0] = 456;
    cout << a.arr[0] << ' ' << b.arr[0] << endl;
    return 0;
}