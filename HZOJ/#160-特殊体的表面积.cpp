#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define PI 3.14
using namespace std;

int main() {
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2f", PI * r * r + 4 * r * r +
                       ((PI * r + 2 * r + 2 * sqrt(2) * r) * h));
    return 0;
}