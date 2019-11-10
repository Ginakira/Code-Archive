#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    while (n--) {
        x *= 1.06;
    }
    printf("%.6f", x);
    return 0;
}