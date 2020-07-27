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
    istream &operator>>(int &n) {
        std::cin >> n;
        return *this;
    }

   private:
};

class ostream {
   public:
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

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    return 0;
}