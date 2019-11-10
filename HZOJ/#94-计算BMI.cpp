#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double w, h;
    scanf("%lf %lf", &w, &h);
    printf("%.2f", w / (h * h));
    return 0;
}