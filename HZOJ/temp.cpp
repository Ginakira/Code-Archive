/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/26 12:24:14
************************************************************/

struct X {
    X() = delete;
    X(const X&) = delete;
    X(int) {}
};

struct Y {
    X x;
    Y() = delete;
    Y(const Y&) = delete;
    Y(int) : x{0} {}
};

int main() {
    Y y1{0};
    // Y y2 = y1;
    return 0;
}