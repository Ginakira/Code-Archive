/************************************************************
    File Name : 11.operator2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/27 19:20:42
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
   public:
    // 初始化列表 小括号外是成员属性 括号内是参数
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {
        // this->x = x;
        // this->y = y;
    }
    int x() const { return __x; }
    int y() const { return __y; }

    Point operator+(const Point &a) { return Point(x() + a.x(), y() + a.y()); }

    // See Line:53
    // void operator+=(const Point &a) {
    //     __x += a.x();
    //     __y += a.y();
    //     return;
    // }

    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }

    // ++放在前面不用传任何参数
    Point &operator++() {
        __x += 1;
        __y += 1;
        return *this;
    }

    // ++放在后面会传一个无用的int参数 用于区分两种++
    // 不能返回引用 因为temp是局部变量 在函数执行完后会被销毁
    Point operator++(int) {
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }

   private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}

int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    cout << "pre incr : " << ++(c += b) << endl;
    cout << c << endl;
    cout << "after incr : " << c++ << endl;
    cout << c << endl;

    // 由下可看到+=应该返回的是n的引用
    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
    return 0;
}