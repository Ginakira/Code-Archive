/************************************************************
    File Name : EP05.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 18:25:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum1 = 5050, sum2 = 0;
    sum2 = (2 * (100 * 100 * 100) + 3 * (100 * 100) + 100) / 6;
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}