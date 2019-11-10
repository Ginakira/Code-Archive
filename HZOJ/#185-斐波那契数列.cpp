#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int fib[40] = {0, 1, 1, 2};

void init() { for (int i = 3; i < 31; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    return;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << fib[n];
    return 0;
}