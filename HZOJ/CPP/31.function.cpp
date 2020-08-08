/************************************************************
    File Name : 31.function.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/08 15:25:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace haizei {
template <typename RT, typename... PARAMS>
class base {
   public:
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base(){};
};

template <typename RT, typename... PARAMS>
class normal_func : public base<RT, PARAMS...> {
   public:
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    RT operator()(PARAMS... args) override { return this->ptr(args...); }

   private:
    func_type ptr;
};

template <typename C, typename RT, typename... PARAMS>
class functor : public base<RT, PARAMS...> {
   public:
    typedef RT (*func_type)(PARAMS...);
    functor(C &func) : ptr(func) {}
    RT operator()(PARAMS... args) override { return this->ptr(args...); }

   private:
    C &ptr;
};

template <typename RT, typename... PARAMS>
class function;

template <typename RT, typename... PARAMS>
class function<RT(PARAMS...)> {
   public:
    function(RT (*func)(PARAMS...))
        : ptr(new normal_func<RT, PARAMS...>(func)) {}
    template <typename T>
    function(T &&a)
        : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(
              a)) {}

    RT operator()(PARAMS... args) { return this->ptr->operator()(args...); }

    ~function() { delete ptr; }

   private:
    base<RT, PARAMS...> *ptr;
};

// 实现function思路
/*
    g是一个对象，可以给g赋值的，一种是普通的函数，另外一种是函数对象
    当传递参数的时候，无论是赋值成什么，调用的都是其构造函数，所以应该有两类构造函数
    构造时，无论是普通函数还是函数对象，我们都给它包装为另外的一个函数对象
    然后将这个函数对象的地址存储起来 重载小括号
    base派生两个子类 一个函数 一个函数对象
*/
}  // namespace haizei

void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return;
}

int add(int a, int b) { return a + b; }

struct MaxClass {
    int operator()(int a, int b) { return a > b ? a : b; }
};

int main() {
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    return 0;
}