#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

long long factorial(int x) {
    if (x == 1) return 1;
    return factorial(x - 1) * x;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}