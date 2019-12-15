/************************************************************
    File Name : pointer.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/14 20:31:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define offset(T, a) (long)(&((T *)(NULL))->a)
struct Data {
    double a;
    int b;
    char c;
};

int main() {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s\n", (char *)(&num1));
    printf("%s\n", (char *)(&num2));
    printf("%s\n", (char *)(&num2 + 1));
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    return 0;
}