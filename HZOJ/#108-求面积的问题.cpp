#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    char c;
    double m, n;
    cin >> c >> m >> n;
    if(c == 'r') {
        cout << setiosflags(ios::fixed) << setprecision(2) << m * n;
    } else if(c == 't') {
        cout << setiosflags(ios::fixed) << setprecision(2) << m * n / 2;
    }
    return 0;
}