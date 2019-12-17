/************************************************************
    File Name : EP28.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 19:18:53
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 1;
    for (int l = 3; l <= 1001; l += 2) {
        sum += 4 * l * l - 6 * l + 6;
    }
    /* sum = (2 * 500 * 500 * 500 + 3 * 500 * 500 + 500) * 2 / 3 - 1 +
          6 * (1004 * 50 / 2) + 500 * 6; */
    printf("%d\n", sum);
    return 0;
}