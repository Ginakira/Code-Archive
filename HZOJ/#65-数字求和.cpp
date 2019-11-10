#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long ans = 0;
    for (int i = 1; i <= 10000; ++i) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) ans += i;
    }
    cout << ans << endl;
    return 0;
}