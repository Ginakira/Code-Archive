#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double n = 0, add;
    scanf("%lf", &add);
    for (int i = 0; i < 6; ++i) {
        n = (n + add) * 1.00417;
    }
    printf("$%.2f", n);
    return 0;
}