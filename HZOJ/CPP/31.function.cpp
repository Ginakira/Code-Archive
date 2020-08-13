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
    virtual base<RT, PARAMS...> *getCopy() = 0;
    virtual ~base(){};
};

template <typename RT, typename... PARAMS>
class normal_func : public base<RT, PARAMS...> {
   public:
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    RT operator()(PARAMS... args) override { return this->ptr(args...); }
    virtual base<RT, PARAMS...> *getCopy() override {
        return new normal_func<RT, PARAMS...>(ptr);
    }

   private:
    func_type ptr;
};

template <typename C, typename RT, typename... PARAMS>
class functor : public base<RT, PARAMS...> {
   public:
    typedef RT (*func_type)(PARAMS...);
    functor(C &func) : ptr(func) {}
    RT operator()(PARAMS... args) override { return this->ptr(args...); }
    virtual base<RT, PARAMS...> *getCopy() override {
        return new functor<C, RT, PARAMS...>(ptr);
    }

   private:
    C &ptr;
};

template <typename RT, typename... PARAMS>
class function;

template <typename RT, typename... PARAMS>
class function<RT(PARAMS...)> {
    typedef normal_func<RT, PARAMS...> T1;

   public:
    function(RT (*func)(PARAMS...))
        : ptr(new normal_func<RT, PARAMS...>(func)) {}
    template <typename T>
    function(T a)
        : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(
              a)) {}

    function(const function &f) { this->ptr = f.ptr->getCopy(); }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }
    RT operator()(PARAMS... args) { return this->ptr->operator()(args...); }

    ~function() {
        if (ptr != nullptr) {
            delete ptr;
        }
    }

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

void print_expr(int a, int b, string caption) {
    cout << caption << " : " << a << " + " << b << endl;
    return;
}

struct MaxClass {
    int operator()(int a, int b) { return a > b ? a : b; }
};

// 完善FunctionCnt
template <typename RT, typename... PARAMS>
class FunctionCnt;

template <typename RT, typename... PARAMS>
class FunctionCnt<RT(PARAMS...)> {
   public:
    FunctionCnt(function<RT(PARAMS...)> g) : g(g), __cnt(0) {}
    RT operator()(PARAMS... params) {
        __cnt += 1;
        return g(params...);
    }
    int cnt() { return this->__cnt; }

   private:
    function<RT(PARAMS...)> g;
    int __cnt;
};

/*
    此处，如果只将构造函数中改为haizei::function，会引发段错误，原因：
    当我们的构造函数初始化列表调用g(g)的时候，会调用系统function的转换构造函数
    也就是template< class F > function( F f ); 这里的f并非引用
    所以又会调用一次haizei::function的拷贝构造函数，而我们并没有显式实现拷贝构造
    所以调用赛是系统的默认拷贝构造函数，也就是进行了浅拷贝。
    当系统function的转换构造执行结束后，局部变量f将会被析构，此时将执行delete
   *ptr 这就会导致在正常调用时，ptr已经被销毁了，无法访问到，引发段错误
*/

int main() {
    int n;
    cout << typeid(n).hash_code() << endl;
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;

    FunctionCnt<int(int, int)> add_cnt(add);
    add_cnt(3, 7);
    add_cnt(4, 5);
    add_cnt(7, 9);
    cout << add_cnt.cnt() << endl;
    FunctionCnt<void(int, int, string)> print_expr_cnt(print_expr);
    print_expr_cnt(1, 2, "Add");
    print_expr_cnt(3, 4, "Test");
    cout << print_expr_cnt.cnt() << endl;
    return 0;
}