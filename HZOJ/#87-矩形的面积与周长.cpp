#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    float a, b;
    scanf("%f", &a);
    scanf("%f", &b);
    printf("%.2f\n", (a + b) * 2);
    printf("%.2f\n", a * b);
    return 0;
}