#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double x, n;
    cin >> x >> n;
    while(n--) {
        x *= 1.06;
    }
    cout << (int)x << endl;
    return 0;
}