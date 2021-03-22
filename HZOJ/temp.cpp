/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/03/22 10:52:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <int n>
struct Sum {
    static const int SUM;
};

template <int n>
const int Sum<n>::SUM = n + Sum<n - 1>::SUM;

template <>
const int Sum<1>::SUM = 1;

int main() {
    cout << Sum<100>::SUM << endl;
    return 0;
}