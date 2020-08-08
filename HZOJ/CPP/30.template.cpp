/************************************************************
    File Name : 30.template.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/06 11:47:11
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
   public:
    A(int x) : x(x) {}
    int x;
};

class B {
   public:
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) { return a.x + b.y; }

namespace haizei {
// 当T或U没有默认构造时 dectltype(T() + U())是有问题的
// 返回值类型后置
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// 模板的特化形式
template <>
int add(int a, int b) {
    cout << "add int : " << a << ", " << b << endl;
    return a + b;
}

// 模板的偏特化形式
template <typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template <typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template <typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
   public:
    // 模板方法
    template <typename T>
    void operator()(const T &a) {
        cout << a << endl;
        return;
    }
};

template <typename T>
class FoolPrintAny {
   public:
    void operator()(const T &a) {
        cout << a << endl;
        return;
    }
};

// 模板类的特化
template <>
class FoolPrintAny<int> {
   public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
        return;
    }
};

// ARGS是类型包的名字
template <typename T>
void printAny(const T &a) {
    cout << a << endl;
    return;
}

// 变参解析工具类
template <int n, typename T, typename... ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};

template <typename T, typename... ARGS>
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

template <typename T>
struct ARG<0, T> {
    typedef T __type;
};

template <typename T, typename... ARGS>
void printAny(const T &a, ARGS... args) {
    cout << a << " ";
    printAny(args...);
    return;
}

template <typename T, typename... ARGS>
class Test;
template <typename T, typename... ARGS>
class Test<T(ARGS...)> {
   public:
    T operator()(ARGS... args) { return add<T>(args...); }

   private:
    template <typename T1, typename U, typename... US>
    T1 add(U a, US... args) {
        return a + add<T1>(args...);
    }
    template <typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};

// 模板函数作为参数 传递时的间接类型推导
template <typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(int (*func)(double)) {
    cout << func(2.3) << endl;
    return;
}

// 去掉引用类型
template <typename T>
struct remove_reference {
    typedef T type;
};

template <typename T>
struct remove_reference<T &> {
    typedef T type;
};

template <typename T>
struct remove_reference<T &&> {
    typedef T type;
};

// 添加 const 限定
template <typename T>
struct add_const {
    typedef const T type;
};

template <typename T>
struct add_const<const T> {
    typedef const T type;
};

// 转换成左值引用
template <typename T>
struct add_lvalue_reference {
    typedef T &type;
};

template <typename T>
struct add_lvalue_reference<T &> {
    typedef T &type;
};

template <typename T>
struct add_lvalue_reference<T &&> {
    typedef T &type;
};

// 转换为右值引用
template <typename T>
struct add_rvalue_reference {
    typedef T &type;
};

template <typename T>
struct add_rvalue_reference<T &> {
    typedef T &&type;
};

template <typename T>
struct add_rvalue_reference<T &&> {
    typedef T &&type;
};

// 去掉指针类型
template <typename T>
struct remove_pointer {
    typedef T type;
};

template <typename T>
struct remove_pointer<T *> {
    typedef typename remove_pointer<T>::type type;
};

// move模板函数 强制转换为右值
template <typename T>
typename add_rvalue_reference<T>::type move(T &&a) {
    return typename add_rvalue_reference<T>::type(a);
}

// 引用类型的推导
// template <typename T>
// T add2(T &a, T &b) {
//     T c = a = b;
//     return c;
// }

// 测试函数
template <typename T>
typename remove_reference<T>::type add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return c;
}

void f(int &x) {
    cout << "f function : left value" << endl;
    return;
}

void f(int &&x) {
    cout << "f function : right value" << endl;
    return;
}

}  // namespace haizei

int main() {
    cout << haizei::add(3, 4) << endl;
    cout << haizei::add(3.1241, 1235.455) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;

    A a(1000);
    B b(645);
    cout << haizei::add(a, b) << endl;

    cout << max(4, 3) << endl;
    // cout << max(4.3, 3) << endl;

    cout << haizei::max(3, 4) << endl;
    cout << haizei::max(3.4, 2) << endl;

    cout << haizei::min(3, 4) << endl;
    cout << haizei::min(3.4, 2) << endl;

    haizei::PrintAny print;
    print(123);
    print("Hello world");
    print(4.3);
    print(&a);

    haizei::FoolPrintAny<string> f;
    f(string("Hello world"));
    haizei::FoolPrintAny<int> f_int;
    f_int(233);

    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;

    haizei::printAny(123, 34.5, "Hello world", &a);

    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;

    // 累加求和
    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(1, 2, 3, 4) << endl;
    haizei::Test<int(int, int, int, int, int)> f5;
    cout << f5(1, 2, 3, 4, 5) << endl;

    haizei::func2(haizei::test_param_func);

    int inta = 123, intb = 456;
    // 推导得到 int add2(int &, int &)
    cout << haizei::add2(inta, intb) << endl;
    cout << haizei::add2(123, 456) << endl;

    haizei::f(n);
    haizei::f(haizei::move(n));

    return 0;
}