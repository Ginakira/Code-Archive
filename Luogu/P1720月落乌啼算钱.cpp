#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int n;
    cin >> n;
    double ans;
    ans = ((pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5));
    printf("%.2f\n", ans);
    return 0;
}