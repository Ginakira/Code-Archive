#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

int fib[1000010] = {0, 1, 1, 2};

int main() {
    int n;
    cin >> n;
    for(int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] >= MOD) fib[i] %= MOD;
    }
    cout << fib[n];
    return 0;
}