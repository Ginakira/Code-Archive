#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool is_leap(int year) {
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    if (is_leap(y)) md[2] = 29;
    if (md[m] >= d)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}