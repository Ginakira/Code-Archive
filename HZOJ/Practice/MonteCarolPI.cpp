/************************************************************
    File Name : mentocarolPI.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/07 18:58:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_OP 100000000

int main() {
    srand(time(0));
    int n = 0, m = 0;
    for (int i = 0; i < MAX_OP; ++i) {
        double x = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        double y = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1);
        if (x * x + y * y <= 1.0) m++;
        n++;
    }
    printf("%lf\n", m * 1.0 / n * 4.0);
    return 0;
}