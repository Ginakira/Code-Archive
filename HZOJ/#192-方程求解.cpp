#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double a;
    cin >> a;
    double l = 0, r = 30, mid;
    while(r - l > 0.00001) {
        mid = (l + r) / 2;
        if(mid * exp(mid) < a) l = mid;
        else r = mid;
        //cout << l << ' ' << r << ' ' << mid << endl;
    }
    cout << setiosflags(ios::fixed) << setprecision(4) << mid << endl;
    return 0;
}