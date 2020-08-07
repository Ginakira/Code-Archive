/************************************************************
    File Name : int_array.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/07 23:27:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IntArray {
   public:
    IntArray(int n) : n(n) { this->arr = new int[n]; }

    IntArray(const IntArray &obj) : n(obj.n) {
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) {
            this->arr[i] = obj.arr[i];
        }
    }

    int &operator[](int ind) {
        if (ind >= 0) {
            return this->arr[ind];
        }
        return this->arr[n + ind];
    }

    void operator+=(int x) {
        for (int i = 0; i < n; ++i) {
            this->arr[i] += x;
        }
        return;
    }

    IntArray &operator++() {  // ++a
        for (int i = 0; i < n; ++i) {
            this->arr[i] += 1;
        }
        return *this;
    }

    IntArray operator++(int x) {
        IntArray ret = (*this);
        for (int i = 0; i < n; ++i) {
            this->arr[i] += 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &, const IntArray &);

    ~IntArray() { delete this->arr; }

   private:
    int *arr, n;
};

ostream &operator<<(ostream &out, const IntArray &a) {
    out << "<Class IntArray> : ";
    for (int i = 0; i < a.n; ++i) {
        out << a.arr[i] << ' ';
    }
    return out;
}

int main() {
    srand(time(0));
    IntArray a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = rand() % 100;
    }
    cout << a[4] << endl;
    cout << a[-2] << endl;  // 输出倒数第二个的数
    cout << a << endl;
    a += 5;                 // 数组中所有元素加5
    cout << a << endl;      // 输出数组中所有元素
    cout << (a++) << endl;  // 给数组中所有的元素都加1
    cout << (++a) << endl;  // 同上
    return 0;
}