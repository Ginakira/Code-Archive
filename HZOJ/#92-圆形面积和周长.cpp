#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define pi 3.14
using namespace std;

int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2f\n%.2f\n", 2 * pi * r, pi * r * r);
    return 0;
}