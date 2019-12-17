/************************************************************
    File Name : EP01-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 15:00:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum3 = (3 + 999) * 333 / 2;
    int sum5 = (5 + 995) * (995 / 5) / 2;
    int sum15 = (15 + (999 / 15) * 15) * (999 / 15) / 2;
    printf("%d", sum3 + sum5 - sum15);
    return 0;
}