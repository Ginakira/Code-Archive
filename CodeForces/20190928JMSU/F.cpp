#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double r;
    while (scanf("%lf", &r)) {
        if (r == 0) break;
        printf("%.3f %.3f\n", sqrt(r * r / 3), sqrt(r * r / 3 * 2));
    }

    return 0;
}