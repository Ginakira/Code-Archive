#include <iostream>
#include <cstdio>
#define pi 3.14159265359
using namespace std;

int main() {
    double r;
    cin >> r;
    printf("%.6f\n%.6f", r * r * pi, r * r * 2);
    return 0;
}