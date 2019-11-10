#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define PI 3.141592653589793238462643383279
#define rad 0.01745
using namespace std;

int main() {
    double a, b, theta, ans;
    cin >> a >> b >> theta;
    theta = PI * theta / 180.0;
    ans = sqrt(a * a + b * b - 2 * a * b * cos(theta));
    printf("%.6f", ans);
    return 0;
}