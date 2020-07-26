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

    void set(int x, int y) {
        this->x = x, this->y = y;
        return;
    }

    void seek() const {
        seek_cnt += 1;
        cout << x << " " << y << endl;
    }

    int S() const { return seek_cnt; }

    static int T() { return Point::total_cnt; }

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }

   private:
    int x, y;
    mutable int seek_cnt;  // mutable声明的属性可以在const方法中修改
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
    d.seek();
    c.seek();
    const Point e(6, 7);
    e.seek();
    e.seek();
    cout << e.S() << endl;
    return 0;
}
/*
    1. 调用了c的赋值运算符
    2. 又因为operator=(People &a)，所以需要将5.6作为一个对象绑定到引用上
    3. 所以中间会生成一个匿名对象，调用的是Point(double z) :
   Point()这个构造函数，这个转换构造函数会先构造默认构造函数，构造完后，引用绑定到了匿名对象上
    4. 继续执行赋值运算符中的代码
    5. 执行完，释放掉5.6所绑定的匿名对象
*/