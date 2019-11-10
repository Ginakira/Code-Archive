#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n / 7 % 2 == 1 && n % 7 == 0) cout << "YES";
    else
        cout << "NO";
    return 0;
}