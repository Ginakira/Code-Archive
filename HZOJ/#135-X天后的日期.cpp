#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool is_leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int add, y, m, d;
    cin >> add >> y >> m >> d;
    if (is_leap(y)) {
        md[2] = 29;
    }
    d += add;
    while (d > md[m]) {
        d -= md[m];
        m++;
        if (m > 12) {
            m = 1, y++;
            if (is_leap(y)) {
                md[2] = 29;
            } else {
                md[2] = 28;
            }
        }
    }
        cout << y << ' ' << m << ' ' << d;
        return 0;
    }