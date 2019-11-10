#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double v, a;
    scanf("%lf%lf", &v, &a);
    printf("%.2f", (v * v) / (2 * a));
    return 0;
}