/************************************************************
    File Name : 10.operator.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/27 18:29:20
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace haizei {

class istream {
   public:
    // 这里返回的是引用 避免连续调用时使用的不是同一个对象
    istream &operator>>(int &n) {
        std::cin >> n;
        return *this;
    }

   private:
};

class ostream {
   public:
    // 参数使用引用也是避免多余的拷贝
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }

    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }

   private:
};

istream cin;
ostream cout;
};  // namespace haizei

// 类外重载
haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

// 下面传过来的其实是字面量（常量） 而如果不加const
// 证明这个引用所绑定的可以修改 显然字面量不可以修改
// 所以需要加上const 让引用z也可以绑定到常量上
std::ostream &operator+(std::ostream &out, const int &z) {
    out << z;
    return out;
}

int main() {
    int n, m;
    // 会被编译器转换成haizei::cin.operator>>(n)
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";

    // 使用类外重载std::cout的加号使编译通过
    // +优先级比<<优先级更高 所以需要括号
    (((((cout + 8) << " ") + 9) << " ") + 10) << "\n";
    return 0;
}