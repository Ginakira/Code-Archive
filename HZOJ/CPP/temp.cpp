/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/07 15:42:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
   public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "copy constructor" << endl;
    }
    Point operator-(const Point &a) {
        Point ret;
        ret.x = this->x - a.x;
        ret.y = this->y - a.y;
        return ret;
    }
    friend Point operator+(const Point &, const Point &);
    friend ostream &operator<<(ostream &, const Point &);

   private:
    int x, y;
};

Point operator+(const Point &a, const Point &b) {
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << "<class Point>(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    Point a(2, 4), b(5, 3);
    Point c = a + b;
    Point d = a + b + c;
    Point e = d - b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;

    return 0;
}