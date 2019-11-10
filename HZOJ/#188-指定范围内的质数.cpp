#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool is_prime(int a) {
    if (a == 1) return false;
    if (a == 2) return true;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = m; i <= n; ++i) {
        if (is_prime(i)) cout << i << endl;
    }
    return 0;
}