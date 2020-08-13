/************************************************************
    File Name : 33.thread.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/13 11:49:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
using namespace std;

void func() {
    cout << "hello world" << endl;
    return;
}

void func2(int x) {
    cout << x << " hello world" << endl;
    return;
}

void func3(int &x) {
    x += 1;
    cout << x << "Hello world" << endl;
    return;
}

int main() {
    thread t1(func);
    thread t2(func);
    thread t3(func);
    t1.join();
    t2.join();
    t3.join();

    thread t4(func2, 4);
    thread t5(func2, 5);
    thread t6(func2, 6);
    t4.join();
    t5.join();
    t6.join();

    int n = 0;
    thread t7(func3, ref(n));
    thread t8(func3, ref(n));
    thread t9(func3, ref(n));
    t7.join();
    t8.join();
    t9.join();
    cout << n << endl;
    return 0;
}