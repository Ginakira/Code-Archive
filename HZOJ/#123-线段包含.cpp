#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a >= c && b <= d) || (c >= a && d <= b)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}