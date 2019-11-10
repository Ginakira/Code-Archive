#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r, b, c, d, e;
    cin >> r >> b >> c >> d >> e;
    if(d + c > e + e) cout << r * c + b * d;
    else {
        if(r > b) cout << b * e * 2 + (r - b) * c;
        else cout << r * e * 2 + (b - r) * d;
    }
    return 0;
}