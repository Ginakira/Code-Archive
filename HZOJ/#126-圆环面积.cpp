#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define PI 3.14
using namespace std;

int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2f", PI * (r1 * r1 - r2 * r2));
    return 0;
}