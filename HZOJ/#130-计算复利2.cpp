#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double m, n, ans = 0;
    scanf("%lf%lf", &m, &n);
    while (n--) {
        ans = (ans + m) * 1.00417;
    }
    printf("$%.2f", ans);
    return 0;
}