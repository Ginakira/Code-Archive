/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/06 21:42:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace haizei {
class ostream {
   public:
    ostream &operator<<(int x) {
        printf("%d", x);
        return *this;
    }

    ostream &operator<<(const std::string &str) {
        printf("%s", str.c_str());
        return *this;
    }

    ostream &operator<<(const char &ch) {
        printf("%c", ch);
        return *this;
    }

    ostream &operator<<(const double &a) {
        char e_str[20];
        sprintf(e_str, "%-6g", a);
        for (int i = 0; e_str[i]; ++i) {
            if (e_str[i] - ' ') continue;
            e_str[i] = 0;
            break;
        }
        printf("%s", e_str);
        return *this;
    }
};
char endl = '\n';
ostream cout;
}  // namespace haizei

int main() {
    haizei::cout << "Hello world" << haizei::endl;
    haizei::cout << 123 << haizei::endl;
    return 0;
}