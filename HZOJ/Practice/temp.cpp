/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/11 18:20:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define offset(T, item) (long long)(&(((T *)(NULL))->item))

struct Data {
    char a;
    short b;
    char c;
    double d;
};

int main() {
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));
    printf("%lld\n", offset(struct Data, c));
    printf("%lld\n", offset(struct Data, d));
    return 0;
}