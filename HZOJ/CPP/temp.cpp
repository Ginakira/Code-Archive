/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/05 00:38:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
   public:
    Point();
    Point(int x, int y);
    int x();
    int y();
    void set_x(int x);
    void set_y(int y);
    static int output_cnt();

   private:
    static int point_cnt;
    int __x, __y;
};

int Point::point_cnt = 0;

Point::Point() { Point::point_cnt += 1; };

Point::Point(int x, int y) : __x(x), __y(y) { Point::point_cnt += 1; }

int Point::x() { return this->__x; }

int Point::y() { return this->__y; }

void Point::set_x(int x) {
    this->__x = x;
    return;
}

void Point::set_y(int y) {
    this->__y = y;
    return;
}

int Point::output_cnt() { return Point::point_cnt; }

int main() {
    Point a(2, 3), b;
    cout << a.x() << ' ' << a.y() << endl;
    cout << Point::output_cnt() << endl;
    return 0;
}