#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int a1, a2, b1, b2;
    scanf("%d/%d\n%d/%d", &a1, &b1, &a2, &b2);
    a1 *= a2;
    b1 *= b2;
    int gcd1 = __gcd(a1, b1);
    a1 /= gcd1, b1 /= gcd1;
    cout << b1 << ' ' << a1;
    return 0;
}