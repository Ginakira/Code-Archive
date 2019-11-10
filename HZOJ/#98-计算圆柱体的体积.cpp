#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#define pi 3.14
using namespace std;

int main() {
    double r, h;
    cin >> r >> h;
    cout << setiosflags(ios::fixed) << setprecision(2) << r * r * pi << endl
         << r * r * pi * h;
    return 0;
}