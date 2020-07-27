/************************************************************
    File Name : 9.any_type_array.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/27 00:26:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Array {
   public:
    Array() {
        this->__size = 10;
        this->__cnt = 0;
        this->data = new T[this->__size];
    }

    Array(int n) {
        this->__size = n;
        this->__cnt - n;
        this->data = new T[this->__size];
    }

    void push_back(const T &a) {
        this->data[this->__cnt++] = a;
        return;
    }

    int size() { return this->__cnt; }

    T &operator[](int ind) { return this->data[ind]; }

   private:
    T *data;
    int __size, __cnt;
};

int main() {
    Array<int> arr;
    cout << arr.size() << endl;
    arr.push_back(233);
    cout << arr.size() << endl;
    cout << arr[0] << endl;
    return 0;
}