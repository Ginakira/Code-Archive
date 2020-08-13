/************************************************************
    File Name : 32.bind.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/13 11:17:58
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int add(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return a + b;
}

int add2(int a, int b, int c) {
    cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;
    return a + b + c;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b) {
    n += 1;
    return func(a, b);
}

int main() {
    add(3, 4);
    add(5, 6);
    function<int(int)> f1 = bind(add, 5, placeholders::_1);
    f1(3), f1(4), f1(5);
    function<int(int, int)> f2 = bind(add, placeholders::_2, placeholders::_1);
    f2(3, 4), f2(5, 6), f2(7, 8);

    function<int(int, int)> f3 =
        bind(add2, placeholders::_2, 6, placeholders::_1);
    f3(9, 10);

    function<int(int, int, int)> f4 =
        bind(add2, placeholders::_1, placeholders::_3, placeholders::_2);
    f4(1, 2, 3);

    // 绑定一个可以统计函数执行次数的方法
    int n = 0;
    function<int(int, int)> f5 =
        bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);
    f5(99, 88);
    f5(92, 84);
    f5(923, 38);
    // 输出0 原因：
    // bind是模板方法 如果只传n的话 此处的类型推导将是int而非int&
    // 所以实际是拷贝了一份 add_cnt中n的引用实际是绑定的这个拷贝后的参数
    // 而不是主函数中的n 所以需要改为ref(n) 让其模板推导类型为int&
    cout << n << endl;
    return 0;
}