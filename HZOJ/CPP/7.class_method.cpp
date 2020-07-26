/************************************************************
    File Name : 7.class_method.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/26 19:43:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
   public:
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
    }

    Point(const Point &a) : Point() {
        cout << "copy constructor : " << this << endl;
        this->x = a.x;
        this->y = a.y;
    }

    Point(double z) : Point() {
        cout << "convert constructor : " << this << endl;
        this->x = 99;
        this->y = 99;
    }

    Point(int x, int y) : Point() {
        cout << "param constructor : " << this << endl;
        // Point::total_cnt += 1;
        this->x = x;
        this->y = y;
    }

    void operator=(const Point &a) {
        cout << "operator= : " << this << endl;
        this->x = a.x, this->y = a.y;
        return;
    }

    static int T() { return Point::total_cnt; }

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }

   private:
    int x, y;
    static int total_cnt;
};

int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
}

int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    Point c(3, 4);
    cout << c.T() << endl;
    Point d(3.4);
    cout << d.T() << endl;
    c = 5.6;
    cout << d.T() << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    return 0;
}