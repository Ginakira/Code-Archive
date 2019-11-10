#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n % m != 0) cout << n / m + 1;
    else
        cout << n / m;
    return 0;
}