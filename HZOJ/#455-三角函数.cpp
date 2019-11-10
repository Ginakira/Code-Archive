#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[3];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int b = a[0], c = a[2];
    cout << b / gcd(b, c) << '/' << c / gcd(b, c);
    return 0;
}