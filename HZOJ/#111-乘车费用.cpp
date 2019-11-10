#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double n;
    cin >> n;
    cout << setiosflags(ios::fixed) << setprecision(1);
    if (n <= 3) {
        cout << 14;
    } else {
        cout << 14 + 2.3 * (n - 3);
    }
    return 0;
}