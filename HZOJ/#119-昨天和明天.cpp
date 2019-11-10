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
    int y, m, d, yy, ym, yd, ay, am, ad;
    cin >> y >> m >> d;
    if (is_leap(y)) md[2] = 29;
    yy = ay = y;
    ym = am = m;
    yd = d - 1, ad = d + 1;
    if (yd < 1) {
        ym--;
        if(ym < 1) {
            ym = 12;
            yy--;
        }
        yd = md[ym];
    }
    if(ad > md[am]) {
        ad = 1;
        am++;
        if(am > 12) {
            am = 1;
            ay++;
        }
    }
    cout << yy << ' ' << ym << ' ' << yd << '\n'
         << ay << ' ' << am << ' ' << ad << '\n';
    return 0;
}