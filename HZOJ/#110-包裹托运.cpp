#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double x;
    cin >> x;
    cout << setiosflags(ios::fixed) << setprecision(2);
    if (x <= 15) {
        cout << 6 * x;
    } else {
        cout << 90 + (x - 15) * 9;
    }
    return 0;
}